#-------------------------------------------------
#
# Project created by QtCreator 2022-10-27T20:03:49
#
#-------------------------------------------------

QT       += core gui
QT       += multimedia
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = boomGame
TEMPLATE = app


SOURCES += main.cpp \
    BoomMan.cpp \
    Boom.cpp \
    Enemy.cpp \
    Game.cpp \
    Score.cpp \
    Health.cpp \
    Heart.cpp \
    Explosion.cpp \
    BoomManDie.cpp \
    PlayerVsEnemy.cpp \
    Flash.cpp \
    FlashLeft.cpp \
    FlashUp.cpp \
    FlashDown.cpp \
    GameOver.cpp \
    PlayerMoveRight.cpp \
    PlayerMoveDown.cpp \
    PlayerMoveLeft.cpp \
    PlayerMoveTop.cpp

HEADERS  += \
    BoomMan.h \
    Boom.h \
    Enemy.h \
    Game.h \
    Score.h \
    Health.h \
    Heart.h \
    Explosion.h \
    BoomManDie.h \
    PlayerVsEnemy.h \
    Flash.h \
    FlashLeft.h \
    FlashUp.h \
    FlashDown.h \
    GameOver.h \
    PlayerMoveRight.h \
    PlayerMoveDown.h \
    PlayerMoveLeft.h \
    PlayerMoveTop.h

FORMS    +=

RESOURCES += \
    res.qrc
