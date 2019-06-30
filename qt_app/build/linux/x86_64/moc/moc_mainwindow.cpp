/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      21,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      14,   12,   11,   11, 0x05,
      48,   12,   11,   11, 0x05,
      82,   11,   11,   11, 0x05,
     102,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
     128,   11,   11,   11, 0x0a,
     156,  151,   11,   11, 0x0a,
     204,   11,   11,   11, 0x0a,
     231,   11,   11,   11, 0x0a,
     260,   11,   11,   11, 0x0a,
     289,   12,   11,   11, 0x0a,
     324,   11,   11,   11, 0x0a,
     342,   11,   11,   11, 0x0a,
     363,   11,   11,   11, 0x0a,
     387,   11,   11,   11, 0x0a,
     411,   11,   11,   11, 0x0a,
     434,   11,   11,   11, 0x0a,
     466,   12,   11,   11, 0x0a,
     492,   12,   11,   11, 0x0a,
     518,   11,   11,   11, 0x0a,
     548,   11,   11,   11, 0x0a,
     562,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0,\0signal_Calibrate_C(double,double)\0"
    "signal_Calibrate_L(double,double)\0"
    "signal_C_save(bool)\0signal_ResetCalibration()\0"
    "slot_DeviceConnected()\0info\0"
    "slot_DeviceDisconnected(const hid_device_info*)\0"
    "slot_CalibrationRequired()\0"
    "slot_L_ValueUpdated(QString)\0"
    "slot_C_ValueUpdated(QString)\0"
    "slot_F_ValueUpdated(double,double)\0"
    "slot_OutOfRange()\0slot_Calibration_C()\0"
    "slot_cal_msg_c(QString)\0slot_cal_msg_l(QString)\0"
    "slot_BufferGrowUp(int)\0"
    "slot_ShowFreqThreschold(double)\0"
    "slot_show_calC(uint,uint)\0"
    "slot_show_calL(uint,uint)\0"
    "slot_calibration_C_finished()\0"
    "slot_C_save()\0on_tabWidget_currentChanged(int)\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->signal_Calibrate_C((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 1: _t->signal_Calibrate_L((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 2: _t->signal_C_save((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->signal_ResetCalibration(); break;
        case 4: _t->slot_DeviceConnected(); break;
        case 5: _t->slot_DeviceDisconnected((*reinterpret_cast< const hid_device_info*(*)>(_a[1]))); break;
        case 6: _t->slot_CalibrationRequired(); break;
        case 7: _t->slot_L_ValueUpdated((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->slot_C_ValueUpdated((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->slot_F_ValueUpdated((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 10: _t->slot_OutOfRange(); break;
        case 11: _t->slot_Calibration_C(); break;
        case 12: _t->slot_cal_msg_c((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 13: _t->slot_cal_msg_l((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 14: _t->slot_BufferGrowUp((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->slot_ShowFreqThreschold((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 16: _t->slot_show_calC((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2]))); break;
        case 17: _t->slot_show_calL((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2]))); break;
        case 18: _t->slot_calibration_C_finished(); break;
        case 19: _t->slot_C_save(); break;
        case 20: _t->on_tabWidget_currentChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
void MainWindow::signal_Calibrate_C(double _t1, double _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::signal_Calibrate_L(double _t1, double _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MainWindow::signal_C_save(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MainWindow::signal_ResetCalibration()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}
QT_END_MOC_NAMESPACE
