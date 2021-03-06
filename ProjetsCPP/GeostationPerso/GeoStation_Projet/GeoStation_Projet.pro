#-------------------------------------------------
#
# Project created by QtCreator 2018-12-14T11:16:31
#
#-------------------------------------------------

QT       += core gui network widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GeoStation_Projet
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    main.cpp \
    abstractapi.cpp \
    evenementapi.cpp \
    avionsapi.cpp \
    sncfapi.cpp \
    pharmacieapi.cpp \
    pollutionapi.cpp \
    satelliteapi.cpp \
    borneelectriqueapi.cpp \
    ordonnanceur.cpp \
    vigicruesapi.cpp \
    meteoapi.cpp \
    awidget.cpp \
    nullapi.cpp \
    cherchephotos.cpp \
    mozaic.cpp \
    tableauwidget.cpp \
    pharmaciewidget.cpp\
    geolocalisationapi.cpp \
    pokemap.cpp \
    sncfwidget.cpp \
    sncfmozaicwidget.cpp \
    mainwindow.cpp \
    museesapi.cpp \
    museesmozaicwidget.cpp \
    museesmainwidget.cpp \
    museeswidget.cpp \
    evenementmozaicwidget.cpp \
    evenementwidget.cpp \
    tableaupanoramicwidget.cpp \
    evenementmainwidget.cpp \
    satellitewidget.cpp \
    avionswidget.cpp \
    avionsmozaicwidget.cpp \
    linechartwidget.cpp \
    vigicruesmosaicwidget.cpp \
    vigicrueswidget.cpp \
    satellitemozaicwidget.cpp




HEADERS += \
    abstractapi.h \
    evenementapi.h \
    avionsapi.h \
    sncfapi.h \
    pharmacieapi.h \
    pollutionapi.h \
    satelliteapi.h \
    borneelectriqueapi.h \
    ordonnanceur.h \
    vigicruesapi.h \
    meteoapi.h \
    awidget.h \
    nullapi.h \
    cherchephotos.h \
    mozaic.h \
    tableauwidget.h \
    pharmaciewidget.h\
    geolocalisationapi.h \
    pokemap.h \
    sncfwidget.h \
    sncfmozaicwidget.h \
    mainwindow.h \
    museesapi.h \
    museesmozaicwidget.h \
    museesmainwidget.h \
    museeswidget.h \
    evenementmozaicwidget.h \
    evenementwidget.h \
    tableaupanoramicwidget.h \
    evenementmainwidget.h \
    satellitewidget.h \
    avionswidget.h \
    avionsmozaicwidget.h \
    linechartwidget.h \
    vigicruesmosaicwidget.h \
    vigicrueswidget.h \
    satellitemozaicwidget.h


FORMS += \
        mainwindow.ui \
    tableauwidget.ui \
    pharmaciewidget.ui\
    sncfmozaicwidget.ui \
    museesmozaicwidget.ui \
    museesmainwidget.ui \
    evenementmozaicwidget.ui \
    tableaupanoramicwidget.ui \
    evenementmainwidget.ui \
    avionsmozaicwidget.ui \
    vigicruesmosaicwidget.ui \
    satellitemozaicwidget.ui




RESOURCES += \
    resources.qrc
