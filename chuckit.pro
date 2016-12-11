#-------------------------------------------------
#
# Project created by QtCreator 2016-12-08T07:24:03
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = chuckit
TEMPLATE = app

ICON = icons/chuckit.icns
QMAKE_CXXFLAGS += -std=c++11

SOURCES += main.cpp\
        View/mainwindow.cpp \
    startup.cpp \
    Model/chuckitmodel.cpp \
    Model/chuckconfig.cpp

HEADERS  += View/mainwindow.hpp \
    startup.hpp \
    Model/chuckitmodel.hpp \
    Model/chuckconfig.hpp

FORMS    += View/mainwindow.ui
