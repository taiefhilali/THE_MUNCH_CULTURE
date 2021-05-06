#include "interw.h"
#include "ui_interw.h"
#include "mainwindowvideo.h"
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
#include <QSound>
#include <QPainter>
#include <QTimer>
interw::interw(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::interw)
{
    ui->setupUi(this);
        ui->numtel->setValidator(new QIntValidator(0, 9999999, this));
        ui->salaire->setValidator(new QIntValidator(0, 9999999, this));
        ui->tab_liv_2->setModel(l.afficher());
        son=new QSound(":/click.wav");
        son2=new QSound(":/iPhone typing on keyboard (6E7D336-WSH).wav");
        QRegExp rx("[a-zA-Z]+");
        QValidator *validator = new QRegExpValidator(rx, this);

        ui->adresse->setValidator(validator);
        ui->adrlivraison->setValidator(validator);
        ui->prenom_2->setValidator(validator);
        ui->prenom->setValidator(validator);
        ui->nom_2->setValidator(validator);
        ui->nom->setValidator(validator);
        qTimer=new QTimer(this);
            connect(qTimer,SIGNAL(timeout()),this,SLOT(clockTimer()));
              connect(qTimer,SIGNAL(timeout()),this,SLOT(clocktimer_2()));
            qTimer->start(100);

}


interw::~interw()
{
    delete ui;
}


void interw::on_ajouter1_clicked()
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


void interw::on_supprimer_2_clicked()
{
    int col = ui->tab_liv_2->currentIndex().column();
        int row = ui->tab_liv_2->currentIndex().row();
        QString sql;
        int id = l.afficher()->index(row, 0).data().toInt();
       sql= QString("DELETE FROM livreur WHERE id=%1").arg(id);
       QSqlQuery qry;
       qry.exec(sql);
       //ui->tab_livr->setModel(l.afficher());
        if(qry.exec(sql) && col>=0)
              {  notif n("supprimé avec succés","livreur supprimé");
            n.afficher();
           ui->tab_liv_2->setModel(l.afficher());

           }
           else
            notif n("echec de suppression ","livreur non supprimé");
                   n.afficher();
                   son->play();
                   son=new QSound(":/click.wav");

       }

void interw::on_modifier3_clicked()
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

void interw::on_Ajouter_2_clicked()
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
          son->play();
          son=new QSound(":/click.wav");
}

void interw::on_supprimer_clicked()
{int col = ui->tab_livr->currentIndex().column();
    int row = ui->tab_livr->currentIndex().row();
    QString sql;
    int id = liv.afficher()->index(row, 0).data().toInt();
   sql= QString("DELETE FROM livraison WHERE id=%1").arg(id);
   QSqlQuery qry;
   qry.exec(sql);
   //ui->tab_livr->setModel(l.afficher());
    if(qry.exec(sql) && col>=0)
          {  notif n("supprimé avec succés","livraison supprimée");
        n.afficher();
       ui->tab_livr->setModel(liv.afficher());

       }
       else
        notif n("echec de suppression ","livraison non supprimée");
               n.afficher();
               son->play();
               son=new QSound(":/click.wav");

}

void interw::on_PDF_clicked()
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
                   son->play();
                   son=new QSound(":/click.wav");

}

void interw::on_pushButton_3_clicked()
{
     ui->tab_livr->setModel(liv.afficher());
      son->play();
      son=new QSound(":/click.wav");
}

void interw::on_commandLinkButton_clicked()
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
           son->play();
           son=new QSound(":/click.wav");


}

void interw::on_colone_tri_activated(const QString &arg1)
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
              son->play();
              son=new QSound(":/click.wav");
  }
}

void interw::on_commandLinkButton_2_clicked()
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
           son->play();
           son=new QSound(":/click.wav");
}

void interw::on_pushButton_4_clicked()
{
     ui->tab_liv_2->setModel(l.afficher());
     son->play();
     son=new QSound(":/click.wav");
}

void interw::on_colone_tri_2_activated(const QString &arg1)
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
              son->play();
              son=new QSound(":/click.wav");
      }

}

void interw::on_PDF_2_clicked()
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
                            <<  "<img src= C:/Users/MediaHelp/Desktop/farchitaa.png width=150px height=200px />"

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
                //   QPainter painter;
                     //    painter.begin(&printer);
                      //   QImage image("C:/Users/MediaHelp/Desktop/farchitaa.jpg");
                     //          painter.drawImage(0,0,image);
                  QTextDocument doc;
                   doc.setHtml(strStream);
                   doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
                   doc.print(&printer);
                   son->play();
                   son=new QSound(":/click.wav");


}

void interw::on_modifier_2_clicked()
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
  son->play();
  son=new QSound(":/click.wav");

}

void interw::on_imprimer_2_clicked()
{
    QString strStream;
               QTextStream out(&strStream);
               const int rowCount = ui->tab_liv_2->model()->rowCount();
               const int columnCount = ui->tab_liv_2->model()->columnCount();
               for (int column = 0; column < columnCount; column++)
                   if (!ui->tab_liv_2->isColumnHidden(column)){
                       out << QString("<td>\t\t\t%1\t\t\t</td>").arg(ui->tab_liv_2->model()->headerData(column, Qt::Horizontal).toString());}
               for (int row = 0; row < rowCount; row++) {
                   out << "<tr>";
                   for (int column = 0; column < columnCount; column++) {
                       if (!ui->tab_liv_2->isColumnHidden(column)) {
                           QString data =ui->tab_liv_2->model()->data(ui->tab_liv_2->model()->index(row, column)).toString().simplified();
                           out << QString("<td bkcolor=10>\t\t\t%1\t\t\t</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                       }
                   }
               }
               QTextDocument *document = new QTextDocument();
               document->setHtml(strStream);
       QPrinter printer ;
              QPrintDialog *daddy = new QPrintDialog(&printer, NULL);
               if (daddy->exec() == QDialog::Accepted) {
                   document->print(&printer);
               }
               delete document;
               son->play();
               son=new QSound(":/click.wav");

}

void interw::on_imprimer_clicked()
{
    QString strStream;
                QTextStream out(&strStream);
                const int rowCount = ui->tab_livr->model()->rowCount();
                const int columnCount = ui->tab_livr->model()->columnCount();
                for (int column = 0; column < columnCount; column++)
                    if (!ui->tab_livr->isColumnHidden(column)){
                        out << QString("<td>\t\t\t%1\t\t\t</td>").arg(ui->tab_livr->model()->headerData(column, Qt::Horizontal).toString());}
                for (int row = 0; row < rowCount; row++) {
                    out << "<tr>";
                    for (int column = 0; column < columnCount; column++) {
                        if (!ui->tab_livr->isColumnHidden(column)) {
                            QString data =ui->tab_livr->model()->data(ui->tab_livr->model()->index(row, column)).toString().simplified();
                            out << QString("<td bkcolor=10>\t\t\t%1\t\t\t</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                        }
                    }
                }
                QTextDocument *document = new QTextDocument();
                document->setHtml(strStream);
        QPrinter printer ;
               QPrintDialog *daddy = new QPrintDialog(&printer, NULL);
                if (daddy->exec() == QDialog::Accepted) {
                    document->print(&printer);
                }
                delete document;
                son->play();
                son=new QSound(":/click.wav");
}

void interw::on_pushButton_5_clicked()
{
    int col = ui->tab_livr->currentIndex().column();
           int row = ui->tab_livr->currentIndex().row();
           QString sql;
        int id = liv.afficher()->index(row, 0).data().toInt();
        QString dt = liv.afficher()->index(row, 2).data().toString();
        QString adresse = liv.afficher()->index(row, 1).data().toString();
        QDate Date = QDate::fromString(dt,"dd/MM/yyyy");

           //int id= ui->id->text().toInt();
           QString idd=liv.afficher()->index(row, 0).data().toString();
           ui->id_3->setText(idd);
           ui->dt->setDate(Date);
           ui->adresse->setText(liv.afficher()->index(row, 1).data().toString());
           son->play();
           son=new QSound(":/click.wav");


 }



void interw::on_nom_textChanged(const QString &arg1)
{
son2->play();
}





void interw::on_excel_clicked()
{
    QTableView *table;
                   table = ui->tab_livr;
                   QString filters("CSV files (*.csv);;All files (*.*)");
                   QString defaultFilter("CSV files (*.csv)");
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
                       //QMessageBox::information(this,"Exporter To Excel","Exporter En Excel Avec Succées ");

                       notif n("Exporter To Excel","Exporter En Excel Avec Succées .\n");
                       n.afficher();
                   }
}

void interw::on_excell_clicked()
{
    QTableView *table;
                   table = ui->tab_liv_2;
                   QString filters("CSV files (*.csv);;All files (*.*)");
                   QString defaultFilter("CSV files (*.csv)");
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
                       //QMessageBox::information(this,"Exporter To Excel","Exporter En Excel Avec Succées ");

                       notif n("Exporter To Excel","Exporter En Excel Avec Succées .\n");
                       n.afficher();
                   }
}

void interw::on_export_2_clicked()
{

    QPixmap pix(ui->tab_livr->size());
              QPainter painter(&pix);
             ui->tab_livr->render(&painter);
              painter.end();
              QPrinter printer(QPrinter::HighResolution);
              printer.setOrientation(QPrinter::Landscape);
              printer.setOutputFormat(QPrinter::PdfFormat);
              printer.setPaperSize(QPrinter::A4);
              printer.setOutputFileName("C:/Users/YedesHamda/Documents/RH_NEWS/rhemp.pdf"); // will be in build folder
              painter.begin(&printer);
              double xscale = printer.pageRect().width() / double(pix.width());
              double yscale = printer.pageRect().height() / double(pix.height());
              double scale = qMin(xscale, yscale);
              painter.translate(printer.paperRect().x() + printer.pageRect().width() / 2,
                                printer.paperRect().y() + printer.pageRect().height() / 2);
              painter.scale(scale, scale);
              painter.translate(-ui->tab_livr->width() / 2, -ui->tab_livr->height() / 2);
              painter.drawPixmap(0, 0, pix);

            QTextDocument doc;

            doc.setHtml("htmlcontent");
            doc.drawContents(&painter);
                notif n("table exporter","table exporter avec succée.\n");
                n.afficher();
              painter.end();
}

void interw::on_exportt_clicked()
{

    QPixmap pix(ui->tab_liv_2->size());
              QPainter painter(&pix);
             ui->tab_liv_2->render(&painter);
              painter.end();
              QPrinter printer(QPrinter::HighResolution);
              printer.setOrientation(QPrinter::Landscape);
              printer.setOutputFormat(QPrinter::PdfFormat);
              printer.setPaperSize(QPrinter::A4);
              printer.setOutputFileName("C:/Users/YedesHamda/Documents/RH_NEWS/rhemp.pdf"); // will be in build folder
              painter.begin(&printer);
              double xscale = printer.pageRect().width() / double(pix.width());
              double yscale = printer.pageRect().height() / double(pix.height());
              double scale = qMin(xscale, yscale);
              painter.translate(printer.paperRect().x() + printer.pageRect().width() / 2,
                                printer.paperRect().y() + printer.pageRect().height() / 2);
              painter.scale(scale, scale);
              painter.translate(-ui->tab_liv_2->width() / 2, -ui->tab_liv_2->height() / 2);
              painter.drawPixmap(0, 0, pix);

            QTextDocument doc;

            doc.setHtml("htmlcontent");
            doc.drawContents(&painter);
                notif n("table exporter","table exporter avec succée.\n");
                n.afficher();
              painter.end();
}

void interw::on_upload_clicked()
{
    filename=QFileDialog::getOpenFileName(this,tr("choose"), "",tr("Images(*.png *.jpg *.jpeg *.bmp *.gif)"));
       if (QString::compare(filename,QString()) !=0)
       {
           QImage image;
           bool valid=image.load(filename);
           if (valid)
           {
               image=image.scaledToWidth(ui->img->width(), Qt::SmoothTransformation);
               ui->img->setPixmap(QPixmap::fromImage(image));
           }
           else
           {
               //qDebug()<<"error";
           }
       }
}
void interw::clockTimer()
{
    QTime clockTime=QTime::currentTime();
    ui->clock->setText(clockTime.toString(" hh : mm : ss"));
    QString date = QDate::currentDate().toString();
    ui->date->setText(date);

}
void interw::clocktimer_2()
{


    QTime clockTime=QTime::currentTime();
    ui->clock_2->setText(clockTime.toString(" hh : mm : ss"));
    QString date = QDate::currentDate().toString();
    ui->date_2->setText(date);



}
void interw::on_pushButton_clicked()
{
    video=new MainWindowvideo(this);
     video->show();
}

void interw::on_pushButton_2_clicked()
{
     ui->label->setNum(l.get_total());
}
