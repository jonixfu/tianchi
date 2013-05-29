INC=$$WORKDIR/include
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

HEADERS += $$SRC/Plugin/TcLineEditPlugin.h      $$INC/Gui/TcLineEdit.h \
           $$SRC/Plugin/TcMarqueeLabelPlugin.h  $$INC/Gui/TcMarqueeLabel.h \
           $$SRC/Plugin/TcClickLabelPlugin.h    $$INC/Gui/TcClickLabel.h \
           $$SRC/Plugin/TcDateEditPlugin.h      $$INC/Gui/TcDateEdit.h \
           $$SRC/Plugin/TianchiPlugins.h \
           $$INC/Core/TcUtils.h

SOURCES += $$SRC/Plugin/TcLineEditPlugin.cpp     $$SRC/Gui/TcLineEdit.cpp \
           $$SRC/Plugin/TcMarqueeLabelPlugin.cpp $$SRC/Gui/TcMarqueeLabel.cpp \
           $$SRC/Plugin/TcClickLabelPlugin.cpp   $$SRC/Gui/TcClickLabel.cpp \
           $$SRC/Plugin/TcDateEditPlugin.cpp     $$SRC/Gui/TcDateEdit.cpp \
           $$SRC/Plugin/TianchiPlugins.cpp \
           $$SRC/Core/TcUtils.cpp
