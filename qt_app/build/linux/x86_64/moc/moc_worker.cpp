/****************************************************************************
** Meta object code from reading C++ file 'worker.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../worker.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'worker.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Worker[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      21,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      15,       // signalCount

 // signals: signature, parameters, type, tag, flags
       8,    7,    7,    7, 0x05,
      45,   37,    7,    7, 0x05,
      80,    7,    7,    7, 0x05,
     111,    7,    7,    7, 0x05,
     144,  142,    7,    7, 0x05,
     181,    7,    7,    7, 0x05,
     201,    7,    7,    7, 0x05,
     226,    7,    7,    7, 0x05,
     276,    7,    7,    7, 0x05,
     302,    7,    7,    7, 0x05,
     328,    7,    7,    7, 0x05,
     353,    7,    7,    7, 0x05,
     387,  142,    7,    7, 0x05,
     415,  142,    7,    7, 0x05,
     443,    7,    7,    7, 0x05,

 // slots: signature, parameters, type, tag, flags
     475,    7,    7,    7, 0x0a,
     493,    7,    7,    7, 0x0a,
     507,  142,    7,    7, 0x0a,
     539,  142,    7,    7, 0x0a,
     571,    7,    7,    7, 0x0a,
     589,    7,    7,    7, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Worker[] = {
    "Worker\0\0signal_CalibrationRequired()\0"
    "message\0signal_CalibrationMessage(QString)\0"
    "signal_L_ValueUpdated(QString)\0"
    "signal_C_ValueUpdated(QString)\0,\0"
    "signal_F_ValueUpdated(double,double)\0"
    "signal_OutOfRange()\0signal_DeviceConnected()\0"
    "signal_DeviceDisconnected(const hid_device_info*)\0"
    "signal_cal_msg_c(QString)\0"
    "signal_cal_msg_l(QString)\0"
    "signal_BufferGrowUp(int)\0"
    "signal_ShowFreqThreschold(double)\0"
    "signal_show_calC(uint,uint)\0"
    "signal_show_calL(uint,uint)\0"
    "signal_calibration_C_finished()\0"
    "slot_setMode(int)\0slot_update()\0"
    "slot_Calibrate_C(double,double)\0"
    "slot_Calibrate_L(double,double)\0"
    "slot_C_save(bool)\0slot_ResetCalibration()\0"
};

void Worker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Worker *_t = static_cast<Worker *>(_o);
        switch (_id) {
        case 0: _t->signal_CalibrationRequired(); break;
        case 1: _t->signal_CalibrationMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->signal_L_ValueUpdated((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->signal_C_ValueUpdated((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->signal_F_ValueUpdated((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 5: _t->signal_OutOfRange(); break;
        case 6: _t->signal_DeviceConnected(); break;
        case 7: _t->signal_DeviceDisconnected((*reinterpret_cast< const hid_device_info*(*)>(_a[1]))); break;
        case 8: _t->signal_cal_msg_c((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->signal_cal_msg_l((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->signal_BufferGrowUp((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->signal_ShowFreqThreschold((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 12: _t->signal_show_calC((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2]))); break;
        case 13: _t->signal_show_calL((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2]))); break;
        case 14: _t->signal_calibration_C_finished(); break;
        case 15: _t->slot_setMode((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->slot_update(); break;
        case 17: _t->slot_Calibrate_C((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 18: _t->slot_Calibrate_L((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 19: _t->slot_C_save((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 20: _t->slot_ResetCalibration(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Worker::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Worker::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Worker,
      qt_meta_data_Worker, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Worker::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Worker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Worker::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Worker))
        return static_cast<void*>(const_cast< Worker*>(this));
    return QObject::qt_metacast(_clname);
}

int Worker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 21)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 21;
    }
    return _id;
}

// SIGNAL 0
void Worker::signal_CalibrationRequired()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void Worker::signal_CalibrationMessage(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Worker::signal_L_ValueUpdated(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Worker::signal_C_ValueUpdated(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Worker::signal_F_ValueUpdated(double _t1, double _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Worker::signal_OutOfRange()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}

// SIGNAL 6
void Worker::signal_DeviceConnected()
{
    QMetaObject::activate(this, &staticMetaObject, 6, 0);
}

// SIGNAL 7
void Worker::signal_DeviceDisconnected(const hid_device_info * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void Worker::signal_cal_msg_c(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void Worker::signal_cal_msg_l(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void Worker::signal_BufferGrowUp(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void Worker::signal_ShowFreqThreschold(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void Worker::signal_show_calC(unsigned int _t1, unsigned int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void Worker::signal_show_calL(unsigned int _t1, unsigned int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void Worker::signal_calibration_C_finished()
{
    QMetaObject::activate(this, &staticMetaObject, 14, 0);
}
QT_END_MOC_NAMESPACE
