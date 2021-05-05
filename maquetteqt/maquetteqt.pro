QT       += core gui
QT += printsupport
QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += sql widgets

CONFIG += c++11
TEMPLATE = app
TARGET =
DEPENDPATH += . bilan
INCLUDEPATH += . bilan
# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bilan.cpp \
    connexion.cpp \
    depense.cpp \
    main.cpp \
    produit.cpp \
    qcustomplot.cpp \
    revenu.cpp \
    youssef.cpp

HEADERS += \
    bilan.h \
    connexion.h \
    depense.h \
    produit.h \
    qcustomplot.h \
    revenu.h \
    youssef.h

FORMS += \
    bilan.ui \
    youssef.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    design.qrc

DISTFILES +=
