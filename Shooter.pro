#-------------------------------------------------
#
# Project created by QtCreator 2016-11-23T17:26:59
#
#-------------------------------------------------

QT       += core gui \
         multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Shooter
TEMPLATE = app


SOURCES += main.cpp \
    bullet.cpp \
    enemy.cpp \
    game.cpp \
    score.cpp \
    player.cpp \
    health.cpp

HEADERS  += \
    bullet.h \
    enemy.h \
    game.h \
    score.h \
    player.h \
    health.h

FORMS    +=

RESOURCES += \
    res.qrc
