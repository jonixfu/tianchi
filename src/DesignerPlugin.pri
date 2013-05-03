TEMPLATE = lib

CONFIG += release

TC_OUTPUT = $${PWD}/../output

TC_SPEC = qt$${QT_VERSION}

win32-g++*     : TC_SPEC = $${TC_SPEC}-mingw32
win32-msvc2005 : TC_SPEC = $${TC_SPEC}-vc2005_x86
win32-msvc2008 : TC_SPEC = $${TC_SPEC}-vc2008_x86
win32-msvc2010 : TC_SPEC = $${TC_SPEC}-vc2010_x86
win32-msvc2012 : TC_SPEC = $${TC_SPEC}-vc2012_x86

TC_OUTPUT = $${TC_OUTPUT}/$${TC_SPEC}/shared
DESTDIR = $$TC_OUTPUT

TC_INCL = $$PWD/../inc
TC_SRC = $$PWD/../src

INCLUDEPATH += . $$TC_INCL

# g++ pch header
win32-g++* : PRECOMPILED_HEADER = $$PWD/../src/tianchi_gcc_pch.h
linux-g++* : PRECOMPILED_HEADER = $$PWD/../src/tianchi_gcc_pch.h
macx-g++*  : PRECOMPILED_HEADER = $$PWD/../src/tianchi_gcc_pch.h


TARGET = tianchidesignerplugin
DEPENDPATH += .
greaterThan(QT_MAJOR_VERSION, 4) {
    QT += widgets designer concurrent
    PLUGIN_TYPE = designer
    CONFIG += tool_plugin
    PLUGIN_CLASS_NAME = Tianchi::DesignerWidgets
} else {
    CONFIG += designer plugin
}

TC_TMP = $${TC_OUTPUT}/release_designerplugins

MOC_DIR = $$TC_TMP
OBJECTS_DIR = $$TC_TMP
UI_DIR = $$TC_TMP
RCC_DIR = $$TC_TMP

target.path = $$[QT_INSTALL_PLUGINS]/designer
INSTALLS += target


HEADERS += $$PWD/LineEditPlugin.h      $$TC_INCL/tianchi/Gui/LineEdit.h \
            $$PWD/MarqueeLabelPlugin.h $$TC_INCL/tianchi/Gui/MarqueeLabel.h \
            $$PWD/ClickLabelPlugin.h   $$TC_INCL/tianchi/Gui/ClickLabel.h \
            $$PWD/DateEditPlugin.h     $$TC_INCL/tianchi/Gui/DateEdit.h \
            $$TC_INCL/tianchi/Core/Utils.h \
            $$PWD/DesignerWidgets.h
SOURCES += $$PWD/LineEditPlugin.cpp      $$TC_SRC/Gui/LineEdit.cpp \
            $$PWD/MarqueeLabelPlugin.cpp $$TC_SRC/Gui/MarqueeLabel.cpp \
            $$PWD/ClickLabelPlugin.cpp   $$TC_SRC/Gui/ClickLabel.cpp \
            $$PWD/DateEditPlugin.cpp     $$TC_SRC/Gui/DateEdit.cpp \
            $$TC_SRC/Core/Utils.cpp \
            $$PWD/DesignerWidgets.cpp
