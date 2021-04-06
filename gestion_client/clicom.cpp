#include "clicom.h"
#include "ui_clicom.h"
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
#include "QSqlRecord"
#include "QSqlQuery"
#include <QSqlDatabase>
#include <QSqlError>
#include<QtPrintSupport/QPrinter>
#include<QPdfWriter>
#include <QFileDialog>
#include<QTextDocument>
#include<QFile>
#include"smtp.h"
#include "stato.h"

Clicom::Clicom(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Clicom)
{
 ui->setupUi(this);
ui->le_id->setValidator(new QIntValidator(100, 999, this));
ui->tableView_3->setModel(C.afficher());
ui->tableView_4->setModel(F.affichercom());
connect(ui->sendBtn, SIGNAL(clicked()),this, SLOT(sendMail()));
   connect(ui->exitBtn, SIGNAL(clicked()),this, SLOT(close()));
}

Clicom::~Clicom()
{
    delete ui;
}
void Clicom::on_Ajouter_clicked()
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

void Clicom::on_supprimer_3_clicked()
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

void Clicom::on_pb_ajouter_clicked()
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

void Clicom::on_pb_supprimer_clicked()
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



void Clicom::on_modifier_clicked()
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



void Clicom::on_modifiercom_clicked()
{
    int id_com,nombre_come;
    QString date_com;
    id_com=ui->idcom->text().toInt();
    date_com=ui->datecome->text();
    nombre_come=ui->nbcom->text().toInt();

    QSqlQuery qry;
    qry.prepare("update Commande set date_com=:date_com,nombre_come=:nombre_come where id_com=:id_com");
    qry.bindValue(":id_com",id_com);
    qry.bindValue(":date_com",date_com);
    qry.bindValue(":nombre_come",nombre_come);

    qry.exec();
    ui->tableView_4->setModel(F.affichercom());//refresh

}

void Clicom::on_push_recherche_3_clicked()
{
    QSqlQueryModel *modal=new QSqlQueryModel();
                QSqlQuery request;
               QString type=ui->rechercher_cli->currentText();
               QString val=ui->le_recherche_3->text();
               val="%"+val+"%";
               if (type=="id_cli"){
                   request.prepare("SELECT * FROM client WHERE id_cli LIKE:val ");
               }else if (type=="nom_cli"){
                   request.prepare("SELECT * FROM client WHERE nom_cli LIKE:val");
               }else if (type=="prenom_cli"){
                   request.prepare("SELECT * FROM client WHERE prenom_cli LIKE:val");
               }else if (type=="nombre_com"){
                   request.prepare("SELECT * FROM client WHERE nombre_com LIKE:val");
               }
               request.bindValue(":val",val);
               request.exec();
               modal->setQuery(request);
               ui->tableView_3->setModel(modal);
}

void Clicom::on_rech_but_clicked()
{
    QSqlQueryModel *modal=new QSqlQueryModel();
                QSqlQuery request;
               QString type=ui->recombo->currentText();
               QString val=ui->linecomande->text();
               val="%"+val+"%";
               if (type=="id_com"){
                   request.prepare("SELECT * FROM Commande WHERE id_com LIKE:val ");
               }else if (type=="date_com"){
                   request.prepare("SELECT * FROM Commande WHERE date_com LIKE:val");
               }else if (type=="nombre_come"){
                   request.prepare("SELECT * FROM Commande WHERE nombre_come LIKE:val");
               }
               request.bindValue(":val",val);
               request.exec();
               modal->setQuery(request);
               ui->tableView_4->setModel(modal);
}

void Clicom::sendMail()
{
    Smtp* smtp = new Smtp(ui->uname->text(), ui->paswd->text(), ui->server->text(), ui->port->text().toInt());
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));


    smtp->sendMail(ui->uname->text(), ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText());
}

void Clicom::mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::warning( 0, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
}

void Clicom::on_pushButton_clicked()
{
    stato *a=new stato();
             a->show();
}

void Clicom::on_pushButton_2_clicked()
{
    int col = ui->tableView_3->currentIndex().column();
        int row = ui->tableView_3->currentIndex().row();

        if(col==0)
        {
            int id=C.afficher()->index(row,col).data().toInt();
            QString sql=QString("SELECT * FROM client WHERE id_cli=:id").arg(id);

        }
        ui->idclient->setText(C.afficher()->index(row,0).data().toString());
        ui->nomclient->setText(C.afficher()->index(row,1).data().toString());
        ui->prenomclient->setText(C.afficher()->index(row,2).data().toString());
        ui->nombreclient->setText(C.afficher()->index(row,3).data().toString());

}

void Clicom::on_pushButton_3_clicked()
{
    int col = ui->tableView_4->currentIndex().column();
    int row = ui->tableView_4->currentIndex().row();

    if(col==0)
    {
        int id=F.affichercom()->index(row,col).data().toInt();
        QString sql=QString("SELECT * FROM Commande WHERE id_com=:id").arg(id);

    }
    ui->idcom->setText(F.affichercom()->index(row,0).data().toString());
    ui->datecome->setText(F.affichercom()->index(row,1).data().toString());
    ui->nbcom->setText(F.affichercom()->index(row,2).data().toString());


}

void Clicom::on_trierClient_clicked()
{
    QString critere=ui->trie->currentText();
        QString mode;
        if (ui->asc->isChecked()==true)
    {
             mode="ASC";
    }
         else if(ui-> desc->isChecked()==true)
         {
             mode="DESC";
         }
      ui->tableView_3->setModel(C.Trier(critere,mode));

}

void Clicom::on_triercom_clicked()
{
    QString critere=ui->triecommande->currentText();
        QString mode;
        if (ui->asend->isChecked()==true)
    {
             mode="ASC";
    }
         else if(ui->decend->isChecked()==true)
         {
             mode="DESC";
         }
      ui->tableView_4->setModel(F.Triercom(critere,mode));
}
