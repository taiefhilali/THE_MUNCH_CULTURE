#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "commande.h"
#include "client.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QTabWidget>
#include <QString>
#include <QFile>
#include <QSqlQuery>
#include <QPixmap>
#include <QDebug>
#include <QInputDialog>
#include"QSqlRecord"
#include"QSqlQuery"
#include <QSqlDatabase>
#include <QSqlError>
#include<QtPrintSupport/QPrinter>
#include<QPdfWriter>
#include <QFileDialog>
#include<QTextDocument>
#include<QFile>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
ui->le_id->setValidator(new QIntValidator(100, 999, this));
ui->tableView_3->setModel(C.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Ajouter_clicked()
{
    int id_cli=ui->le_id->text().toInt();
    QString nom_cli=ui->le_nom->text();
    QString prenom_cli=ui->le_prenom->text();
    int nombre_com=ui->le_nombre->text().toInt();
 Client C(id_cli,nom_cli,prenom_cli,nombre_com);
 bool test=C.ajouter();
 QMessageBox msgBox;

 if(test)
   {  msgBox.setText("Ajout avec succes.");
     ui->tableView_3->setModel(C.afficher());
 }
 else
     msgBox.setText("Echec d'ajout");
     msgBox.exec();
}

void MainWindow::on_supprimer_3_clicked()
{

    Client C1; C1.setid_cli(ui->le_idsupprimer->text().toInt());
    bool test=C1.supprimer(C1.getid_cli());
    QMessageBox msgBox;

    if(test)
       { msgBox.setText("Suppression avec succes.");
    ui->tableView_3->setModel(C.afficher());

    }
    else
        msgBox.setText("Echec de suppression");
        msgBox.exec();
}

void MainWindow::on_pb_ajouter_clicked()
{
    int id_com=ui->le_com->text().toInt();
    QString date_com=ui->le_date->text();
    int nombre_come=ui->le_nb->text().toInt();
 Commande F(id_com,date_com,nombre_come);
 bool test=F.ajoutercom();
 QMessageBox msgBox;

 if(test)
   {  msgBox.setText("Ajout avec succes.");
     ui->tableView_4->setModel(F.affichercom());
 }
 else
     msgBox.setText("Echec d'ajout");
     msgBox.exec();
}

void MainWindow::on_pb_supprimer_clicked()
{
     Commande C2; C2.setid_com(ui->le_idsupprimer_2->text().toInt());
    bool test=C2.supprimercom(C2.getid_com());
    QMessageBox msgBox;

    if(test)
       { msgBox.setText("Suppression avec succes.");
          ui->tableView_4->setModel(F.affichercom());
    }
    else
        msgBox.setText("Echec de suppression");
        msgBox.exec();
}








void MainWindow::on_trie_activated()
{

    Client C;
    QString choix= ui->trie->currentText();
    ui->tableView_3->setModel(C.Trier(choix));
}

void MainWindow::on_modifier_clicked()
{

    int id_cli,nombre_com;
    QString nom_cli,prenom_cli;
    id_cli=ui->idclient->text().toInt();
    nom_cli=ui->nomclient->text();
    prenom_cli=ui->prenomclient->text();
    nombre_com=ui->nombreclient->text().toInt();

    QSqlQuery qry;
    qry.prepare("update client set nom_cli=:nom_cli,prenom_cli=:prenom_cli,nombre_com=:nombre_com where id_cli=:id_cli");
    qry.bindValue(":id_cli",id_cli);
     qry.bindValue(":nom_cli",nom_cli);
    qry.bindValue(":prenom_cli",prenom_cli);
    qry.bindValue(":nombre_com",nombre_com);


    qry.exec();
    ui->tableView_3->setModel(C.afficher());//refresh
}
