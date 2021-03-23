#include "livraison.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>

livraison::livraison()
{
    adr="";
    date="";
}
livraison::livraison(QString adr,QString date)
{
  this->id=id;
    this->adr=adr;
    this->date=date;
}
int livraison::getid(){return id;}
void livraison::setid(int id){this->id=id;}
QString livraison::get_adr(){return adr;}
QString livraison::get_date(){return date;}
bool livraison::ajouter()
{
    QSqlQuery query;
    QString res= QString::number(id);
    query.prepare("INSERT INTO livraison (adr,datee) VALUES (:adr,:date)");
    query.bindValue(":adr",adr);
    query.bindValue(":date",date);
    return  query.exec();

}
QSqlQueryModel * livraison::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from livraison");
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("adr"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("datee"));
        return model;

}
bool livraison::supprimer(int id)
{
    QSqlQuery query;
    QString res= QString::number(id);
    query.prepare("delete from livraison where id = :id");
    query.bindValue(":id",res);
    return query.exec();
}
bool livraison::modifE(int id,QString adr,QString date)
{
    QSqlQuery query;
    QString res=QString::number(id);
    query.prepare("update livraison set adr=:adr,datee=:date where id= :id");
    query.bindValue(":id",res);
    query.bindValue(":adr",adr);
    query.bindValue(":date",date);



    return query.exec();
}
