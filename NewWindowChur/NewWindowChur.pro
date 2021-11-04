QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    catalogue.cpp \
    checkoutscreen.cpp \
    createfiles.cpp \
    dialog.cpp \
    main.cpp \
    mainwindow.cpp \
    signupscreen.cpp \
    signupscreen2.cpp

HEADERS += \
    catalogue.h \
    checkoutscreen.h \
    createfiles.h \
    dialog.h \
    mainwindow.h \
    signupscreen.h \
    signupscreen2.h

FORMS += \
    catalogue.ui \
    checkoutscreen.ui \
    dialog.ui \
    mainwindow.ui \
    signupscreen.ui \
    signupscreen2.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc
