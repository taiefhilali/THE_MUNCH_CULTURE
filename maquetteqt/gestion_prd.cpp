#include "gestion_prd.h"
#include "ui_gestion_prd.h"
#include "revenu.h"
#include "depense.h"
#include "produit.h"
#include "QSqlQuery"
#include <QMessageBox>
#include <QFileDialog>
#include <QTextStream>
#include <QTextEdit>

gestion_prd::gestion_prd(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestion_prd)
{
    ui->setupUi(this);
    ui->setupUi(this);
    ui->tab_rev->setModel(R.afficher());
    ui->tab_dep->setModel(D.afficher());
    ui->tab_produit->setModel(P.afficher());

}

gestion_prd::~gestion_prd()
{
    delete ui;
}

void gestion_prd::on_Ajouter_clicked()
{

        int id_rev=ui->le_id_rev->text().toInt();
        int tot_rev=ui->le_tot_rev->text().toInt();


    Revenu R(id_rev,tot_rev);
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






void gestion_prd::on_supprimer_3_clicked()
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





void gestion_prd::on_ajouter1_clicked()
{


            int id_produit=ui->le_id_produit->text().toInt();
            int tot_produit=ui->le_tot_produit->text().toInt();
            QString type_produit=ui->le_type_produit_2->text();


        Produit P(id_produit,tot_produit,type_produit);
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


void gestion_prd::on_supprimer_2_clicked()
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









void gestion_prd::on_modifier_3_clicked()
{
    {
        int id_rev,tot_rev;


        id_rev=ui->le_id_rev_3->text().toInt();
        tot_rev=ui->le_tot_rev_2->text().toInt();

        QSqlQuery qry;
        qry.prepare("update REVENU set id_rev=:id_rev,tot_rev=:tot_rev where id_rev=:id_rev");
        qry.bindValue(":id_rev",id_rev);
        qry.bindValue(":tot_rev",tot_rev);


        qry.exec();
        ui->tab_rev->setModel(R.afficher());//refresh

    }

}








void gestion_prd::on_pushButton_3_clicked()
{
    QSqlQueryModel *modal=new QSqlQueryModel();
                QSqlQuery request;
               QString type=ui->cb_recherche_3->currentText();
               QString val=ui->le_recherche_3->text();
               val="%"+val+"%";
               if (type=="id_rev"){
                   request.prepare("SELECT * FROM REVENU WHERE id_rev LIKE:val ");
               }else if (type=="tot_rev"){
                   request.prepare("SELECT * FROM REVENU WHERE tot_rev LIKE:val");

               }
               request.bindValue(":val",val);
               request.exec();
               modal->setQuery(request);
               ui->tab_rev->setModel(modal);
}
/*void gestion_prd::on_triecommande_activated()
{
    Revenu R;
    QString choix= ui->tab_rev->currentText();
    ui->tab_rev->setModel(R.tab_rev(choix));
}*/

void gestion_prd::on_EXCEL_clicked()
{

            QTableView *table;
                              table = ui->tab_rev;
                              QString filters("mdb files (*.csv);;All files (*.*)");
                              QString defaultFilter("mdb files (*.csv)");
                              QString fileName = QFileDialog::getSaveFileName(0, "Save file", QCoreApplication::applicationDirPath(),
                                                 filters, &defaultFilter);
                              QFile file(fileName);
                              QAbstractItemModel *model =  table->model();
                              if (file.open(QFile::WriteOnly | QFile::Truncate)) {
                                  QTextStream data(&file);
                                  QStringList strList;
                                  for (int i = 0; i < model->columnCount(); i++) {
                                      if (model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString().length() > 0)
                                          strList.append("\"" + model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString() + "\"");
                                      else
                                          strList.append("");
                                  }
                                  data << strList.join(";") << "\n";
                                  for (int i = 0; i < model->rowCount(); i++) {
                                      strList.clear();
                                      for (int j = 0; j < model->columnCount(); j++) {
                                          if (model->data(model->index(i, j)).toString().length() > 0)
                                              strList.append("\"" + model->data(model->index(i, j)).toString() + "\"");
                                          else
                                              strList.append("");
                                      }
                                      data << strList.join(";") + "\n";
                                  }
                                  file.close();
                                  QMessageBox::information(this,"Exporter To  export","Exporter En  export Avec Succées ");
                              }
}

void gestion_prd::on_pushButton_1_clicked()  //ajouter depense
{


    int id_dep=ui->le_id_dep->text().toInt();
   int tot_dep=ui->le_tot_dep->text().toInt();

Depense D(id_dep,tot_dep);
 bool test=D.ajouter();
 QMessageBox msgBox;

 if(test)
   {  msgBox.setText("Ajout avec succes.");
     ui->tab_dep->setModel(D.afficher());
 }
 else
     msgBox.setText("Echec d'ajout");
     msgBox.exec();
}

void gestion_prd::on_supprimer_6_clicked()
{Depense D1; D1.setid_dep(ui->le_id_sup_3->text().toInt());
    bool test=D1.supprimer(D1.getid_dep());
    QMessageBox msgBox;

    if(test)
       { msgBox.setText("Suppression avec succes.");
    ui->tab_dep->setModel(D.afficher());

    }
    else
        msgBox.setText("Echec de suppression");
        msgBox.exec();
}



void gestion_prd::on_pushButton_2_clicked()  //modifier depense
{
    {
        int id_dep,tot_dep;

        id_dep=ui->le_id_dep_5->text().toInt();
        tot_dep=ui->le_tot_dep_2->text().toInt();


        QSqlQuery qry;
        qry.prepare("update DEPENSE set tot_dep=:tot_dep where id_dep=:id_dep");
        qry.bindValue(":id_dep",id_dep);
        qry.bindValue(":tot_dep",tot_dep);



        qry.exec();
        ui->tab_dep->setModel(D.afficher());//refresh

    }

}

void gestion_prd::on_modifier3_2_clicked() //modifier produit
{
    {
        int id_produit,tot_produit;
                QString type_produit;

        id_produit=ui->le_id_produit_3->text().toInt();
        tot_produit=ui->le_tot_produit_3->text().toInt();
        type_produit=ui->le_type_produit->text();


        QSqlQuery qry;
        qry.prepare("update PRODUIT set tot_produit=:tot_produit,type_produit=:type_produit where id_produit=:id_produit");


        qry.bindValue(":id_produit",id_produit);
        qry.bindValue(":tot_produit",tot_produit);
        qry.bindValue(":type_produit",type_produit);



        qry.exec();
        ui->tab_produit->setModel(P.afficher());//refresh

    }


}

void gestion_prd::on_pushButton_7_clicked()  //rechercher depense
{
    QSqlQueryModel *modal=new QSqlQueryModel();
                QSqlQuery request;
               QString type=ui->cb_recherche_8->currentText();
               QString val=ui->le_recherche_8->text();
               val="%"+val+"%";
               if (type=="id_dep"){
                   request.prepare("SELECT * FROM DEPENSE WHERE id_dep LIKE:val ");
               }else if (type=="tot_dep"){
                   request.prepare("SELECT * FROM DEPENSE WHERE tot_dep LIKE:val");

               }
               request.bindValue(":val",val);
               request.exec();
               modal->setQuery(request);
               ui->tab_dep->setModel(modal);
}

void gestion_prd::on_pushButton_4_clicked()
{
    QSqlQueryModel *modal=new QSqlQueryModel();
                QSqlQuery request;
               QString type=ui->cb_recherche_4->currentText();
               QString val=ui->le_recherche_4->text();
               val="%"+val+"%";
               if (type=="id_produit"){
                   request.prepare("SELECT * FROM PRODUIT WHERE id_produit LIKE:val ");
               }else if (type=="tot_produit"){
                   request.prepare("SELECT * FROM PRODUIT WHERE tot_produit LIKE:val");
               }else if (type=="type_produit"){
                   request.prepare("SELECT * FROM PRODUIT WHERE type_produit LIKE:val");
               request.bindValue(":val",val);
               request.exec();
               modal->setQuery(request);
               ui->tab_produit->setModel(modal);

}
}

void gestion_prd::on_pushButton_clicked()
{
    Revenu R;
    QString choix= ui->cb_recherche_9->currentText();
    ui->tab_rev->setModel(R.Trierrev(choix));
}

void gestion_prd::on_pushButton_8_clicked()
{
    Depense D;
    QString choix= ui->cb_recherche_8->currentText();
    ui->tab_dep->setModel(D.Trierdep(choix));

}

void gestion_prd::on_EXCEL_4_clicked()
{ QTableView *table;
    table = ui->tab_dep;
    QString filters("mdb files (*.csv);;All files (*.*)");
    QString defaultFilter("mdb files (*.csv)");
    QString fileName = QFileDialog::getSaveFileName(0, "Save file", QCoreApplication::applicationDirPath(),
                       filters, &defaultFilter);
    QFile file(fileName);
    QAbstractItemModel *model =  table->model();
    if (file.open(QFile::WriteOnly | QFile::Truncate)) {
        QTextStream data(&file);
        QStringList strList;
        for (int i = 0; i < model->columnCount(); i++) {
            if (model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString().length() > 0)
                strList.append("\"" + model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString() + "\"");
            else
                strList.append("");
        }
        data << strList.join(";") << "\n";
        for (int i = 0; i < model->rowCount(); i++) {
            strList.clear();
            for (int j = 0; j < model->columnCount(); j++) {
                if (model->data(model->index(i, j)).toString().length() > 0)
                    strList.append("\"" + model->data(model->index(i, j)).toString() + "\"");
                else
                    strList.append("");
            }
            data << strList.join(";") + "\n";
        }
        file.close();
        QMessageBox::information(this,"Exporter To  export","Exporter En  export Avec Succées ");
    }

}

void gestion_prd::on_pushButton_9_clicked()
{
    Produit P;
    QString choix= ui->trieprod->currentText();
    ui->tab_produit->setModel(P.Trierproduit(choix));

}
