INC=$$WORKDIR/inc
SRC=$$WORKDIR/src
RES=$$WORKDIR/res

QT += gui sql network script
greaterThan(QT_MAJOR_VERSION, 4) {
    QT += widgets concurrent
    win32:QT += axcontainer
} else {
    win32:CONFIG += qaxcontainer
    DEFINES += QT_WIDGETS_LIB
}

TARGET = tianchi
TEMPLATE = lib

CONFIG(debug, debug|release) {
    TARGET = $${TARGET}d
} else {
    win32:RC_FILE = $$SRC/tianchi.rc
}

CONFIG(static, static|shared) | CONFIG(staticlib, staticlib|shared) {
    TARGET = $${TARGET}_lib
} else {
    DEFINES += TIANCHI_EXPORT
}
DESTDIR = $$WORKDIR/lib
win32-g++*     : DESTDIR = $$WORKDIR/lib/mingw32
win32-msvc2005 : DESTDIR = $$WORKDIR/lib/vc2005_x86
win32-msvc2008 : DESTDIR = $$WORKDIR/lib/vc2008_x86
win32-msvc2010 : DESTDIR = $$WORKDIR/lib/vc2010_x86
win32-msvc2012 : DESTDIR = $$WORKDIR/lib/vc2012_x86

INCLUDEPATH += $$INC


# g++ pch header
win32-g++* : PRECOMPILED_HEADER = $$PWD/../src/tianchi_gcc_pch.h
linux-g++* : PRECOMPILED_HEADER = $$PWD/../src/tianchi_gcc_pch.h
macx-g++*  : PRECOMPILED_HEADER = $$PWD/../src/tianchi_gcc_pch.h

win32:LIBS += -lversion
win32-msvc*:LIBS += -ladvapi32 -lole32
HEADERS += \
    $$INC/Global.h \
    $$INC/tianchi.h \
    $$INC/Chinese/Chinese.h \
    $$INC/Core/Classes.h \
    $$INC/Core/Common.h \
    $$INC/Core/String.h \
    $$INC/Core/Utils.h \
    $$INC/File/Json.h \
    $$INC/File/LogTiny.h \
    $$INC/File/MSExcel.h \
    $$INC/File/FileUtils.h \
    $$INC/File/Directory.h \
    $$INC/Gui/MarqueeLabel.h \
    $$INC/Gui/ClickLabel.h \
    $$INC/Gui/LineEdit.h \
    $$INC/Gui/FlowLayout.h \
    $$INC/Gui/GlowEffect.h \
    $$INC/Gui/DateEdit.h \
    $$INC/Gui/GuiUtils.h \
    $$INC/Gui/TreeWidgetHeaderSetupDialog.h \
    $$INC/Network/DownloadHttp.h \
    $$INC/Network/SingleInstance.h \
    $$INC/Sql/MSSQL.h \
    $$INC/OS/OS.h

SOURCES += \
    $$SRC/Chinese/Chinese.cpp \
    $$SRC/Core/Classes.cpp \
    $$SRC/Core/Utils.cpp \
    $$SRC/Core/Common.cpp \
    $$SRC/Core/String.cpp \
    $$SRC/File/Json.cpp \
    $$SRC/File/LogTiny.cpp \
    $$SRC/File/MSExcel.cpp \
    $$SRC/File/FileUtils.cpp \
    $$SRC/File/Directory.cpp \
    $$SRC/Gui/MarqueeLabel.cpp \
    $$SRC/Gui/ClickLabel.cpp \
    $$SRC/Gui/LineEdit.cpp \
    $$SRC/Gui/FlowLayout.cpp \
    $$SRC/Gui/GlowEffect.cpp \
    $$SRC/Gui/DateEdit.cpp \
    $$SRC/Gui/TreeWidgetHeaderSetupDialog.cpp \
    $$SRC/Gui/GuiUtils.cpp \
    $$SRC/Network/DownloadHttp.cpp \
    $$SRC/Network/SingleInstance.cpp \
    $$SRC/Sql/MSSQL.cpp \
    $$SRC/OS/OS.cpp

FORMS += \
    $$SRC/Gui/TreeWidgetHeaderSetupDialog.ui

RESOURCES += \
    $$RES/tianchi.qrc

