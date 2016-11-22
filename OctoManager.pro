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
    OctoItem.cpp \
    OctoButtonItem.cpp

HEADERS  += \
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
    OctoItem.h \
    OctoButtonItem.h

FORMS += \
    OctoManagerView.ui \
    OctoSettingsView.ui \
    OctoClientManagerView.ui \
    OctoProjectManagerView.ui

RESOURCES += \
    resources.qrc
