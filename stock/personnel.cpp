#include "personnel.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QString>
#include <QBuffer>
#include <cstdlib>
#include <QImage>

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
         query.prepare("INSERT INTO personnel (id, nom, prenom,mdp,date_emb,salaire,type,image) "
                       "VALUES (:id, :nom, :prenom,:mdp,:date_emb,:salaire,:type,:image)");
         query.bindValue(":id",id);
         query.bindValue(":nom", nom);
         query.bindValue(":prenom", prenom);
         query.bindValue(":mdp",mdp);
         query.bindValue(":date_emb", date_emb);
         query.bindValue(":salaire", salaire);
         query.bindValue(":type", type);
         query.bindValue(":image", image, QSql::Binary);

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
bool personnel:: modifier(QString nom,QString prenom,QString mdp,QString date_emb,QString salaire,QString type,QString id )
{       QSqlQuery query;
         query.prepare("UPDATE personnel set ID=:id,nom=:nom,PRENOM=:prenom ,MDP=:mdp,date_emb=:date_emb,SALAIRE=:salaire,TYPE=:type where ID= :id ");
         query.bindValue(":id",id);
         query.bindValue(":nom", nom);
         query.bindValue(":prenom", prenom);
         query.bindValue(":mdp",mdp);
         query.bindValue(":date_emb", date_emb);
         query.bindValue(":salaire", salaire);
         query.bindValue(":type", type);

        return    query.exec();

}


QSqlQueryModel* personnel::afficherselonid()// tri

{
    QSqlQueryModel* model=new QSqlQueryModel() ;
   QSqlQuery *query=new QSqlQuery;
   query->prepare("select * from personnel ORDER BY ID  ") ;
   query->exec() ;
   model->setQuery(*query) ;



return model;

}
QSqlQueryModel * personnel::rechercheid(QString id)

{
    QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery query;

    query.prepare("select * from personnel where ID=:ID");
    query.bindValue(":ID", id);


    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id personnel"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom personnel"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom personnel"));
    //  model->setHeaderData(3, Qt::Horizontal, QObject::tr("comboBox_personnel"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("mdp personnel"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("date_emb personnel"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("salaire personnel"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("type personnel"));

       return model;

}
//QSqlQueryModel * personnel::rechercher_personnel(QString valeur)
//{
//    QSqlQueryModel * model= new QSqlQueryModel();
//    model->setQuery("select * from personnelS where nom_personnel='"+valeur+"' ");

//    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id personnel"));
//    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom personnel"));
//    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom personnel"));
//    //  model->setHeaderData(3, Qt::Horizontal, QObject::tr("comboBox_personnel"));
//    model->setHeaderData(4, Qt::Horizontal, QObject::tr("mdp personnel"));
//    model->setHeaderData(5, Qt::Horizontal, QObject::tr("date_emb personnel"));
//    model->setHeaderData(6, Qt::Horizontal, QObject::tr("salaire personnel"));
//    model->setHeaderData(7, Qt::Horizontal, QObject::tr("type personnel"));

//        return model;
//}

QByteArray personnel:: GetImage()
{
    return this->image;
}

void  personnel::AjoutImage(QString fileName){


    if (fileName.isEmpty())
    {
        qDebug()<<"EMPTY EMPTY !!!!!";

        fileName="personnel-image_standard.png";

    }
    QImage imageTMP(fileName);

    QByteArray byteArray;

    QBuffer buffer(&byteArray);

    imageTMP.save(&buffer, "PNG");

    image=byteArray;
}
