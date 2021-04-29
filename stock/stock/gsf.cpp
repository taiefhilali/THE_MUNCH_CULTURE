#include "gsf.h"
#include "ui_gsf.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QTabWidget>
#include <QMessageBox>
#include <QString>
#include <QFile>
#include <QSqlQuery>
#include <QPixmap>
#include <QDebug>
#include"QSqlRecord"
#include"QSqlQuery"
#include <QLabel>
#include <QPixmap>
#include <QSqlDatabase>
#include <QSqlError>
#include<QtPrintSupport/QPrinter>
#include<QPdfWriter>
#include <QFileDialog>
#include<QTextDocument>
#include <QDateTime>
#include <QPainter>
#include <QSound>
#include "stocks.h"
#include "fourn.h"
#include "statistiq.h"
#include "stati.h"
#include "qcustomplot.h"
//#include "stati.h"
#include "ui_pdf.h"
#include <QTimer>

gsf::gsf(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gsf)
{
    ui->setupUi(this);

   /* qTimer=new QTimer(this);
    connect(qTimer,SIGNAL(timeout()),this,SLOT(clockTimer()));
    qTimer->start(100);*/
    //***************************************controles de saisie********************
        ui->prix->setValidator(new QIntValidator(0, 9999999, this));
        ui->quantite->setValidator(new QIntValidator(0, 9999999, this));
        ui->tab_stk_2->setModel(S.afficher());
        ui->tel->setValidator(new QIntValidator(0, 9999999, this));
        ui->tab_fourn_2->setModel(f.afficher());
          son=new QSound(":/sons/click.wav");
          son2=new QSound(":/sons/12.wav");
          label1 = new QLabel;

             label1->setPixmap(QPixmap("/imge/taief.png"));

             label1->show();
             QRegExp rx("[a-zA-Z]+");
             QValidator *validator = new QRegExpValidator(rx, this);

             ui->nom->setValidator(validator);
             ui->prenom->setValidator(validator);
             ui->adresse->setValidator(validator);
             ui->adresse_2->setValidator(validator);
             ui->noms->setValidator(validator);
             ui->noms1->setValidator(validator);
             ui->prenom_2->setValidator(validator);
             ui->nom_2->setValidator(validator);
             ui->prenom_2->setValidator(validator);




}

gsf::~gsf()
{
    delete ui;
}
//------------ajout1-------//
/*void gsf::clockTimer()
{
    QTime clockTime=QTime::currentTime();
    ui->clock->setText(clockTime.toString(" hh : mm : ss"));
    QString date = QDate::currentDate().toString();
    ui->date->setText(date);

}*/
//********************************AJOUTER STOCK*******************
void gsf::on_Ajouter_clicked()
{  son->play();

    //QString dat = ui->dat->text();

    son2->play();
 QString dat = ui->dat->text();
QString type= ui->type->currentText();
       int prix = ui->prix->text().toInt();
       int quantite = ui->quantite->text().toInt();
       QString nom = ui->noms->text();

       stocks S (0,dat, prix,quantite,nom,type);
       bool test=S.ajouter();
       QMessageBox msgBox;
    if(test)
         {  msgBox.setText("Ajout avec succes.");
           ui->tab_stk_2->setModel(S.afficher());
       }
       else
           msgBox.setText("Echec d'ajout");
           msgBox.exec();
            ui->tab_stk_2->setModel(S.afficher());

   }

//***********************************************SUPPRIMER STOCK**************************
void gsf::on_supprimer_clicked()
{ son->play();
    int col = ui->tab_stk_2->currentIndex().column();
       int row = ui->tab_stk_2->currentIndex().row();
       QString sql;
       int id = S.afficher()->index(row, 0).data().toInt();
      sql= QString("DELETE FROM STOCK WHERE id=%1").arg(id);
      QSqlQuery qry;
      qry.exec(sql);
      //ui->tab_stk_2->setModel(S.afficher());
        QMessageBox msgBox;
        if(qry.exec(sql)&& col >=0)
               { msgBox.setText("Suppression avec succes.");
            ui->tab_stk_2->setModel(S.afficher());

            }
            else
                msgBox.setText("Echec de suppression");
                msgBox.exec();
                 son->play();
}
//----------------ajout 2-----------------//
/*void gsf::on_ajouter1_clicked()
{ son->play();
    fourn S;
    ui->tab_stk_2->setModel(S.afficher());

    QString nom = ui->nom->text();
    QString prenom = ui->prenom->text();
       int tel = ui->tel->text().toInt();
        QString adresse = ui->adresse->text();
       fourn f (0,nom,prenom,tel,adresse);
       bool test=f.ajouter();
       QMessageBox msgBox;

    if(test)
         {  msgBox.setText("Ajout avec succes.");
           ui->tab_fourn_2->setModel(f.afficher());
       }
       else
           msgBox.setText("Echec d'ajout");
           msgBox.exec();
            son->play();
}
*/


/*void gsf::on_supprimer_2_clicked()
{ son->play();
    fourn f; f.setid(ui->supprimer_2->text().toInt());
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
*/




//******************************MODIFIER STOCK****************************//

void gsf::on_modifier_2_clicked()
{

 son->play();

  int id= ui->id->text().toInt();
     stocks S(id,"",0,0,"","");
     S.modifier(ui);
     QMessageBox:: information(nullptr,QObject::tr("Bravo"),QObject::tr(" modification effectuee\n"
                                                                              "click cancel to exit."),QMessageBox::Cancel);
    ui->tab_stk_2->setModel(S.afficher());
     son->play();
}

// -------------------------rechercher stock------------//

void gsf::on_rechercher_clicked()
{ son->play();

    int id= ui->id->text().toInt();
       stocks S(id,"",0,0,"","");
       S.Rechercherstocks(id);
       //ui->lineEdit_2 ->setText(com.get_nomProduit());
       ui->dat_3->setText(S.get_dat());
       ui->prix_2->setText(QString::number(S.get_prix()));
       ui->quantite_2->setText(QString::number(S.get_quantite()));
       ui->noms->setText(S.get_noms());
        ui->type->currentText();
        QMessageBox:: information(nullptr,QObject::tr("Bravo"),QObject::tr(" recherche effectue\n"
                                                                                 "click cancel to exit."),QMessageBox::Cancel);
         son->play();


}
//------------------------------1st refresh stockk--------------------/
void gsf::on_refresh_clicked()
{ son->play();

        stocks S;
        ui->tab_stk_2->setModel(S.afficher());
         son->play();
  }


//***************************************pdf stocK**************************//
void gsf::on_PDF_3_clicked()
{ son->play();
    QString strStream;
                    QTextStream out(&strStream);

                    const int rowCount = ui->tab_stk_2->model()->rowCount();
                    const int columnCount = ui->tab_stk_2->model()->columnCount();

                    out <<  "<html>\n"
                        "<head>\n"

                        "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                          <<  "<br>"
                           << "<br>"
                           << "<br>"
                        <<  QString("<GESTION DU STOCK>%1</>\n").arg("strTitle")
                        <<  "</head>\n"
                           "<br>"

                        "<body bgcolor=#e0c182 link=#5000A0>\n"
                          "<img src=C:/Users/taief/Documents/111.png>"
                       //     "<align='right'> " << datefich << "</align>"
                        "<center> <H1>Liste des stocks </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                    // headers
                    out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                    for (int column = 0; column < columnCount; column++)
                        if (!ui->tab_stk_2->isColumnHidden(column))
                            out << QString("<th>%1</th>").arg(ui->tab_stk_2->model()->headerData(column, Qt::Horizontal).toString());
                    out << "</tr></thead>\n";

                    // data table
                    QTimer *qTimer;
                        qTimer=new QTimer(this);
                            connect(qTimer,SIGNAL(timeout()),this,SLOT(clockTimer()));
                            qTimer->start(100);
                    for (int row = 0; row < rowCount; row++) {
                        out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                        for (int column = 0; column < columnCount; column++) {
                            if (!ui->tab_stk_2->isColumnHidden(column)) {
                                QString data = ui->tab_stk_2->model()->data(ui->tab_stk_2->model()->index(row, column)).toString().simplified();
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

              qDebug()<<"le pdf a ete cree";
              QMessageBox::information(this,"pdf cree","ce pdf a ete cree");
               QTextDocument doc;
                doc.setHtml(strStream);
                doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
                doc.print(&printer);

 son->play();
}


//****************************TRIE STOCK****************
void gsf::on_combo_activated()
{ son->play();
    stocks S;
    QString choix= ui->combo->currentText();
    ui->tab_stk_2->setModel(S.Trier(choix));
     son->play();
}



void gsf::on_pushButton_2_clicked()
{ son->play();
    statistiq *a=new statistiq();
              a->show();
               son->play();
}
//*******************************Modifier FOURNISSEURS*******************************
void gsf::on_modifier3_clicked()
{ son->play();
    int id= ui->id_2->text().toInt();
     fourn f(id,"","",0,"");
     f.modifier(ui);

     QMessageBox:: information(nullptr,QObject::tr("Bravo"),QObject::tr(" modification effectuee\n"
                                                                              "click cancel to exit."),QMessageBox::Cancel);


     ui->tab_fourn_2->setModel(f.afficher());
     son->play();



}
//**********************************REFERESH FOURNISSEURS***************
void gsf::on_refresh_2_clicked()
{ son->play();
    fourn f;
    ui->tab_fourn_2->setModel(f.afficher());
     son->play();
}

void gsf::on_rechercher_2_clicked()
{ son->play();
    int id= ui->id_2->text().toInt();
       fourn f(id,"","",0,"");
       f.Rechercherfourns(id);
       //ui->lineEdit_2 ->setText(com.get_nomProduit());
       ui->nom_2->setText(f.get_nom());
       ui->prenom_2->setText(f.get_prenom());
       ui->tel_2->setText(QString::number(f.get_tel()));
       ui->adresse_2->setText(f.get_adresse());
        QMessageBox:: information(nullptr,QObject::tr("Bravo"),QObject::tr(" recherche effectue\n"
                                                                                 "click cancel to exit."),QMessageBox::Cancel);
         son->play();
}
//***************************TRIE FOURNISSEURS*******************
void gsf::on_trie_2_activated()
{ son->play();
    fourn f;
    QString choix= ui->combo_2->currentText();
    ui->tab_fourn_2->setModel(f.Trier(choix));
     son->play();
}
//*************************PDF FOURNISSEURS********************
void gsf::on_pdf2_clicked()
{
    QString strStream;
                    QTextStream out(&strStream);

                    const int rowCount = ui->tab_fourn_2->model()->rowCount();
                    const int columnCount = ui->tab_fourn_2->model()->columnCount();

                    out <<  "<html>\n"
                        "<head>\n"

                        "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                          <<  "<br>"
                           << "<br>"
                           << "<br>"
                        <<  QString("<LISTE DES FOURNISSEURTS>%1</>\n").arg("strTitle")
                        <<  "</head>\n"
                           "<br>"

                        "<body bgcolor=#DABBEC link=#5000A0>\n"
                          "<img src=images/111.png>"
                       //     "<align='right'> " << datefich << "</align>"
                        "<center> <H1>Liste des fournisseurs </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                    // headers

                    out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                    for (int column = 0; column < columnCount; column++)
                        if (!ui->tab_fourn_2->isColumnHidden(column))
                            out << QString("<th>%1</th>").arg(ui->tab_fourn_2->model()->headerData(column, Qt::Horizontal).toString());
                    out << "</tr></thead>\n";

                    // data table
                    QTimer *qTimer;
                        qTimer=new QTimer(this);
                            connect(qTimer,SIGNAL(timeout()),this,SLOT(clockTimer()));
                            qTimer->start(100);
                    for (int row = 0; row < rowCount; row++) {
                        out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                        for (int column = 0; column < columnCount; column++) {
                            if (!ui->tab_fourn_2->isColumnHidden(column)) {
                                QString data = ui->tab_fourn_2->model()->data(ui->tab_fourn_2->model()->index(row, column)).toString().simplified();
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

              qDebug()<<"le pdf a ete cree";
              QMessageBox::information(this,"pdf cree","ce pdf a ete cree");
               QTextDocument doc;
                doc.setHtml(strStream);
                doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
                doc.print(&printer);
}
//*******************************TRIE STOCK*************************
void gsf::on_combo_2_activated()
{ son->play();
    fourn f;
    QString choix= ui->combo_2->currentText();
    ui->tab_fourn_2->setModel(f.Trier(choix));
     son->play();
}



/*void gsf::on_stat_2_clicked()
{
    stat *b=new stat();
              b->show();
}*/


//*******************************supprimer FOURNISSEURS*******************
void gsf::on_delete_2_clicked()
{ son->play();
    int col = ui->tab_fourn_2->currentIndex().column();
       int row = ui->tab_fourn_2->currentIndex().row();
       QString sql;
       int id = f.afficher()->index(row, 0).data().toInt();
      sql= QString("DELETE FROM fourn WHERE id=%1").arg(id);
      QSqlQuery qry;
      qry.exec(sql);
      //ui->tab_stk_2->setModel(S.afficher());
        QMessageBox msgBox;
        if(qry.exec(sql)&& col >=0)
               { msgBox.setText("Suppression avec succes.");
            ui->tab_fourn_2->setModel(f.afficher());

            }
            else
                msgBox.setText("Echec de suppression");
                msgBox.exec();
                 son->play();
}

//*****************************IMPRIMER STOCK************************
void gsf::on_pushButton_clicked()
{ son->play();
    QString strStream;
                QTextStream out(&strStream);
                const int rowCount = ui->tab_stk_2->model()->rowCount();
                const int columnCount = ui->tab_stk_2->model()->columnCount();
                for (int column = 0; column < columnCount; column++)
                    if (!ui->tab_stk_2->isColumnHidden(column)){
                        out << QString("<td>\t\t\t%1\t\t\t</td>").arg(ui->tab_stk_2->model()->headerData(column, Qt::Horizontal).toString());}
                for (int row = 0; row < rowCount; row++) {
                    out << "<tr>";
                    for (int column = 0; column < columnCount; column++) {
                        if (!ui->tab_stk_2->isColumnHidden(column)) {
                            QString data =ui->tab_stk_2->model()->data(ui->tab_stk_2->model()->index(row, column)).toString().simplified();
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
}
//**************************************RECHERCHER STOCK************************
void gsf::on_commandLinkButton_clicked()
{ son->play();
    QSqlQueryModel *modal=new QSqlQueryModel();
            QSqlQuery request;
         QString type=ui->recherche->currentText();
           QString val=ui->rechercher_3->text();
           val="%"+val+"%";
           if (type=="id"){
    request.prepare("SELECT * FROM stock WHERE id LIKE:val order by id");
           }
           else if (type=="dat"){
                request.prepare("SELECT * FROM stock WHERE dat LIKE:val order by dat");
           }
           else if (type=="prix"){
               request.prepare("SELECT * FROM stock WHERE prix LIKE:val order by prix");
           }
           else if (type=="quantite"){
               request.prepare("SELECT * FROM stock WHERE quantite LIKE:val order by quantite");
           }
           else if (type=="nom"){
               request.prepare("SELECT * FROM stock WHERE nom LIKE:val order by nom");
           }

           request.bindValue(":val",val);
           request.exec();
           modal->setQuery(request);
           ui->tab_stk_2->setModel(modal);
 son->play();
}
//********************************RECHERCHER FOURNISSEURS****************
void gsf::on_commandLinkButton_2_clicked()

{   son->play();
    QSqlQueryModel *modal=new QSqlQueryModel();
    QSqlQuery request;
 QString type=ui->com->currentText();
   QString val=ui->rechercher_4->text();
   val="%"+val+"%";
   if (type=="id"){
request.prepare("SELECT * FROM fourn WHERE id LIKE:val order by id");
   }
   else if (type=="nom"){
        request.prepare("SELECT * FROM fourn WHERE nom LIKE:val order by nom");
   }
   else if (type=="prenom"){
       request.prepare("SELECT * FROM fourn WHERE prenom LIKE:val order by prenom");
   }
   else if (type=="tel"){
       request.prepare("SELECT * FROM fourn WHERE tel LIKE:val order by tel");
   }
   else if (type=="adresse"){
       request.prepare("SELECT * FROM fourn WHERE adresse LIKE:val order by adresse");
   }

   request.bindValue(":val",val);
   request.exec();
   modal->setQuery(request);
   ui->tab_fourn_2->setModel(modal);
 son->play();

}
//*************************IMPRIMER IMPRIMER*************************
void gsf::on_pushButton_3_clicked()
{ son->play();
    QString strStream;
                QTextStream out(&strStream);
                const int rowCount = ui->tab_fourn_2->model()->rowCount();
                const int columnCount = ui->tab_fourn_2->model()->columnCount();
                for (int column = 0; column < columnCount; column++)
                    if (!ui->tab_fourn_2->isColumnHidden(column)){
                        out << QString("<td>\t\t\t%1\t\t\t</td>").arg(ui->tab_fourn_2->model()->headerData(column, Qt::Horizontal).toString());}
                for (int row = 0; row < rowCount; row++) {
                    out << "<tr>";
                    for (int column = 0; column < columnCount; column++) {
                        if (!ui->tab_fourn_2->isColumnHidden(column)) {
                            QString data =ui->tab_fourn_2->model()->data(ui->tab_fourn_2->model()->index(row, column)).toString().simplified();
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
}




//****************************IMPORT FOURNISSEURS*******************/////

void gsf::on_IMPORT_clicked()
{ son->play();
    int col = ui->tab_fourn_2->currentIndex().column();
        int row = ui->tab_fourn_2->currentIndex().row();
        QString sql;
     int id = f.afficher()->index(row, 0).data().toInt();
    QString nom = f.afficher()->index(row, 1).data().toString();
    int tel = f.afficher()->index(row, 3).data().toInt();
   QString  prenom=f.afficher()->index(row, 2).data().toString();
   QString  adresse=f.afficher()->index(row, 4).data().toString();
        //int id= ui->id->text().toInt();
        QString idd=f.afficher()->index(row, 0).data().toString();
        ui->id_2->setText(idd);
        ui->nom_2->setText(nom);
        ui->prenom_2->setText(prenom);
         ui->tel_2->setText(QString::number(tel));
          ui->adresse_2->setText(adresse);
       // ui->dat_3->setText(S.afficher()->index(row, 1).data().toString());
         //ui->prix_2->setText(QString::number(prix));
        // ui->quantite_2->setText(QString::number(quantite));
          son->play();
}
//*************************IMPORT STOCK*************************************
void gsf::on_pushButton_4_clicked()
{ son->play();
    int col = ui->tab_stk_2->currentIndex().column();
        int row = ui->tab_stk_2->currentIndex().row();
        QString sql;
     int id = S.afficher()->index(row, 0).data().toInt();
     int prix = S.afficher()->index(row, 2).data().toInt();
     int quantite = S.afficher()->index(row, 3).data().toInt();

        //int id= ui->id->text().toInt();
        QString idd=S.afficher()->index(row, 0).data().toString();
         QString typee=S.afficher()->index(row, 5).data().toString();
        ui->id->setText(idd);
         ui->dat_3->setText(S.afficher()->index(row, 1).data().toString());
         ui->prix_2->setText(QString::number(prix));
         ui->quantite_2->setText(QString::number(quantite));
         ui->noms1->setText(S.afficher()->index(row, 4).data().toString());
         ui->type->currentText();
          son->play();
}

void gsf::on_play_clicked()
{
       son->play();
}
//-------export1---/////
void gsf::on_EXPORT_clicked()
{
    QPixmap pix(ui->tab_stk_2->size());

              QPainter painter(&pix);

             ui->tab_stk_2->render(&painter);

              painter.end();

              QPrinter printer(QPrinter::HighResolution);

              printer.setOrientation(QPrinter::Landscape);

              printer.setOutputFormat(QPrinter::PdfFormat);

              printer.setPaperSize(QPrinter::A4);

              printer.setOutputFileName("C:/Users/taief/Documents/stock/st."
                                        ""
                                        ""); // will be in build folder

              painter.begin(&printer);

              double xscale = printer.pageRect().width() / double(pix.width());

              double yscale = printer.pageRect().height() / double(pix.height());

              double scale = qMin(xscale, yscale);

              painter.translate(printer.paperRect().x() + printer.pageRect().width() / 2,

                                printer.paperRect().y() + printer.pageRect().height() / 2);

              painter.scale(scale, scale);

              painter.translate(-ui->tab_stk_2->width() / 2, -ui->tab_stk_2->height() / 2);

              painter.drawPixmap(0, 0, pix);



            QTextDocument doc;



            doc.setHtml("htmlcontent");

            doc.drawContents(&painter);



              painter.end();
}

void gsf::on_excel_clicked()
{
    QTableView *table;
                  table = ui->tab_stk_2;
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

void gsf::on_rechercherfournn_clicked()
{
    son->play();
        int id= ui->id_2->text().toInt();
           fourn f(id,"","",0,"");
           f.Rechercherfourns(id);
           //ui->lineEdit_2 ->setText(com.get_nomProduit());
           ui->nom_2->setText(f.get_nom());
           ui->prenom_2->setText(f.get_prenom());
           ui->tel_2->setText(QString::number(f.get_tel()));
           ui->adresse_2->setText(f.get_adresse());
            QMessageBox:: information(nullptr,QObject::tr("Bravo"),QObject::tr(" recherche effectue\n"
                                                                                     "click cancel to exit."),QMessageBox::Cancel);
             son->play();
}
//---IMPORT CALENDER---/
void gsf::on_pushButton_5_clicked()
{
    son->play();
        int col = ui->tab_stk_2->currentIndex().column();
            int row = ui->tab_stk_2->currentIndex().row();
            QString sql;
         int id = S.afficher()->index(row, 0).data().toInt();
         int prix = S.afficher()->index(row, 2).data().toInt();
         int quantite = S.afficher()->index(row, 3).data().toInt();
       QString dat=S.afficher()->index(row, 1).data().toString();
            //int id= ui->id->text().toInt();
            QString idd=S.afficher()->index(row, 0).data().toString();
            ui->id->setText(idd);
            ui->dat_2->setSelectedDate(QDate::fromString(dat,"dd/MM/yyyy"));
           // ui->dat_3->setText(S.afficher()->index(row, 1).data().toString());
             ui->prix_2->setText(QString::number(prix));
             ui->quantite_2->setText(QString::number(quantite));
              son->play();
}
//****************************STATISTIQUE FOURNISSEURS**************
void gsf::on_stat_2_clicked()
{
    stati *b=new stati();
              b->show();
}


void gsf::on_pushButton_7_clicked()
{
    statistiq *b=new statistiq();
              b->show();
}

//*****************************STATISTIQUES STOCK***************************
void gsf::on_pushButton_8_clicked()
{
    statistiq *b=new statistiq();
              b->show();
}

//***************************REFRESH STOCK********************************

void gsf::on_refresh_3_clicked()
{
    son->play();

            stocks S;
            ui->tab_stk_2->setModel(S.afficher());
             son->play();
}
// **********************************ajouter fournisseurs******************************
void gsf::on_ajouter3_clicked()
{
    son->play();
        QString nom = ui->nom->text();
        QString prenom = ui->prenom->text();
           int tel = ui->tel->text().toInt();
            QString adresse = ui->adresse->text();
           fourn f (0,nom,prenom,tel,adresse);
           bool test=f.ajouter();
           QMessageBox msgBox;

        if(test)
             {  msgBox.setText("Ajout avec succes.");
               ui->tab_fourn_2->setModel(f.afficher());
           }
           else
               msgBox.setText("Echec d'ajout");
               msgBox.exec();
                ui->tab_fourn_2->setModel(f.afficher());
                son->play();
}




//*********************************************AUTRE FACON DU PDF*********************************//
void gsf::on_pushButton_imprimer_5_clicked()
{ son2->play();
    go = new pdf(this);
       go->show();
}
//************************TYPING SOUND***********************
void gsf::on_noms_textChanged(const QString &arg1)
{
    son2->play();
}




void gsf::on_prenom_textChanged(const QString &arg1)
{
    son2->play();
}

/*void gsf::on_jh_clicked()
{
   //QString code=ui->lineEdit_code_pdf_3->text();
 f. pdffonction(code);
}*/

void gsf::on_newpdf_clicked()
{
    QString code=ui->lineEdit_code_pdf_3->text();
  f. pdffonction(code);
}
