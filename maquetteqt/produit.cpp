#include "produit.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
Produit::Produit()
{
id_produit=0; tot_produit=0; ;
}
Produit::Produit(int id_produit,int tot_produit)
{this-> id_produit=id_produit; this-> tot_produit=tot_produit; }
int Produit::getid_produit(){return id_produit;}
int Produit::gettot_produit(){return tot_produit;}

void Produit::setid_produit(int id_produit){this-> id_produit=id_produit;}
void Produit::settot_produit(int tot_produit){this-> tot_produit=tot_produit;}

bool Produit::ajouter()
{
    QSqlQuery query;
  QString id_string= QString::number(id_produit);
  QString totproduit= QString::number(tot_produit);


         query.prepare("INSERT INTO PRODUIT (id_produit,tot_produit) "
                                   "VALUES (:id_produit, :tot_produit)");
         query.bindValue(":id_produit",id_string);
         query.bindValue(":tot_produit", totproduit);


        return query.exec();
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




  return  model;
}
