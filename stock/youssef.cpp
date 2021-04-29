#include "youssef.h"
#include "ui_youssef.h"
#include "revenu.h"
#include "depense.h"
#include "produit.h"
#include "mainwindow.h"
#include "QSqlQuery"
#include <QMessageBox>
#include <QFileDialog>
#include <QTextStream>
#include <QTextEdit>
#include <QDateTime>
#include <QCalendarWidget>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>
#include <QPrinter>
youssef::youssef(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::youssef)
{
    ui->setupUi(this);
    ui->tab_rev->setModel(R.afficher());
    ui->tab_dep->setModel(D.afficher());
    ui->tab_produit->setModel(P.afficher());
    click = new QMediaPlayer();
        click->setMedia(QUrl::fromLocalFile("C:/Users/achou/Desktop/gestion de comptabilite/maquetteqt/Click.mp3"));
    makePolt();
    makePolt_2();
    makePolt_3();

}


youssef::~youssef()
{
    delete ui;
}

void youssef::on_Ajouter_clicked()
{int i=0;
    click->setMedia(QUrl::fromLocalFile("C:/Users/achou/Desktop/gestion de comptabilite/maquetteqt/Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    int id_rev=ui->le_id_rev->text().toInt();
    int tot_rev=ui->le_tot_rev->text().toInt();
    QString type_rev=ui->letyperev->currentText();
    QString date_rev=ui->date_3->text();

Revenu R(id_rev,tot_rev,type_rev,date_rev);
 bool test=R.ajouter();
 QMessageBox msgBox;

 if(test)
   {  while (i<101) {
         ui->progressBar->setValue(i);
         QTimer timer;
         //        timer.setSingleShot(true);
         timer.setInterval(10);
         QEventLoop loop;
         connect(&timer, SIGNAL(timeout()), &loop, SLOT(quit()));
         timer.start();
         loop.exec();
         i++;
     }
     msgBox.setText("Ajout avec succes.");
     ui->tab_rev->setModel(R.afficher());

 }
 else
     msgBox.setText("Echec d'ajout");
     msgBox.exec();



}



void youssef::on_modifier_3_clicked()
{
    {int i=0;
        int id_rev,tot_rev;
                QString type_rev, date_rev;


        id_rev=ui->le_id_rev_3->text().toInt();
        tot_rev=ui->le_tot_rev_2->text().toInt();
        type_rev=ui->mtyperev->currentText();
        date_rev=ui->dates->text();
        click->setMedia(QUrl::fromLocalFile("C:/Users/achou/Desktop/gestion de comptabilite/maquetteqt/Click.mp3"));
            click->play();
            qDebug()<<click ->errorString();
            {while (i<101) {
                            ui->progressBar->setValue(i);
                            QTimer timer;
                            //        timer.setSingleShot(true);
                            timer.setInterval(10);
                            QEventLoop loop;
                            connect(&timer, SIGNAL(timeout()), &loop, SLOT(quit()));
                            timer.start();
                            loop.exec();
                            i++;
                        }
            }
        QSqlQuery qry;
        qry.prepare("update REVENU set id_rev=:id_rev,tot_rev=:tot_rev,type_rev=:type_rev,date_rev=:date_rev where id_rev=:id_rev");
        qry.bindValue(":id_rev",id_rev);
        qry.bindValue(":tot_rev",tot_rev);
        qry.bindValue(":type_rev",type_rev);
        qry.bindValue(":date_rev",date_rev);


        qry.exec();
        ui->tab_rev->setModel(R.afficher());//refresh

    }

}

void youssef::on_supprimer_3_clicked()
{int i=0;
    Revenu R1; R1.setid_rev(ui->le_id_sup->text().toInt());
    bool test=R1.supprimer(R1.getid_rev());
    QMessageBox msgBox;
    click->setMedia(QUrl::fromLocalFile("C:/Users/achou/Desktop/gestion de comptabilite/maquetteqt/Click.mp3"));
        click->play();
        qDebug()<<click ->errorString();

    if(test)
       {  while (i<101) {
                ui->progressBar->setValue(i);
                QTimer timer;
                //        timer.setSingleShot(true);
                timer.setInterval(10);
                QEventLoop loop;
                connect(&timer, SIGNAL(timeout()), &loop, SLOT(quit()));
                timer.start();
                loop.exec();
                i++;
            }
        msgBox.setText("Suppression avec succes.");
    ui->tab_rev->setModel(R.afficher());

    }
    else
        msgBox.setText("Echec de suppression");
        msgBox.exec();

}

void youssef::on_pushButton_3_clicked()
{ int i=0;
    QSqlQueryModel *modal=new QSqlQueryModel();
                QSqlQuery request;
               QString type=ui->cb_recherche_3->currentText();
               QString val=ui->le_recherche_3->text();
               val="%"+val+"%";
               if (type=="id_rev"){
                   request.prepare("SELECT * FROM REVENU WHERE id_rev LIKE:val ");
               }else if (type=="tot_rev"){
                   request.prepare("SELECT * FROM REVENU WHERE tot_rev LIKE:val");

               }else if (type=="type_rev"){
                   request.prepare("SELECT * FROM REVENU WHERE type_rev LIKE:val");
               }else if (type=="date_rev"){
                   request.prepare("SELECT * FROM REVENU WHERE date_rev LIKE:val");
               }
               request.bindValue(":val",val);
               request.exec();
               modal->setQuery(request);
               {while (i<101) {
                               ui->progressBar->setValue(i);
                               QTimer timer;
                               //        timer.setSingleShot(true);
                               timer.setInterval(10);
                               QEventLoop loop;
                               connect(&timer, SIGNAL(timeout()), &loop, SLOT(quit()));
                               timer.start();
                               loop.exec();
                               i++;
                           }
               }
               ui->tab_rev->setModel(modal);
               click->setMedia(QUrl::fromLocalFile("C:/Users/achou/Desktop/gestion de comptabilite/maquetteqt/Click.mp3"));
                   click->play();
                   qDebug()<<click ->errorString();

}

void youssef::on_pushButton_clicked()
{int i=0;
    click->setMedia(QUrl::fromLocalFile("C:/Users/achou/Desktop/gestion de comptabilite/maquetteqt/Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();


    QString critere=ui->cb_recherche_9->currentText();
        QString mode;
        if (ui->asc->isChecked()==true)
    {
             mode="ASC";
    }
         else if(ui->desc->isChecked()==true)
         {
             mode="DESC";
         }
        {while (i<101) {
                        ui->progressBar->setValue(i);
                        QTimer timer;
                        //        timer.setSingleShot(true);
                        timer.setInterval(10);
                        QEventLoop loop;
                        connect(&timer, SIGNAL(timeout()), &loop, SLOT(quit()));
                        timer.start();
                        loop.exec();
                        i++;
                    }
        }
      ui->tab_rev->setModel(R.Trierrev(critere,mode));


}





void youssef::on_EXCEL_clicked()
{
    click->setMedia(QUrl::fromLocalFile("C:/Users/achou/Desktop/gestion de comptabilite/maquetteqt/Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
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

void youssef::on_pushButton_1_clicked()
{int i=0;
    click->setMedia(QUrl::fromLocalFile("C:/Users/achou/Desktop/gestion de comptabilite/maquetteqt/Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();

    int id_dep=ui->le_id_dep->text().toInt();
   int tot_dep=ui->le_tot_dep->text().toInt();
   QString type_dep=ui->letypedep->currentText();
   QString date_dep=ui->date->text();

Depense D(id_dep,tot_dep,type_dep,date_dep);
 bool test=D.ajouter();
 QMessageBox msgBox;

 if(test)
   {  while (i<101) {
             ui->progressBar_2->setValue(i);
             QTimer timer;
             //        timer.setSingleShot(true);
             timer.setInterval(10);
             QEventLoop loop;
             connect(&timer, SIGNAL(timeout()), &loop, SLOT(quit()));
             timer.start();
             loop.exec();
             i++;
         }
     msgBox.setText("Ajout avec succes.");
     ui->tab_dep->setModel(D.afficher());
 }
 else
     msgBox.setText("Echec d'ajout");
     msgBox.exec();

}

void youssef::on_supprimer_6_clicked()
{
    int i=0;
    click->setMedia(QUrl::fromLocalFile("C:/Users/achou/Desktop/gestion de comptabilite/maquetteqt/Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    Depense D1; D1.setid_dep(ui->le_id_sup_3->text().toInt());
        bool test=D1.supprimer(D1.getid_dep());
        QMessageBox msgBox;

        if(test)
           {while (i<101) {
                    ui->progressBar_2->setValue(i);
                    QTimer timer;
                    //        timer.setSingleShot(true);
                    timer.setInterval(10);
                    QEventLoop loop;
                    connect(&timer, SIGNAL(timeout()), &loop, SLOT(quit()));
                    timer.start();
                    loop.exec();
                    i++;
                }
            msgBox.setText("Suppression avec succes.");
        ui->tab_dep->setModel(D.afficher());

        }
        else
            msgBox.setText("Echec de suppression");
            msgBox.exec();

}

void youssef::on_pushButton_2_clicked()
{int i=0;
    click->setMedia(QUrl::fromLocalFile("C:/Users/achou/Desktop/gestion de comptabilite/maquetteqt/Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    {
        int id_dep,tot_dep;
        QString type_dep,date_dep;

        id_dep=ui->le_id_dep_5->text().toInt();
        tot_dep=ui->le_tot_dep_2->text().toInt();
        type_dep=ui->mtypedep->currentText();
        date_dep=ui->datess->text();
        {while (i<101) {
                        ui->progressBar_2->setValue(i);
                        QTimer timer;
                        //        timer.setSingleShot(true);
                        timer.setInterval(10);
                        QEventLoop loop;
                        connect(&timer, SIGNAL(timeout()), &loop, SLOT(quit()));
                        timer.start();
                        loop.exec();
                        i++;
                    }
        }

        QSqlQuery qry;
        qry.prepare("update DEPENSE set tot_dep=:tot_dep,type_dep=:type_dep, date_dep=:date_dep where id_dep=:id_dep");
        qry.bindValue(":id_dep",id_dep);
        qry.bindValue(":tot_dep",tot_dep);
        qry.bindValue(":type_dep",type_dep);
        qry.bindValue(":date_dep",date_dep);



        qry.exec();
        ui->tab_dep->setModel(D.afficher());//refresh


    }

}

void youssef::on_pushButton_7_clicked()
{int i=0;
    click->setMedia(QUrl::fromLocalFile("C:/Users/achou/Desktop/gestion de comptabilite/maquetteqt/Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    QSqlQueryModel *modal=new QSqlQueryModel();
                QSqlQuery request;
               QString type=ui->cb_recherche_8->currentText();
               QString val=ui->le_recherche_8->text();
               val="%"+val+"%";
               if (type=="id_dep"){
                   request.prepare("SELECT * FROM DEPENSE WHERE id_dep LIKE:val ");
               }else if (type=="tot_dep"){
                   request.prepare("SELECT * FROM DEPENSE WHERE tot_dep LIKE:val");

               }else if (type=="type_dep"){
                   request.prepare("SELECT * FROM DEPENSE WHERE type_dep LIKE:val");
               }else if (type=="date_dep"){
                   request.prepare("SELECT * FROM DEPENSE WHERE date_dep LIKE:val");
               }
               {while (i<101) {
                               ui->progressBar_2->setValue(i);
                               QTimer timer;
                               //        timer.setSingleShot(true);
                               timer.setInterval(10);
                               QEventLoop loop;
                               connect(&timer, SIGNAL(timeout()), &loop, SLOT(quit()));
                               timer.start();
                               loop.exec();
                               i++;
                           }
               }
               request.bindValue(":val",val);
               request.exec();
               modal->setQuery(request);
               ui->tab_dep->setModel(modal);

}

void youssef::on_pushButton_8_clicked()
{int i=0;
    click->setMedia(QUrl::fromLocalFile("C:/Users/achou/Desktop/gestion de comptabilite/maquetteqt/Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();

    QString critere=ui->cb_recherche_10->currentText();
        QString mode;
        if (ui->asc1->isChecked()==true)
    {
             mode="ASC";
    }
         else if(ui->desc1->isChecked()==true)
         {
             mode="DESC";
         }
        {while (i<101) {
                        ui->progressBar->setValue(i);
                        QTimer timer;
                        //        timer.setSingleShot(true);
                        timer.setInterval(10);
                        QEventLoop loop;
                        connect(&timer, SIGNAL(timeout()), &loop, SLOT(quit()));
                        timer.start();
                        loop.exec();
                        i++;
                    }
        }
      ui->tab_dep->setModel(D.Trierdep(critere,mode));

}

void youssef::on_EXCEL_4_clicked()
{click->setMedia(QUrl::fromLocalFile("C:/Users/achou/Desktop/gestion de comptabilite/maquetteqt/Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    QTableView *table;
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


void youssef::on_ajouter1_clicked()
{int i=0;
    click->setMedia(QUrl::fromLocalFile("C:/Users/achou/Desktop/gestion de comptabilite/maquetteqt/Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();

    int id_produit=ui->le_id_produit->text().toInt();
    QString nom_produit=ui->le_nom_produit->text();
    QString type_produit=ui->letypeproduit->currentText();
    int tot_produit=ui->le_tot_produit->text().toInt();
    QString date_produit=ui->ledateproduit->text();



Produit P(id_produit,nom_produit,type_produit,tot_produit,date_produit);
 bool test=P.ajouter();
 QMessageBox msgBox;

 if(test)
   { while (i<101) {
             ui->progressBar_3->setValue(i);
             QTimer timer;
             //        timer.setSingleShot(true);
             timer.setInterval(10);
             QEventLoop loop;
             connect(&timer, SIGNAL(timeout()), &loop, SLOT(quit()));
             timer.start();
             loop.exec();
             i++;
         }
     msgBox.setText("Ajout avec succes.");
     ui->tab_produit->setModel(P.afficher());
 }
 else
     msgBox.setText("Echec d'ajout");
     msgBox.exec();
}

void youssef::on_supprimer_2_clicked()
{
    int i=0;
    click->setMedia(QUrl::fromLocalFile("C:/Users/achou/Desktop/gestion de comptabilite/maquetteqt/Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    Produit P1; P1.setid_produit(ui->le_id_supprimer->text().toInt());
    bool test=P1.supprimer(P1.getid_produit());
    QMessageBox msgBox;

    if(test)
       { while (i<101) {
            ui->progressBar_3->setValue(i);
            QTimer timer;
            //        timer.setSingleShot(true);
            timer.setInterval(10);
            QEventLoop loop;
            connect(&timer, SIGNAL(timeout()), &loop, SLOT(quit()));
            timer.start();
            loop.exec();
            i++;
        }
        msgBox.setText("Suppression avec succes.");
    ui->tab_produit->setModel(P.afficher());

    }
    else
        msgBox.setText("Echec de suppression");
        msgBox.exec();
}

void youssef::on_modifier3_2_clicked()
{int i=0;
    click->setMedia(QUrl::fromLocalFile("C:/Users/achou/Desktop/gestion de comptabilite/maquetteqt/Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
   {
        int id_produit,tot_produit;
                QString nom_produit,type_produit,date_produit;

        id_produit=ui->le_id_produit_3->text().toInt();
        nom_produit=ui->le_nom_produit_3->text();
        type_produit=ui->mtypeproduit->currentText();
        tot_produit=ui->le_tot_produit_3->text().toInt();
        date_produit=ui->mdateproduit->text();

        {while (i<101) {
                    ui->progressBar_3->setValue(i);
                    QTimer timer;
                    //        timer.setSingleShot(true);
                    timer.setInterval(10);
                    QEventLoop loop;
                    connect(&timer, SIGNAL(timeout()), &loop, SLOT(quit()));
                    timer.start();
                    loop.exec();
                    i++;
                }
        }
        QSqlQuery qry;
        qry.prepare("update PRODUIT set nom_produit=:nom_produit,type_produit=:type_produit,tot_produit=:tot_produit,date_produit=:date_produit where id_produit=:id_produit");


        qry.bindValue(":id_produit",id_produit);
        qry.bindValue(":nom_produit",nom_produit);
        qry.bindValue(":type_produit",type_produit);
        qry.bindValue(":tot_produit",tot_produit);
        qry.bindValue(":date_produit",date_produit);



        qry.exec();
        ui->tab_produit->setModel(P.afficher());//refresh

    }



}

void youssef::on_pushButton_9_clicked()
{int i=0;
    click->setMedia(QUrl::fromLocalFile("C:/Users/achou/Desktop/gestion de comptabilite/maquetteqt/Click.mp3"));
        click->play();
        qDebug()<<click ->errorString();
    QString critere=ui->trieprod->currentText();
        QString mode;
        if (ui->asc2->isChecked()==true)
    {
             mode="ASC";
    }
         else if(ui->desc2->isChecked()==true)
         {
             mode="DESC";
         }
        {while (i<101) {
                    ui->progressBar_3->setValue(i);
                    QTimer timer;
                    //        timer.setSingleShot(true);
                    timer.setInterval(10);
                    QEventLoop loop;
                    connect(&timer, SIGNAL(timeout()), &loop, SLOT(quit()));
                    timer.start();
                    loop.exec();
                    i++;
                }
        }
      ui->tab_produit->setModel(P.Trierproduit(critere,mode));

}

void youssef::on_pushButton_4_clicked()
{int i=0;
    click->setMedia(QUrl::fromLocalFile("C:/Users/achou/Desktop/gestion de comptabilite/maquetteqt/Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    QSqlQueryModel *modal=new QSqlQueryModel();
                QSqlQuery request;
               QString type=ui->cb_recherche_4->currentText();
               QString val=ui->le_recherche_4->text();
               val="%"+val+"%";
               if (type=="id_produit"){
                   request.prepare("SELECT * FROM PRODUIT WHERE id_produit LIKE:val");
               }else if (type=="nom_produit"){
                   request.prepare("SELECT * FROM PRODUIT WHERE nom_produit LIKE:val");
               }else if (type=="type_produit"){
                   request.prepare("SELECT * FROM PRODUIT WHERE type_produit LIKE:val");
               }else if (type=="tot_produit"){
                   request.prepare("SELECT * FROM PRODUIT WHERE tot_produit LIKE:val");
               }else if (type=="date_produit"){
                   request.prepare("SELECT * FROM PRODUIT WHERE date_produit LIKE:val");
                   {while (i<101) {
                               ui->progressBar_3->setValue(i);
                               QTimer timer;
                               //        timer.setSingleShot(true);
                               timer.setInterval(10);
                               QEventLoop loop;
                               connect(&timer, SIGNAL(timeout()), &loop, SLOT(quit()));
                               timer.start();
                               loop.exec();
                               i++;
                           }}
               request.bindValue(":val",val);
               request.exec();
               modal->setQuery(request);
               ui->tab_produit->setModel(modal);

}


}
void youssef::on_EXCEL_3_clicked()
{click->setMedia(QUrl::fromLocalFile("C:/Users/achou/Desktop/gestion de comptabilite/maquetteqt/Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    QTableView *table;
        table = ui->tab_produit;
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


//Statistique

void youssef::makePolt()
{

       QLinearGradient gradient(0, 0, 0, 400);
       gradient.setColorAt(0, QColor(90, 90, 90));
       gradient.setColorAt(0.38, QColor(105, 105, 105));
       gradient.setColorAt(1, QColor(70, 70, 70));
       ui->customPlot->setBackground(QBrush(gradient));


       QCPBars *regen = new QCPBars(ui->customPlot->xAxis,ui-> customPlot->yAxis);

       regen->setAntialiased(false);

       regen->setStackingGap(1);




       regen->setName("Nombre de produits par rapport a la type");
       regen->setPen(QPen(QColor(0, 168, 140).lighter(130)));
       regen->setBrush(QColor(0, 168, 140));

       QVector<double> ticks;
       QVector<QString> labels;






       ticks << 1<<2<<3;

      labels <<"fastfood"<<"healthyfood "<<"others";
       QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
       textTicker->addTicks(ticks, labels);
       ui->customPlot->xAxis->setTicker(textTicker);
       ui->customPlot->xAxis->setTickLabelRotation(60);
       ui->customPlot->xAxis->setSubTicks(false);
       ui->customPlot->xAxis->setTickLength(0, 3);
       ui->customPlot->xAxis->setRange(0, 8);
       ui->customPlot->xAxis->setBasePen(QPen(Qt::white));
       ui->customPlot->xAxis->setTickPen(QPen(Qt::white));
       ui->customPlot->xAxis->grid()->setVisible(true);
       //ui->customPlot->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
       ui->customPlot->xAxis->setTickLabelColor(Qt::white);
       ui->customPlot->xAxis->setLabelColor(Qt::white);


       ui->customPlot->yAxis->setRange(0,10);
       ui->customPlot->yAxis->setPadding(10); // a bit more space to the left border
       ui->customPlot->yAxis->setLabel("Nombre de produits par rapport au type");
       ui->customPlot->yAxis->setBasePen(QPen(Qt::white));
       ui->customPlot->yAxis->setTickPen(QPen(Qt::white));
       ui->customPlot->yAxis->setSubTickPen(QPen(Qt::white));
       ui->customPlot->yAxis->grid()->setSubGridVisible(true);
       ui->customPlot->yAxis->setTickLabelColor(Qt::white);
       ui->customPlot->yAxis->setLabelColor(Qt::white);
      // ui->customPlot->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
      // ui->customPlot->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));


       QVector<double> regenData;
       int n1=0,n2=0,n3=0;

           QSqlQuery q1("select count(*) from produit where type_produit='fastfood'");
           while (q1.next())
           {
               n1 = q1.value(0).toInt();
               qDebug()<<"Nombre Produits : "<<n1<<endl;
           }

           QSqlQuery q2("select count(*) from produit where type_produit='healthyfood'");
           while (q2.next())
           {
               n2 = q2.value(0).toInt();
               qDebug()<<"Nombre produits : "<<n2<<endl;
           }

           QSqlQuery q3("select count(*) from produit where type_produit='others' ");
           while (q3.next())
           {
                n3 = q3.value(0).toInt();
                qDebug()<<"Nombre Produits : "<<n3<<endl;
           }




       regenData << n1<<n2<<n3;
       regen->setData(ticks, regenData);


       ui->customPlot->legend->setVisible(true);
       ui->customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
       ui->customPlot->legend->setBrush(QColor(255, 255, 255, 100));
       ui->customPlot->legend->setBorderPen(Qt::NoPen);
       QFont legendFont = font();
       legendFont.setPointSize(10);
       ui->customPlot->legend->setFont(legendFont);
       ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);


}



void youssef::on_pushButton_5_clicked()
{int i=0;
    click->setMedia(QUrl::fromLocalFile("C:/Users/achou/Desktop/gestion de comptabilite/maquetteqt/Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
 int col = ui->tab_produit->currentIndex().column();
    int row = ui->tab_produit->currentIndex().row();

    if(col==0)
    { while (i<101) {
            ui->progressBar_3->setValue(i);
            QTimer timer;
            //        timer.setSingleShot(true);
            timer.setInterval(10);
            QEventLoop loop;
            connect(&timer, SIGNAL(timeout()), &loop, SLOT(quit()));
            timer.start();
            loop.exec();
            i++;
        }
        int id=P.afficher()->index(row,col).data().toInt();
        QString sql=QString("SELECT * FROM PRODUIT WHERE id_produit=:id").arg(id);

    }
    ui->le_id_produit_3->setText(P.afficher()->index(row,0).data().toString());
    ui->le_nom_produit_3->setText(P.afficher()->index(row,1).data().toString());
    ui->letypeproduit->setCurrentText(P.afficher()->index(row,1).data().toString());

    ui->le_tot_produit_3->setText(P.afficher()->index(row,3).data().toString());
    //ui->ledateproduit->setText(P.afficher()->index(row,1).data().toString());


}


void youssef::on_pushButton_6_clicked()
{click->setMedia(QUrl::fromLocalFile("C:/Users/achou/Desktop/gestion de comptabilite/maquetteqt/Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    int col = ui->tab_dep->currentIndex().column();
       int row = ui->tab_dep->currentIndex().row();

       if(col==0)
       {
           int id=D.afficher()->index(row,col).data().toInt();
           QString sql=QString("SELECT * FROM DEPENSE WHERE id_dep=:id").arg(id);

       }
       ui->le_id_dep_5->setText(D.afficher()->index(row,0).data().toString());
       ui->le_tot_dep_2->setText(D.afficher()->index(row,1).data().toString());
       //ui->mtypedep->setCurrentText(D.afficher()->index(row,2).data().toString());






              // le_date_dep_2->setText(D.afficher()->index(row,3).data().toString());

    }

void youssef::on_pushButton_10_clicked()
{click->setMedia(QUrl::fromLocalFile("C:/Users/achou/Desktop/gestion de comptabilite/maquetteqt/Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    int col = ui->tab_rev->currentIndex().column();
       int row = ui->tab_rev->currentIndex().row();

       if(col==0)
       {
           int id=R.afficher()->index(row,col).data().toInt();
           QString sql=QString("SELECT * FROM REVENU WHERE id_rev=:id").arg(id);
          //QString dat_rev=R.afficher()->index(row, 3).data().toString();
       }
       ui->le_id_rev_3->setText(R.afficher()->index(row,0).data().toString());
       ui->le_tot_rev_2->setText(R.afficher()->index(row,1).data().toString());
       ui->mtyperev->setCurrentText(R.afficher()->index(row,2).data().toString());
       //ui->dates->setText(R.afficher()->index(row, 3).data().toString());
        //ui->datee->setSelectedDate(QDate::fromString(date_rev,"dd/MM/yyyy"));
    }



void youssef::on_impression_clicked()   //imprimer revenu
{click->setMedia(QUrl::fromLocalFile("C:/Users/achou/Desktop/gestion de comptabilite/maquetteqt/Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    QString strStream;
                   QTextStream out(&strStream);
                   const int rowCount = ui->tab_rev->model()->rowCount();
                   const int columnCount = ui->tab_rev->model()->columnCount();
                   for (int column = 0; column < columnCount; column++)
                       if (!ui->tab_rev->isColumnHidden(column)){
                           out << QString("<td>\t\t\t%1\t\t\t</td>").arg(ui->tab_rev->model()->headerData(column, Qt::Horizontal).toString());}
                   for (int row = 0; row < rowCount; row++) {
                       out << "<tr>";
                       for (int column = 0; column < columnCount; column++) {
                           if (!ui->tab_rev->isColumnHidden(column)) {
                               QString data =ui->tab_rev->model()->data(ui->tab_rev->model()->index(row, column)).toString().simplified();
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

}








void youssef::on_pdf_clicked()  //pdf revenu
{click->setMedia(QUrl::fromLocalFile("C:/Users/achou/Desktop/gestion de comptabilite/maquetteqt/Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    QString strStream;
                          QTextStream out(&strStream);

                          const int rowCount = ui->tab_rev->model()->rowCount();
                          const int columnCount = ui->tab_rev->model()->columnCount();

                          out <<  "<html>\n"
                              "<head>\n"
                              "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                              <<  QString("<title>%1</title>\n").arg("strTitle")
                              <<  "</head>\n"
                              "<body bgcolor=#ffffff link=#5000A0>\n"

                             //     "<align='right'> " << datefich << "</align>"
                              "<center> <H1>Liste des revenus </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                          // headers
                          out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                          for (int column = 0; column < columnCount; column++)
                              if (!ui->tab_rev->isColumnHidden(column))
                                  out << QString("<th>%1</th>").arg(ui->tab_rev->model()->headerData(column, Qt::Horizontal).toString());
                          out << "</tr></thead>\n";

                          // data table
                          for (int row = 0; row < rowCount; row++) {
                              out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                              for (int column = 0; column < columnCount; column++) {
                                  if (!ui->tab_rev->isColumnHidden(column)) {
                                      QString data = ui->tab_rev->model()->data(ui->tab_rev->model()->index(row, column)).toString().simplified();
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

void youssef::on_impression_2_clicked() //imprimer depense
{click->setMedia(QUrl::fromLocalFile("C:/Users/achou/Desktop/gestion de comptabilite/maquetteqt/Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    QString strStream;
    QTextStream out(&strStream);
    const int rowCount = ui->tab_dep->model()->rowCount();
    const int columnCount = ui->tab_dep->model()->columnCount();
    for (int column = 0; column < columnCount; column++)
        if (!ui->tab_dep->isColumnHidden(column)){
            out << QString("<td>\t\t\t%1\t\t\t</td>").arg(ui->tab_dep->model()->headerData(column, Qt::Horizontal).toString());}
    for (int row = 0; row < rowCount; row++) {
        out << "<tr>";
        for (int column = 0; column < columnCount; column++) {
            if (!ui->tab_dep->isColumnHidden(column)) {
                QString data =ui->tab_dep->model()->data(ui->tab_dep->model()->index(row, column)).toString().simplified();
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

}



void youssef::on_pdff_clicked() //pdf depense
{click->setMedia(QUrl::fromLocalFile("C:/Users/achou/Desktop/gestion de comptabilite/maquetteqt/Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    QString strStream;
    QTextStream out(&strStream);

    const int rowCount = ui->tab_dep->model()->rowCount();
    const int columnCount = ui->tab_dep->model()->columnCount();

    out <<  "<html>\n"
        "<head>\n"
        "<meta Content=\"Text/html; charset=Windows-1251\">\n"
        <<  QString("<title>%1</title>\n").arg("strTitle")
        <<  "</head>\n"
        "<body bgcolor=#ffffff link=#5000A0>\n"

       //     "<align='right'> " << datefich << "</align>"
        "<center> <H1>Liste des depenses </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

    // headers
    out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
    for (int column = 0; column < columnCount; column++)
        if (!ui->tab_rev->isColumnHidden(column))
            out << QString("<th>%1</th>").arg(ui->tab_dep->model()->headerData(column, Qt::Horizontal).toString());
    out << "</tr></thead>\n";

    // data table
    for (int row = 0; row < rowCount; row++) {
        out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
        for (int column = 0; column < columnCount; column++) {
            if (!ui->tab_dep->isColumnHidden(column)) {
                QString data = ui->tab_dep->model()->data(ui->tab_dep->model()->index(row, column)).toString().simplified();
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





void youssef::on_impression_3_clicked()  //imprimer produit
{click->setMedia(QUrl::fromLocalFile("C:/Users/achou/Desktop/gestion de comptabilite/maquetteqt/Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    QString strStream;
        QTextStream out(&strStream);
        const int rowCount = ui->tab_produit->model()->rowCount();
        const int columnCount = ui->tab_produit->model()->columnCount();
        for (int column = 0; column < columnCount; column++)
            if (!ui->tab_produit->isColumnHidden(column)){
                out << QString("<td>\t\t\t%1\t\t\t</td>").arg(ui->tab_produit->model()->headerData(column, Qt::Horizontal).toString());}
        for (int row = 0; row < rowCount; row++) {
            out << "<tr>";
            for (int column = 0; column < columnCount; column++) {
                if (!ui->tab_produit->isColumnHidden(column)) {
                    QString data =ui->tab_produit->model()->data(ui->tab_produit->model()->index(row, column)).toString().simplified();
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
}

void youssef::on_pdfff_clicked()   //pdf produit
{click->setMedia(QUrl::fromLocalFile("C:/Users/achou/Desktop/gestion de comptabilite/maquetteqt/Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    QString strStream;
    QTextStream out(&strStream);

    const int rowCount = ui->tab_produit->model()->rowCount();
    const int columnCount = ui->tab_produit->model()->columnCount();

    out <<  "<html>\n"
        "<head>\n"
        "<meta Content=\"Text/html; charset=Windows-1251\">\n"
        <<  QString("<title>%1</title>\n").arg("strTitle")
        <<  "</head>\n"
        "<body bgcolor=#ffffff link=#5000A0>\n"

       //     "<align='right'> " << datefich << "</align>"
        "<center> <H1>Liste des produits </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

    // headers
    out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
    for (int column = 0; column < columnCount; column++)
        if (!ui->tab_rev->isColumnHidden(column))
            out << QString("<th>%1</th>").arg(ui->tab_produit->model()->headerData(column, Qt::Horizontal).toString());
    out << "</tr></thead>\n";

    // data table
    for (int row = 0; row < rowCount; row++) {
        out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
        for (int column = 0; column < columnCount; column++) {
            if (!ui->tab_produit->isColumnHidden(column)) {
                QString data = ui->tab_produit->model()->data(ui->tab_produit->model()->index(row, column)).toString().simplified();
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













void youssef::on_calendarWidget_clicked(const QDate &date1)
{ click->setMedia(QUrl::fromLocalFile("C:/Users/achou/Desktop/gestion de comptabilite/maquetteqt/Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    QSqlQueryModel * modal= new QSqlQueryModel();
    QString sql;
                QString date= ui->calendarWidget->selectedDate().toString("dd/MM/yyyy");
                QSqlQuery request;
                                request.prepare("select * from revenu where date_rev= :date");
                                request.bindValue(":date",date);

                                request.exec();
                                modal->setQuery(request);
                                ui->tab_rev->setModel(modal);
}

void youssef::on_calendarWidget_2_clicked(const QDate &date1)
{ click->setMedia(QUrl::fromLocalFile("C:/Users/achou/Desktop/gestion de comptabilite/maquetteqt/Click.mp3"));
    click->play();
    qDebug()<<click ->errorString();
    QSqlQueryModel * modal= new QSqlQueryModel();
    QString sql;
                QString date= ui->calendarWidget_2->selectedDate().toString("dd/MM/yyyy");
                QSqlQuery request;
                                request.prepare("select * from depense where date_dep= :date");
                                request.bindValue(":date",date);

                                request.exec();
                                modal->setQuery(request);
                                ui->tab_dep->setModel(modal);
}
void youssef::makePolt_2()
{

       QLinearGradient gradient(0, 0, 0, 400);
       gradient.setColorAt(0, QColor(90, 90, 90));
       gradient.setColorAt(0.38, QColor(105, 105, 105));
       gradient.setColorAt(1, QColor(70, 70, 70));
       ui->customPlot_2->setBackground(QBrush(gradient));


       QCPBars *regen = new QCPBars(ui->customPlot_2->xAxis,ui-> customPlot_2->yAxis);

       regen->setAntialiased(false);

       regen->setStackingGap(1);




       regen->setName("Nombre de revenu par rapport a la type");
       regen->setPen(QPen(QColor(0, 168, 140).lighter(130)));
       regen->setBrush(QColor(0, 168, 140));

       QVector<double> ticks;
       QVector<QString> labels;






       ticks << 1<<2<<3;

      labels <<"type1"<<"type2 "<<"type3";
       QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
       textTicker->addTicks(ticks, labels);
       ui->customPlot_2->xAxis->setTicker(textTicker);
       ui->customPlot_2->xAxis->setTickLabelRotation(60);
       ui->customPlot_2->xAxis->setSubTicks(false);
       ui->customPlot_2->xAxis->setTickLength(0, 3);
       ui->customPlot_2->xAxis->setRange(0, 8);
       ui->customPlot_2->xAxis->setBasePen(QPen(Qt::white));
       ui->customPlot_2->xAxis->setTickPen(QPen(Qt::white));
       ui->customPlot_2->xAxis->grid()->setVisible(true);
       //ui->customPlot_2->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
       ui->customPlot_2->xAxis->setTickLabelColor(Qt::white);
       ui->customPlot_2->xAxis->setLabelColor(Qt::white);


       ui->customPlot_2->yAxis->setRange(0,10);
       ui->customPlot_2->yAxis->setPadding(10); // a bit more space to the left border
       ui->customPlot_2->yAxis->setLabel("Nombre de produits par rapport au type");
       ui->customPlot_2->yAxis->setBasePen(QPen(Qt::white));
       ui->customPlot_2->yAxis->setTickPen(QPen(Qt::white));
       ui->customPlot_2->yAxis->setSubTickPen(QPen(Qt::white));
       ui->customPlot_2->yAxis->grid()->setSubGridVisible(true);
       ui->customPlot_2->yAxis->setTickLabelColor(Qt::white);
       ui->customPlot_2->yAxis->setLabelColor(Qt::white);
      // ui->customPlot_2->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
      // ui->customPlot_2->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));


       QVector<double> regenData;
       int n1=0,n2=0,n3=0;

           QSqlQuery q1("select count(*) from revenu where type_rev='type1'");
           while (q1.next())
           {
               n1 = q1.value(0).toInt();
               qDebug()<<"Nombre revenus : "<<n1<<endl;
           }

           QSqlQuery q2("select count(*) from revenu where type_rev='type2'");
           while (q2.next())
           {
               n2 = q2.value(0).toInt();
               qDebug()<<"Nombre revenus : "<<n2<<endl;
           }

           QSqlQuery q3("select count(*) from revenu where type_rev='type3' ");
           while (q3.next())
           {
                n3 = q3.value(0).toInt();
                qDebug()<<"Nombre revenus : "<<n3<<endl;
           }




       regenData << n1<<n2<<n3;
       regen->setData(ticks, regenData);


       ui->customPlot_2->legend->setVisible(true);
       ui->customPlot_2->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
       ui->customPlot_2->legend->setBrush(QColor(255, 255, 255, 100));
       ui->customPlot_2->legend->setBorderPen(Qt::NoPen);
       QFont legendFont = font();
       legendFont.setPointSize(10);
       ui->customPlot_2->legend->setFont(legendFont);
       ui->customPlot_2->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);


}
void youssef::makePolt_3()
{

       QLinearGradient gradient(0, 0, 0, 400);
       gradient.setColorAt(0, QColor(90, 90, 90));
       gradient.setColorAt(0.38, QColor(105, 105, 105));
       gradient.setColorAt(1, QColor(70, 70, 70));
       ui->customPlot_3->setBackground(QBrush(gradient));


       QCPBars *regen = new QCPBars(ui->customPlot_3->xAxis,ui-> customPlot_3->yAxis);

       regen->setAntialiased(false);

       regen->setStackingGap(1);




       regen->setName("Nombre de depense par rapport a la type");
       regen->setPen(QPen(QColor(0, 168, 140).lighter(130)));
       regen->setBrush(QColor(0, 168, 140));

       QVector<double> ticks;
       QVector<QString> labels;






       ticks << 1<<2<<3;

      labels <<"type1"<<"type2 "<<"type3";
       QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
       textTicker->addTicks(ticks, labels);
       ui->customPlot_3->xAxis->setTicker(textTicker);
       ui->customPlot_3->xAxis->setTickLabelRotation(60);
       ui->customPlot_3->xAxis->setSubTicks(false);
       ui->customPlot_3->xAxis->setTickLength(0, 3);
       ui->customPlot_3->xAxis->setRange(0, 8);
       ui->customPlot_3->xAxis->setBasePen(QPen(Qt::white));
       ui->customPlot_3->xAxis->setTickPen(QPen(Qt::white));
       ui->customPlot_3->xAxis->grid()->setVisible(true);
       //ui->customPlot_3->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
       ui->customPlot_3->xAxis->setTickLabelColor(Qt::white);
       ui->customPlot_3->xAxis->setLabelColor(Qt::white);


       ui->customPlot_3->yAxis->setRange(0,10);
       ui->customPlot_3->yAxis->setPadding(10); // a bit more space to the left border
       ui->customPlot_3->yAxis->setLabel("Nombre de produits par rapport au type");
       ui->customPlot_3->yAxis->setBasePen(QPen(Qt::white));
       ui->customPlot_3->yAxis->setTickPen(QPen(Qt::white));
       ui->customPlot_3->yAxis->setSubTickPen(QPen(Qt::white));
       ui->customPlot_3->yAxis->grid()->setSubGridVisible(true);
       ui->customPlot_3->yAxis->setTickLabelColor(Qt::white);
       ui->customPlot_3->yAxis->setLabelColor(Qt::white);
      // ui->customPlot_3->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
      // ui->customPlot_3->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));


       QVector<double> regenData;
       int n1=0,n2=0,n3=0;

           QSqlQuery q1("select count(*) from depense where type_dep='type1'");
           while (q1.next())
           {
               n1 = q1.value(0).toInt();
               qDebug()<<"Nombre depenses : "<<n1<<endl;
           }

           QSqlQuery q2("select count(*) from depense where type_dep='type2'");
           while (q2.next())
           {
               n2 = q2.value(0).toInt();
               qDebug()<<"Nombre depenses : "<<n2<<endl;
           }

           QSqlQuery q3("select count(*) from depense where type_dep='type3' ");
           while (q3.next())
           {
                n3 = q3.value(0).toInt();
                qDebug()<<"Nombre depenses : "<<n3<<endl;
           }




       regenData << n1<<n2<<n3;
       regen->setData(ticks, regenData);


       ui->customPlot_3->legend->setVisible(true);
       ui->customPlot_3->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
       ui->customPlot_3->legend->setBrush(QColor(255, 255, 255, 100));
       ui->customPlot_3->legend->setBorderPen(Qt::NoPen);
       QFont legendFont = font();
       legendFont.setPointSize(10);
       ui->customPlot_3->legend->setFont(legendFont);
       ui->customPlot_3->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);


}
