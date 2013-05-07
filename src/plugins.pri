INC=$$WORKDIR/inc
SRC=$$WORKDIR/src
RES=$$WORKDIR/res

TARGET = TcPlugins

TEMPLATE = lib
CONFIG += release
CONFIG(debug, debug|release) {
    TARGET = $${TARGET}d
} else {
    win32:RC_FILE = $$SRC/plugins.rc
}

INCLUDEPATH += . $$INC

# g++ pch header
win32-g++* : PRECOMPILED_HEADER = $$SRC/tianchi_gcc_pch.h
linux-g++* : PRECOMPILED_HEADER = $$SRC/tianchi_gcc_pch.h
macx-g++*  : PRECOMPILED_HEADER = $$SRC/tianchi_gcc_pch.h

win32-g++*     : DESTDIR = $$WORKDIR/lib/mingw32
win32-msvc2005 : DESTDIR = $$WORKDIR/lib/vc2005_x86
win32-msvc2008 : DESTDIR = $$WORKDIR/lib/vc2008_x86
win32-msvc2010 : DESTDIR = $$WORKDIR/lib/vc2010_x86
win32-msvc2012 : DESTDIR = $$WORKDIR/lib/vc2012_x86

# !!!!!!!!!!!!!!!!!!!!!!!!!!!!
# 强设为 lib 目录
#DESTDIR = $$WORKDIR/lib

greaterThan(QT_MAJOR_VERSION, 4) {
    QT += widgets designer concurrent
    PLUGIN_TYPE = designer
    PLUGIN_CLASS_NAME = TianchiPlugins
    CONFIG += tool_plugin
} else {
    CONFIG += designer plugin
}

HEADERS += $$SRC/Plugin/LineEditPlugin.h      $$INC/tianchi/Gui/LineEdit.h \
           $$SRC/Plugin/MarqueeLabelPlugin.h  $$INC/tianchi/Gui/MarqueeLabel.h \
           $$SRC/Plugin/ClickLabelPlugin.h    $$INC/tianchi/Gui/ClickLabel.h \
           $$SRC/Plugin/DateEditPlugin.h      $$INC/tianchi/Gui/DateEdit.h \
           $$SRC/Plugin/TianchiPlugins.h \
           $$INC/tianchi/Core/Utils.h

SOURCES += $$SRC/Plugin/LineEditPlugin.cpp     $$SRC/Gui/LineEdit.cpp \
           $$SRC/Plugin/MarqueeLabelPlugin.cpp $$SRC/Gui/MarqueeLabel.cpp \
           $$SRC/Plugin/ClickLabelPlugin.cpp   $$SRC/Gui/ClickLabel.cpp \
           $$SRC/Plugin/DateEditPlugin.cpp     $$SRC/Gui/DateEdit.cpp \
           $$SRC/Plugin/TianchiPlugins.cpp \
           $$SRC/Core/Utils.cpp
