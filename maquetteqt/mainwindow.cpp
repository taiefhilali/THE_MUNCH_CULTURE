#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "revenu.h"
#include "produit.h"

#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_Ajouter_clicked()
{

        int id_rev=ui->le_id_rev->text().toInt();
        int tot_rev=ui->le_tot_rev->text().toInt();
        int id_dep=ui->le_id_dep->text().toInt();
       int tot_dep=ui->le_tot_dep->text().toInt();

    Revenu R(id_rev,tot_rev,id_dep,tot_dep);
     bool test=R.ajouter();
     QMessageBox msgBox;

     if(test)
       {  msgBox.setText("Ajout avec succes.");
         ui->tab_rev->setModel(R.afficher());
     }
     else
         msgBox.setText("Echec d'ajout");
         msgBox.exec();
    }






void MainWindow::on_supprimer_3_clicked()
{
    Revenu R1; R1.setid_rev(ui->le_id_sup->text().toInt());
    bool test=R1.supprimer(R1.getid_rev());
    QMessageBox msgBox;

    if(test)
       { msgBox.setText("Suppression avec succes.");
    ui->tab_rev->setModel(R.afficher());

    }
    else
        msgBox.setText("Echec de suppression");
        msgBox.exec();
}




void MainWindow::on_ajouter1_clicked()
{


            int id_produit=ui->le_id_produit->text().toInt();
            int tot_produit=ui->le_tot_produit->text().toInt();


        Produit P(id_produit,tot_produit);
         bool test=P.ajouter();
         QMessageBox msgBox;

         if(test)
           {  msgBox.setText("Ajout avec succes.");
             ui->tab_produit->setModel(P.afficher());
         }
         else
             msgBox.setText("Echec d'ajout");
             msgBox.exec();


}


void MainWindow::on_supprimer_2_clicked()
{
    Produit P1; P1.setid_produit(ui->le_id_supprimer->text().toInt());
    bool test=P1.supprimer(P1.getid_produit());
    QMessageBox msgBox;

    if(test)
       { msgBox.setText("Suppression avec succes.");
    ui->tab_produit->setModel(P.afficher());

    }
    else
        msgBox.setText("Echec de suppression");
        msgBox.exec();
}


