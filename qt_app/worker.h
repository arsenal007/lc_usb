#pragma once

#include <QThread>
#include <QTimer>
#include <TRingBuffer.hpp>
#include <QDebug>


class Sleeper : public QThread
{
public:
  static void usleep(unsigned long usecs){QThread::usleep(usecs);}
  static void msleep(unsigned long msecs){QThread::msleep(msecs);}
  static void sleep(unsigned long secs){QThread::sleep(secs);}
};

#if defined(Q_OS_WIN)
#include <windows.h>
#endif

#include <QObject>
#include "hidapi.h"
#include "lc.h"

class Worker : public QObject
{
  Q_OBJECT

public:
  enum MODE: int
  {
    MEASURE_C = 0,
    MEASURE_L,
    CALIBRATE_C_DUMMY = 2,
    CALIBRATE_L_DUMMY = 3,
    CALIBRATE_C = 100,
    CALIBRATE_L = 101
  };

  Worker( void );
  void SetParent(QObject * parent);
  ~Worker();

signals:
  void signal_CalibrationRequired();
  void signal_CalibrationMessage(QString message);
  void signal_L_ValueUpdated(QString);
  void signal_C_ValueUpdated(QString);
  void signal_F_ValueUpdated( double, double );
  void signal_OutOfRange();
  void signal_DeviceConnected();
  void signal_DeviceDisconnected( const hid_device_info * );
  void signal_cal_msg_c( QString );
  void signal_cal_msg_l( QString );
  void signal_BufferGrowUp( int );
  void signal_ShowFreqThreschold( double );
  void signal_show_calC( unsigned int, unsigned int );
  void signal_show_calL( unsigned int, unsigned int );
  void signal_calibration_C_finished( void );

public slots:

  void slot_setMode( int );
  void slot_update( void );
  void slot_Calibrate_C( double, double );
  void slot_Calibrate_L( double, double );
  void slot_C_save( bool );
  void slot_ResetCalibration( void );

private:
  void begin( void );
  void work( void );
  void stop( void );

  bool _init();

  void _hid_ProcessError();
  void _hid_SendStatus();

  struct report_t
  {
    unsigned char id;
    unsigned char data[16];
  } __attribute__((packed));


  inline void _hid_ReadCalibration(void)
  {
    auto refC_calC = _original_ReadIntValueFromBytes(&settings[1], &settings[2]);
    auto refL_calC = _original_ReadIntValueFromBytes(&settings[3], &settings[4], &settings[5]);
    //auto N = _original_ReadIntValueFromBytes(&settings[6], &settings[7]);
    auto refC_calL = _original_ReadIntValueFromBytes(&settings[8], &settings[9]);
    auto refL_calL = _original_ReadIntValueFromBytes(&settings[10], &settings[11], &settings[12]);
    auto is_C = _lc.Set<lc::ESet::SOFT_C>(refC_calC, refL_calC);
    auto is_L = _lc.Set<lc::ESet::SOFT_L>(refC_calL, refL_calL);
    if ( is_C )
    {
        emit signal_show_calC( refC_calC, refL_calC );
    }

    if ( is_L )
    {
        emit signal_show_calC( refC_calL, refL_calL );
    }

    if ( !is_C && !is_L )
    {
        emit signal_CalibrationRequired();
        _needCalibration = true;
    }
  }

  inline void GetSettings( void ) {
    report_t g;
    g.id = 3;

    int result = ::hid_get_feature_report(_device, (unsigned char*) &g, sizeof(g));
    if(result == -1)
    {
        _hid_ProcessError();
        return;
    }
    ::memcpy(settings, g.data, sizeof(settings));
    qDebug() << "GetSettings" << _original_ReadIntValueFromBytes(&settings[1], &settings[2]);
  }

  inline void SendSettings( void ) {
    Sleeper::sleep(5);

    report_t g;
    g.id = 3;

    ::memcpy(g.data, settings, sizeof(settings));
    qDebug() << "SendSettings" << _original_ReadIntValueFromBytes(&g.data[1], &g.data[2]);
    int result = ::hid_send_feature_report(_device, (unsigned char*)&g, sizeof(g));
    if(result == -1)
    {

        _hid_ProcessError();
        return;
    }

  }



  struct C {
  };

  struct L {
  };



  inline void SetSettings( C, bool avg ) {
    auto refC_calC = _lc.Get_refC_calC();
    auto refL_calC = _lc.Get_refL_calC();
    qDebug() << "SetSettings" << avg;
    if (avg) {
        auto refC_calC_avg = _original_ReadIntValueFromBytes(&settings[1], &settings[2]);
        auto refL_calC_avg = _original_ReadIntValueFromBytes(&settings[3], &settings[4], &settings[5]);
        auto N = _original_ReadIntValueFromBytes(&settings[6], &settings[7]);
        refC_calC_avg = (refC_calC_avg * N + refC_calC) / ( N - 1 );
        refL_calC_avg = (refL_calC_avg * N + refL_calC) / ( N - 1 );
        N++;
        _original_WriteIntValueToBytes( refC_calC_avg, settings[1], settings[2] );
        _original_WriteIntValueToBytes( refL_calC_avg, settings[3], settings[4], settings[5] );
        _original_WriteIntValueToBytes( N, settings[6], settings[7] );
      }
    else {
      uint32_t N{1u};
      _original_WriteIntValueToBytes(refC_calC, settings[1], settings[2] );
      _original_WriteIntValueToBytes(refL_calC, settings[3], settings[4], settings[5] );
      _original_WriteIntValueToBytes(N, settings[6], settings[7] );
    }
  }

  inline void SetSettings( L, bool avg ) {
    auto refC_calL = _lc.Get_refC_calL();
    auto refL_calL = _lc.Get_refL_calL();
    if (avg) {
        auto refC_calC_avg = _original_ReadIntValueFromBytes(&settings[8], &settings[9]);
        auto refL_calC_avg = _original_ReadIntValueFromBytes(&settings[10], &settings[11], &settings[12]);
        auto N = _original_ReadIntValueFromBytes(&settings[13], &settings[14]);
        refC_calC_avg = (refC_calC_avg * N + refC_calL) / ( N - 1 );
        refL_calC_avg = (refL_calC_avg * N + refL_calL) / ( N - 1 );
        N++;
        _original_WriteIntValueToBytes( refC_calC_avg, settings[8], settings[9] );
        _original_WriteIntValueToBytes( refL_calC_avg, settings[10], settings[11], settings[12] );
        _original_WriteIntValueToBytes( N, settings[13], settings[14] );
      }
    else {
      uint32_t N{1u};
      _original_WriteIntValueToBytes(refC_calL, settings[8], settings[9] );
      _original_WriteIntValueToBytes(refL_calL, settings[10], settings[11], settings[12] );
      _original_WriteIntValueToBytes(N, settings[13], settings[14] );
    }
  }


  template<typename T>
  inline void _hid_SendCalibration( bool b )
  {
    if(!_device)
      return;
    GetSettings();
    SetSettings(T{},b);
    SendSettings();
  }



  void _hid_ReadData();


  template<typename A, typename B, typename C>
  inline unsigned int _original_ReadIntValueFromBytes(A a, B b, C c)
  {
    unsigned int result=0;
    result = (*(a)<<16)|(*(b)<<8)|*(c);
    //if (result>>23==1) result |= 0xFF<<24;
    return result;
  }

  template<typename A, typename B>
  inline uint16_t _original_ReadIntValueFromBytes(A a, B b)
  {
      uint16_t result = 0;
      result = (*(a) << 8) | *(b);
      return result;
  }

  template<typename V, typename A, typename B, typename C>
  inline bool _original_WriteIntValueToBytes( V value, A & a, B & b, C & c)
  {
    if( 0xffffff < value) return (false);
    a = (value>>16)&0xFFFFFF;
    b = (value>>8)&0xFFFF;
    c = (value)&0xFF;
    return (true);
  }

  template<typename V, typename A, typename B>
  inline bool _original_WriteIntValueToBytes( V value, A & a, B & b)
  {
    if( 0xffff < value) return (false);
    a = (value>>8)&0xFFFF;
    b = (value)&0xFF;
    return (true);
  }


  template<typename A, typename B,typename C>
  inline auto diff(A a, B b, C prefix) {
    QString diff_;
    auto d = a - b;
    if (0 < d)
      diff_ += QString::fromUtf8(" [+");
    else if (d < 0)
      diff_ += QString::fromUtf8(" [-");
    else
      diff_ += QString::fromUtf8(" [");
    diff_ += QString("%1").arg( d ) + prefix + QString::fromUtf8("]");
    return diff_;
  }









  enum
  {
    RELAY_BIT           = (1 << 7),
    PCPROGRAMRUN_BIT    = (1 << 6)
  };

  //минимально допустимая частота (out of range)
  static constexpr frequency_t MINFREQ = 16000;
  hid_device* _device;
  MODE        _mode;

  unsigned char rawdata[3];   // Массив для данных с таймеров (частота)
  unsigned char status;       // Флаги, relay, led, etc...
  unsigned char settings[16]; // Массив для настроек

  lc          _lc;
  bool        _needCalibration;
  bool		_connected;
  QObject * _parent;
  using BufStat_t =  Kernel::System::TRingBuffer<frequency_t>;
  template<size_t N>
  using buf_e_t = Kernel::System::TRingBufferStatistic<frequency_t, N>;


  QTimer*     _timer;
  uint8_t _decimation_counter;

  struct TCalibration {
    TCalibration(void) :
      idle_freq{},
      tolerance{5.0},
      cal{}
    {}
    double idle_freq;
    double tolerance;
    double cal;

  };


  TCalibration _c;

  buf_e_t<512> _ring_buffer;


  template<typename R1,typename R2>
  inline void successfully_calibrated( R1 ref1, R2 ref2) {
    _c.idle_freq = double{};
    _ring_buffer.reset();
    if ( _mode == CALIBRATE_L ) {
        _lc.Set<lc::ESet::HARD_L>(ref1, ref2);
        _mode = CALIBRATE_L_DUMMY;
    }

    if ( _mode == CALIBRATE_C ) {
        _lc.Set<lc::ESet::HARD_C>(ref2, ref1);
        _mode = CALIBRATE_C_DUMMY;
    }
  }

  inline void trigerred_f1(void)
  {
    QString f1;
    f1.setNum(_c.idle_freq, 'G', 8);

    if ( _mode == CALIBRATE_C )
    {
      emit signal_cal_msg_c("F1=" + f1 + "Hz, Please insert calibration C!");
    }

    if ( _mode == CALIBRATE_L )
    {
      emit signal_cal_msg_l("F1=" + f1 + "Hz, Please insert calibration L!");
    }
  }

  template<typename F2>
  inline void trigerred_f2(F2 f2_)
  {
    QString f1;
    f1.setNum(_c.idle_freq, 'G', 8);
    QString f2;
    f2.setNum(f2_, 'G', 8);

    if ( _mode == CALIBRATE_C )
    {
       emit signal_cal_msg_c("F1=" + f1 + "Hz, F2=" + f2 + "Hz");
    }

    if ( _mode == CALIBRATE_L )
    {
       emit signal_cal_msg_l("F1=" + f1 + "Hz, F2=" + f2 + "Hz");
    }

  }

  template<typename F>
  inline void calibrate( F f )
  {
    if ( MINFREQ > _c.idle_freq ) {
        if ( _ring_buffer.full() ) {
            _c.idle_freq = f;
            trigerred_f1();
          }
    } else {
        auto ref1 = floor(_lc.GetRef( _c.idle_freq, f, _c.cal , _c.tolerance ) + 0.5);
        if ( 100.0 < ref1 )
          {
            if ( f < _c.idle_freq )  {
                trigerred_f2(f);
                auto ref2 = floor( _lc.GetLC( _c.idle_freq, ref1 ) + 0.5 );
                _c.idle_freq = double{};
                successfully_calibrated(ref1, ref2);
              } else {
                _c.idle_freq = double{};
              }
          }
      }
  }
};

/*
template<typename T, size_t N>
inline void reset_array(T& a[N]) {
  for (size_t i = 0; i < N; i++)
    a[i] = T{};
}


class TCalBase : public QObject
{
  Q_OBJECT
public:
  template <typename C,typename R>
  TCalBase( C&c, R& rb ) : _calibration{c},_ring_buffer{rb} {}

  virtual void run (void) {}

  void slot_Calibrate(double C,double L, double tolerance)
  {
    _calibration.tolerance = tolerance;
    _calibration.calC = C;
    _calibration.calL = L;
    reset_array( _calibration.ref ) ;
  }
protected:
  Worker::TCalibration& _calibration;
};

class TIdleCapicatanceThreschold : public TCalBase {

  void run( frequency_t f ) override {
    if (MINFREQ > _calibration.idle_freq) {
        emit idle_freq_not_trigerred();
        if ( _freq_stat->full() ) _calibration.idle_freq = f;
      } else {
        next();
      }
  }
};

class TCalibrateCapicatanceMeasurments : public TCalBase {
  void run( frequency_t f ) override {
    emit idle_freq_trigerred();
    auto ref1 = floor( _lc.GetRef( _calibration.idle_freq, f, _calibration.calC , _calibration.tolerance ) + 0.5);
    if ( 10000.0 < ref1 )
      {
        if ( f < _calibration.idle_freq )  {
            auto ref2 = floor(_lc.GetCapacitance( _calibration.idle_freq, 0, ref1 ) + 0.5);
            _calibration.idle_freq = double{};
            _freq_stat->reset();
            _lc.Set_refC_calC( refC );
            _lc.Set_calL_calL( refL );
            next();
            emit signal_ShowRef(refC, refL);
          } else {
            _calibration.idle_freq = double{};
          }
      }
  }
};

class TCalStateMachine {
public:
  void operator++(int) {
    auto f = _ring_buffer.getM();
    if ( _ring_buffer.getD() <= threshold(f) ) state->run(f);
  }

private:
  inline auto threshold( frequency_t freq ) {
    auto t = _calibration.tolerance * freq;
    emit signal_ShowFreqThreschold( t );
    return (t);
  }

  Worker::TCalibration _calibration;
  Worker::buf_e_t<256> _ring_buffer;
};
*/

