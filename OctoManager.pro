#-------------------------------------------------
#
# Project created by QtCreator 2016-11-04T16:06:56
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = OctoManager
TEMPLATE = app


SOURCES +=\
    OctoButton.cpp \
    OctoClient.cpp \
    OctoClientManagerView.cpp \
    OctoDash.cpp \
    OctoDashLogic.cpp \
    OctoDashScreen.cpp \
    OctoManagerView.cpp \
    OctoProject.cpp \
    OctoProjectManagerView.cpp \
    OctoSettings.cpp \
    OctoSettingsView.cpp \
    OctoSettingsGeneral.cpp \
    OctoSettingsWorkspace.cpp \
    OctoManagerMain.cpp \
    OctoButtonProject.cpp \
    OctoButtonManager.cpp \
    OctoItem.cpp

HEADERS  += \
    OctoButton.h \
    OctoClient.h \
    OctoClientmanagerview.h \
    OctoDash.h \
    OctoDashLogic.h \
    OctoDashScreen.h \
    OctoManagerView.h \
    OctoProject.h \
    OctoProjectManagerView.h \
    OctoSettings.h \
    OctoSettingsView.h \
    OctoSettingsWorkspace.h \
    OctoSettingsGeneral.h \
    OctoButtonProject.h \
    OctoButtonManager.h \
    OctoItem.h

FORMS += \
    OctoManagerView.ui \
    OctoSettingsView.ui \
    OctoClientManagerView.ui \
    OctoProjectManagerView.ui

RESOURCES += \
    resources.qrc
