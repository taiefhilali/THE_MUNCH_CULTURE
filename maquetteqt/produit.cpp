#include "produit.h"

#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QString>
#include <QSqlDatabase>
#include <QSqlError>
#include <QFile>

Produit::Produit()
{
    id_produit=0;
    nom_produit="";
    tot_produit=0;
    type_produit="";
    date_produit="";
}
Produit::Produit(int id_produit,QString nom_produit,QString type_produit,int tot_produit,QString date_produit)
{
  this->id_produit=id_produit;
    this->nom_produit=nom_produit;
    this->type_produit=type_produit;
    this->tot_produit=tot_produit;
    this->date_produit=date_produit;

}
int Produit::getid_produit(){return id_produit;}
void Produit::setid_produit(int id_produit){this->id_produit=id_produit;}

QString Produit::getnom_produit(){return nom_produit;}
QString Produit::gettype_produit(){return type_produit;}
int Produit::gettot_produit(){return tot_produit;}
QString Produit::getdate_produit(){return date_produit;}

bool Produit::ajouter()
{
    QSqlQuery query;
    //QString idproduit= QString::number(id_produit);
    //QString totproduit= QString::number(tot_produit);

    query.prepare("INSERT INTO produit (id_produit,nom_produit,type_produit,tot_produit,date_produit) VALUES (:id_produit,:nom_produit,:type_produit,:tot_produit,:date_produit)");
   query.bindValue(":id_produit",id_produit);
   query.bindValue(":nom_produit",nom_produit);
   query.bindValue(":type_produit",type_produit);
   query.bindValue(":tot_produit",tot_produit);
   query.bindValue(":date_prduit",date_produit);

return  query.exec();

}
bool Produit::supprimer(int  id_produit)
{
    QSqlQuery query;
         query.prepare(" Delete from PRODUIT where id_produit=:id_produit");
         query.bindValue(0,  id_produit);

        return query.exec();


}
QSqlQueryModel* Produit::afficher()
{
  QSqlQueryModel* model=new QSqlQueryModel();


   model->setQuery("SELECT* FROM PRODUIT");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_produit"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom_produit"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("type_produit"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("tot_produit"));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr("date_produit"));



  return  model;
}

bool Produit::modifier(int id_produit,QString nom_produit, QString type_produit,int tot_produit,QString date_produit)
{
    QSqlQuery query;

    QString res3=QString::number(id_produit);
    QString res4=QString(nom_produit);
    QString res5=QString(type_produit);
    QString res6=QString::number(tot_produit);
    QString res7=QString(date_produit);

    query.prepare("update PRODUIT set id_produit=id_produit, nom_produit=nom_produit, type_produit=type_produit, tot_produit=tot_produit, date_produit=date_produit where id_produit= :id_produit");

    query.bindValue(":id_produit",res3);
    query.bindValue(":nom_produit",res4);
    query.bindValue(":type_produit",res5);
    query.bindValue(":tot_produit",res6);
    query.bindValue(":date_produit",res7);




    return query.exec();

}

QSqlQueryModel * recherche_4(int id_produit)
 {


         QSqlQueryModel* model = new QSqlQueryModel();
          model->setQuery("select * from PRODUIT where (id_produit LIKE id_produit='"+QString::number(id_produit)+"'");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_produit"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom_produit"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("type_produit "));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("tot_produit "));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("date_produit "));


              return model;




 }
QSqlQueryModel * Produit::Trierproduit(const QString &critere, const QString &mode){



    QSqlQueryModel *model=new QSqlQueryModel();




model->setQuery("select * from produit order by "+critere+" "+mode+"");

    return model;
}


