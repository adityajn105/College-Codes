#-------------------------------------------------
#
# Project created by QtCreator 2016-02-05T13:50:07
#
#-------------------------------------------------

QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TARGET = PersonnelDB
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    person.cpp \
    qlongvalidator.cpp \
    record.cpp

HEADERS  += mainwindow.h \
    person.h \
    qlongvalidator.h \
    record.h

FORMS    += mainwindow.ui
