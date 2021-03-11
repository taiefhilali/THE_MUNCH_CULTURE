#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QTabWidget>
#include <QMessageBox>
#include <QString>
#include <QFile>
#include <QSqlQuery>
#include <QPixmap>
#include"QSqlRecord"
#include"QSqlQuery"
#include "stocks.h"
#include "fourn.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    ui->setupUi(this);

        ui->prix->setValidator(new QIntValidator(0, 9999999, this));
        ui->quantite->setValidator(new QIntValidator(0, 9999999, this));
        ui->tab_stk_2->setModel(S.afficher());
        ui->tel->setValidator(new QIntValidator(0, 9999999, this));
        ui->tab_fourn_2->setModel(f.afficher());

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_Ajouter_clicked()
{
    QString dat = ui->dat->text();
       int prix = ui->prix->text().toInt();
       int quantite = ui->quantite->text().toInt();
       stocks S (dat, prix,quantite);
       bool test=S.ajouter();
       QMessageBox msgBox;
    if(test)
         {  msgBox.setText("Ajout avec succes.");
           ui->tab_stk_2->setModel(S.afficher());
       }
       else
           msgBox.setText("Echec d'ajout");
           msgBox.exec();
   }


void MainWindow::on_supprimer_clicked()
{
   stocks S; S.setid(ui->le_supprimer->text().toInt());
        bool test=S.supprimer(S.getid());
        QMessageBox msgBox;
        if(test)
               { msgBox.setText("Suppression avec succes.");
            ui->tab_stk_2->setModel(S.afficher());

            }
            else
                msgBox.setText("Echec de suppression");
                msgBox.exec();
}

void MainWindow::on_ajouter1_clicked()
{
    QString nom = ui->nom->text();
    QString prenom = ui->prenom->text();
       int tel = ui->tel->text().toInt();
        QString adresse = ui->adresse->text();
       fourn f (nom, prenom,tel,adresse);
       bool test=f.ajouter();
       QMessageBox msgBox;
    if(test)
         {  msgBox.setText("Ajout avec succes.");
           ui->tab_fourn_2->setModel(f.afficher());
       }
       else
           msgBox.setText("Echec d'ajout");
           msgBox.exec();
}



void MainWindow::on_supprimer_2_clicked()
{
    fourn f; f.setid(ui->le_supprimer->text().toInt());
         bool test=f.supprimer(f.getid());
         QMessageBox msgBox;
         if(test)
                { msgBox.setText("Suppression avec succes.");
             ui->tab_fourn_2->setModel(f.afficher());

             }
             else
                 msgBox.setText("Echec de suppression");
                 msgBox.exec();
}








