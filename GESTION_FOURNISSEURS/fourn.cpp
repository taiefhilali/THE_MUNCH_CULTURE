#include "fourn.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QString>
fourn::fourn()
{
    id=0;
    nom="";
    prenom="";
    tel=0;
    adresse="";
}
fourn::fourn(QString nom,QString prenom,int tel,QString adresse)
{
  this->id=id;
    this->nom=nom;
    this->prenom=prenom;
    this->tel=tel;
    this->adresse=adresse;
}
int fourn::getid(){return id;}
void fourn::setid(int id){this->id=id;}
QString fourn::get_nom(){return nom;}
QString fourn::get_prenom(){return prenom;}
int fourn::get_tel(){return tel;}
QString fourn::get_adresse(){return adresse;}

bool fourn::ajouter()
{
    QSqlQuery query;
    QString res= QString::number(id);
    query.prepare("INSERT INTO fourn (nom,prenom,tel,adresse) VALUES (:nom,:prenom,:tel,:adresse)");
 //   query.bindValue(":id",res);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":tel",tel);
    query.bindValue(":adresse",adresse);
return  query.exec();

}

QSqlQueryModel * fourn::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from fourn");
   // model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("tel"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("adresse"));
 return model;

}

bool fourn::supprimer(int id)
{
    QSqlQuery query;
    QString res= QString::number(id);
    query.prepare("delete from fourn where id = :id");
    query.bindValue(":id",res);
    return query.exec();
}
