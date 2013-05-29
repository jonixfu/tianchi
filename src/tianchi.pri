INC=$$WORKDIR/include
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
# ǿ��Ϊ lib Ŀ¼
DESTDIR = $$WORKDIR/lib

INCLUDEPATH += $$INC


# g++ pch header
win32-g++* : PRECOMPILED_HEADER = $$PWD/../src/tianchi_gcc_pch.h
linux-g++* : PRECOMPILED_HEADER = $$PWD/../src/tianchi_gcc_pch.h
macx-g++*  : PRECOMPILED_HEADER = $$PWD/../src/tianchi_gcc_pch.h

win32:LIBS += -lversion
win32-msvc*:LIBS += -ladvapi32 -lole32
HEADERS += \
    $$INC/tianchi.h \
    $$INC/TcGlobal.h \
    $$INC/Chinese/TcChinese.h \
    $$INC/Core/TcClasses.h \
    $$INC/Core/TcCommon.h \
    $$INC/Core/TcString.h \
    $$INC/Core/TcUtils.h \
    $$INC/Core/TcError.h \
    $$INC/File/TcDir.h \
    $$INC/File/TcExcelReader.h \
    $$INC/File/TcFile.h \
    $$INC/File/TcFileIO.h \
    $$INC/File/TcJson.h \
    $$INC/File/TcKeyValue.h \
    $$INC/File/TcLog.h \
    $$INC/File/TcMSExcel.h \
    $$INC/Gui/TcMarqueeLabel.h \
    $$INC/Gui/TcClickLabel.h \
    $$INC/Gui/TcLineEdit.h \
    $$INC/Gui/TcFlowLayout.h \
    $$INC/Gui/TcGlowEffect.h \
    $$INC/Gui/TcDateEdit.h \
    $$INC/Gui/TcGuiUtils.h \
    $$INC/Gui/TcFormUtils.h \
    $$INC/Network/TcUdp.h \
    $$INC/Network/TcDownloadHttp.h \
    $$INC/Network/TcSingleInstance.h \
    $$INC/Sql/TcDatabase.h \
    $$INC/Sql/TcDataAccess.h \
    $$INC/Sql/TcMSSQL.h \
    $$INC/Widget/TcTreeEx.h \
    $$INC/Widget/TcHeaderSetupDialog.h \
    $$INC/OS/TcOS.h

SOURCES += \
    $$SRC/Chinese/TcChinese.cpp \
    $$SRC/Core/TcClasses.cpp \
    $$SRC/Core/TcUtils.cpp \
    $$SRC/Core/TcCommon.cpp \
    $$SRC/Core/TcString.cpp \
    $$SRC/Core/TcError.cpp \
    $$SRC/File/TcDir.cpp \
    $$SRC/File/TcExcelReader.cpp \
    $$SRC/File/TcFile.cpp \
    $$SRC/File/TcFileIO.cpp \
    $$SRC/File/TcJson.cpp \
    $$SRC/File/TcKeyValue.cpp \
    $$SRC/File/TcLog.cpp \
    $$SRC/File/TcMSExcel.cpp \
    $$SRC/Gui/TcMarqueeLabel.cpp \
    $$SRC/Gui/TcClickLabel.cpp \
    $$SRC/Gui/TcLineEdit.cpp \
    $$SRC/Gui/TcFlowLayout.cpp \
    $$SRC/Gui/TcGlowEffect.cpp \
    $$SRC/Gui/TcDateEdit.cpp \
    $$SRC/Gui/TcGuiUtils.cpp \
    $$SRC/Gui/TcFormUtils.cpp \
    $$SRC/Network/TcUdp.cpp \
    $$SRC/Network/TcDownloadHttp.cpp \
    $$SRC/Network/TcSingleInstance.cpp \
    $$SRC/Sql/TcDataAccess.cpp \
    $$SRC/Sql/TcDatabase.cpp \
    $$SRC/Sql/TcMSSQL.cpp \
    $$SRC/Widget/TcTreeEx.cpp \
    $$SRC/Widget/TcHeaderSetupDialog.cpp \
    $$SRC/OS/TcOS.cpp

FORMS += \
    $$SRC/Widget/TcHeaderSetupDialog.ui

RESOURCES += \
    $$RES/tianchi.qrc

