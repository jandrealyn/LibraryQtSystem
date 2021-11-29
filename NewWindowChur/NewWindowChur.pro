QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    SystemFiles.cpp \
    adminaddbook.cpp \
    admincatalogue.cpp \
    admindue.cpp \
    admineditbook.cpp \
    adminedituser.cpp \
    adminhome.cpp \
    adminoverdue.cpp \
    adminreturn.cpp \
    adminsystem.cpp \
    adminuser.cpp \
    catalogue.cpp \
    checkoutscreen.cpp \
    loginscreen.cpp \
    main.cpp \
    mainwindow.cpp \
    overdue.cpp \
    reservebook.cpp \
    signupscreen.cpp \
    signupscreen2.cpp \
    updateuserdetails.cpp \
    updateuserpicture.cpp

HEADERS += \
    SystemFiles.h \
    adminaddbook.h \
    admincatalogue.h \
    admindue.h \
    admineditbook.h \
    adminedituser.h \
    adminhome.h \
    adminoverdue.h \
    adminreturn.h \
    adminsystem.h \
    adminuser.h \
    catalogue.h \
    checkoutscreen.h \
    loginscreen.h \
    mainwindow.h \
    overdue.h \
    reservebook.h \
    signupscreen.h \
    signupscreen2.h \
    updateuserdetails.h \
    updateuserpicture.h

FORMS += \
    adminaddbook.ui \
    admincatalogue.ui \
    admindue.ui \
    admineditbook.ui \
    adminedituser.ui \
    adminhome.ui \
    adminoverdue.ui \
    adminreturn.ui \
    adminsystem.ui \
    adminuser.ui \
    catalogue.ui \
    checkoutscreen.ui \
    loginscreen.ui \
    mainwindow.ui \
    overdue.ui \
    reservebook.ui \
    signupscreen.ui \
    signupscreen2.ui \
    updateuserdetails.ui \
    updateuserpicture.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
#isEmpty(TARGET_EXT) {
#    win32 {
#        TARGET_CUSTOM_EXT = .exe
#    }
#    macx {
#        TARGET_CUSTOM_EXT = .app
#    }
#} else {
#    TARGET_CUSTOM_EXT = $${TARGET_EXT}
#}
#win32 {
#    DEPLOY_COMMAND = windeployqt
#}
#macx {
#    DEPLOY_COMMAND = macdeployqt
#}
#CONFIG( debug, debug|release ) {
#    # debug
#    DEPLOY_TARGET = $$shell_quote($$shell_path($${OUT_PWD}/debug/$${TARGET}$${TARGET_CUSTOM_EXT}))
#} else {
#    # release
#    DEPLOY_TARGET = $$shell_quote($$shell_path($${OUT_PWD}/release/$${TARGET}$${TARGET_CUSTOM_EXT}))
#}
##  # Uncomment the following line to help debug the deploy command when running qmake
##  warning($${DEPLOY_COMMAND} $${DEPLOY_TARGET})
## Use += instead of = if you use multiple QMAKE_POST_LINKs
#QMAKE_POST_LINK = $${DEPLOY_COMMAND} $${DEPLOY_TARGET}

RESOURCES += \
    images.qrc

DISTFILES += \
    images/top-books.png \
    umlclassdiagrams.qmodel
