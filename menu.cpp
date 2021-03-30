#include "menu.h"
#include "ui_menu.h"
#include <QMessageBox>
#include "personnel.h"
#include "profil.h"

menu::menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::menu)
{
    ui->setupUi(this);
     ui->tableView->setModel(p.afficher());
    ui->tableView_2->setModel(e.afficher());


}

menu::~menu()
{
    delete ui;
}

void menu::on_Ajouter_clicked()
{
    QString id=ui->id->text();
    QString nom=ui->nom->text();
    QString prenom=ui->prenom->text();
    QString mdp=ui->mdp->text();
    QString date_emb=ui->date_emb->text();
    QString salaire=ui->salaire->text();
    QString type=ui->type->text();

 personnel p(id,nom,prenom,mdp,date_emb,salaire,type);
 bool test=p.ajouter();
 QMessageBox msgBox;

 if(test)
   {  msgBox.setText("Ajout avec succes.");
//     ui->tab_etudiant->setModel(E.afficher());
 }
 else
     msgBox.setText("Echec d'ajout");
     msgBox.exec();
}

void menu::on_ajouter1_clicked()

    {
        QString ID=ui->id_profil->text();
        QString login=ui->login->text();
        QString mdp=ui->mdp->text();


     profil p(ID,login,mdp);
     bool test=p.ajouter();
     QMessageBox msgBox;

     if(test)
       {  msgBox.setText("Ajout avec succes.");
    //     ui->tab_etudiant->setModel(E.afficher());
     }
     else
         msgBox.setText("Echec d'ajout");
         msgBox.exec();
    }


void menu::on_pushButton_3_clicked()
{
    profil E1; E1.setid(ui->id_profil->text());
    bool test=E1.supprimer(E1.getid());
    QMessageBox msgBox;

    if(test)
       { msgBox.setText("Suppression avec succes.");
    ui->tableView_2->setModel(E1.afficher());

    }
    else
        msgBox.setText("Echec de suppression");
        msgBox.exec();

}
