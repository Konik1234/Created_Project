QT = core
QT += widgets
CONFIG += c++17 cmdline

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        klocek.cpp \
        main.cpp \
        okno.cpp \
        plansza.cpp

TRANSLATIONS += \
    Tetris_POIO_pl_PL.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = $$[QT_INSTALL_EXAMPLES]/widgets/widgets/tetrix
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    klocek.h \
    okno.h \
    plansza.h
