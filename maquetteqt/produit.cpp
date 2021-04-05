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

    tot_produit=0;
    type_produit="";
}
Produit::Produit(int id_produit,int tot_produit,QString type_produit)
{
  this->id_produit=id_produit;

    this->tot_produit=tot_produit;
    this->type_produit=type_produit;
}
int Produit::getid_produit(){return id_produit;}
void Produit::setid_produit(int id_produit){this->id_produit=id_produit;}

int Produit::gettot_produit(){return tot_produit;}
QString Produit::gettype_produit(){return type_produit;}

bool Produit::ajouter()
{
    QSqlQuery query;
    //QString idproduit= QString::number(id_produit);
    //QString totproduit= QString::number(tot_produit);

    query.prepare("INSERT INTO produit (id_produit,tot_produit,type_produit) VALUES (:id_produit,:tot_produit,:type_produit)");
   query.bindValue(":id_produit",id_produit);

    query.bindValue(":tot_produit",tot_produit);
    query.bindValue(":type_produit",type_produit);
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
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("tot_produit"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("type_produit"));



  return  model;
}

bool Produit::modifier(int id_produit,int tot_produit, QString type_produit)
{
    QSqlQuery query;

    QString idproduit=QString::number(id_produit);
     QString totproduit=QString::number(tot_produit);




    query.prepare("update PRODUIT set tot_produit=tot_produit, type_produit=type_produit where id_produit= :id_produit");

    query.bindValue(":id_produit",idproduit);
    query.bindValue(":tot_produit",totproduit);
    query.bindValue(":type_produit",type_produit);



    return query.exec();
}

QSqlQueryModel * recherche_4(int id_produit)
 {
     QSqlQueryModel* model = new QSqlQueryModel();
      model->setQuery("select * from produit where (id_produit LIKE id_produit='"+QString::number(id_produit)+"'");
      model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_produit"));
      model->setHeaderData(1, Qt::Horizontal, QObject::tr("tot_produit "));
      model->setHeaderData(3, Qt::Horizontal, QObject::tr("type_produit "));


          return model;




 }
QSqlQueryModel * Produit::Trierproduit(QString choix1){
    QSqlQueryModel *model=new QSqlQueryModel();


    if (choix1=="id_produit"){
         model->setQuery("SELECT * FROM Produit ORDER BY id_produit DESC ");
    }
    else if(choix1=="tot_produit"){
         model->setQuery("SELECT * FROM Produit ORDER BY tot_produit ");
    }else if(choix1=="type_produit"){
        model->setQuery("SELECT * FROM Produit ORDER BY type_produit ");}



    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_produit"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("tot_produit"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("type_produit"));



return model;
}


