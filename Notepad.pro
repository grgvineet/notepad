#-------------------------------------------------
#
# Project created by QtCreator 2014-10-16T16:02:35
#
#-------------------------------------------------

QT       += core gui
QT       += printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Notepad
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    find.cpp \
    font.cpp

HEADERS  += mainwindow.h \
    find.h \
    font.h

FORMS    += mainwindow.ui \
    find.ui \
    font.ui
