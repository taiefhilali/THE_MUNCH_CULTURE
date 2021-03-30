#include "personnel.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QString>


personnel::personnel()
{
id="";
nom=" ";
prenom="";
mdp="" ;
date_emb="" ;
salaire="" ;
type="" ;
}

personnel::personnel(QString id,QString nom,QString prenom,QString mdp,QString date_emb,QString salaire, QString type)
{this->id=id;
this->nom=nom;
this->prenom=prenom;
this->mdp=mdp;
this->date_emb=date_emb ;
this->salaire=salaire ;
this->type=type ;
}
QString personnel::getid(){return id;}
QString personnel::getnom(){return  nom;}
QString personnel::getprenom(){return prenom;}
QString personnel::  getmdp()
{return mdp ;}
QString personnel:: getdate_emb()
{
   return date_emb ;
}
QString personnel ::  getsalaire()
{
    return salaire;
}
QString personnel :: gettype()
{return type;
}
void personnel :: setid(QString id)
{
    this->id=id;
}
void personnel :: setnom(QString nom )
{this->nom=nom;}
void personnel :: setprenom(QString prenom)
{this->prenom=prenom;}
void personnel :: setmdp(QString mdp)
{this->mdp=mdp;}
void personnel :: setdate_emb(QString date_emb)
{this->date_emb=date_emb;}
void personnel :: setsalaire(QString salaire)
{this->salaire=salaire;}
void personnel :: settype(QString type)
{this->type=type;}
bool personnel::ajouter()
{

    QSqlQuery query;
         query.prepare("INSERT INTO personnel (id, nom, prenom,mdp,date_emb,salaire,type) "
                       "VALUES (:id, :nom, :prenom,:mdp,:date_emb,:salaire,:type)");
         query.bindValue(":id",id);
         query.bindValue(":nom", nom);
         query.bindValue(":prenom", prenom);
         query.bindValue(":mdp",mdp);
         query.bindValue(":date_emb", date_emb);
         query.bindValue(":salaire", salaire);
         query.bindValue(":type", type);

        return query.exec();

}
bool personnel::supprimer(QString id)
{
    QSqlQuery query;
         query.prepare(" Delete from personnel where id=:id");
         query.bindValue(0, id);

        return query.exec();


}
QSqlQueryModel* personnel::afficher()
{
  QSqlQueryModel* model=new QSqlQueryModel();


   model->setQuery("SELECT* FROM personnel");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identenfiant"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("mdp"));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr("date_emb"));
   model->setHeaderData(5, Qt::Horizontal, QObject::tr("salaire"));
   model->setHeaderData(6, Qt::Horizontal, QObject::tr("type"));

  return  model;
}
