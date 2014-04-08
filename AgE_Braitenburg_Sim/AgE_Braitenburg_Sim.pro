#-------------------------------------------------
#
# Project created by QtCreator 2014-04-04T11:38:06
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AgE_Braitenburg_Sim
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Braitenburg_GUI.cpp \
    robot.cpp

HEADERS  += mainwindow.h \
    Braitenburg_GUI.h \
    robot.h

FORMS    += mainwindow.ui
