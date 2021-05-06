#include "livreur.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>

livreur::livreur()
{
    id=0;
    nom="";
    prenom="";
    numtel=0;
    salaire=0;

}
livreur::livreur(QString nom,QString prenom,int numtel,int salaire)
{
  this->id=id;
    this->nom=nom;
    this->prenom=prenom;
    this->numtel=numtel;
    this->salaire=salaire;}
      //int livreur::get_id(){return id;}
int livreur::getid(){return id;}
void livreur::setid(int id){this->id=id;}
    QString livreur::get_nom(){return nom;}
    QString livreur::get_prenom(){return prenom;}
    int livreur::get_numtel(){return numtel;}
    int livreur::get_salaire(){return salaire;}
    bool livreur::ajouter()
    {
        QSqlQuery query;
        QString res= QString::number(id);
        query.prepare("INSERT INTO livreur (nom,prenom,numtel,salaire) VALUES (:nom,:prenom,:numtel,:salaire)");
     //query.bindValue(":id",res);
        query.bindValue(":nom",nom);
        query.bindValue(":prenom",prenom);
        query.bindValue(":numtel",numtel);
        query.bindValue(":salaire",salaire);
    return  query.exec();

    }
    QSqlQueryModel * livreur::afficher()
    {QSqlQueryModel * model= new QSqlQueryModel();
        model->setQuery("select * from livreur");
       // model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("numtel"));
        model->setHeaderData(6, Qt::Horizontal, QObject::tr("salaire"));
        return model;

        }
    bool livreur::supprimer(int id)
    {
        QSqlQuery query;
        QString res= QString::number(id);
        query.prepare("delete from livreur where id = :id");
        query.bindValue(":id",res);
        return query.exec();
    }
    bool livreur::modif(int id,QString nom,QString prenom,int numtel,int salaire)
    {
        QSqlQuery query;
        QString res=QString::number(id);
        query.prepare("update livreur set nom=:nom,prenom=:prenom,numtel=:numtel,salaire=:salaire where id= :id");
            query.bindValue(":id",res);
            query.bindValue(":nom",nom);
            query.bindValue(":prenom",prenom);
            query.bindValue(":numtel",numtel);
            query.bindValue(":salaire",salaire);
            return query.exec();
        }
    int livreur::get_total()
        {
            QSqlQuery query;
            query.prepare("SELECT salaire FROM livreur ");
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
