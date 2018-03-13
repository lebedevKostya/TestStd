QT += core
QT -= gui

TARGET = TestStd
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    MyDb.cpp \
    eventGenerator.cpp

HEADERS += \
    MyDb.h \
    EventData.h
LIBS +=


unix|win32: LIBS += -ldb_cxx
