/********************************************************************************
** Form generated from reading UI file 'clicom.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLICOM_H
#define UI_CLICOM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Clicom
{
public:
    QTabWidget *temprature;
    QWidget *tab1;
    QTabWidget *tabWidget_2;
    QWidget *tab_3;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *le_id;
    QLineEdit *le_prenom;
    QLineEdit *le_nombre;
    QPushButton *Ajouter;
    QLineEdit *le_nom;
    QTableView *tableView_3;
    QLabel *label_5;
    QLineEdit *le_idsupprimer;
    QPushButton *supprimer_3;
    QPushButton *push_recherche_3;
    QLineEdit *le_recherche_3;
    QPushButton *modifier;
    QComboBox *trie;
    QComboBox *rechercher_cli;
    QLabel *label_23;
    QPushButton *pushButton_2;
    QRadioButton *desc;
    QRadioButton *asc;
    QPushButton *trierClient;
    QLabel *label_9;
    QLineEdit *le_adresse;
    QPushButton *acualiser_1;
    QLabel *date;
    QLabel *clock;
    QPushButton *exel_client;
    QPushButton *pdf;
    QWidget *tab_2;
    QTabWidget *affichage2;
    QWidget *tab_11;
    QLabel *label_15;
    QLabel *label_17;
    QLineEdit *le_com;
    QLineEdit *le_nb;
    QPushButton *pb_ajouter;
    QLabel *label_42;
    QLineEdit *le_date;
    QTableView *tableView_4;
    QLineEdit *le_idsupprimer_2;
    QLabel *label_43;
    QPushButton *pb_supprimer;
    QComboBox *triecommande;
    QLineEdit *linecomande;
    QPushButton *rech_but;
    QPushButton *modifiercom;
    QComboBox *recombo;
    QLabel *label_24;
    QPushButton *pushButton_3;
    QPushButton *triercom;
    QRadioButton *decend;
    QRadioButton *asend;
    QLabel *label_26;
    QComboBox *combotype;
    QPushButton *pushButton;
    QLabel *label_28;
    QLabel *total;
    QLabel *label_dt;
    QPushButton *pushButton_5;
    QLabel *clock_2;
    QLabel *date_2;
    QPushButton *excel;
    QPushButton *satist;
    QPushButton *pdf_com;
    QWidget *tab;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *exitBtn;
    QPushButton *sendBtn;
    QWidget *layoutWidget_2;
    QFormLayout *formLayout;
    QLabel *label_16;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label_21;
    QLabel *label_22;
    QLineEdit *server;
    QLineEdit *port;
    QLineEdit *uname;
    QLineEdit *paswd;
    QLineEdit *rcpt;
    QLineEdit *subject;
    QPlainTextEdit *msg;
    QLabel *label_10;
    QLabel *label_25;

    void setupUi(QDialog *Clicom)
    {
        if (Clicom->objectName().isEmpty())
            Clicom->setObjectName(QStringLiteral("Clicom"));
        Clicom->resize(902, 652);
        temprature = new QTabWidget(Clicom);
        temprature->setObjectName(QStringLiteral("temprature"));
        temprature->setGeometry(QRect(0, 0, 911, 701));
        tab1 = new QWidget();
        tab1->setObjectName(QStringLiteral("tab1"));
        tabWidget_2 = new QTabWidget(tab1);
        tabWidget_2->setObjectName(QStringLiteral("tabWidget_2"));
        tabWidget_2->setGeometry(QRect(0, 0, 901, 661));
        QFont font;
        font.setFamily(QStringLiteral("MS Shell Dlg 2"));
        tabWidget_2->setFont(font);
        tabWidget_2->setStyleSheet(QStringLiteral("tabWidget_2 = new QWidget(this); m_myWidget->setGeometry(0, 0, 300, 100)"));
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        label = new QLabel(tab_3);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 130, 47, 14));
        label_2 = new QLabel(tab_3);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 90, 41, 16));
        label_3 = new QLabel(tab_3);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(0, 170, 71, 16));
        label_4 = new QLabel(tab_3);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(0, 210, 121, 16));
        le_id = new QLineEdit(tab_3);
        le_id->setObjectName(QStringLiteral("le_id"));
        le_id->setGeometry(QRect(140, 90, 113, 20));
        le_id->setStyleSheet(QStringLiteral("m_myWidget = new QWidget(this); m_myWidget->setGeometry(0, 0, 300, 100); QPalette pal = palette();"));
        le_prenom = new QLineEdit(tab_3);
        le_prenom->setObjectName(QStringLiteral("le_prenom"));
        le_prenom->setGeometry(QRect(140, 170, 113, 20));
        le_nombre = new QLineEdit(tab_3);
        le_nombre->setObjectName(QStringLiteral("le_nombre"));
        le_nombre->setGeometry(QRect(140, 210, 113, 20));
        Ajouter = new QPushButton(tab_3);
        Ajouter->setObjectName(QStringLiteral("Ajouter"));
        Ajouter->setGeometry(QRect(140, 290, 91, 31));
        QIcon icon;
        icon.addFile(QStringLiteral(":/StyleSheet/verifier-signer_318-9087.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        Ajouter->setIcon(icon);
        le_nom = new QLineEdit(tab_3);
        le_nom->setObjectName(QStringLiteral("le_nom"));
        le_nom->setGeometry(QRect(140, 130, 113, 20));
        tableView_3 = new QTableView(tab_3);
        tableView_3->setObjectName(QStringLiteral("tableView_3"));
        tableView_3->setGeometry(QRect(270, 10, 601, 301));
        label_5 = new QLabel(tab_3);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(360, 380, 31, 21));
        QFont font1;
        font1.setPointSize(10);
        label_5->setFont(font1);
        le_idsupprimer = new QLineEdit(tab_3);
        le_idsupprimer->setObjectName(QStringLiteral("le_idsupprimer"));
        le_idsupprimer->setGeometry(QRect(430, 369, 181, 31));
        le_idsupprimer->setStyleSheet(QStringLiteral("m_myWidget = new QWidget(this); m_myWidget->setGeometry(0, 0, 300, 100); QPalette pal = palette();"));
        supprimer_3 = new QPushButton(tab_3);
        supprimer_3->setObjectName(QStringLiteral("supprimer_3"));
        supprimer_3->setGeometry(QRect(620, 370, 91, 31));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/StyleSheet/seo-social-web-network-internet_262_icon-icons.com_61518.png"), QSize(), QIcon::Normal, QIcon::Off);
        supprimer_3->setIcon(icon1);
        push_recherche_3 = new QPushButton(tab_3);
        push_recherche_3->setObjectName(QStringLiteral("push_recherche_3"));
        push_recherche_3->setGeometry(QRect(620, 470, 91, 28));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/StyleSheet/kisspng-computer-icons-magnifying-glass-clip-art-glass-buttons-5ae1a2958d8b85.9342250715247366615798.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        push_recherche_3->setIcon(icon2);
        le_recherche_3 = new QLineEdit(tab_3);
        le_recherche_3->setObjectName(QStringLiteral("le_recherche_3"));
        le_recherche_3->setGeometry(QRect(430, 470, 181, 31));
        modifier = new QPushButton(tab_3);
        modifier->setObjectName(QStringLiteral("modifier"));
        modifier->setGeometry(QRect(20, 330, 91, 31));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/StyleSheet/kisspng-computer-icons-user-profile-icon-design-edit-5b21054a784701.8199027215288906984927.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        modifier->setIcon(icon3);
        trie = new QComboBox(tab_3);
        trie->setObjectName(QStringLiteral("trie"));
        trie->setGeometry(QRect(340, 410, 73, 22));
        rechercher_cli = new QComboBox(tab_3);
        rechercher_cli->setObjectName(QStringLiteral("rechercher_cli"));
        rechercher_cli->setGeometry(QRect(340, 480, 73, 21));
        label_23 = new QLabel(tab_3);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(0, 0, 891, 591));
        label_23->setStyleSheet(QLatin1String("background-color:tranparent;\n"
"\n"
"border-image:url(:/StyleSheet/11.jpg);\n"
"\n"
"background:none;\n"
"\n"
"border:none;\n"
"\n"
"background-repeat:none;"));
        pushButton_2 = new QPushButton(tab_3);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(20, 290, 91, 31));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/StyleSheet/t\303\251l\303\251charg\303\251.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon4);
        desc = new QRadioButton(tab_3);
        desc->setObjectName(QStringLiteral("desc"));
        desc->setGeometry(QRect(480, 410, 97, 20));
        asc = new QRadioButton(tab_3);
        asc->setObjectName(QStringLiteral("asc"));
        asc->setGeometry(QRect(480, 440, 97, 20));
        trierClient = new QPushButton(tab_3);
        trierClient->setObjectName(QStringLiteral("trierClient"));
        trierClient->setGeometry(QRect(620, 410, 93, 28));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/StyleSheet/117264.png"), QSize(), QIcon::Normal, QIcon::Off);
        trierClient->setIcon(icon5);
        label_9 = new QLabel(tab_3);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(0, 250, 91, 16));
        le_adresse = new QLineEdit(tab_3);
        le_adresse->setObjectName(QStringLiteral("le_adresse"));
        le_adresse->setGeometry(QRect(140, 250, 113, 20));
        acualiser_1 = new QPushButton(tab_3);
        acualiser_1->setObjectName(QStringLiteral("acualiser_1"));
        acualiser_1->setGeometry(QRect(740, 320, 101, 28));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/StyleSheet/pngtree-cartoon-arrow-icon-download-image_1256957.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        acualiser_1->setIcon(icon6);
        date = new QLabel(tab_3);
        date->setObjectName(QStringLiteral("date"));
        date->setGeometry(QRect(0, 50, 231, 16));
        date->setMinimumSize(QSize(231, 0));
        QFont font2;
        font2.setPointSize(12);
        date->setFont(font2);
        clock = new QLabel(tab_3);
        clock->setObjectName(QStringLiteral("clock"));
        clock->setGeometry(QRect(0, 10, 261, 16));
        clock->setFont(font2);
        exel_client = new QPushButton(tab_3);
        exel_client->setObjectName(QStringLiteral("exel_client"));
        exel_client->setGeometry(QRect(440, 320, 101, 28));
        pdf = new QPushButton(tab_3);
        pdf->setObjectName(QStringLiteral("pdf"));
        pdf->setGeometry(QRect(560, 320, 101, 28));
        tabWidget_2->addTab(tab_3, QString());
        label_23->raise();
        label->raise();
        label_2->raise();
        label_3->raise();
        label_4->raise();
        le_id->raise();
        le_prenom->raise();
        le_nombre->raise();
        Ajouter->raise();
        le_nom->raise();
        tableView_3->raise();
        label_5->raise();
        le_idsupprimer->raise();
        supprimer_3->raise();
        push_recherche_3->raise();
        le_recherche_3->raise();
        modifier->raise();
        trie->raise();
        rechercher_cli->raise();
        pushButton_2->raise();
        desc->raise();
        asc->raise();
        trierClient->raise();
        label_9->raise();
        le_adresse->raise();
        acualiser_1->raise();
        date->raise();
        clock->raise();
        exel_client->raise();
        pdf->raise();
        temprature->addTab(tab1, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        affichage2 = new QTabWidget(tab_2);
        affichage2->setObjectName(QStringLiteral("affichage2"));
        affichage2->setGeometry(QRect(0, 0, 821, 601));
        tab_11 = new QWidget();
        tab_11->setObjectName(QStringLiteral("tab_11"));
        label_15 = new QLabel(tab_11);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(10, 130, 71, 16));
        label_17 = new QLabel(tab_11);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(10, 160, 151, 16));
        le_com = new QLineEdit(tab_11);
        le_com->setObjectName(QStringLiteral("le_com"));
        le_com->setGeometry(QRect(170, 100, 113, 20));
        le_nb = new QLineEdit(tab_11);
        le_nb->setObjectName(QStringLiteral("le_nb"));
        le_nb->setGeometry(QRect(170, 160, 113, 20));
        pb_ajouter = new QPushButton(tab_11);
        pb_ajouter->setObjectName(QStringLiteral("pb_ajouter"));
        pb_ajouter->setGeometry(QRect(180, 240, 91, 31));
        pb_ajouter->setIcon(icon);
        label_42 = new QLabel(tab_11);
        label_42->setObjectName(QStringLiteral("label_42"));
        label_42->setGeometry(QRect(10, 100, 121, 16));
        le_date = new QLineEdit(tab_11);
        le_date->setObjectName(QStringLiteral("le_date"));
        le_date->setGeometry(QRect(170, 130, 113, 22));
        tableView_4 = new QTableView(tab_11);
        tableView_4->setObjectName(QStringLiteral("tableView_4"));
        tableView_4->setGeometry(QRect(300, 10, 501, 251));
        le_idsupprimer_2 = new QLineEdit(tab_11);
        le_idsupprimer_2->setObjectName(QStringLiteral("le_idsupprimer_2"));
        le_idsupprimer_2->setGeometry(QRect(370, 350, 191, 31));
        le_idsupprimer_2->setStyleSheet(QStringLiteral("m_myWidget = new QWidget(this); m_myWidget->setGeometry(0, 0, 300, 100); QPalette pal = palette();"));
        label_43 = new QLabel(tab_11);
        label_43->setObjectName(QStringLiteral("label_43"));
        label_43->setGeometry(QRect(300, 350, 41, 20));
        pb_supprimer = new QPushButton(tab_11);
        pb_supprimer->setObjectName(QStringLiteral("pb_supprimer"));
        pb_supprimer->setGeometry(QRect(570, 350, 91, 31));
        pb_supprimer->setIcon(icon1);
        triecommande = new QComboBox(tab_11);
        triecommande->setObjectName(QStringLiteral("triecommande"));
        triecommande->setGeometry(QRect(290, 390, 73, 22));
        linecomande = new QLineEdit(tab_11);
        linecomande->setObjectName(QStringLiteral("linecomande"));
        linecomande->setGeometry(QRect(380, 460, 181, 31));
        rech_but = new QPushButton(tab_11);
        rech_but->setObjectName(QStringLiteral("rech_but"));
        rech_but->setGeometry(QRect(570, 457, 101, 31));
        rech_but->setIcon(icon2);
        modifiercom = new QPushButton(tab_11);
        modifiercom->setObjectName(QStringLiteral("modifiercom"));
        modifiercom->setGeometry(QRect(50, 240, 101, 28));
        modifiercom->setIcon(icon3);
        recombo = new QComboBox(tab_11);
        recombo->setObjectName(QStringLiteral("recombo"));
        recombo->setGeometry(QRect(290, 470, 73, 21));
        label_24 = new QLabel(tab_11);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setGeometry(QRect(0, 0, 821, 581));
        label_24->setStyleSheet(QLatin1String("background-color:tranparent;\n"
"\n"
"border-image:url(:/StyleSheet/11.jpg);\n"
"\n"
"background:none;\n"
"\n"
"border:none;\n"
"\n"
"background-repeat:none;"));
        pushButton_3 = new QPushButton(tab_11);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(50, 280, 101, 28));
        pushButton_3->setIcon(icon4);
        triercom = new QPushButton(tab_11);
        triercom->setObjectName(QStringLiteral("triercom"));
        triercom->setGeometry(QRect(570, 390, 93, 28));
        triercom->setIcon(icon5);
        decend = new QRadioButton(tab_11);
        decend->setObjectName(QStringLiteral("decend"));
        decend->setGeometry(QRect(430, 390, 97, 20));
        asend = new QRadioButton(tab_11);
        asend->setObjectName(QStringLiteral("asend"));
        asend->setGeometry(QRect(430, 420, 97, 20));
        label_26 = new QLabel(tab_11);
        label_26->setObjectName(QStringLiteral("label_26"));
        label_26->setGeometry(QRect(10, 200, 141, 16));
        combotype = new QComboBox(tab_11);
        combotype->setObjectName(QStringLiteral("combotype"));
        combotype->setGeometry(QRect(170, 200, 111, 22));
        pushButton = new QPushButton(tab_11);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(600, 310, 93, 28));
        label_28 = new QLabel(tab_11);
        label_28->setObjectName(QStringLiteral("label_28"));
        label_28->setGeometry(QRect(360, 310, 56, 16));
        total = new QLabel(tab_11);
        total->setObjectName(QStringLiteral("total"));
        total->setGeometry(QRect(420, 310, 56, 16));
        QFont font3;
        font3.setPointSize(10);
        font3.setBold(true);
        font3.setUnderline(true);
        font3.setWeight(75);
        total->setFont(font3);
        total->setTabletTracking(false);
        total->setAcceptDrops(false);
        total->setStyleSheet(QLatin1String("background-color:tranparent;\n"
"\n"
"border-image:url(:/StyleSheet/11.jpg);\n"
"\n"
"background:none;\n"
"\n"
"border:none;\n"
"\n"
"background-repeat:none;"));
        label_dt = new QLabel(tab_11);
        label_dt->setObjectName(QStringLiteral("label_dt"));
        label_dt->setGeometry(QRect(510, 310, 71, 16));
        label_dt->setStyleSheet(QLatin1String("background-color:tranparent;\n"
"\n"
"border-image:url(:/StyleSheet/11.jpg);\n"
"\n"
"background:none;\n"
"\n"
"border:none;\n"
"\n"
"background-repeat:none;"));
        pushButton_5 = new QPushButton(tab_11);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(700, 270, 101, 28));
        pushButton_5->setIcon(icon6);
        clock_2 = new QLabel(tab_11);
        clock_2->setObjectName(QStringLiteral("clock_2"));
        clock_2->setGeometry(QRect(0, 10, 261, 16));
        clock_2->setFont(font2);
        date_2 = new QLabel(tab_11);
        date_2->setObjectName(QStringLiteral("date_2"));
        date_2->setGeometry(QRect(0, 40, 231, 16));
        date_2->setFont(font2);
        excel = new QPushButton(tab_11);
        excel->setObjectName(QStringLiteral("excel"));
        excel->setGeometry(QRect(600, 270, 93, 28));
        satist = new QPushButton(tab_11);
        satist->setObjectName(QStringLiteral("satist"));
        satist->setGeometry(QRect(690, 460, 93, 28));
        pdf_com = new QPushButton(tab_11);
        pdf_com->setObjectName(QStringLiteral("pdf_com"));
        pdf_com->setGeometry(QRect(490, 270, 93, 28));
        affichage2->addTab(tab_11, QString());
        label_24->raise();
        label_15->raise();
        label_17->raise();
        le_com->raise();
        le_nb->raise();
        pb_ajouter->raise();
        label_42->raise();
        le_date->raise();
        tableView_4->raise();
        le_idsupprimer_2->raise();
        label_43->raise();
        pb_supprimer->raise();
        triecommande->raise();
        linecomande->raise();
        rech_but->raise();
        modifiercom->raise();
        recombo->raise();
        pushButton_3->raise();
        triercom->raise();
        decend->raise();
        asend->raise();
        label_26->raise();
        combotype->raise();
        pushButton->raise();
        label_28->raise();
        total->raise();
        label_dt->raise();
        pushButton_5->raise();
        clock_2->raise();
        date_2->raise();
        excel->raise();
        satist->raise();
        pdf_com->raise();
        temprature->addTab(tab_2, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        layoutWidget = new QWidget(tab);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(130, 470, 331, 30));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        exitBtn = new QPushButton(layoutWidget);
        exitBtn->setObjectName(QStringLiteral("exitBtn"));

        horizontalLayout->addWidget(exitBtn);

        sendBtn = new QPushButton(layoutWidget);
        sendBtn->setObjectName(QStringLiteral("sendBtn"));

        horizontalLayout->addWidget(sendBtn);

        layoutWidget_2 = new QWidget(tab);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(130, 90, 331, 380));
        formLayout = new QFormLayout(layoutWidget_2);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::ExpandingFieldsGrow);
        formLayout->setRowWrapPolicy(QFormLayout::WrapLongRows);
        formLayout->setVerticalSpacing(9);
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_16 = new QLabel(layoutWidget_2);
        label_16->setObjectName(QStringLiteral("label_16"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_16);

        label_18 = new QLabel(layoutWidget_2);
        label_18->setObjectName(QStringLiteral("label_18"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_18);

        label_19 = new QLabel(layoutWidget_2);
        label_19->setObjectName(QStringLiteral("label_19"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_19);

        label_20 = new QLabel(layoutWidget_2);
        label_20->setObjectName(QStringLiteral("label_20"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_20);

        label_21 = new QLabel(layoutWidget_2);
        label_21->setObjectName(QStringLiteral("label_21"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_21);

        label_22 = new QLabel(layoutWidget_2);
        label_22->setObjectName(QStringLiteral("label_22"));

        formLayout->setWidget(6, QFormLayout::LabelRole, label_22);

        server = new QLineEdit(layoutWidget_2);
        server->setObjectName(QStringLiteral("server"));

        formLayout->setWidget(0, QFormLayout::FieldRole, server);

        port = new QLineEdit(layoutWidget_2);
        port->setObjectName(QStringLiteral("port"));

        formLayout->setWidget(1, QFormLayout::FieldRole, port);

        uname = new QLineEdit(layoutWidget_2);
        uname->setObjectName(QStringLiteral("uname"));

        formLayout->setWidget(2, QFormLayout::FieldRole, uname);

        paswd = new QLineEdit(layoutWidget_2);
        paswd->setObjectName(QStringLiteral("paswd"));
        paswd->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(3, QFormLayout::FieldRole, paswd);

        rcpt = new QLineEdit(layoutWidget_2);
        rcpt->setObjectName(QStringLiteral("rcpt"));

        formLayout->setWidget(4, QFormLayout::FieldRole, rcpt);

        subject = new QLineEdit(layoutWidget_2);
        subject->setObjectName(QStringLiteral("subject"));

        formLayout->setWidget(5, QFormLayout::FieldRole, subject);

        msg = new QPlainTextEdit(layoutWidget_2);
        msg->setObjectName(QStringLiteral("msg"));

        formLayout->setWidget(6, QFormLayout::FieldRole, msg);

        label_10 = new QLabel(layoutWidget_2);
        label_10->setObjectName(QStringLiteral("label_10"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_10);

        label_25 = new QLabel(tab);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setGeometry(QRect(5, -5, 831, 631));
        label_25->setStyleSheet(QLatin1String("background-color:tranparent;\n"
"\n"
"border-image:url(:/StyleSheet/11.jpg);\n"
"\n"
"background:none;\n"
"\n"
"border:none;\n"
"\n"
"background-repeat:none;"));
        temprature->addTab(tab, QString());
        label_25->raise();
        layoutWidget->raise();
        layoutWidget_2->raise();

        retranslateUi(Clicom);

        temprature->setCurrentIndex(1);
        tabWidget_2->setCurrentIndex(0);
        affichage2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Clicom);
    } // setupUi

    void retranslateUi(QDialog *Clicom)
    {
        Clicom->setWindowTitle(QApplication::translate("Clicom", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("Clicom", "<html><head/><body><p><span style=\" font-weight:600; color:#ffffff;\">nom </span></p></body></html>", Q_NULLPTR));
        label_2->setText(QApplication::translate("Clicom", "<html><head/><body><p><span style=\" font-weight:600; color:#ffffff;\">id</span></p></body></html>", Q_NULLPTR));
        label_3->setText(QApplication::translate("Clicom", "<html><head/><body><p><span style=\" font-weight:600; color:#ffffff;\">prenom</span></p></body></html>", Q_NULLPTR));
        label_4->setText(QApplication::translate("Clicom", "<html><head/><body><p><span style=\" font-weight:600; color:#ffffff;\">numero telephone</span></p></body></html>", Q_NULLPTR));
        Ajouter->setText(QApplication::translate("Clicom", "Ajouter", Q_NULLPTR));
        label_5->setText(QApplication::translate("Clicom", "<html><head/><body><p><span style=\" font-weight:600; color:#ffffff;\">id</span></p></body></html>", Q_NULLPTR));
        supprimer_3->setText(QApplication::translate("Clicom", "Supprimer", Q_NULLPTR));
        push_recherche_3->setText(QApplication::translate("Clicom", "recherche", Q_NULLPTR));
        le_recherche_3->setPlaceholderText(QApplication::translate("Clicom", "Rechercher", Q_NULLPTR));
        modifier->setText(QApplication::translate("Clicom", "modifier", Q_NULLPTR));
        trie->clear();
        trie->insertItems(0, QStringList()
         << QApplication::translate("Clicom", "id_cli", Q_NULLPTR)
         << QApplication::translate("Clicom", "nom_cli", Q_NULLPTR)
         << QApplication::translate("Clicom", "prenom_cli", Q_NULLPTR)
         << QApplication::translate("Clicom", "nombre_com", Q_NULLPTR)
        );
        rechercher_cli->clear();
        rechercher_cli->insertItems(0, QStringList()
         << QApplication::translate("Clicom", "id_cli", Q_NULLPTR)
         << QApplication::translate("Clicom", "nom_cli", Q_NULLPTR)
         << QApplication::translate("Clicom", "prenom_cli", Q_NULLPTR)
         << QApplication::translate("Clicom", "nombre_com", Q_NULLPTR)
        );
        label_23->setText(QString());
        pushButton_2->setText(QApplication::translate("Clicom", "importer", Q_NULLPTR));
        desc->setText(QApplication::translate("Clicom", "descendant", Q_NULLPTR));
        asc->setText(QApplication::translate("Clicom", "ascendant", Q_NULLPTR));
        trierClient->setText(QApplication::translate("Clicom", "trier", Q_NULLPTR));
        label_9->setText(QApplication::translate("Clicom", "<html><head/><body><p><span style=\" font-weight:600; color:#ffffff;\">adresse</span></p></body></html>", Q_NULLPTR));
        acualiser_1->setText(QApplication::translate("Clicom", "actualiser", Q_NULLPTR));
        date->setText(QApplication::translate("Clicom", "<html><head/><body><p><span style=\" font-weight:600; color:#ff0000;\">date</span></p></body></html>", Q_NULLPTR));
        clock->setText(QApplication::translate("Clicom", "<html><head/><body><p><span style=\" font-weight:600; color:#ff0000;\">clock</span></p><p><span style=\" font-weight:600; color:#ff0000;\"><br/></span></p></body></html>", Q_NULLPTR));
        exel_client->setText(QApplication::translate("Clicom", "exel", Q_NULLPTR));
        pdf->setText(QApplication::translate("Clicom", "pdf", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_3), QApplication::translate("Clicom", "menu", Q_NULLPTR));
        temprature->setTabText(temprature->indexOf(tab1), QApplication::translate("Clicom", "Gestion des clients", Q_NULLPTR));
        label_15->setText(QApplication::translate("Clicom", "<html><head/><body><p><span style=\" font-weight:600; color:#ffffff;\">date</span></p></body></html>", Q_NULLPTR));
        label_17->setText(QApplication::translate("Clicom", "<html><head/><body><p><span style=\" font-weight:600; color:#ffffff;\">nombre de commande</span></p></body></html>", Q_NULLPTR));
        pb_ajouter->setText(QApplication::translate("Clicom", "Ajouter", Q_NULLPTR));
        label_42->setText(QApplication::translate("Clicom", "<html><head/><body><p><span style=\" font-weight:600; color:#ffffff;\">id </span></p></body></html>", Q_NULLPTR));
        label_43->setText(QApplication::translate("Clicom", "<html><head/><body><p><span style=\" font-weight:600; color:#ffffff;\">id </span></p></body></html>", Q_NULLPTR));
        pb_supprimer->setText(QApplication::translate("Clicom", "Supprimer", Q_NULLPTR));
        triecommande->clear();
        triecommande->insertItems(0, QStringList()
         << QApplication::translate("Clicom", "id_com", Q_NULLPTR)
         << QApplication::translate("Clicom", "date_com", Q_NULLPTR)
         << QApplication::translate("Clicom", "nombre_come", Q_NULLPTR)
        );
        rech_but->setText(QApplication::translate("Clicom", "rechercher", Q_NULLPTR));
        modifiercom->setText(QApplication::translate("Clicom", "modifier", Q_NULLPTR));
        recombo->clear();
        recombo->insertItems(0, QStringList()
         << QApplication::translate("Clicom", "id_com", Q_NULLPTR)
         << QApplication::translate("Clicom", "date_com", Q_NULLPTR)
         << QApplication::translate("Clicom", "nombre_come", Q_NULLPTR)
        );
        label_24->setText(QString());
        pushButton_3->setText(QApplication::translate("Clicom", "importer", Q_NULLPTR));
        triercom->setText(QApplication::translate("Clicom", "trier", Q_NULLPTR));
        decend->setText(QApplication::translate("Clicom", "descendant", Q_NULLPTR));
        asend->setText(QApplication::translate("Clicom", "ascendant", Q_NULLPTR));
        label_26->setText(QApplication::translate("Clicom", "<html><head/><body><p><span style=\" font-weight:600; color:#ffffff;\">type de commande</span></p></body></html>", Q_NULLPTR));
        combotype->clear();
        combotype->insertItems(0, QStringList()
         << QApplication::translate("Clicom", "a emporter", Q_NULLPTR)
         << QApplication::translate("Clicom", "sur place", Q_NULLPTR)
        );
        pushButton->setText(QApplication::translate("Clicom", "Total", Q_NULLPTR));
        label_28->setText(QApplication::translate("Clicom", "<html><head/><body><p><span style=\" font-weight:600; color:#ffffff;\">Total:</span></p></body></html>", Q_NULLPTR));
        total->setText(QApplication::translate("Clicom", "<html><head/><body><p><span style=\" color:#ffffff;\"><br/></span></p></body></html>", Q_NULLPTR));
        label_dt->setText(QApplication::translate("Clicom", "<html><head/><body><p><span style=\" font-weight:600; color:#000000;\">commande</span></p></body></html>", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("Clicom", "actualier", Q_NULLPTR));
        clock_2->setText(QApplication::translate("Clicom", "clock", Q_NULLPTR));
        date_2->setText(QApplication::translate("Clicom", "<html><head/><body><p>date</p></body></html>", Q_NULLPTR));
        excel->setText(QApplication::translate("Clicom", "excel", Q_NULLPTR));
        satist->setText(QApplication::translate("Clicom", "staistique", Q_NULLPTR));
        pdf_com->setText(QApplication::translate("Clicom", "pdf", Q_NULLPTR));
        affichage2->setTabText(affichage2->indexOf(tab_11), QApplication::translate("Clicom", "menu", Q_NULLPTR));
        temprature->setTabText(temprature->indexOf(tab_2), QApplication::translate("Clicom", "Gestion des commandes", Q_NULLPTR));
        exitBtn->setText(QApplication::translate("Clicom", "Exit", Q_NULLPTR));
        sendBtn->setText(QApplication::translate("Clicom", "Send", Q_NULLPTR));
        label_16->setText(QApplication::translate("Clicom", "Server port:", Q_NULLPTR));
        label_18->setText(QApplication::translate("Clicom", "Username:", Q_NULLPTR));
        label_19->setText(QApplication::translate("Clicom", "Password:", Q_NULLPTR));
        label_20->setText(QApplication::translate("Clicom", "Recipant to:", Q_NULLPTR));
        label_21->setText(QApplication::translate("Clicom", "Subject:", Q_NULLPTR));
        label_22->setText(QApplication::translate("Clicom", "Message:", Q_NULLPTR));
        server->setText(QApplication::translate("Clicom", "smtp.gmail.com", Q_NULLPTR));
        port->setText(QApplication::translate("Clicom", "465", Q_NULLPTR));
        paswd->setInputMask(QString());
        label_10->setText(QApplication::translate("Clicom", "Smtp-server:", Q_NULLPTR));
        label_25->setText(QString());
        temprature->setTabText(temprature->indexOf(tab), QApplication::translate("Clicom", "mailling", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Clicom: public Ui_Clicom {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLICOM_H
