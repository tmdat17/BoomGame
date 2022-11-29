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
    Map.cpp \
    Tile.cpp \
    Score.cpp \
    Health.cpp \
    Heart.cpp

HEADERS  += \
    BoomMan.h \
    Boom.h \
    Enemy.h \
    Game.h \
    Map.h \
    Tile.h \
    Score.h \
    Health.h \
    Heart.h

FORMS    +=

RESOURCES += \
    res.qrc
