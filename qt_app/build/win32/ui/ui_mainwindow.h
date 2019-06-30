/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionCalibrate;
    QAction *actionConnectionState;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QTabWidget *tabs;
    QWidget *tabC;
    QHBoxLayout *hboxLayout;
    QGridLayout *LayoutC;
    QLabel *label_C;
    QWidget *tabL;
    QHBoxLayout *_2;
    QGridLayout *LayoutL;
    QLabel *label_L;
    QWidget *tabUSB;
    QHBoxLayout *horizontalLayout_2;
    QListWidget *listWidget;
    QWidget *tabCalC;
    QHBoxLayout *horizontalLayout_3;
    QWidget *widgetCalibrationParams;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_C;
    QLabel *label_C_msg;
    QLabel *label_cal_C;
    QLabel *label_P_C;
    QLabel *label_pF;
    QLineEdit *lineEdit_C_T;
    QLabel *label_SDT_C;
    QCheckBox *checkBoxAvg_C;
    QPushButton *pushButton_C_Save;
    QPushButton *pushButton_C_Go;
    QWidget *tabCalL;
    QHBoxLayout *horizontalLayout;
    QWidget *widgetCalibrationCParams;
    QGridLayout *gridLayout_2;
    QLineEdit *lineEdit_L_T;
    QLineEdit *lineEdit_L;
    QLabel *label_P_L;
    QLabel *label_SDT_L;
    QLabel *label_nH;
    QLabel *label_cal_L;
    QCheckBox *checkBoxAvg_L;
    QLabel *label_L_msg;
    QPushButton *pushButton_L_Go;
    QPushButton *pushButton_L_Save;
    QGridLayout *gridLayout_4;
    QLabel *label_D;
    QLabel *label_F;
    QProgressBar *progressBar;
    QLabel *label_threschold;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setWindowModality(Qt::WindowModal);
        MainWindow->resize(639, 280);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/icon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionCalibrate = new QAction(MainWindow);
        actionCalibrate->setObjectName(QString::fromUtf8("actionCalibrate"));
        actionConnectionState = new QAction(MainWindow);
        actionConnectionState->setObjectName(QString::fromUtf8("actionConnectionState"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/dot_red.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionConnectionState->setIcon(icon1);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setLayoutDirection(Qt::LeftToRight);
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(-1, -1, -1, 0);
        tabs = new QTabWidget(centralWidget);
        tabs->setObjectName(QString::fromUtf8("tabs"));
        tabs->setEnabled(false);
        QFont font;
        font.setFamily(QString::fromUtf8("Times New Roman"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        tabs->setFont(font);
        tabC = new QWidget();
        tabC->setObjectName(QString::fromUtf8("tabC"));
        hboxLayout = new QHBoxLayout(tabC);
        hboxLayout->setSpacing(0);
        hboxLayout->setContentsMargins(11, 11, 11, 11);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        LayoutC = new QGridLayout();
        LayoutC->setSpacing(6);
        LayoutC->setObjectName(QString::fromUtf8("LayoutC"));
        label_C = new QLabel(tabC);
        label_C->setObjectName(QString::fromUtf8("label_C"));
        label_C->setEnabled(false);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_C->sizePolicy().hasHeightForWidth());
        label_C->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setFamily(QString::fromUtf8("Times New Roman"));
        font1.setPointSize(48);
        font1.setBold(true);
        font1.setWeight(75);
        label_C->setFont(font1);

        LayoutC->addWidget(label_C, 1, 0, 1, 1);


        hboxLayout->addLayout(LayoutC);

        tabs->addTab(tabC, QString());
        tabL = new QWidget();
        tabL->setObjectName(QString::fromUtf8("tabL"));
        _2 = new QHBoxLayout(tabL);
        _2->setSpacing(0);
        _2->setContentsMargins(11, 11, 11, 11);
        _2->setObjectName(QString::fromUtf8("_2"));
        _2->setContentsMargins(0, 0, 0, 0);
        LayoutL = new QGridLayout();
        LayoutL->setSpacing(6);
        LayoutL->setObjectName(QString::fromUtf8("LayoutL"));
        label_L = new QLabel(tabL);
        label_L->setObjectName(QString::fromUtf8("label_L"));
        label_L->setFont(font1);

        LayoutL->addWidget(label_L, 0, 0, 1, 1);


        _2->addLayout(LayoutL);

        tabs->addTab(tabL, QString());
        tabUSB = new QWidget();
        tabUSB->setObjectName(QString::fromUtf8("tabUSB"));
        horizontalLayout_2 = new QHBoxLayout(tabUSB);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        listWidget = new QListWidget(tabUSB);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        horizontalLayout_2->addWidget(listWidget);

        tabs->addTab(tabUSB, QString());
        tabCalC = new QWidget();
        tabCalC->setObjectName(QString::fromUtf8("tabCalC"));
        horizontalLayout_3 = new QHBoxLayout(tabCalC);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        widgetCalibrationParams = new QWidget(tabCalC);
        widgetCalibrationParams->setObjectName(QString::fromUtf8("widgetCalibrationParams"));
        gridLayout = new QGridLayout(widgetCalibrationParams);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit_C = new QLineEdit(widgetCalibrationParams);
        lineEdit_C->setObjectName(QString::fromUtf8("lineEdit_C"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEdit_C->sizePolicy().hasHeightForWidth());
        lineEdit_C->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(lineEdit_C, 1, 1, 1, 1);

        label_C_msg = new QLabel(widgetCalibrationParams);
        label_C_msg->setObjectName(QString::fromUtf8("label_C_msg"));
        sizePolicy1.setHeightForWidth(label_C_msg->sizePolicy().hasHeightForWidth());
        label_C_msg->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(label_C_msg, 4, 0, 1, 3);

        label_cal_C = new QLabel(widgetCalibrationParams);
        label_cal_C->setObjectName(QString::fromUtf8("label_cal_C"));
        label_cal_C->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_cal_C, 1, 0, 1, 1);

        label_P_C = new QLabel(widgetCalibrationParams);
        label_P_C->setObjectName(QString::fromUtf8("label_P_C"));
        label_P_C->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_P_C, 0, 2, 1, 1);

        label_pF = new QLabel(widgetCalibrationParams);
        label_pF->setObjectName(QString::fromUtf8("label_pF"));

        gridLayout->addWidget(label_pF, 1, 2, 1, 1);

        lineEdit_C_T = new QLineEdit(widgetCalibrationParams);
        lineEdit_C_T->setObjectName(QString::fromUtf8("lineEdit_C_T"));
        sizePolicy1.setHeightForWidth(lineEdit_C_T->sizePolicy().hasHeightForWidth());
        lineEdit_C_T->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(lineEdit_C_T, 0, 1, 1, 1);

        label_SDT_C = new QLabel(widgetCalibrationParams);
        label_SDT_C->setObjectName(QString::fromUtf8("label_SDT_C"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_SDT_C->sizePolicy().hasHeightForWidth());
        label_SDT_C->setSizePolicy(sizePolicy2);
        label_SDT_C->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_SDT_C, 0, 0, 1, 1);

        checkBoxAvg_C = new QCheckBox(widgetCalibrationParams);
        checkBoxAvg_C->setObjectName(QString::fromUtf8("checkBoxAvg_C"));
        sizePolicy1.setHeightForWidth(checkBoxAvg_C->sizePolicy().hasHeightForWidth());
        checkBoxAvg_C->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(checkBoxAvg_C, 5, 0, 1, 1);

        pushButton_C_Save = new QPushButton(widgetCalibrationParams);
        pushButton_C_Save->setObjectName(QString::fromUtf8("pushButton_C_Save"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(pushButton_C_Save->sizePolicy().hasHeightForWidth());
        pushButton_C_Save->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(pushButton_C_Save, 5, 1, 1, 1);


        horizontalLayout_3->addWidget(widgetCalibrationParams);

        pushButton_C_Go = new QPushButton(tabCalC);
        pushButton_C_Go->setObjectName(QString::fromUtf8("pushButton_C_Go"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Minimum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(pushButton_C_Go->sizePolicy().hasHeightForWidth());
        pushButton_C_Go->setSizePolicy(sizePolicy4);
        QFont font2;
        font2.setFamily(QString::fromUtf8("Times New Roman"));
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        pushButton_C_Go->setFont(font2);

        horizontalLayout_3->addWidget(pushButton_C_Go);

        tabs->addTab(tabCalC, QString());
        tabCalL = new QWidget();
        tabCalL->setObjectName(QString::fromUtf8("tabCalL"));
        horizontalLayout = new QHBoxLayout(tabCalL);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        widgetCalibrationCParams = new QWidget(tabCalL);
        widgetCalibrationCParams->setObjectName(QString::fromUtf8("widgetCalibrationCParams"));
        gridLayout_2 = new QGridLayout(widgetCalibrationCParams);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        lineEdit_L_T = new QLineEdit(widgetCalibrationCParams);
        lineEdit_L_T->setObjectName(QString::fromUtf8("lineEdit_L_T"));
        sizePolicy1.setHeightForWidth(lineEdit_L_T->sizePolicy().hasHeightForWidth());
        lineEdit_L_T->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(lineEdit_L_T, 0, 1, 1, 1);

        lineEdit_L = new QLineEdit(widgetCalibrationCParams);
        lineEdit_L->setObjectName(QString::fromUtf8("lineEdit_L"));
        sizePolicy1.setHeightForWidth(lineEdit_L->sizePolicy().hasHeightForWidth());
        lineEdit_L->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(lineEdit_L, 1, 1, 1, 1);

        label_P_L = new QLabel(widgetCalibrationCParams);
        label_P_L->setObjectName(QString::fromUtf8("label_P_L"));
        label_P_L->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_P_L, 0, 2, 1, 1);

        label_SDT_L = new QLabel(widgetCalibrationCParams);
        label_SDT_L->setObjectName(QString::fromUtf8("label_SDT_L"));
        sizePolicy2.setHeightForWidth(label_SDT_L->sizePolicy().hasHeightForWidth());
        label_SDT_L->setSizePolicy(sizePolicy2);
        label_SDT_L->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_SDT_L, 0, 0, 1, 1);

        label_nH = new QLabel(widgetCalibrationCParams);
        label_nH->setObjectName(QString::fromUtf8("label_nH"));
        sizePolicy.setHeightForWidth(label_nH->sizePolicy().hasHeightForWidth());
        label_nH->setSizePolicy(sizePolicy);
        label_nH->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_nH, 1, 2, 1, 1);

        label_cal_L = new QLabel(widgetCalibrationCParams);
        label_cal_L->setObjectName(QString::fromUtf8("label_cal_L"));
        sizePolicy1.setHeightForWidth(label_cal_L->sizePolicy().hasHeightForWidth());
        label_cal_L->setSizePolicy(sizePolicy1);
        label_cal_L->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_cal_L, 1, 0, 1, 1);

        checkBoxAvg_L = new QCheckBox(widgetCalibrationCParams);
        checkBoxAvg_L->setObjectName(QString::fromUtf8("checkBoxAvg_L"));
        sizePolicy1.setHeightForWidth(checkBoxAvg_L->sizePolicy().hasHeightForWidth());
        checkBoxAvg_L->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(checkBoxAvg_L, 3, 0, 1, 3);

        label_L_msg = new QLabel(widgetCalibrationCParams);
        label_L_msg->setObjectName(QString::fromUtf8("label_L_msg"));
        sizePolicy1.setHeightForWidth(label_L_msg->sizePolicy().hasHeightForWidth());
        label_L_msg->setSizePolicy(sizePolicy1);
        label_L_msg->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_L_msg, 2, 0, 1, 3);


        horizontalLayout->addWidget(widgetCalibrationCParams);

        pushButton_L_Go = new QPushButton(tabCalL);
        pushButton_L_Go->setObjectName(QString::fromUtf8("pushButton_L_Go"));
        QSizePolicy sizePolicy5(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(pushButton_L_Go->sizePolicy().hasHeightForWidth());
        pushButton_L_Go->setSizePolicy(sizePolicy5);
        pushButton_L_Go->setFont(font2);

        horizontalLayout->addWidget(pushButton_L_Go);

        pushButton_L_Save = new QPushButton(tabCalL);
        pushButton_L_Save->setObjectName(QString::fromUtf8("pushButton_L_Save"));
        sizePolicy3.setHeightForWidth(pushButton_L_Save->sizePolicy().hasHeightForWidth());
        pushButton_L_Save->setSizePolicy(sizePolicy3);

        horizontalLayout->addWidget(pushButton_L_Save);

        tabs->addTab(tabCalL, QString());

        verticalLayout_2->addWidget(tabs);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        label_D = new QLabel(centralWidget);
        label_D->setObjectName(QString::fromUtf8("label_D"));
        label_D->setFont(font2);

        gridLayout_4->addWidget(label_D, 0, 1, 1, 1);

        label_F = new QLabel(centralWidget);
        label_F->setObjectName(QString::fromUtf8("label_F"));
        label_F->setFont(font2);

        gridLayout_4->addWidget(label_F, 0, 0, 1, 1);

        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setFont(font2);
        progressBar->setValue(24);

        gridLayout_4->addWidget(progressBar, 1, 0, 1, 3);

        label_threschold = new QLabel(centralWidget);
        label_threschold->setObjectName(QString::fromUtf8("label_threschold"));
        label_threschold->setFont(font2);

        gridLayout_4->addWidget(label_threschold, 0, 2, 1, 1);


        verticalLayout_2->addLayout(gridLayout_4);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabs->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "USB LC meter", 0, QApplication::UnicodeUTF8));
        actionCalibrate->setText(QApplication::translate("MainWindow", "\320\232\320\260\320\273\320\270\320\261\321\200\320\276\320\262\320\272\320\260", 0, QApplication::UnicodeUTF8));
        actionConnectionState->setText(QApplication::translate("MainWindow", "not connected", 0, QApplication::UnicodeUTF8));
        label_C->setText(QApplication::translate("MainWindow", "\320\241", 0, QApplication::UnicodeUTF8));
        tabs->setTabText(tabs->indexOf(tabC), QApplication::translate("MainWindow", "Capacitance", 0, QApplication::UnicodeUTF8));
        label_L->setText(QApplication::translate("MainWindow", "L", 0, QApplication::UnicodeUTF8));
        tabs->setTabText(tabs->indexOf(tabL), QApplication::translate("MainWindow", "Inductance", 0, QApplication::UnicodeUTF8));
        tabs->setTabText(tabs->indexOf(tabUSB), QApplication::translate("MainWindow", "HID USB", 0, QApplication::UnicodeUTF8));
        lineEdit_C->setText(QApplication::translate("MainWindow", "1000", 0, QApplication::UnicodeUTF8));
        label_C_msg->setText(QString());
        label_cal_C->setText(QApplication::translate("MainWindow", "calibration C", 0, QApplication::UnicodeUTF8));
        label_P_C->setText(QApplication::translate("MainWindow", "%", 0, QApplication::UnicodeUTF8));
        label_pF->setText(QApplication::translate("MainWindow", "pF", 0, QApplication::UnicodeUTF8));
        lineEdit_C_T->setText(QApplication::translate("MainWindow", "0.002", 0, QApplication::UnicodeUTF8));
        label_SDT_C->setText(QApplication::translate("MainWindow", " standard deviation threshold", 0, QApplication::UnicodeUTF8));
        checkBoxAvg_C->setText(QApplication::translate("MainWindow", "AVARGE", 0, QApplication::UnicodeUTF8));
        pushButton_C_Save->setText(QApplication::translate("MainWindow", "Save", 0, QApplication::UnicodeUTF8));
        pushButton_C_Go->setText(QApplication::translate("MainWindow", "Go", 0, QApplication::UnicodeUTF8));
        tabs->setTabText(tabs->indexOf(tabCalC), QApplication::translate("MainWindow", "C Calibration", 0, QApplication::UnicodeUTF8));
        lineEdit_L_T->setText(QApplication::translate("MainWindow", "0.002", 0, QApplication::UnicodeUTF8));
        lineEdit_L->setText(QApplication::translate("MainWindow", "89200", 0, QApplication::UnicodeUTF8));
        label_P_L->setText(QApplication::translate("MainWindow", "%", 0, QApplication::UnicodeUTF8));
        label_SDT_L->setText(QApplication::translate("MainWindow", " standard deviation threshold", 0, QApplication::UnicodeUTF8));
        label_nH->setText(QApplication::translate("MainWindow", "nH", 0, QApplication::UnicodeUTF8));
        label_cal_L->setText(QApplication::translate("MainWindow", "calibration L", 0, QApplication::UnicodeUTF8));
        checkBoxAvg_L->setText(QApplication::translate("MainWindow", "AVARGE", 0, QApplication::UnicodeUTF8));
        label_L_msg->setText(QString());
        pushButton_L_Go->setText(QApplication::translate("MainWindow", "Go", 0, QApplication::UnicodeUTF8));
        pushButton_L_Save->setText(QApplication::translate("MainWindow", "Save", 0, QApplication::UnicodeUTF8));
        tabs->setTabText(tabs->indexOf(tabCalL), QApplication::translate("MainWindow", "L Calibration", 0, QApplication::UnicodeUTF8));
        label_D->setText(QString());
        label_F->setText(QString());
        label_threschold->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
