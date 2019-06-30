#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QThread>
#include <worker.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

signals:
    void signal_Calibrate_C( double, double );
    void signal_Calibrate_L( double, double );
    void signal_C_save( bool );
    void signal_ResetCalibration( void );

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    static void*    _SMonitorThreadFunc(void* arg);
           void*    _monitorThreadFunc();

public slots:
    void slot_DeviceConnected();    
    void slot_DeviceDisconnected( const hid_device_info * info);
    void slot_CalibrationRequired();
    void slot_L_ValueUpdated(QString);
    void slot_C_ValueUpdated(QString);
    void slot_F_ValueUpdated(double, double );
    void slot_OutOfRange();
    void slot_Calibration_C( void );
    void slot_cal_msg_c( QString );
    void slot_cal_msg_l( QString );
    void slot_BufferGrowUp( int );
    void slot_ShowFreqThreschold( double );
    void slot_show_calC( unsigned int, unsigned int );
    void slot_show_calL( unsigned int, unsigned int );
    void slot_calibration_C_finished( void );
    void slot_C_save( void );



private slots:
    void on_tabWidget_currentChanged(int);
/*  void on_radioButton100_clicked();
    void on_radioButton1000_clicked();
    void on_radioButton10000_clicked();*/

private:
    Ui::MainWindow *ui;
    QThread*        _workerThread;
    Worker*         _workerObject;
    QLabel*         _connectionIconLabel;
    QLabel*         _connectionTextLabel;
    QTimer*         _lockTimer;
    bool            _stopMonitoring;
    std::string     _devicePath;
    QMenu*          _menu;
    QAction*        _act0;
    QAction*        _act1;
};

#endif // MAINWINDOW_H
