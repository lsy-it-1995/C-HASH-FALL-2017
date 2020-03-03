TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp

HEADERS += \
    chain_hash.h \
    open_hash.h \
    double_hash.h \
    struct_record.h \
    timer.h \
    random.h
