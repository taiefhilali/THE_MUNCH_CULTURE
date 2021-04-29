

#include "stocks.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QTranslator>
#include <QString>
#include <QDateTime>
#include <QSqlDatabase>
#include <QSqlError>
#include "ui_pdf.h"
#include<QSqlQuery>
#include<QMessageBox>
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QString>

stocks::stocks()
{
    id=0;
    dat="";
    prix=0;
    quantite=0;
    nom="";
    type="";

}
stocks::stocks(int id,QString dat ,int prix,int quantite,QString nom,QString type)
{
  this->id=id;
    this->dat=dat;
    this->prix=prix;
    this->quantite=quantite;
    this->nom=nom;
     this->type=type;

}
int stocks::getid(){return id;}
void stocks::setid(int id){this->id=id;}
QString stocks::get_dat(){return dat;}
int stocks::get_prix(){return prix;}
int stocks::get_quantite(){return quantite;}
QString stocks::get_noms(){return nom;}
QString stocks::get_type(){return type;}
bool stocks::ajouter()
{
    QSqlQuery query;
    QString res= QString::number(id);

    query.prepare("INSERT INTO stock (dat,prix,quantite,nom,type) VALUES (:dat,:prix,:quantite,:nom,:type)");
   query.bindValue(":id",res);
    query.bindValue(":dat",dat);
    query.bindValue(":prix",prix);
    query.bindValue(":quantite",quantite);
    query.bindValue(":nom",nom);
    query.bindValue(":type",type);

return  query.exec();

}

QSqlQueryModel * stocks::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from stock");
   // model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("dat"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prix(dt)"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("quantite"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("type"));

 return model;

}

bool stocks::supprimer(int id)
{
    QSqlQuery query;
    QString res= QString::number(id);
    query.prepare("delete from stock where id = :id");
    query.bindValue(":id",res);
    return query.exec();
}
bool stocks::modifier(Ui::gsf *ui){


     int id= ui->id->text().toInt();
     QString dat = ui->dat_2->selectedDate().toString();
     int prix= ui->prix_2->text().toInt();
     int quantite= ui->quantite_2->text().toInt();
     QString nom = ui->noms1->text();
     QString type= ui->type_2->currentText();
     stocks S(id,dat,prix,quantite,nom,type);

     QSqlQuery query;
        query.prepare("UPDATE stock SET dat ='"+dat+"',prix='"+QString::number(prix)+"',quantite='"+QString::number(quantite)+"',nom ='"+nom+"',type ='"+type+"' WHERE id= '"+QString::number(id)+"'");
        query.bindValue(":id",getid());
        query.bindValue(":dat",get_dat());
        query.bindValue(":Prix",get_prix());
        query.bindValue(":quantite",get_quantite());
        query.bindValue(":nom",get_noms());
        query.bindValue(":type",get_type());


              return query.exec();

       }

void stocks::Rechercherstocks(int id){
        QSqlQuery query2;


        query2.prepare ("SELECT * FROM stock WHERE id= '"+QString::number(id)+"'");
        query2.exec();

        while(query2.next()){
            id= query2.value(0).toInt();
            dat= query2.value(1).toString();
            prix=query2.value(2).toInt();
            quantite= query2.value(3).toInt();
            nom= query2.value(4).toString();
            type= query2.value(5).toString();
        }


    }

QSqlQueryModel * stocks::Trier(QString choix1){
    QSqlQueryModel *model=new QSqlQueryModel();


    if (choix1=="id"){
         model->setQuery("SELECT * FROM stock ORDER BY id DESC ");
    }
    else if(choix1=="dat"){
         model->setQuery("SELECT * FROM stock ORDER BY dat ");
    }
    else if(choix1=="prix"){
        model->setQuery("SELECT * FROM stock ORDER BY prix DESC ");
    }
    else if(choix1=="quantite"){
        model->setQuery("SELECT * FROM stock ORDER BY quantite DESC ");
    }
    else if(choix1=="nom"){
        model->setQuery("SELECT * FROM stock ORDER BY nom  ");
    }
    else if(choix1=="type"){
        model->setQuery("SELECT * FROM stock ORDER BY type  ");
    }


    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("dat"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prix(dt)"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("quantite"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("nom"));
     model->setHeaderData(5, Qt::Horizontal, QObject::tr("type"));

return model;
}
void stocks::pdffonction(QString code)
{
        QPrinter printer;
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setOutputFileName("C:/Users/taief/Documents/stock/taieff.pdf");
        QPainter painter;
        painter.begin(&printer);

        QFont font;

        QSqlQuery query;
        QString idd, id,qt,nom,typeanim_pdf,id_pdf,nb_pdf,type_pdf,idanimation_pdf,lieu_pdf,dateanim_pdf,duree_pdf,cin_pdf;


        if (code=="stock")
        {
            query.prepare("select * from stock where id='"+code+"'");
            if (query.exec())
            {
                while (query.next())
                {   id=query.value(0).toString();
                    nb_pdf=query.value(1).toString();
                    type_pdf=query.value(3).toString();
                    idanimation_pdf=query.value(2).toString();
                    nom=query.value(4).toString();

                }
            }
            font.setPixelSize(50);
            painter.setFont(font);
            painter.setPen(Qt::red);
            painter.drawText(350,150,"stock");

            font.setPixelSize(35);
            painter.setFont(font);
            painter.setPen(Qt::blue);
            painter.drawText(20,300,"id: ");
            painter.drawText(20,500,"dat:");
            painter.drawText(20,650,"prix:");
            painter.drawText(20,800,"quantite:");
            painter.drawText(20,950,"nom:");


            font.setPixelSize(22);
            painter.setFont(font);
            painter.setPen(Qt::black);
            painter.drawText(300,500,nb_pdf);
            painter.drawText(300,300,id);
            painter.drawText(300,650,idanimation_pdf);
             painter.drawText(300,800,type_pdf);
              painter.drawText(300,950,nom);

        }


        /*QImage image("C:/User/taief/Documents/stock/pdf.png");
        painter.drawImage(10,10,image);
        painter.end();
        qDebug()<<"le pdf a ete cree";
        QMessageBox::information(this,"pdf cree","ce pdf a ete cree");*/
        /*QImage image("C:/Users/taief/Documents/stock/pdf.png");
             painter.drawImage(30,30,image);*/
             QImage image1("C:/Users/taief/Documents/stock/s.png");
             painter.drawImage(10,10,image1);

             painter.end();
             qDebug()<<"le pdf a ete cree";
           //  QMessageBox::information(this,"pdf cree","ce pdf a ete cree");
}
int stocks::get_total()
{
    QSqlQuery query;
    query.prepare("SELECT prix FROM stock ");
 int total=0;
    if(query.exec())
    {
        while (query.next())
        {
            total+=query.value(0).toInt();
        }
    }
    return total;
}
bool stocks::suppAffectation(QString nom)
{
    QSqlQuery query;

   query.prepare("delete from stock where nom=:nom");
   query.bindValue(":nom", nom);

   return query.exec();

}
