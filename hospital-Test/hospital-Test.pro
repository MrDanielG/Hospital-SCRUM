QT += testlib sql
QT -= gui

TARGET = hospital
CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_pruebas.cpp
