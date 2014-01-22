#-------------------------------------------------
#
# Project created by QtCreator 2011-06-10T20:26:01
#
#-------------------------------------------------

QT       += core gui

TARGET = Calc
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Function.cpp \
    about.cpp \
    in2pre.cpp \
    pre2.cpp \
    post2_in2post.cpp

HEADERS  += mainwindow.h \
    Function.h \
    about.h \
    in2pre.h \
    pre2.h \
    post2_in2post.h

FORMS    += mainwindow.ui \
    about.ui \
    in2pre.ui \
    pre2.ui \
    post2_in2post.ui

RC_FILE += Calc.rc
