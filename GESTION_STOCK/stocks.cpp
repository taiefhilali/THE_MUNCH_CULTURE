

#include "stocks.h"
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

}
stocks::stocks(QString dat ,int prix,int quantite)
{
  this->id=id;
    this->dat=dat;
    this->prix=prix;
    this->quantite=quantite;

}
int stocks::getid(){return id;}
void stocks::setid(int id){this->id=id;}
QString stocks::get_dat(){return dat;}
int stocks::get_prix(){return prix;}
int stocks::get_quantite(){return quantite;}
bool stocks::ajouter()
{
    QSqlQuery query;
    QString res= QString::number(id);
    query.prepare("INSERT INTO stock (dat,prix,quantite) VALUES (:dat,:prix,:quantite)");
 //   query.bindValue(":id",res);
    query.bindValue(":dat",dat);
    query.bindValue(":prix",prix);
    query.bindValue(":quantite",quantite);

return  query.exec();

}

QSqlQueryModel * stocks::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from stock");
   // model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("dat"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prix"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("quantite"));

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
