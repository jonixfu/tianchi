QT += gui sql network script
greaterThan(QT_MAJOR_VERSION, 4) { 
    QT += widgets
    win32:QT += axcontainer
} else {
    win32:CONFIG += qaxcontainer
    DEFINES += QT_WIDGETS_LIB
}

TARGET = tianchi

INC=$$WORKDIR/inc
SRC=$$WORKDIR/src
RES=$$WORKDIR/res

TEMPLATE = lib

CONFIG(debug, debug|release) {
    TARGET = $${TARGET}d
}

CONFIG(static, static|shared) | CONFIG(staticlib, staticlib|shared) {
    TARGET = $${TARGET}_s
    DESTDIR  = $$WORKDIR/lib_static
} else {
    DEFINES += TIANCHI_EXPORT
    DESTDIR  = $$WORKDIR/lib_dynamic
}

INCLUDEPATH += $$INC

win32:!win32-g++{
    LIBS += -lversion -ladvapi32 -lole32
}

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
    $$INC/Gui/MarqueeLabel.h \
    $$INC/Gui/ClickLabel.h \
    $$INC/Gui/DateEdit.h \
    $$INC/Gui/GuiUtils.h \
    $$INC/Gui/TreeWidgetHeaderSetupDialog.h \
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
    $$SRC/Gui/MarqueeLabel.cpp \
    $$SRC/Gui/ClickLabel.cpp \
    $$SRC/Gui/DateEdit.cpp \
    $$SRC/Gui/TreeWidgetHeaderSetupDialog.cpp \
    $$SRC/Gui/GuiUtils.cpp \
    $$SRC/OS/OS.cpp

FORMS += \
    $$SRC/Gui/TreeWidgetHeaderSetupDialog.ui

RESOURCES += \
    $$RES/tianchi.qrc
