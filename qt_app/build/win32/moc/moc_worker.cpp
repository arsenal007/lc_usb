/****************************************************************************
** Meta object code from reading C++ file 'worker.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../worker.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'worker.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Worker_t {
    QByteArrayData data[25];
    char stringdata0[462];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Worker_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Worker_t qt_meta_stringdata_Worker = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Worker"
QT_MOC_LITERAL(1, 7, 26), // "signal_CalibrationRequired"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 25), // "signal_CalibrationMessage"
QT_MOC_LITERAL(4, 61, 7), // "message"
QT_MOC_LITERAL(5, 69, 21), // "signal_L_ValueUpdated"
QT_MOC_LITERAL(6, 91, 21), // "signal_C_ValueUpdated"
QT_MOC_LITERAL(7, 113, 21), // "signal_F_ValueUpdated"
QT_MOC_LITERAL(8, 135, 17), // "signal_OutOfRange"
QT_MOC_LITERAL(9, 153, 22), // "signal_DeviceConnected"
QT_MOC_LITERAL(10, 176, 25), // "signal_DeviceDisconnected"
QT_MOC_LITERAL(11, 202, 22), // "const hid_device_info*"
QT_MOC_LITERAL(12, 225, 16), // "signal_cal_msg_c"
QT_MOC_LITERAL(13, 242, 16), // "signal_cal_msg_l"
QT_MOC_LITERAL(14, 259, 19), // "signal_BufferGrowUp"
QT_MOC_LITERAL(15, 279, 25), // "signal_ShowFreqThreschold"
QT_MOC_LITERAL(16, 305, 16), // "signal_show_calC"
QT_MOC_LITERAL(17, 322, 16), // "signal_show_calL"
QT_MOC_LITERAL(18, 339, 29), // "signal_calibration_C_finished"
QT_MOC_LITERAL(19, 369, 12), // "slot_setMode"
QT_MOC_LITERAL(20, 382, 11), // "slot_update"
QT_MOC_LITERAL(21, 394, 16), // "slot_Calibrate_C"
QT_MOC_LITERAL(22, 411, 16), // "slot_Calibrate_L"
QT_MOC_LITERAL(23, 428, 11), // "slot_C_save"
QT_MOC_LITERAL(24, 440, 21) // "slot_ResetCalibration"

    },
    "Worker\0signal_CalibrationRequired\0\0"
    "signal_CalibrationMessage\0message\0"
    "signal_L_ValueUpdated\0signal_C_ValueUpdated\0"
    "signal_F_ValueUpdated\0signal_OutOfRange\0"
    "signal_DeviceConnected\0signal_DeviceDisconnected\0"
    "const hid_device_info*\0signal_cal_msg_c\0"
    "signal_cal_msg_l\0signal_BufferGrowUp\0"
    "signal_ShowFreqThreschold\0signal_show_calC\0"
    "signal_show_calL\0signal_calibration_C_finished\0"
    "slot_setMode\0slot_update\0slot_Calibrate_C\0"
    "slot_Calibrate_L\0slot_C_save\0"
    "slot_ResetCalibration"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Worker[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      21,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      15,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  119,    2, 0x06 /* Public */,
       3,    1,  120,    2, 0x06 /* Public */,
       5,    1,  123,    2, 0x06 /* Public */,
       6,    1,  126,    2, 0x06 /* Public */,
       7,    2,  129,    2, 0x06 /* Public */,
       8,    0,  134,    2, 0x06 /* Public */,
       9,    0,  135,    2, 0x06 /* Public */,
      10,    1,  136,    2, 0x06 /* Public */,
      12,    1,  139,    2, 0x06 /* Public */,
      13,    1,  142,    2, 0x06 /* Public */,
      14,    1,  145,    2, 0x06 /* Public */,
      15,    1,  148,    2, 0x06 /* Public */,
      16,    2,  151,    2, 0x06 /* Public */,
      17,    2,  156,    2, 0x06 /* Public */,
      18,    0,  161,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      19,    1,  162,    2, 0x0a /* Public */,
      20,    0,  165,    2, 0x0a /* Public */,
      21,    2,  166,    2, 0x0a /* Public */,
      22,    2,  171,    2, 0x0a /* Public */,
      23,    1,  176,    2, 0x0a /* Public */,
      24,    0,  179,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Double, QMetaType::Double,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::UInt, QMetaType::UInt,    2,    2,
    QMetaType::Void, QMetaType::UInt, QMetaType::UInt,    2,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double, QMetaType::Double,    2,    2,
    QMetaType::Void, QMetaType::Double, QMetaType::Double,    2,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,

       0        // eod
};

void Worker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Worker *>(_o);
        Q_UNUSED(_t)
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
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Worker::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Worker::signal_CalibrationRequired)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Worker::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Worker::signal_CalibrationMessage)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Worker::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Worker::signal_L_ValueUpdated)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Worker::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Worker::signal_C_ValueUpdated)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Worker::*)(double , double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Worker::signal_F_ValueUpdated)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Worker::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Worker::signal_OutOfRange)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (Worker::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Worker::signal_DeviceConnected)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (Worker::*)(const hid_device_info * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Worker::signal_DeviceDisconnected)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (Worker::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Worker::signal_cal_msg_c)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (Worker::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Worker::signal_cal_msg_l)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (Worker::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Worker::signal_BufferGrowUp)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (Worker::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Worker::signal_ShowFreqThreschold)) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (Worker::*)(unsigned int , unsigned int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Worker::signal_show_calC)) {
                *result = 12;
                return;
            }
        }
        {
            using _t = void (Worker::*)(unsigned int , unsigned int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Worker::signal_show_calL)) {
                *result = 13;
                return;
            }
        }
        {
            using _t = void (Worker::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Worker::signal_calibration_C_finished)) {
                *result = 14;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Worker::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_Worker.data,
    qt_meta_data_Worker,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Worker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Worker::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Worker.stringdata0))
        return static_cast<void*>(this);
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
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 21)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 21;
    }
    return _id;
}

// SIGNAL 0
void Worker::signal_CalibrationRequired()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Worker::signal_CalibrationMessage(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Worker::signal_L_ValueUpdated(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Worker::signal_C_ValueUpdated(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Worker::signal_F_ValueUpdated(double _t1, double _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Worker::signal_OutOfRange()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void Worker::signal_DeviceConnected()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void Worker::signal_DeviceDisconnected(const hid_device_info * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void Worker::signal_cal_msg_c(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void Worker::signal_cal_msg_l(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void Worker::signal_BufferGrowUp(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void Worker::signal_ShowFreqThreschold(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void Worker::signal_show_calC(unsigned int _t1, unsigned int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void Worker::signal_show_calL(unsigned int _t1, unsigned int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void Worker::signal_calibration_C_finished()
{
    QMetaObject::activate(this, &staticMetaObject, 14, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
