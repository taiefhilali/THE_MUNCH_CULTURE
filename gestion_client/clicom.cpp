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
#include<QPdfWriter>
#include <QFileDialog>
#include<QTextDocument>
#include<QFile>
#include"smtp.h"
#include <QFileDialog>
#include <QTextStream>
#include <QTextEdit>
#include <QSound>
#include <QTimer>
#include <QPrinter>
#include "stat.h"
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
 son=new QSound(":/sons/click.wav");
 qTimer=new QTimer(this);
     connect(qTimer,SIGNAL(timeout()),this,SLOT(clockTimer()));
       connect(qTimer,SIGNAL(timeout()),this,SLOT(clocktimer_2()));
     qTimer->start(100);
}

Clicom::~Clicom()
{
    delete ui;
}
void Clicom::on_Ajouter_clicked()
{
     son->play();
    int id_cli=ui->le_id->text().toInt();
    QString nom_cli=ui->le_nom->text();
    QString prenom_cli=ui->le_prenom->text();
    int num_tel=ui->le_nombre->text().toInt();
    QString adresse=ui->le_adresse->text();


 Client C(id_cli,nom_cli,prenom_cli,num_tel,adresse);
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
     son->play();
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
      son->play();
    int id_com=ui->le_com->text().toInt();
    QString date_com=ui->le_date->text();
    int nombre_come=ui->le_nb->text().toInt();
    QString type_com=ui->combotype->currentText();

 Commande F(id_com,date_com,nombre_come,type_com);
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
      son->play();
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
  son->play();
    int id_cli,num_tel;
    QString nom_cli,prenom_cli,adresse;
    id_cli=ui->le_id->text().toInt();
    nom_cli=ui->le_nom->text();
    prenom_cli=ui->le_prenom->text();
    num_tel=ui->le_nombre->text().toInt();
     adresse=ui->le_adresse->text();

    QSqlQuery qry;
    qry.prepare("update client set nom_cli=:nom_cli,prenom_cli=:prenom_cli,num_tel=:num_tel ,adresse=:adresse where id_cli=:id_cli");
    qry.bindValue(":id_cli",id_cli);
     qry.bindValue(":nom_cli",nom_cli);
    qry.bindValue(":prenom_cli",prenom_cli);
    qry.bindValue(":num_tel",num_tel);
    qry.bindValue(":adresse",adresse);



    qry.exec();
    ui->tableView_3->setModel(C.afficher());//refresh
}



void Clicom::on_modifiercom_clicked()
{  son->play();
    int id_com,nombre_come;
    QString date_com,type_com;
    id_com=ui->le_com->text().toInt();
    date_com=ui->le_date->text();
    nombre_come=ui->le_nb->text().toInt();
    type_com=ui->combotype->currentText();


    QSqlQuery qry;
    qry.prepare("update Commande set date_com=:date_com,nombre_come=:nombre_come ,type_com=:type_com where id_com=:id_com");
    qry.bindValue(":id_com",id_com);
    qry.bindValue(":date_com",date_com);
    qry.bindValue(":nombre_come",nombre_come);
    qry.bindValue(":type_com",type_com);


    qry.exec();
    ui->tableView_4->setModel(F.affichercom());//refresh

}

void Clicom::on_push_recherche_3_clicked()
{  son->play();
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
               }else if (type=="num_tel"){
                   request.prepare("SELECT * FROM client WHERE num_tel LIKE:val");
               }else if (type=="adresse"){
                   request.prepare("SELECT * FROM client WHERE adresse LIKE:val");
               }

               request.bindValue(":val",val);
               request.exec();
               modal->setQuery(request);
               ui->tableView_3->setModel(modal);
}

void Clicom::on_rech_but_clicked()
{  son->play();
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



void Clicom::on_pushButton_2_clicked()
{  son->play();
    int col = ui->tableView_3->currentIndex().column();
        int row = ui->tableView_3->currentIndex().row();

        if(col==0)
        {
            int id=C.afficher()->index(row,col).data().toInt();
            QString sql=QString("SELECT * FROM client WHERE id_cli=:id").arg(id);

        }
        ui->le_id->setText(C.afficher()->index(row,0).data().toString());
        ui->le_nom->setText(C.afficher()->index(row,1).data().toString());
        ui->le_prenom->setText(C.afficher()->index(row,2).data().toString());
        ui->le_nombre->setText(C.afficher()->index(row,3).data().toString());
        ui->le_adresse->setText(C.afficher()->index(row,4).data().toString());

}

void Clicom::on_pushButton_3_clicked()
{  son->play();
    int col = ui->tableView_4->currentIndex().column();
    int row = ui->tableView_4->currentIndex().row();

    if(col==0)
    {
        int id=F.affichercom()->index(row,col).data().toInt();
        QString sql=QString("SELECT * FROM Commande WHERE id_com=:id").arg(id);

    }
    ui->le_com->setText(F.affichercom()->index(row,0).data().toString());
    ui->le_date->setText(F.affichercom()->index(row,1).data().toString());
    ui->le_nb->setText(F.affichercom()->index(row,2).data().toString());
    ui->combotype->setCurrentText(F.affichercom()->index(row,3).data().toString());



}

void Clicom::on_trierClient_clicked()
{  son->play();
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
{  son->play();
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

void Clicom::on_pushButton_clicked()
{  son->play();
    ui->total->setNum(F.get_total());
    ui->label_dt->setText("Commandes");
}

void Clicom::on_pushButton_4_clicked()
{
    ui->temprature->setCurrentIndex(1);

}

void Clicom::on_gestiondescommandesnavbar_clicked()
{
    ui->temprature->setCurrentIndex(2);
}

void Clicom::on_mailingnavbar_clicked()
{
    ui->temprature->setCurrentIndex(3);
}


void Clicom::on_pushButton_5_clicked()
{

       ui->tableView_4->setModel(F.affichercom());
}

void Clicom::on_acualiser_1_clicked()
{  son->play();
   ui->tableView_3->setModel(C.afficher());
}
void Clicom::clockTimer()
{
    QTime clockTime=QTime::currentTime();
    ui->clock->setText(clockTime.toString(" hh : mm : ss"));
    QString date = QDate::currentDate().toString();
    ui->date->setText(date);

}
void Clicom::clocktimer_2()
{
    QTime clockTime=QTime::currentTime();
    ui->clock_2->setText(clockTime.toString(" hh : mm : ss"));
    QString date = QDate::currentDate().toString();
    ui->date_2->setText(date);

}

void Clicom::on_excel_clicked()
{
   son->play();
        QTableView *table;
                          table = ui->tableView_4;
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

void Clicom::on_exel_client_clicked()
{
    son->play();
         QTableView *table;
                           table = ui->tableView_3;
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

void Clicom::on_pdf_clicked()
{    son->play();

    QString strStream;
                          QTextStream out(&strStream);

                          const int rowCount = ui->tableView_3->model()->rowCount();
                          const int columnCount = ui->tableView_3->model()->columnCount();

                          out <<  "<html>\n"
                              "<head>\n"
                              "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                              <<  QString("<title>%1</title>\n").arg("strTitle")
                              <<  "</head>\n"
                              "<body bgcolor=#ffffff link=#5000A0>\n"

                             //     "<align='right'> " << datefich << "</align>"
                              "<center> <H1>Liste des clients </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                          // headers
                          out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                          for (int column = 0; column < columnCount; column++)
                              if (!ui->tableView_3->isColumnHidden(column))
                                  out << QString("<th>%1</th>").arg(ui->tableView_3->model()->headerData(column, Qt::Horizontal).toString());
                          out << "</tr></thead>\n";

                          // data table
                          for (int row = 0; row < rowCount; row++) {
                              out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                              for (int column = 0; column < columnCount; column++) {
                                  if (!ui->tableView_3->isColumnHidden(column)) {
                                      QString data = ui->tableView_3->model()->data(ui->tableView_3->model()->index(row, column)).toString().simplified();
                                      out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                                  }
                              }
                              out << "</tr>\n";
                          }
                          out <<  "</table> </center>\n"
                              "</body>\n"
                              "</html>\n";

                    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
                      if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

                     QPrinter printer (QPrinter::PrinterResolution);
                      printer.setOutputFormat(QPrinter::PdfFormat);
                     printer.setPaperSize(QPrinter::A4);
                    printer.setOutputFileName(fileName);

                     QTextDocument doc;
                      doc.setHtml(strStream);
                      doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
                      doc.print(&printer);
}

void Clicom::on_satist_clicked()
{    son->play();

    Stat *a=new Stat();
           a->show();
}

void Clicom::on_pdf_com_clicked()
{    son->play();

    QString strStream;
                          QTextStream out(&strStream);

                          const int rowCount = ui->tableView_4->model()->rowCount();
                          const int columnCount = ui->tableView_4->model()->columnCount();

                          out <<  "<html>\n"
                              "<head>\n"
                              "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                              <<  QString("<title>%1</title>\n").arg("strTitle")
                              <<  "</head>\n"
                              "<body bgcolor=#ffffff link=#5000A0>\n"

                             //     "<align='right'> " << datefich << "</align>"
                              "<center> <H1>Liste des commandes </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                          // headers
                          out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                          for (int column = 0; column < columnCount; column++)
                              if (!ui->tableView_4->isColumnHidden(column))
                                  out << QString("<th>%1</th>").arg(ui->tableView_4->model()->headerData(column, Qt::Horizontal).toString());
                          out << "</tr></thead>\n";

                          // data table
                          for (int row = 0; row < rowCount; row++) {
                              out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                              for (int column = 0; column < columnCount; column++) {
                                  if (!ui->tableView_4->isColumnHidden(column)) {
                                      QString data = ui->tableView_4->model()->data(ui->tableView_4->model()->index(row, column)).toString().simplified();
                                      out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                                  }
                              }
                              out << "</tr>\n";
                          }
                          out <<  "</table> </center>\n"
                              "</body>\n"
                              "</html>\n";

                    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
                      if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

                     QPrinter printer (QPrinter::PrinterResolution);
                      printer.setOutputFormat(QPrinter::PdfFormat);
                     printer.setPaperSize(QPrinter::A4);
                    printer.setOutputFileName(fileName);

                     QTextDocument doc;
                      doc.setHtml(strStream);
                      doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
                      doc.print(&printer);
}
