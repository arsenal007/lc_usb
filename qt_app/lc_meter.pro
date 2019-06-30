#-------------------------------------------------
#
# Project created by QtCreator 2017-10-03T13:00:04
#
#-------------------------------------------------

lessThan(QT_MAJOR_VERSION, 5):		QT += core gui
greaterThan(QT_MAJOR_VERSION, 4): 	QT += widgets

TARGET = lc-meter
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

windows {
    ARCHITECTURE = win32
}

linux* {
    linux-arm-gnueabi-g++{
        ARCHITECTURE = linux/arm
    }

    linux-g++-32{
        ARCHITECTURE = linux/x86
    }

    linux-g++-64{
        ARCHITECTURE = linux/x86_64
    }

    isEmpty(ARCHITECTURE){
        arch = $$system(uname -m) # i686 or x86_64
        contains(arch, x86_64):{
            ARCHITECTURE = linux/x86_64
        } else {
            ARCHITECTURE = linux/x86
        }
    }
}

DESTDIR     = $$PWD/bin/$$ARCHITECTURE
OBJECTS_DIR = $$PWD/build/$$ARCHITECTURE/obj
MOC_DIR     = $$PWD/build/$$ARCHITECTURE/moc
RCC_DIR     = $$PWD/build/$$ARCHITECTURE/qrc
UI_DIR      = $$PWD/build/$$ARCHITECTURE/ui
INCLUDEPATH = $$PWD/

LIBS += -lsetupapi
#LIBS += $$PWD/libs/libqtmain.a
#LIBS += -ludev

QMAKE_LFLAGS_RELEASE += -static -static-libgcc
# With C++11 support
greaterThan(QT_MAJOR_VERSION, 4){
CONFIG += c++14
} else {
QMAKE_CXXFLAGS += -std=c++1y
}

CONFIG += static
CONFIG -= debug


SOURCES += \
    hid.c \
    main.cpp\
    mainwindow.cpp \
    worker.cpp \
    lc.cpp

HEADERS  += \
    mainwindow.h \
    worker.h \
    lc.h \
    hidapi.h \
    TRingBuffer.hpp

FORMS += \
    mainwindow.ui

RESOURCES += \
    resources.qrc
