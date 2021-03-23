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
#include <QTabWidget>
#include <QMessageBox>
#include <QPixmap>
#include <QTextDocument>
#include <QTextStream>
#include"QDate"
#include <iostream>
#include"QSqlRecord"
#include"QSqlQuery"
#include <QPrintDialog>
#include <QPrinter>
#include <QSystemTrayIcon>
#include <QFileDialog>
#include <QFile>
#include <QFileInfo>

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
    int id = ui->id_2->text().toInt();
        QString nom = ui->nom_2->text();
        QString prenom =ui->prenom_2->text();
        int numtel =ui->numtel_3->text().toInt();
        int salaire =ui->salaire_2->text().toInt();
        livreur l(nom,prenom,numtel,salaire);
           bool test = l.modif(id,nom,prenom,numtel,salaire);
        if (test)

        {
                    QMessageBox::information(nullptr, QObject::tr("database is open"),
                                QObject::tr("livraison modifiée.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
        }
  ui->tab_liv_2->setModel(l.afficher());

}

void MainWindow::on_Ajouter_clicked()
{
    QString adrlivraison = ui->adrlivraison->text();
      QString datelivraison = ui->datelivraison->text();
livraison liv(adrlivraison,datelivraison);
    bool test=liv.ajouter();
    QMessageBox msgBox;
    if(test)
        {  notif n("ajouté avec succés","livraison ajoutée");
        n.afficher();
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
          {  notif n("supprimé avec succés","livraison supprimée");
        n.afficher();
       ui->tab_livr->setModel(liv.afficher());

       }
       else
        notif n("echec de suppression ","livraison non supprimée");
               n.afficher();
           msgBox.exec();
}

void MainWindow::on_PDF_clicked()
{
    QString strStream;
                       QTextStream out(&strStream);

                       const int rowCount = ui->tab_livr->model()->rowCount();
                       const int columnCount = ui->tab_livr->model()->columnCount();

                       out <<  "<html>\n"
                           "<head>\n"
                           "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                           <<  QString("<title>%1</title>\n").arg("strTitle")
                           <<  "</head>\n"
                           "<body bgcolor=#ffffff link=#5000A0>\n"

                          //     "<align='right'> " << datefich << "</align>"
                           "<center> <H1>Liste des stocks </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                       // headers
                       out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                       for (int column = 0; column < columnCount; column++)
                           if (!ui->tab_livr->isColumnHidden(column))
                               out << QString("<th>%1</th>").arg(ui->tab_livr->model()->headerData(column, Qt::Horizontal).toString());
                       out << "</tr></thead>\n";

                       // data table
                       for (int row = 0; row < rowCount; row++) {
                           out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                           for (int column = 0; column < columnCount; column++) {
                               if (!ui->tab_livr->isColumnHidden(column)) {
                                   QString data = ui->tab_livr->model()->data(ui->tab_livr->model()->index(row, column)).toString().simplified();
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

void MainWindow::on_pushButton_3_clicked()
{
     ui->tab_livr->setModel(liv.afficher());
}

void MainWindow::on_commandLinkButton_clicked()
{
    QSqlQueryModel *modal=new QSqlQueryModel();
            QSqlQuery request;
         QString type=ui->cb_recherche->currentText();
           QString val=ui->le_recherche->text();
           val="%"+val+"%";
           if (type=="id_livr"){
    request.prepare("SELECT * FROM livraison WHERE id LIKE:val order by id");
           }
           else if (type=="adresse"){
                request.prepare("SELECT * FROM livraison WHERE adr LIKE:val order by adr");
           }
           else if (type=="date"){
               request.prepare("SELECT * FROM livraison WHERE datee LIKE:val order by datee");
           }

           request.bindValue(":val",val);
           request.exec();
           modal->setQuery(request);
           ui->tab_livr->setModel(modal);

}

void MainWindow::on_colone_tri_activated(const QString &arg1)
{

    QString type=arg1;
      QString val=ui->le_recherche->text();
      val="%"+val+"%";
      if (type=="id_livr"){
          QSqlQueryModel * modal= new QSqlQueryModel();
          QSqlQuery request;
              request.prepare("select * from livraison order by id DESC");
              request.exec();
              modal->setQuery(request);
              ui->tab_livr->setModel(modal);    }
      else if (type=="adresse"){
          QSqlQueryModel * modal= new QSqlQueryModel();
          QSqlQuery request;
              request.prepare("select * from livraison order by adr DESC");
              request.exec();
              modal->setQuery(request);
              ui->tab_livr->setModel(modal); }else if (type=="date"){
          QSqlQueryModel * modal= new QSqlQueryModel();
          QSqlQuery request;
              request.prepare("select * from livraison order by datee DESC");
              request.exec();
              modal->setQuery(request);
              ui->tab_livr->setModel(modal);
  }
}

void MainWindow::on_commandLinkButton_2_clicked()
{
    QSqlQueryModel *modal=new QSqlQueryModel();
            QSqlQuery request;
         QString type=ui->cb_recherche_2->currentText();
           QString val=ui->rech->text();
           val="%"+val+"%";
           if (type=="id_livreur"){
    request.prepare("SELECT * FROM livreur WHERE id LIKE:val order by id");
           }
           else if (type=="nom_liv"){
                request.prepare("SELECT * FROM livreur WHERE nom LIKE:val order by nom");
           }
           else if (type=="prenom_liv"){
               request.prepare("SELECT * FROM livreur WHERE prenom LIKE:val order by prenom");
           }
           else if (type=="num_tel"){
               request.prepare("SELECT * FROM livreur WHERE numtel LIKE:val order by numtel");
           }
           else if (type=="salaire"){
               request.prepare("SELECT * FROM livreur WHERE salaire LIKE:val order by salaire");
           }

           request.bindValue(":val",val);
           request.exec();
           modal->setQuery(request);
           ui->tab_liv_2->setModel(modal);
}

void MainWindow::on_pushButton_4_clicked()
{
     ui->tab_liv_2->setModel(l.afficher());
}

void MainWindow::on_colone_tri_2_activated(const QString &arg1)
{
    QString type=arg1;
      QString val=ui->le_recherche->text();
      val="%"+val+"%";
      if (type=="id_livreur"){
          QSqlQueryModel * modal= new QSqlQueryModel();
          QSqlQuery request;
              request.prepare("select * from livreur order by id DESC");
              request.exec();
              modal->setQuery(request);
              ui->tab_liv_2->setModel(modal);    }
            else if (type=="nom_liv"){

           QSqlQueryModel * modal= new QSqlQueryModel();
           QSqlQuery request;
               request.prepare("select * from livreur order by nom DESC");
               request.exec();
               modal->setQuery(request);
               ui->tab_liv_2->setModel(modal);
      }
      else if (type=="prenom_liv"){
          QSqlQueryModel * modal= new QSqlQueryModel();
          QSqlQuery request;
              request.prepare("select * from livreur order by prenom DESC");
              request.exec();
              modal->setQuery(request);
              ui->tab_liv_2->setModel(modal);
      }
      else if (type=="num_tel"){
          QSqlQueryModel * modal= new QSqlQueryModel();
          QSqlQuery request;
              request.prepare("select * from livreur order by numtel DESC");
              request.exec();
              modal->setQuery(request);
              ui->tab_liv_2->setModel(modal);
      }
      else if (type=="salaire"){
          QSqlQueryModel * modal= new QSqlQueryModel();
          QSqlQuery request;
              request.prepare("select * from livreur order by salaire DESC");
              request.exec();
              modal->setQuery(request);
              ui->tab_liv_2->setModel(modal);
      }

}

void MainWindow::on_PDF_2_clicked()
{
    QString strStream;
                       QTextStream out(&strStream);

                       const int rowCount = ui->tab_liv_2->model()->rowCount();
                       const int columnCount = ui->tab_liv_2->model()->columnCount();

                       out <<  "<html>\n"
                           "<head>\n"
                           "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                           <<  QString("<title>%1</title>\n").arg("strTitle")
                           <<  "</head>\n"
                           "<body bgcolor=#ffffff link=#5000A0>\n"

                          //     "<align='right'> " << datefich << "</align>"
                           "<center> <H1>Liste des stocks </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                       // headers
                       out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                       for (int column = 0; column < columnCount; column++)
                           if (!ui->tab_liv_2->isColumnHidden(column))
                               out << QString("<th>%1</th>").arg(ui->tab_liv_2->model()->headerData(column, Qt::Horizontal).toString());
                       out << "</tr></thead>\n";

                       // data table
                       for (int row = 0; row < rowCount; row++) {
                           out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                           for (int column = 0; column < columnCount; column++) {
                               if (!ui->tab_liv_2->isColumnHidden(column)) {
                                   QString data = ui->tab_liv_2->model()->data(ui->tab_liv_2->model()->index(row, column)).toString().simplified();
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

void MainWindow::on_modifier_2_clicked()
{
    int id = ui->id_3->text().toInt();
        QString adr = ui->adresse->text();
        QString date =ui->dt->text();
        livraison l(adr,date);
           bool test = l.modifE(id,adr,date);
        if (test)

        {
                    QMessageBox::information(nullptr, QObject::tr("database is open"),
                                QObject::tr("livraison modifiée.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
        }
  ui->tab_livr->setModel(l.afficher());

}
