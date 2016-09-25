QT += core
QT -= gui

TARGET = Euler_Problem_96_Su_Doku
CONFIG += console c++11
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    sudoku.cpp \
    sudokusolver.cpp

HEADERS += \
    sudoku.h \
    sudokusolver.h

