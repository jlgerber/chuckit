#-------------------------------------------------
#
# Project created by QtCreator 2016-12-08T07:24:03
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = chuckit
TEMPLATE = app

#QMAKE_CXXFLAGS += -std=c++11

SOURCES += main.cpp\
        View/mainwindow.cpp \
    startup.cpp \
    Model/chuckitmodel.cpp

HEADERS  += View/mainwindow.hpp \
    startup.hpp \
    Model/chuckitmodel.hpp

FORMS    += View/mainwindow.ui
