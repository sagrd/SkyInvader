#-------------------------------------------------
#
# Project created by QtCreator 2017-01-06T00:35:54
#
#-------------------------------------------------

QT       += core gui \
#          multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SkyInvader
TEMPLATE = app


SOURCES += main.cpp \
    bullet.cpp \
    enemy.cpp \
    game.cpp \
    score.cpp \
    player.cpp \
    health.cpp \
    include.cpp \
    cloudfront.cpp \
    cloudback.cpp \
    healthpop.cpp \
    ship.cpp \
    missileenemy.cpp \
    button.cpp \
    tree.cpp \
    boss.cpp

HEADERS  += \
    bullet.h \
    enemy.h \
    game.h \
    score.h \
    player.h \
    health.h \
    include.h \
    cloudfront.h \
    cloudback.h \
    healthpop.h \
    ship.h \
    missileenemy.h \
    button.h \
    tree.h \
    boss.h

RESOURCES += \
    res.qrc

FORMS +=
