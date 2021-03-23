#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QTabWidget>
#include <QMessageBox>
#include <QString>
#include <QSqlQuery>
#include <QPixmap>
#include"QSqlRecord"
#include"QSqlQuery"
#include "livreur.h"
#include "livraison.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
        ui->numtel->setValidator(new QIntValidator(0, 9999999, this));
        ui->salaire->setValidator(new QIntValidator(0, 9999999, this));
        ui->tab_liv_2->setModel(l.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_ajouter1_clicked()
{
    QString nom = ui->nom->text();
        QString prenom = ui->prenom->text();
        int numtel = ui->numtel->text().toInt();
        int salaire = ui->salaire->text().toInt();
        livreur l(nom, prenom,numtel,salaire);
        bool test=l.ajouter();
        QMessageBox msgBox;
     if(test)
          {  msgBox.setText("Ajout avec succes.");
            ui->tab_liv_2->setModel(l.afficher());
        }
        else
            msgBox.setText("Echec d'ajout");
            msgBox.exec();
    }


void MainWindow::on_supprimer_2_clicked()
{
    livreur l; l.setid(ui->id->text().toInt());
        bool test=l.supprimer(l.getid());
        QMessageBox msgBox;
    if(test)
           { msgBox.setText("Suppression avec succes.");
        ui->tab_liv_2->setModel(l.afficher());
}

   else
       msgBox.setText("Echec de suppression");
       msgBox.exec();
       }

void MainWindow::on_modifier3_clicked()
{
    int id = ui->id->text().toInt();
    int salaire = ui->salaire->text().toInt();
      QString nom = ui->nom->text();
      QString prenom =ui->prenom->text();
      int numtel = ui->numtel->text().toInt();
      livreur l(nom,prenom,numtel,salaire);
         bool test = l.modif(id,nom,prenom,numtel,salaire);
      if (test)
      {
                  QMessageBox::information(nullptr, QObject::tr("database is open"),
                  QObject::tr("livreur modifié.\n"
             "Click Cancel to exit."), QMessageBox::Cancel);
      }
}

void MainWindow::on_Ajouter_clicked()
{
    QString adrlivraison = ui->adrlivraison->text();
      QString datelivraison = ui->datelivraison->text();
livraison liv(adrlivraison,datelivraison);
    bool test=liv.ajouter();
    QMessageBox msgBox;
    if(test)
        {  msgBox.setText("Ajout avec succes.");
          ui->tab_livr->setModel(liv.afficher());
      }
      else
          msgBox.setText("Echec d'ajout");
          msgBox.exec();
}

void MainWindow::on_supprimer_clicked()
{
    livraison liv; liv.setid(ui->idsupprimer->text().toInt());
        bool test=liv.supprimer(liv.getid());
        QMessageBox msgBox;
    if(test)
          { msgBox.setText("Suppression avec succes.");
       ui->tab_livr->setModel(liv.afficher());

       }
       else
           msgBox.setText("Echec de suppression");
           msgBox.exec();
}
