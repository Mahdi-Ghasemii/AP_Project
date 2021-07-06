
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Farm.cpp \
    Habitat.cpp \
    Logo.cpp \
    Player.cpp \
    Ranking.cpp \
    SignIn.cpp \
    SignUp.cpp \
    main.cpp\
    Siloo.cpp\
    Building.cpp\
    Storage.cpp\
    Store.cpp\
    Product.cpp

HEADERS +=\
    Farm.h \
    Habitat.h \
    Logo.h \
    Player.h \
    Ranking.h \
    SignIn.h \
    SignUp.h \
    Siloo.h\
    Building.h\
    Storage.h\
    Store.h\
    Product.h\

FORMS += \
    Farm.ui \
    Habitat.ui \
    Logo.ui \
    Ranking.ui \
    SignIn.ui \
    SignUp.ui \
    Storage.ui\
    Siloo.ui\
    Store.ui\

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
