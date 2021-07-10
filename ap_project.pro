QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ChickenHome.cpp \
    CowHome.cpp \
    Farm.cpp \
    Habitat.cpp \
    Logo.cpp \
    Player.cpp \
    Ranking.cpp \
    SheepHome.cpp \
    SignIn.cpp \
    SignUp.cpp \
    gandomfarm.cpp \
    main.cpp\
    Siloo.cpp\
    Building.cpp\
    Storage.cpp\
    Store.cpp\
    Product.cpp \
    mainfarm.cpp \
    yonjefarm.cpp \

HEADERS +=\
    ChickenHome.h \
    CowHome.h \
    Data.h \
    Farm.h \
    Habitat.h \
    Logo.h \
    Player.h \
    Ranking.h \
    SheepHome.h \
    SignIn.h \
    SignUp.h \
    Siloo.h \
    Building.h \
    Storage.h \
    Store.h \
    Product.h \
    gandomfarm.h \
    mainfarm.h \
    yonjefarm.h \

FORMS += \
    ChickenHome.ui \
    CowHome.ui \
    Farm.ui \
    Logo.ui \
    Ranking.ui \
    SheepHome.ui \
    SignIn.ui \
    SignUp.ui \
    Storage.ui \
    Siloo.ui \
    Store.ui \
    gandomfarm.ui \
    yonjefarm.ui \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
