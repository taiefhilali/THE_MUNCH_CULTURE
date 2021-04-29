QT       += core gui sql serialport multimedia multimediawidgets
QT       += printsupport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets multimedia

CONFIG += c++11
QT += multimedia


TRANSLATIONS = stoppola_fi.ts


# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

TARGET = test_son

TEMPLATE = app


TRANSLATIONS = mock_en.ts mock_es.ts

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    arduino.cpp \
    clicom.cpp \
    client.cpp \
    commande.cpp \
    connexion.cpp \
    depense.cpp \
    fourn.cpp \
    gsf.cpp \
    historique.cpp \
    interw.cpp \
    livraison.cpp \
    livreur.cpp \
    main.cpp \
    mainwindow.cpp \
    mainwindowvideo.cpp \
    menu.cpp \
    notif.cpp \
    personnel.cpp \
    produit.cpp \
    profil.cpp \
    qcustomplot.cpp \
    revenu.cpp \
    smtp.cpp \
    stat.cpp \
    stati.cpp \
    statistiq.cpp \
    stocks.cpp \
    youssef.cpp

HEADERS += \
    arduino.h \
    clicom.h \
    client.h \
    commande.h \
    connexion.h \
    depense.h \
    fourn.h \
    gsf.h \
    historique.h \
    interw.h \
    livraison.h \
    livreur.h \
    mainwindow.h \
    mainwindowvideo.h \
    menu.h \
    notif.h \
    personnel.h \
    produit.h \
    profil.h \
    qcustomplot.h \
    revenu.h \
    smtp.h \
    stat.h \
    stati.cpp.autosave \
    stati.h \
    statistiq.h \
    stocks.h \
    youssef.h

FORMS += \
    clicom.ui \
    gsf.ui \
    interw.ui \
    mainwindow.ui \
    mainwindowvideo.ui \
    menu.ui \
    stat.ui \
    stati.ui \
    statistiq.ui \
    youssef.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    design.qrc \
    design.qrc \
    design.qrc \
    design.qrc \
    design.qrc \
    hh.qrc \
    image.qrc \
    test_son.qrc \
    traduction.qrc

DISTFILES += \
    1.jpg \
    11.jpg \
    117264.png \
    ajouter.jpg \
    couverture.jfif \
    historique.txt \
    kisspng-computer-icons-magnifying-glass-clip-art-glass-buttons-5ae1a2958d8b85.9342250715247366615798.jpg \
    kisspng-computer-icons-user-profile-icon-design-edit-5b21054a784701.8199027215288906984927.jpg \
    pngtree-cartoon-arrow-icon-download-image_1256957.jpg
