/********************************************************************************
** Form generated from reading UI file 'menu.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENU_H
#define UI_MENU_H

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
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_menu
{
public:
    QTabWidget *temprature;
    QWidget *tab_4;
    QLabel *MUNCHCULTURE;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QWidget *tab1;
    QTabWidget *tabWidget_2;
    QWidget *tab_3;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *id;
    QLineEdit *salaire;
    QLineEdit *type;
    QPushButton *Ajouter;
    QLineEdit *date_emb;
    QLineEdit *nom;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *prenom;
    QLabel *label_7;
    QLineEdit *mdp;
    QWidget *tab_5;
    QTableView *table_personnel;
    QComboBox *cb_recherche;
    QLineEdit *le_recherche;
    QLineEdit *i_stock;
    QPushButton *supprimer_employee;
    QLineEdit *id_employee;
    QLabel *label_37;
    QPushButton *modifier_employee;
    QComboBox *colone_tri;
    QPushButton *button_mailing;
    QPushButton *tri_employee;
    QLineEdit *mdp_3;
    QLineEdit *type_2;
    QLabel *label_8;
    QLabel *label_9;
    QLineEdit *salaire_2;
    QLineEdit *date_emb_2;
    QLabel *label_10;
    QLineEdit *prenom_2;
    QLabel *label_11;
    QLabel *label_12;
    QLineEdit *nom_2;
    QLabel *label_13;
    QLabel *label_14;
    QWidget *tab_2;
    QTabWidget *affichage2;
    QWidget *tab_11;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QLineEdit *id_profil;
    QLineEdit *mdp_2;
    QPushButton *ajouter1;
    QLineEdit *login;
    QWidget *tab_12;
    QTableView *table_profil;
    QComboBox *cb_recherche_2;
    QLineEdit *le_recherche_2;
    QComboBox *colone_tri_2;
    QComboBox *ordre_tri_2;
    QPushButton *button_tri_2;
    QPushButton *supprimer_2;
    QLineEdit *le_supprimer_2;
    QPushButton *modifier_profil;
    QPushButton *supprimer_profil;
    QLabel *label_21;
    QLabel *label_22;
    QLineEdit *login_3;
    QLineEdit *id_profil_3;
    QLabel *label_23;
    QLineEdit *mdp_5;
    QWidget *tab;
    QWidget *layoutWidget;
    QFormLayout *formLayout;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label_24;
    QLabel *label_25;
    QLabel *label_26;
    QLabel *label_27;
    QLineEdit *server;
    QLineEdit *port;
    QLineEdit *uname;
    QLineEdit *paswd;
    QLineEdit *rcpt;
    QLineEdit *subject;
    QPlainTextEdit *msg;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *exitBtn;
    QPushButton *sendBtn;

    void setupUi(QDialog *menu)
    {
        if (menu->objectName().isEmpty())
            menu->setObjectName(QStringLiteral("menu"));
        menu->resize(967, 622);
        temprature = new QTabWidget(menu);
        temprature->setObjectName(QStringLiteral("temprature"));
        temprature->setGeometry(QRect(10, 0, 841, 701));
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        MUNCHCULTURE = new QLabel(tab_4);
        MUNCHCULTURE->setObjectName(QStringLiteral("MUNCHCULTURE"));
        MUNCHCULTURE->setGeometry(QRect(210, 40, 441, 111));
        QFont font;
        font.setPointSize(50);
        MUNCHCULTURE->setFont(font);
        pushButton = new QPushButton(tab_4);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(340, 160, 161, 51));
        pushButton_2 = new QPushButton(tab_4);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(340, 280, 161, 51));
        temprature->addTab(tab_4, QString());
        tab1 = new QWidget();
        tab1->setObjectName(QStringLiteral("tab1"));
        tabWidget_2 = new QTabWidget(tab1);
        tabWidget_2->setObjectName(QStringLiteral("tabWidget_2"));
        tabWidget_2->setGeometry(QRect(10, 10, 781, 621));
        tabWidget_2->setStyleSheet(QStringLiteral("tabWidget_2 = new QWidget(this); m_myWidget->setGeometry(0, 0, 300, 100)"));
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        label = new QLabel(tab_3);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(150, 90, 121, 16));
        label_2 = new QLabel(tab_3);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(150, 20, 121, 16));
        label_3 = new QLabel(tab_3);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(150, 150, 101, 16));
        label_4 = new QLabel(tab_3);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(160, 220, 71, 16));
        id = new QLineEdit(tab_3);
        id->setObjectName(QStringLiteral("id"));
        id->setGeometry(QRect(290, 20, 113, 20));
        id->setStyleSheet(QStringLiteral("m_myWidget = new QWidget(this); m_myWidget->setGeometry(0, 0, 300, 100); QPalette pal = palette();"));
        salaire = new QLineEdit(tab_3);
        salaire->setObjectName(QStringLiteral("salaire"));
        salaire->setGeometry(QRect(290, 150, 113, 20));
        type = new QLineEdit(tab_3);
        type->setObjectName(QStringLiteral("type"));
        type->setGeometry(QRect(290, 210, 113, 20));
        Ajouter = new QPushButton(tab_3);
        Ajouter->setObjectName(QStringLiteral("Ajouter"));
        Ajouter->setGeometry(QRect(510, 250, 75, 23));
        date_emb = new QLineEdit(tab_3);
        date_emb->setObjectName(QStringLiteral("date_emb"));
        date_emb->setGeometry(QRect(290, 90, 113, 20));
        nom = new QLineEdit(tab_3);
        nom->setObjectName(QStringLiteral("nom"));
        nom->setGeometry(QRect(290, 270, 113, 22));
        label_5 = new QLabel(tab_3);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(160, 280, 55, 16));
        label_6 = new QLabel(tab_3);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(160, 340, 55, 16));
        prenom = new QLineEdit(tab_3);
        prenom->setObjectName(QStringLiteral("prenom"));
        prenom->setGeometry(QRect(290, 330, 113, 22));
        label_7 = new QLabel(tab_3);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(160, 410, 55, 16));
        mdp = new QLineEdit(tab_3);
        mdp->setObjectName(QStringLiteral("mdp"));
        mdp->setGeometry(QRect(290, 400, 113, 22));
        tabWidget_2->addTab(tab_3, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        table_personnel = new QTableView(tab_5);
        table_personnel->setObjectName(QStringLiteral("table_personnel"));
        table_personnel->setGeometry(QRect(20, 60, 471, 301));
        cb_recherche = new QComboBox(tab_5);
        cb_recherche->setObjectName(QStringLiteral("cb_recherche"));
        cb_recherche->setGeometry(QRect(500, 50, 141, 22));
        le_recherche = new QLineEdit(tab_5);
        le_recherche->setObjectName(QStringLiteral("le_recherche"));
        le_recherche->setGeometry(QRect(660, 50, 113, 20));
        i_stock = new QLineEdit(tab_5);
        i_stock->setObjectName(QStringLiteral("i_stock"));
        i_stock->setGeometry(QRect(510, 140, 131, 20));
        supprimer_employee = new QPushButton(tab_5);
        supprimer_employee->setObjectName(QStringLiteral("supprimer_employee"));
        supprimer_employee->setGeometry(QRect(690, 140, 75, 23));
        id_employee = new QLineEdit(tab_5);
        id_employee->setObjectName(QStringLiteral("id_employee"));
        id_employee->setGeometry(QRect(220, 370, 113, 20));
        id_employee->setStyleSheet(QStringLiteral("m_myWidget = new QWidget(this); m_myWidget->setGeometry(0, 0, 300, 100); QPalette pal = palette();"));
        label_37 = new QLabel(tab_5);
        label_37->setObjectName(QStringLiteral("label_37"));
        label_37->setGeometry(QRect(80, 370, 121, 16));
        modifier_employee = new QPushButton(tab_5);
        modifier_employee->setObjectName(QStringLiteral("modifier_employee"));
        modifier_employee->setGeometry(QRect(370, 370, 75, 23));
        colone_tri = new QComboBox(tab_5);
        colone_tri->setObjectName(QStringLiteral("colone_tri"));
        colone_tri->setGeometry(QRect(580, 90, 91, 22));
        button_mailing = new QPushButton(tab_5);
        button_mailing->setObjectName(QStringLiteral("button_mailing"));
        button_mailing->setGeometry(QRect(690, 90, 75, 23));
        tri_employee = new QPushButton(tab_5);
        tri_employee->setObjectName(QStringLiteral("tri_employee"));
        tri_employee->setGeometry(QRect(664, 180, 101, 23));
        mdp_3 = new QLineEdit(tab_5);
        mdp_3->setObjectName(QStringLiteral("mdp_3"));
        mdp_3->setGeometry(QRect(400, 519, 113, 22));
        type_2 = new QLineEdit(tab_5);
        type_2->setObjectName(QStringLiteral("type_2"));
        type_2->setGeometry(QRect(220, 460, 113, 20));
        label_8 = new QLabel(tab_5);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(80, 490, 55, 16));
        label_9 = new QLabel(tab_5);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(80, 400, 121, 16));
        salaire_2 = new QLineEdit(tab_5);
        salaire_2->setObjectName(QStringLiteral("salaire_2"));
        salaire_2->setGeometry(QRect(220, 430, 113, 20));
        date_emb_2 = new QLineEdit(tab_5);
        date_emb_2->setObjectName(QStringLiteral("date_emb_2"));
        date_emb_2->setGeometry(QRect(220, 400, 113, 20));
        label_10 = new QLabel(tab_5);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(80, 460, 71, 16));
        prenom_2 = new QLineEdit(tab_5);
        prenom_2->setObjectName(QStringLiteral("prenom_2"));
        prenom_2->setGeometry(QRect(220, 520, 113, 22));
        label_11 = new QLabel(tab_5);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(80, 430, 101, 16));
        label_12 = new QLabel(tab_5);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(360, 520, 55, 16));
        nom_2 = new QLineEdit(tab_5);
        nom_2->setObjectName(QStringLiteral("nom_2"));
        nom_2->setGeometry(QRect(220, 490, 113, 22));
        label_13 = new QLabel(tab_5);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(80, 520, 55, 16));
        label_14 = new QLabel(tab_5);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(510, 90, 55, 16));
        tabWidget_2->addTab(tab_5, QString());
        temprature->addTab(tab1, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        affichage2 = new QTabWidget(tab_2);
        affichage2->setObjectName(QStringLiteral("affichage2"));
        affichage2->setGeometry(QRect(20, 10, 771, 601));
        tab_11 = new QWidget();
        tab_11->setObjectName(QStringLiteral("tab_11"));
        label_15 = new QLabel(tab_11);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(20, 40, 47, 14));
        label_16 = new QLabel(tab_11);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(20, 10, 121, 16));
        label_17 = new QLabel(tab_11);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(20, 70, 121, 16));
        id_profil = new QLineEdit(tab_11);
        id_profil->setObjectName(QStringLiteral("id_profil"));
        id_profil->setGeometry(QRect(150, 10, 113, 20));
        mdp_2 = new QLineEdit(tab_11);
        mdp_2->setObjectName(QStringLiteral("mdp_2"));
        mdp_2->setGeometry(QRect(150, 70, 113, 20));
        ajouter1 = new QPushButton(tab_11);
        ajouter1->setObjectName(QStringLiteral("ajouter1"));
        ajouter1->setGeometry(QRect(370, 80, 75, 23));
        login = new QLineEdit(tab_11);
        login->setObjectName(QStringLiteral("login"));
        login->setGeometry(QRect(150, 40, 113, 20));
        affichage2->addTab(tab_11, QString());
        tab_12 = new QWidget();
        tab_12->setObjectName(QStringLiteral("tab_12"));
        table_profil = new QTableView(tab_12);
        table_profil->setObjectName(QStringLiteral("table_profil"));
        table_profil->setGeometry(QRect(20, 10, 441, 261));
        cb_recherche_2 = new QComboBox(tab_12);
        cb_recherche_2->setObjectName(QStringLiteral("cb_recherche_2"));
        cb_recherche_2->setGeometry(QRect(480, 30, 141, 22));
        le_recherche_2 = new QLineEdit(tab_12);
        le_recherche_2->setObjectName(QStringLiteral("le_recherche_2"));
        le_recherche_2->setGeometry(QRect(630, 30, 113, 20));
        colone_tri_2 = new QComboBox(tab_12);
        colone_tri_2->setObjectName(QStringLiteral("colone_tri_2"));
        colone_tri_2->setGeometry(QRect(480, 70, 91, 22));
        ordre_tri_2 = new QComboBox(tab_12);
        ordre_tri_2->setObjectName(QStringLiteral("ordre_tri_2"));
        ordre_tri_2->setGeometry(QRect(590, 70, 51, 22));
        button_tri_2 = new QPushButton(tab_12);
        button_tri_2->setObjectName(QStringLiteral("button_tri_2"));
        button_tri_2->setGeometry(QRect(660, 70, 75, 23));
        supprimer_2 = new QPushButton(tab_12);
        supprimer_2->setObjectName(QStringLiteral("supprimer_2"));
        supprimer_2->setGeometry(QRect(650, 130, 75, 23));
        le_supprimer_2 = new QLineEdit(tab_12);
        le_supprimer_2->setObjectName(QStringLiteral("le_supprimer_2"));
        le_supprimer_2->setGeometry(QRect(480, 130, 131, 20));
        modifier_profil = new QPushButton(tab_12);
        modifier_profil->setObjectName(QStringLiteral("modifier_profil"));
        modifier_profil->setGeometry(QRect(380, 370, 75, 23));
        supprimer_profil = new QPushButton(tab_12);
        supprimer_profil->setObjectName(QStringLiteral("supprimer_profil"));
        supprimer_profil->setGeometry(QRect(620, 197, 111, 31));
        label_21 = new QLabel(tab_12);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(90, 330, 121, 16));
        label_22 = new QLabel(tab_12);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(90, 390, 121, 16));
        login_3 = new QLineEdit(tab_12);
        login_3->setObjectName(QStringLiteral("login_3"));
        login_3->setGeometry(QRect(220, 360, 113, 20));
        id_profil_3 = new QLineEdit(tab_12);
        id_profil_3->setObjectName(QStringLiteral("id_profil_3"));
        id_profil_3->setGeometry(QRect(220, 330, 113, 20));
        label_23 = new QLabel(tab_12);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(90, 360, 47, 14));
        mdp_5 = new QLineEdit(tab_12);
        mdp_5->setObjectName(QStringLiteral("mdp_5"));
        mdp_5->setGeometry(QRect(220, 390, 113, 20));
        affichage2->addTab(tab_12, QString());
        temprature->addTab(tab_2, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        layoutWidget = new QWidget(tab);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(380, 30, 341, 380));
        formLayout = new QFormLayout(layoutWidget);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::ExpandingFieldsGrow);
        formLayout->setRowWrapPolicy(QFormLayout::WrapLongRows);
        formLayout->setVerticalSpacing(9);
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_18 = new QLabel(layoutWidget);
        label_18->setObjectName(QStringLiteral("label_18"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_18);

        label_19 = new QLabel(layoutWidget);
        label_19->setObjectName(QStringLiteral("label_19"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_19);

        label_20 = new QLabel(layoutWidget);
        label_20->setObjectName(QStringLiteral("label_20"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_20);

        label_24 = new QLabel(layoutWidget);
        label_24->setObjectName(QStringLiteral("label_24"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_24);

        label_25 = new QLabel(layoutWidget);
        label_25->setObjectName(QStringLiteral("label_25"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_25);

        label_26 = new QLabel(layoutWidget);
        label_26->setObjectName(QStringLiteral("label_26"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_26);

        label_27 = new QLabel(layoutWidget);
        label_27->setObjectName(QStringLiteral("label_27"));

        formLayout->setWidget(6, QFormLayout::LabelRole, label_27);

        server = new QLineEdit(layoutWidget);
        server->setObjectName(QStringLiteral("server"));

        formLayout->setWidget(0, QFormLayout::FieldRole, server);

        port = new QLineEdit(layoutWidget);
        port->setObjectName(QStringLiteral("port"));

        formLayout->setWidget(1, QFormLayout::FieldRole, port);

        uname = new QLineEdit(layoutWidget);
        uname->setObjectName(QStringLiteral("uname"));

        formLayout->setWidget(2, QFormLayout::FieldRole, uname);

        paswd = new QLineEdit(layoutWidget);
        paswd->setObjectName(QStringLiteral("paswd"));
        paswd->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(3, QFormLayout::FieldRole, paswd);

        rcpt = new QLineEdit(layoutWidget);
        rcpt->setObjectName(QStringLiteral("rcpt"));

        formLayout->setWidget(4, QFormLayout::FieldRole, rcpt);

        subject = new QLineEdit(layoutWidget);
        subject->setObjectName(QStringLiteral("subject"));

        formLayout->setWidget(5, QFormLayout::FieldRole, subject);

        msg = new QPlainTextEdit(layoutWidget);
        msg->setObjectName(QStringLiteral("msg"));

        formLayout->setWidget(6, QFormLayout::FieldRole, msg);

        layoutWidget_2 = new QWidget(tab);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(410, 180, 242, 30));
        horizontalLayout = new QHBoxLayout(layoutWidget_2);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        exitBtn = new QPushButton(tab);
        exitBtn->setObjectName(QStringLiteral("exitBtn"));
        exitBtn->setGeometry(QRect(270, 160, 93, 28));
        sendBtn = new QPushButton(tab);
        sendBtn->setObjectName(QStringLiteral("sendBtn"));
        sendBtn->setGeometry(QRect(170, 160, 93, 28));
        temprature->addTab(tab, QString());

        retranslateUi(menu);

        temprature->setCurrentIndex(0);
        tabWidget_2->setCurrentIndex(1);
        affichage2->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(menu);
    } // setupUi

    void retranslateUi(QDialog *menu)
    {
        menu->setWindowTitle(QApplication::translate("menu", "Dialog", Q_NULLPTR));
        MUNCHCULTURE->setText(QApplication::translate("menu", "<html><head/><body><p align=\"center\"><span style=\" font-size:26pt; color:#845f64;\">MUNCH CULTURE</span></p></body></html>", Q_NULLPTR));
        pushButton->setText(QApplication::translate("menu", "GESTION DES EMPLOYEE", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("menu", "GESTION PROFILS", Q_NULLPTR));
        temprature->setTabText(temprature->indexOf(tab_4), QApplication::translate("menu", "home", Q_NULLPTR));
        label->setText(QApplication::translate("menu", "date_emb", Q_NULLPTR));
        label_2->setText(QApplication::translate("menu", "Id_employee", Q_NULLPTR));
        label_3->setText(QApplication::translate("menu", "salaire", Q_NULLPTR));
        label_4->setText(QApplication::translate("menu", "type", Q_NULLPTR));
        Ajouter->setText(QApplication::translate("menu", "Ajouter", Q_NULLPTR));
        label_5->setText(QApplication::translate("menu", "nom", Q_NULLPTR));
        label_6->setText(QApplication::translate("menu", "prenom", Q_NULLPTR));
        label_7->setText(QApplication::translate("menu", "mdp", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_3), QApplication::translate("menu", "Ajout", Q_NULLPTR));
        cb_recherche->clear();
        cb_recherche->insertItems(0, QStringList()
         << QApplication::translate("menu", "Id_employee", Q_NULLPTR)
         << QApplication::translate("menu", "date naissance employee", Q_NULLPTR)
         << QApplication::translate("menu", "adressse", Q_NULLPTR)
         << QApplication::translate("menu", "numero de tel ", Q_NULLPTR)
        );
        le_recherche->setPlaceholderText(QApplication::translate("menu", "Rechercher", Q_NULLPTR));
        i_stock->setPlaceholderText(QApplication::translate("menu", "id_stock", Q_NULLPTR));
        supprimer_employee->setText(QApplication::translate("menu", "Supprimer", Q_NULLPTR));
        label_37->setText(QApplication::translate("menu", "Id_employee", Q_NULLPTR));
        modifier_employee->setText(QApplication::translate("menu", "modifier", Q_NULLPTR));
        colone_tri->clear();
        colone_tri->insertItems(0, QStringList()
         << QApplication::translate("menu", "Id_employee", Q_NULLPTR)
         << QApplication::translate("menu", "date de naissance employee", Q_NULLPTR)
         << QApplication::translate("menu", "adresse", Q_NULLPTR)
         << QApplication::translate("menu", "num de tel", Q_NULLPTR)
        );
        button_mailing->setText(QApplication::translate("menu", "mailing", Q_NULLPTR));
        tri_employee->setText(QApplication::translate("menu", "tri selon id", Q_NULLPTR));
        label_8->setText(QApplication::translate("menu", "nom", Q_NULLPTR));
        label_9->setText(QApplication::translate("menu", "date_emb", Q_NULLPTR));
        label_10->setText(QApplication::translate("menu", "type", Q_NULLPTR));
        label_11->setText(QApplication::translate("menu", "salaire", Q_NULLPTR));
        label_12->setText(QApplication::translate("menu", "mdp", Q_NULLPTR));
        label_13->setText(QApplication::translate("menu", "prenom", Q_NULLPTR));
        label_14->setText(QApplication::translate("menu", "tri", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_5), QApplication::translate("menu", "Affichage", Q_NULLPTR));
        temprature->setTabText(temprature->indexOf(tab1), QApplication::translate("menu", "Gestion des employee", Q_NULLPTR));
        label_15->setText(QApplication::translate("menu", "login", Q_NULLPTR));
        label_16->setText(QApplication::translate("menu", "ID_profil", Q_NULLPTR));
        label_17->setText(QApplication::translate("menu", "mdp", Q_NULLPTR));
        ajouter1->setText(QApplication::translate("menu", "Ajouter", Q_NULLPTR));
        affichage2->setTabText(affichage2->indexOf(tab_11), QApplication::translate("menu", "Ajout", Q_NULLPTR));
        cb_recherche_2->clear();
        cb_recherche_2->insertItems(0, QStringList()
         << QApplication::translate("menu", "id_profil", Q_NULLPTR)
         << QApplication::translate("menu", "date de naissance", Q_NULLPTR)
         << QApplication::translate("menu", "adresse", Q_NULLPTR)
         << QApplication::translate("menu", "numero de tel", Q_NULLPTR)
        );
        le_recherche_2->setPlaceholderText(QApplication::translate("menu", "Rechercher", Q_NULLPTR));
        colone_tri_2->clear();
        colone_tri_2->insertItems(0, QStringList()
         << QApplication::translate("menu", "id_profil", Q_NULLPTR)
         << QApplication::translate("menu", "date de naissance", Q_NULLPTR)
         << QApplication::translate("menu", "adresse", Q_NULLPTR)
         << QApplication::translate("menu", "numero de tel", Q_NULLPTR)
        );
        ordre_tri_2->clear();
        ordre_tri_2->insertItems(0, QStringList()
         << QApplication::translate("menu", "ASC", Q_NULLPTR)
         << QApplication::translate("menu", "DESC", Q_NULLPTR)
        );
        button_tri_2->setText(QApplication::translate("menu", "tri", Q_NULLPTR));
        supprimer_2->setText(QApplication::translate("menu", "mailing", Q_NULLPTR));
        le_supprimer_2->setPlaceholderText(QApplication::translate("menu", "id_f", Q_NULLPTR));
        modifier_profil->setText(QApplication::translate("menu", "Modifier", Q_NULLPTR));
        supprimer_profil->setText(QApplication::translate("menu", "supprimer", Q_NULLPTR));
        label_21->setText(QApplication::translate("menu", "ID_profil", Q_NULLPTR));
        label_22->setText(QApplication::translate("menu", "mdp", Q_NULLPTR));
        label_23->setText(QApplication::translate("menu", "login", Q_NULLPTR));
        affichage2->setTabText(affichage2->indexOf(tab_12), QApplication::translate("menu", "Affichage", Q_NULLPTR));
        temprature->setTabText(temprature->indexOf(tab_2), QApplication::translate("menu", "Gestion de profil", Q_NULLPTR));
        label_18->setText(QApplication::translate("menu", "Smtp-server:", Q_NULLPTR));
        label_19->setText(QApplication::translate("menu", "Server port:", Q_NULLPTR));
        label_20->setText(QApplication::translate("menu", "Username:", Q_NULLPTR));
        label_24->setText(QApplication::translate("menu", "Password:", Q_NULLPTR));
        label_25->setText(QApplication::translate("menu", "Recipant to:", Q_NULLPTR));
        label_26->setText(QApplication::translate("menu", "Subject:", Q_NULLPTR));
        label_27->setText(QApplication::translate("menu", "Message:", Q_NULLPTR));
        server->setText(QApplication::translate("menu", "smtp.gmail.com", Q_NULLPTR));
        port->setText(QApplication::translate("menu", "465", Q_NULLPTR));
        paswd->setInputMask(QString());
        exitBtn->setText(QApplication::translate("menu", "Exit", Q_NULLPTR));
        sendBtn->setText(QApplication::translate("menu", "Send", Q_NULLPTR));
        temprature->setTabText(temprature->indexOf(tab), QApplication::translate("menu", "Page", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class menu: public Ui_menu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENU_H
