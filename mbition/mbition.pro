TEMPLATE = app

QT += qml quick

SOURCES += main.cpp \
    parser/CPUInfoParser.cpp \
    parser/Parser.cpp \
    data/DataTypes.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    parser/CPUInfoParser.h \
    parser/Parser.h \
    data/DataTypes.h
