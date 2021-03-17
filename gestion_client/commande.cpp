#include "commande.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
Commande::Commande()
{
id_com=0; date_com=" ";  nombre_come=0;
}

Commande::Commande(int id_com,QString date_com,int nombre_come)
{this->id_com=id_com; this->date_com=date_com; this->nombre_come=nombre_come;  }
int Commande::getid_com(){return id_com;}
QString Commande::getdate_com(){return  date_com;}
int Commande::getnombre_come(){return nombre_come;}

void Commande::setid_com(int id_com){this->id_com=id_com;}
void Commande::setdate_com(QString date_com){this->date_com=date_com;}
void Commande::setnombre_come(int nombre_come){this->nombre_come=nombre_come;}
bool Commande::ajoutercom()
{

    QSqlQuery query;
  QString id_string= QString::number(id_com);
         query.prepare("INSERT INTO commande (id_com, date_com, nombre_come) "
                       "VALUES (:id, :forename, :nombrec)");
         query.bindValue(":id",id_string);
         query.bindValue(":forename", date_com);
          query.bindValue(":nombrec", nombre_come);
        return query.exec();

}
bool Commande::supprimercom(int id_com)
{
    QSqlQuery query;
         query.prepare(" Delete from commande where id_com=:id");
         query.bindValue(0, id_com);

        return query.exec();


}
QSqlQueryModel* Commande::affichercom()
{
  QSqlQueryModel* model=new QSqlQueryModel();


   model->setQuery("SELECT* FROM commande");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_com"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("date_com"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("nombre_come"));



  return  model;
}
