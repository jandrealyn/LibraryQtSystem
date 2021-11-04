QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    admin.cpp \
    admincatalogue.cpp \
    admindue.cpp \
    adminhome.cpp \
    adminoverdue.cpp \
    adminreturned.cpp \
    adminsystem.cpp \
    adminuser.cpp \
    catalogue.cpp \
    checkoutscreen.cpp \
    createfiles.cpp \
    dialog.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    admin.h \
    admincatalogue.h \
    admindue.h \
    adminhome.h \
    adminoverdue.h \
    adminreturned.h \
    adminsystem.h \
    adminuser.h \
    catalogue.h \
    checkoutscreen.h \
    createfiles.h \
    dialog.h \
    mainwindow.h

FORMS += \
    admin.ui \
    admincatalogue.ui \
    admindue.ui \
    adminhome.ui \
    adminoverdue.ui \
    adminreturned.ui \
    adminsystem.ui \
    adminuser.ui \
    catalogue.ui \
    checkoutscreen.ui \
    dialog.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc
