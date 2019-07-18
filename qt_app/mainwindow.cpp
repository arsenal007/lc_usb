#include <QString>
#include <QDebug>
#include <QMenu>
#include <QTimer>
#include <QMessageBox>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdio.h>
#include <unistd.h>



MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::MainWindow)
  , _workerThread(new QThread{})
  , _workerObject{new Worker{}}
  , _connectionIconLabel(new QLabel{this})
  , _connectionTextLabel(new QLabel(this))
  , _lockTimer(new QTimer(this))
  , _stopMonitoring{false}
{
  ui->setupUi(this);
  //ui->widgetCalibrationMessage->hide();


  ui->statusBar->addPermanentWidget(_connectionIconLabel);
  ui->statusBar->addPermanentWidget(_connectionTextLabel, 1);

  _lockTimer->setSingleShot(true);
  _lockTimer->start(1000);

  slot_DeviceDisconnected(nullptr);

  _workerObject->moveToThread(_workerThread);
  connect(_workerThread, SIGNAL(finished()), _workerThread, SLOT(deleteLater()));
  connect(_workerThread, SIGNAL(finished()), _workerObject, SLOT(deleteLater()));
  connect(qApp, SIGNAL(aboutToQuit()), _workerThread, SLOT(quit()));
  connect(_workerObject, SIGNAL(signal_C_ValueUpdated(QString)), SLOT(slot_C_ValueUpdated(QString)));
  connect(_workerObject, SIGNAL(signal_L_ValueUpdated(QString)), SLOT(slot_L_ValueUpdated(QString)));
  connect(_workerObject, SIGNAL(signal_F_ValueUpdated(double, double)), SLOT(slot_F_ValueUpdated( double, double )));
  connect(_workerObject, SIGNAL(signal_OutOfRange()), SLOT(slot_OutOfRange()));
  connect(_workerObject, SIGNAL( signal_CalibrationRequired() ), SLOT(slot_CalibrationRequired()));
  connect(_workerObject, SIGNAL( signal_BufferGrowUp( int ) ),  SLOT( slot_BufferGrowUp( int ) ));
  connect(_workerObject, SIGNAL( signal_ShowFreqThreschold( double ) ),  SLOT( slot_ShowFreqThreschold( double ) ));
  connect(_workerObject, SIGNAL( signal_show_calC( unsigned int, unsigned int ) ),  SLOT( slot_show_calC( unsigned int, unsigned int ) ));
  connect(_workerObject, SIGNAL( signal_show_calL( unsigned int, unsigned int ) ),  SLOT( slot_show_calL( unsigned int, unsigned int ) ));
  connect(_workerObject, SIGNAL( signal_calibration_C_finished() ), SLOT( slot_calibration_C_finished( void ) ) );
  connect(_workerObject, SIGNAL( signal_cal_msg_c(QString)), SLOT(slot_cal_msg_c(QString)) );
  connect(_workerObject, SIGNAL( signal_cal_msg_l(QString)), SLOT(slot_cal_msg_l(QString)) );
  connect(this, SIGNAL(signal_ResetCalibration()), _workerObject,  SLOT( slot_ResetCalibration() ));
  connect(ui->pushButton_C_Go, SIGNAL (released()), SLOT(slot_Calibration_C( void )));
  connect(ui->pushButton_C_Save, SIGNAL (released()), SLOT(slot_C_save( void )));
  connect(this, SIGNAL(signal_Calibrate_C( double, double )), _workerObject, SLOT(slot_Calibrate_C( double, double )) );
  connect(this, SIGNAL(signal_Calibrate_L( double, double )), _workerObject, SLOT(slot_Calibrate_L( double, double )) );
  connect(this, SIGNAL(signal_C_save( bool )), _workerObject, SLOT(slot_C_save( bool )) );



  _workerObject->SetParent(this);
  _workerThread->start();
  ui->tabs->setEnabled(true);
}

MainWindow::~MainWindow()
{
  _stopMonitoring = true;
  _workerThread->wait();
  if (_workerObject)  delete _workerObject;
  delete ui;
}




void MainWindow::slot_DeviceConnected()
{
  ui->tabs->insertTab(0, ui->tabC, "Capacitance");
  ui->tabC->setEnabled( true );
  ui->tabs->insertTab(1, ui->tabL, "Inductance");
  ui->tabL->setEnabled( true );
  auto id = ui->tabs->indexOf( ui->tabUSB );
  if ( -1 < id ) ui->tabs->removeTab( id );
  //ui->tabWidget->setCurrentIndex(0);
  _connectionTextLabel->setText(QString::fromUtf8("connected"));
  _connectionIconLabel->setPixmap(QPixmap(":/images/dot_green.png"));
  slot_OutOfRange();
  connect(ui->tabs, SIGNAL(currentChanged(int)), _workerObject, SLOT(slot_setMode(int)));
  connect(ui->tabs, SIGNAL(currentChanged(int)),  SLOT(on_tabWidget_currentChanged(int)));
  //ui->tabWidget->setCurrentIndex(0);
}

void MainWindow::slot_DeviceDisconnected(const hid_device_info * info)
{
  disconnect(ui->tabs, SIGNAL(currentChanged(int)), nullptr, nullptr);

  auto remove_tab = [&tabs = ui->tabs](auto & tab){
      auto id = tabs->indexOf( tab );
      if ( -1 < id ) {
          tab->setEnabled(false);
          tabs->removeTab( id );
        }
  };

  remove_tab( ui->tabC );
  remove_tab( ui->tabL );
  remove_tab( ui->tabCalC );
  remove_tab( ui->tabCalL );
  remove_tab( ui->tabUSB );
  ui->progressBar->setValue(0);
  ui->progressBar->setEnabled( false );

  auto id = ui->tabs->indexOf( ui->tabUSB );
  if ( id < 0 ) {
      ui->tabs->insertTab(0, ui->tabUSB, "HID USB");
      ui->tabUSB->setEnabled( true );
  }
  int i = 0;
  while (info) {
      auto vendor = QString("%1").arg(info->vendor_id, 4, 16, QChar('0')).toUpper().prepend("0x");
      auto product = QString("%1").arg(info->product_id, 4, 16, QChar('0')).toUpper().prepend("0x");
      //auto vendor = QString().number(info->vendor_id, 16);
      //auto product = QString().number(info->vendor_id, 16);

      ui->listWidget->takeItem( i );
      ui->listWidget->insertItem( i, vendor + "::" + product + " [0x16C0 :: 0x05DF]");
      i++;
      info = info->next;
    };

  //ui->tabWidget->setCurrentIndex(id);
  _connectionTextLabel->setText(QString::fromUtf8("not connected"));
  _connectionIconLabel->setPixmap(QPixmap(":/images/dot_red.png"));
  slot_OutOfRange();
}


void MainWindow::slot_cal_msg_c( QString  str ) {
     ui->label_C_msg->setText( str );
}

void MainWindow::slot_cal_msg_l( QString  str ) {
     ui->label_L_msg->setText( str );
}

void MainWindow::slot_show_calC( unsigned int refC, unsigned int refL ) {
  auto L = QString("%1").arg( refL );
  auto C = QString("%1").arg( refC );
  ui->label_C_msg->setText( "<font color='Black'>refC = " + C + "pF, refL = " + L + "nH </font>" );
}

void MainWindow::slot_calibration_C_finished( void ) {
  ui->lineEdit_C_T->setEnabled(true);
  ui->lineEdit_C->setEnabled(true);
  ui->pushButton_C_Go->setEnabled(true);
  //ui->pushButton_C_Save->setEnabled(true);
  //ui->checkBoxAvg_C->setEnabled(true);
}

void MainWindow::slot_show_calL( unsigned int refC, unsigned int refL ) {
  auto L = QString("%1").arg( refL );
  auto C = QString("%1").arg( refC );
  ui->label_L_msg->setText( "<font color='Black'>refC = " + C + "pF, refL = " + L + "nH </font>" );
}


void MainWindow::slot_CalibrationRequired( void )
{
  QMessageBox::warning(this, QString::fromUtf8("device is not calibrated"), QString::fromUtf8("Прибор не калиброван! Необходимо провести калибровку!"));
}

void MainWindow::slot_L_ValueUpdated( QString L )
{
  if ( _lockTimer->isActive() )
    return;
  ui->label_L->setText("<font color='Black'>L = " + L + "</font>");
}

void MainWindow::slot_C_ValueUpdated( QString C )
{
  if(_lockTimer->isActive())
    return;
  ui->label_C->setText("<font color='Black'>C = " + C + "</font>");
}

void MainWindow::slot_F_ValueUpdated( double F, double D )
{
  if(_lockTimer->isActive())
    return;
  QString f;
  f.setNum( F, 'G', 8 );
  ui->label_F->setText("<font color='Black'>F = " + f + "Hz</font>");
  QString d;
  d.setNum( D, 'G', 8 );
  ui->label_D->setText("<font color='Black'>standart deviation = " + d + "Hz</font>");
}

void MainWindow::slot_OutOfRange()
{
  slot_C_ValueUpdated("");
  slot_L_ValueUpdated("");
}

void MainWindow::on_tabWidget_currentChanged(int index)
{
  slot_OutOfRange();
  _lockTimer->stop();
  _lockTimer->start(1000);
  if ( ui->tabs->indexOf( ui->tabCalC ) == index )
  {
      ui->label_C_msg->setText("");
      ui->lineEdit_C_T->setEnabled( true );
      ui->lineEdit_C->setEnabled( true );
      ui->lineEdit_L->setEnabled( true );
      ui->pushButton_C_Go->setEnabled( true );
      ui->pushButton_C_Save->setEnabled( true );
      emit signal_ResetCalibration();
  } else {
      ui->label_threschold->setText("");
  }
}


void MainWindow::slot_Calibration_C( void ) {
  auto tolerance=ui->lineEdit_C_T->text().toDouble();
  auto C = ui->lineEdit_C->text().toDouble();
  //auto L = ui->lineEdit_L->text().toDouble();
  if (C < 60.0) {
      ui->label_C_msg->setText(QString::fromUtf8("Please write correct calibration C"));
      return;
    }
  ui->lineEdit_C_T->setEnabled(false);
  ui->lineEdit_C->setEnabled(false);
  ui->pushButton_C_Go->setEnabled(false);
  //ui->pushButton_C_Save->setEnabled(false);
  //ui->checkBoxAvg_C->setEnabled(false);
  tolerance/=100.0;
  tolerance = tolerance < pow(10,-9) ? pow(10,-9) : tolerance;
  emit signal_Calibrate_C( C, tolerance );
}




void MainWindow::slot_ShowFreqThreschold( double threschold) {
  QString s;
  s.setNum( threschold, 'G', 4 );
  ui->label_threschold->setText("<font color='Black'> threschold = " + s + "Hz</font>");
}


void MainWindow::slot_BufferGrowUp( int i)
{
  i++;
  ui->progressBar->setValue(i);
}

void MainWindow::slot_C_save( void ) {
  emit signal_C_save( ui->checkBoxAvg_C->isChecked() );
}

/*
void MainWindow::on_radioButton100_clicked()
{
    ui->progressBar->setRange( 0, 100 );
    ui->progressBar->setValue(0);
    emit signal_buff_100();
}

void MainWindow::on_radioButton1000_clicked()
{
    ui->progressBar->setRange( 0, 1000 );
    ui->progressBar->setValue(0);
    emit signal_buff_1000();
}

void MainWindow::on_radioButton10000_clicked()
{
    ui->progressBar->setRange( 0, 10000 );
    ui->progressBar->setValue(0);
    emit signal_buff_10000();
}*/
