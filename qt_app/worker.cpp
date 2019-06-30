#include "worker.h"
#include <iostream>
#include <QTimer>
#include <QDebug>


Worker::Worker(void)
    : QObject{}
    , _device{}
    , _mode(MEASURE_C)
    , _needCalibration{ false }
    , _parent{}
    , _ring_buffer{}
    , _decimation_counter{}
    , _c{}
{
    _timer = new QTimer(this);
    connect(_timer, SIGNAL(timeout()), this, SLOT(slot_update()));
    _timer->start( 100 );
}

Worker::~Worker()
{
    stop();
    ::hid_exit();
}




void Worker::slot_update(void) {
    if ( _device )
        work();
    else
        begin();

}

bool Worker::_init(  )
{
    _device = ::hid_open(0x16C0, 0x05DF, nullptr);
    if(!_device) {
        return false;
    }

    //slot_setMode(_mode);
    GetSettings();
    _hid_ReadCalibration();

    return true;
}

void Worker::SetParent( QObject * parent ) {
    _parent = parent;
    connect( this, SIGNAL(signal_DeviceConnected()), _parent, SLOT(slot_DeviceConnected()));
    connect( this, SIGNAL(signal_DeviceDisconnected(const hid_device_info *  )), _parent, SLOT(slot_DeviceDisconnected(const hid_device_info * )));

    //connect( this, SIGNAL(signal_idle_freq_not_trigerred()), _parent, SLOT(slot_Calibration()));

}




void Worker::begin( void )
{
    if (!_parent) return;


    status |= PCPROGRAMRUN_BIT;
    if( _init() )
    {
		//connected
		emit signal_DeviceConnected();
    } 
	else
	{
		//disconnected
        auto hids = ::hid_enumerate(0x0000,0x0000);
        emit signal_DeviceDisconnected(hids);
	}
}



void Worker::stop()
{
    if(_device)
    {
        status &= ~(RELAY_BIT | PCPROGRAMRUN_BIT);
        _hid_SendStatus();
        ::hid_close(_device);
        _device = nullptr;
    }

}

void Worker::slot_setMode(int mode)
{
    _mode = (MODE)mode;

    bool doSend(false);
    switch (_mode)
    {
    case ( CALIBRATE_C ):
    case (MEASURE_C):
        {
        status &= ~RELAY_BIT;
        doSend = true;
        break;
    }
    case (CALIBRATE_L):
    case (MEASURE_L):{
        status |= RELAY_BIT;
        doSend = true;
        break;
 }


    default:
        break;
    }

    if(_device && doSend)
    {
        _hid_SendStatus();
        emit signal_C_ValueUpdated("0");
        emit signal_L_ValueUpdated("0");
    }
}

void Worker::work()
{
    //if ( _needCalibration ) return;

    _hid_ReadData(); //Принимаем данные
    if(_device == nullptr)
    {
        stop();
        return;
    }

    _lc.SetFrequency(rawdata[0],rawdata[1],rawdata[2]);

    if ( (_lc.GetFrequency() >= 50) && (_lc.GetFrequency() <= MINFREQ))
    {
        // out of range
        emit signal_OutOfRange();
        return;
    }
    _ring_buffer.put( _lc.GetFrequency() );
    emit signal_BufferGrowUp( _ring_buffer.size() );
    {
        auto f = _ring_buffer.getM();
        auto d = _ring_buffer.getD();
        if ( ++_decimation_counter%10 == 0u ) emit signal_F_ValueUpdated( f, d );
    }

    double data{};
    QString value;
    switch(_mode)
    {
    case (MEASURE_C):
    {
        data = _lc.GetCapacitance(); //pF
        //data = _lc.GetAdaptiveCapacitance(data);
        if(data > 0)
        {
            value = QString("%1").arg(data);
            if(_lc.GetPrefixC() == 0)
            {
                value += QString::fromUtf8(" pF");
            }
            else if(_lc.GetPrefixC() == 1)
            {
                value += QString::fromUtf8(" nF");
            }
            else if(_lc.GetPrefixC() == 2)
            {
                value += QString::fromUtf8(" µF");
            }
        }
        else
        {
            value = "";
        }
        emit signal_C_ValueUpdated( value );
        break;
    }
    case (MEASURE_L):
    {

        if(_lc.GetFrequency() < 50) //zero (индуктивность не вставлена)
        {
            emit signal_L_ValueUpdated("");
            break;
        }

        data = _lc.GetInductance(); //Значение индуктивности в µH
        //data = _lc.GetAdaptiveInductance(data);

        if(data >= 0)
        {
            value = QString("%1").arg(data);
            if(_lc.GetPrefixL() == 0)
            {
                value += QString::fromUtf8(" µH");
            }
            else if(_lc.GetPrefixL() == 1)
            {
                value += QString::fromUtf8(" mH");
            }
        }
        emit signal_L_ValueUpdated(value);
        break;
    }
    case ( CALIBRATE_L ):
    case ( CALIBRATE_C ):
    {
        auto f = _ring_buffer.getM();
        auto threshold = _c.tolerance * f;
        if ( _ring_buffer.getD() <= threshold ) calibrate(f);
        emit signal_ShowFreqThreschold( threshold );
        break;
    }
    case (CALIBRATE_C_DUMMY):
    {
        emit signal_show_calC( _lc.Get_refC_calC(), _lc.Get_refL_calC() );
        break;
    }
    case (CALIBRATE_L_DUMMY):
    {
        emit signal_show_calL( _lc.Get_refC_calL(), _lc.Get_refL_calL() );
        break;
    }
    }
}

void Worker::slot_Calibrate_C(double C, double tolerance)
{
    _c.tolerance = tolerance;
    _c.cal = C;
    _c.idle_freq = double{};
    _ring_buffer.reset();
    slot_setMode(CALIBRATE_C);
}

void Worker::slot_Calibrate_L(double L, double tolerance)
{
    _c.tolerance = tolerance;
    _c.cal = L;
    _c.idle_freq = double{};
    _ring_buffer.reset();
    slot_setMode(CALIBRATE_L);
}

void Worker::slot_C_save( bool save_averge_value)
{
  qDebug() << "save calibration";
  _hid_SendCalibration<C>(save_averge_value);
}



void Worker::slot_ResetCalibration( void )
{
    _c.idle_freq = double{};
}

void Worker::_hid_ProcessError()
{
    if ( _device )
    {
        ::hid_close(_device);
        _device = nullptr;
	
    }
    emit signal_DeviceDisconnected(::hid_enumerate(0,0));
}

void Worker::_hid_SendStatus()
{
    if(_device == nullptr) {
        emit signal_DeviceDisconnected(::hid_enumerate(0,0));
        return;
	}

#pragma pack(push, 1)
    struct report_t
    {
        unsigned char id;
        unsigned char status;
    };
#pragma pack(pop)

    report_t report;
    report.id = 0x02;
    report.status = status;

    int result = ::hid_send_feature_report(_device, reinterpret_cast<uint8_t*>(&report) , sizeof(report));

    if(result == -1)
        _hid_ProcessError();
}

void Worker::_hid_ReadData()
{

    if(_device == nullptr) {
        emit signal_DeviceDisconnected(::hid_enumerate(0,0));
		return;
	}
        

#pragma pack(push, 1)
    struct report_t
    {
        unsigned char id;
        unsigned char data[3];
    };
#pragma pack(pop)

    report_t report;
    report.id = 0x01;

    int result = ::hid_get_feature_report(_device, (unsigned char*) &report, sizeof(report));
    if(result == -1)
    {
        _hid_ProcessError();
        return;
    }

    ::memcpy(rawdata, report.data, sizeof(rawdata));
}
