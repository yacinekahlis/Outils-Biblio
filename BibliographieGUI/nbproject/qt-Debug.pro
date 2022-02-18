# This file is generated automatically. Do not edit.
# Use project properties -> Build -> Qt -> Expert -> Custom Definitions.
TEMPLATE = app
DESTDIR = dist/Debug/GNU-Linux
TARGET = BibliographieGUI
VERSION = 1.0.0
CONFIG -= debug_and_release app_bundle lib_bundle
CONFIG += debug 
PKGCONFIG +=
QT = core gui widgets
SOURCES += JournalInterface.cpp OuvrageInterface.cpp ReferenceInterface.cpp SuppressionInterface.cpp main.cpp
HEADERS += JournalInterface.h OuvrageInterface.h ReferenceInterface.h SuppressionInterface.h
FORMS += JournalInterface.ui OuvrageInterface.ui ReferenceInterface.ui SuppressionInterface.ui
RESOURCES +=
TRANSLATIONS +=
OBJECTS_DIR = build/Debug/GNU-Linux
MOC_DIR = 
RCC_DIR = 
UI_DIR = 
QMAKE_CC = gcc
QMAKE_CXX = g++-10
DEFINES += 
INCLUDEPATH += ../TP3_source 
LIBS += ../TP3_source/dist/Debug/GNU-Linux/libtp3_source.a  
