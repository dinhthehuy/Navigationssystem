QT       += core gui
QT       += testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    adresse.cpp \
    karte.cpp \
    karteadresseanlegen.cpp \
    kartepoianlegen.cpp \
    main.cpp \
    mainwindow.cpp \
    ort.cpp \
    poi.cpp \
    test.cpp

HEADERS += \
    adresse.h \
    karte.h \
    karteadresseanlegen.h \
    kartepoianlegen.h \
    mainwindow.h \
    ort.h \
    poi.h \
    test.h

FORMS += \
    karte.ui \
    karteadresseanlegen.ui \
    kartepoianlegen.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Map.qrc
