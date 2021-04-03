

#include "stocks.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QString>
#include <QDateTime>
#include <QSqlDatabase>
#include <QSqlError>
stocks::stocks()
{
    id=0;
    dat="";
    prix=0;
    quantite=0;
    nom="";

}
stocks::stocks(int id,QString dat ,int prix,int quantite,QString nom)
{
  this->id=id;
    this->dat=dat;
    this->prix=prix;
    this->quantite=quantite;
    this->nom=nom;

}
int stocks::getid(){return id;}
void stocks::setid(int id){this->id=id;}
QString stocks::get_dat(){return dat;}
int stocks::get_prix(){return prix;}
int stocks::get_quantite(){return quantite;}
QString stocks::get_noms(){return nom;}
bool stocks::ajouter()
{
    QSqlQuery query;
    QString res= QString::number(id);
    query.prepare("INSERT INTO stock (dat,prix,quantite,nom) VALUES (:dat,:prix,:quantite,:nom)");
 //   query.bindValue(":id",res);
    query.bindValue(":dat",dat);
    query.bindValue(":prix",prix);
    query.bindValue(":quantite",quantite);
    query.bindValue(":nom",nom);

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
     stocks S(id,dat,prix,quantite,nom);

     QSqlQuery query;
        query.prepare("UPDATE stock SET dat ='"+dat+"',prix='"+QString::number(prix)+"',quantite='"+QString::number(quantite)+"',nom ='"+nom+"' WHERE id= '"+QString::number(id)+"'");
        query.bindValue(":id",getid());
        query.bindValue(":dat",get_dat());
        query.bindValue(":Prix",get_prix());
        query.bindValue(":quantite",get_quantite());
        query.bindValue(":nom",get_noms());


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


    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("dat"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prix(dt)"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("quantite"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("nom"));

return model;
}
