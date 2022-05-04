QT       += core gui \
    quick
QT       +=network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = bankautomat
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
        main.cpp \
    mainwindow.cpp \
    nosto.cpp \
    saldo.cpp \
    tilitapahtumat.cpp \
    valikko.cpp

HEADERS += \
    mainwindow.h \
    nosto.h \
    saldo.h \
    tilitapahtumat.h \
    valikko.h

FORMS += \
    mainwindow.ui \
    nosto.ui \
    saldo.ui \
    tilitapahtumat.ui \
    valikko.ui \

DISTFILES +=
