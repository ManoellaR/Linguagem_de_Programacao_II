QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ammocount.cpp \
    ammunition.cpp \
    bullet.cpp \
    game.cpp \
    gameover.cpp \
    health.cpp \
    heart.cpp \
    main.cpp \
    menu.cpp \
    player.cpp \
    zombie.cpp

HEADERS += \
    ammocount.hpp \
    ammunition.hpp \
    bullet.hpp \
    game.hpp \
    gameover.hpp \
    health.hpp \
    heart.hpp \
    menu.hpp \
    player.hpp \
    zombie.hpp

FORMS += \
    gameover.ui \
    menu.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources.qrc
