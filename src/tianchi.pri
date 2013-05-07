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

win32-g++*     : DESTDIR = $$WORKDIR/lib/mingw32
win32-msvc2005 : DESTDIR = $$WORKDIR/lib/vc2005_x86
win32-msvc2008 : DESTDIR = $$WORKDIR/lib/vc2008_x86
win32-msvc2010 : DESTDIR = $$WORKDIR/lib/vc2010_x86
win32-msvc2012 : DESTDIR = $$WORKDIR/lib/vc2012_x86

# !!!!!!!!!!!!!!!!!!!!!!!!!!!!
# 强设为 lib 目录
#DESTDIR = $$WORKDIR/lib

INCLUDEPATH += $$INC


# g++ pch header
win32-g++* : PRECOMPILED_HEADER = $$PWD/../src/tianchi_gcc_pch.h
linux-g++* : PRECOMPILED_HEADER = $$PWD/../src/tianchi_gcc_pch.h
macx-g++*  : PRECOMPILED_HEADER = $$PWD/../src/tianchi_gcc_pch.h

win32:LIBS += -lversion
win32-msvc*:LIBS += -ladvapi32 -lole32
HEADERS += \
    $$INC/tianchi.h \
    $$INC/tianchi/Global.h \
    $$INC/tianchi/Chinese/Chinese.h \
    $$INC/tianchi/Core/Classes.h \
    $$INC/tianchi/Core/Common.h \
    $$INC/tianchi/Core/String.h \
    $$INC/tianchi/Core/Utils.h \
    $$INC/tianchi/File/Json.h \
    $$INC/tianchi/File/Log.h \
    $$INC/tianchi/File/MSExcel.h \
    $$INC/tianchi/File/File.h \
    $$INC/tianchi/File/Directory.h \
    $$INC/tianchi/Gui/MarqueeLabel.h \
    $$INC/tianchi/Gui/ClickLabel.h \
    $$INC/tianchi/Gui/LineEdit.h \
    $$INC/tianchi/Gui/FlowLayout.h \
    $$INC/tianchi/Gui/GlowEffect.h \
    $$INC/tianchi/Gui/DateEdit.h \
    $$INC/tianchi/Gui/GuiUtils.h \
    $$INC/tianchi/Gui/HeaderSetupDialog.h \
    $$INC/tianchi/Gui/FormUtils.h \
    $$INC/tianchi/Network/Udp.h \
    $$INC/tianchi/Network/DownloadHttp.h \
    $$INC/tianchi/Network/SingleInstance.h \
    $$INC/tianchi/Sql/MSSQL.h \
    $$INC/tianchi/Sql/DataAccess.h \
    $$INC/tianchi/Sql/Database.h \
    $$INC/tianchi/Widget/TreeEx.h \
    $$INC/tianchi/OS/OS.h

SOURCES += \
    $$SRC/Chinese/Chinese.cpp \
    $$SRC/Core/Classes.cpp \
    $$SRC/Core/Utils.cpp \
    $$SRC/Core/Common.cpp \
    $$SRC/Core/String.cpp \
    $$SRC/File/Json.cpp \
    $$SRC/File/Log.cpp \
    $$SRC/File/MSExcel.cpp \
    $$SRC/File/File.cpp \
    $$SRC/File/Directory.cpp \
    $$SRC/Gui/MarqueeLabel.cpp \
    $$SRC/Gui/ClickLabel.cpp \
    $$SRC/Gui/LineEdit.cpp \
    $$SRC/Gui/FlowLayout.cpp \
    $$SRC/Gui/GlowEffect.cpp \
    $$SRC/Gui/DateEdit.cpp \
    $$SRC/Gui/HeaderSetupDialog.cpp \
    $$SRC/Gui/GuiUtils.cpp \
    $$SRC/Gui/FormUtils.cpp \
    $$SRC/Network/Udp.cpp \
    $$SRC/Network/DownloadHttp.cpp \
    $$SRC/Network/SingleInstance.cpp \
    $$SRC/Sql/MSSQL.cpp \
    $$SRC/Sql/DataAccess.cpp \
    $$SRC/Sql/Database.cpp \
    $$SRC/Widget/TreeEx.cpp \
    $$SRC/OS/OS.cpp

FORMS += \
    $$SRC/Gui/HeaderSetupDialog.ui

RESOURCES += \
    $$RES/tianchi.qrc

