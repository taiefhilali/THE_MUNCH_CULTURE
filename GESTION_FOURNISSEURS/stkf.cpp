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
#include <QDebug>
#include"QSqlRecord"
#include"QSqlQuery"
#include <QSqlDatabase>
#include <QSqlError>
#include<QtPrintSupport/QPrinter>
#include<QPdfWriter>
#include <QFileDialog>
#include<QTextDocument>
#include <QDateTime>
#include "stocks.h"
#include "fourn.h"
#include "statistiq.h"
#include "qcustomplot.h"

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
{ //QString dat = ui->dat->text();
 QString dat = ui->dat->selectedDate().toString();

       int prix = ui->prix->text().toInt();
       int quantite = ui->quantite->text().toInt();
       stocks S (0,dat, prix,quantite);
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
       fourn f (0,nom, prenom,tel,adresse);
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






void MainWindow::on_modifier_2_clicked()
{
    int id= ui->id->text().toInt();
     stocks S(id,"",0,0);
     S.modifier(ui);
     qDebug()<<"stock modifié avec succées";
}



void MainWindow::on_rechercher_clicked()
{

    int id= ui->id->text().toInt();
       stocks S(id,"",0,0);
       S.Rechercherstocks(id);
       //ui->lineEdit_2 ->setText(com.get_nomProduit());
       ui->dat_3->setText(S.get_dat());
       ui->prix_2->setText(QString::number(S.get_prix()));
       ui->quantite_2->setText(QString::number(S.get_quantite()));
        QMessageBox:: information(nullptr,QObject::tr("Bravo"),QObject::tr(" recherche effectue\n"
                                                                                 "click cancel to exit."),QMessageBox::Cancel);


}
//------------------------------1st refresh stockk--------------------/
void MainWindow::on_refresh_clicked()
{

        stocks S;
        ui->tab_stk_2->setModel(S.afficher());
  }



void MainWindow::on_PDF_2_clicked()
{
    QString strStream;
                    QTextStream out(&strStream);

                    const int rowCount = ui->tab_stk_2->model()->rowCount();
                    const int columnCount = ui->tab_stk_2->model()->columnCount();

                    out <<  "<html>\n"
                        "<head>\n"
                        "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                        <<  QString("<title>%1</title>\n").arg("strTitle")
                        <<  "</head>\n"
                        "<body bgcolor=#ffffff link=#5000A0>\n"

                       //     "<align='right'> " << datefich << "</align>"
                        "<center> <H1>Liste des fournisseurs </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                    // headers
                    out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                    for (int column = 0; column < columnCount; column++)
                        if (!ui->tab_stk_2->isColumnHidden(column))
                            out << QString("<th>%1</th>").arg(ui->tab_stk_2->model()->headerData(column, Qt::Horizontal).toString());
                    out << "</tr></thead>\n";

                    // data table
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

               QTextDocument doc;
                doc.setHtml(strStream);
                doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
                doc.print(&printer);


}



void MainWindow::on_combo_activated()
{
    stocks S;
    QString choix= ui->combo->currentText();
    ui->tab_stk_2->setModel(S.Trier(choix));
}



void MainWindow::on_pushButton_2_clicked()
{
    statistiq *a=new statistiq();
              a->show();
}

void MainWindow::on_modifier3_clicked()
{
    int id= ui->id_2->text().toInt();
     fourn f(id,"","",0,"");
     f.modifier(ui);
     QMessageBox:: information(nullptr,QObject::tr("Bravo"),QObject::tr(" modification effectuee\n"
                                                                              "click cancel to exit."),QMessageBox::Cancel);



}

void MainWindow::on_refresh_2_clicked()
{
    fourn f;
    ui->tab_fourn_2->setModel(f.afficher());
}

void MainWindow::on_rechercher_2_clicked()
{
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
}

void MainWindow::on_trie_2_activated()
{
    fourn f;
    QString choix= ui->combo_2->currentText();
    ui->tab_fourn_2->setModel(f.Trier(choix));
}

void MainWindow::on_pdf2_clicked()
{
    QString strStream;
                    QTextStream out(&strStream);

                    const int rowCount = ui->tab_fourn_2->model()->rowCount();
                    const int columnCount = ui->tab_fourn_2->model()->columnCount();

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
                        if (!ui->tab_fourn_2->isColumnHidden(column))
                            out << QString("<th>%1</th>").arg(ui->tab_fourn_2->model()->headerData(column, Qt::Horizontal).toString());
                    out << "</tr></thead>\n";

                    // data table
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

               QTextDocument doc;
                doc.setHtml(strStream);
                doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
                doc.print(&printer);


}

void MainWindow::on_combo_2_activated()
{
    fourn f;
    QString choix= ui->combo_2->currentText();
    ui->tab_fourn_2->setModel(f.Trier(choix));
}
