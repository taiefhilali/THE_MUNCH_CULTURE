#include "commande.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QString>
#include <QSqlDatabase>
#include <QSqlError>
#include <QFile>
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
QSqlQueryModel * Commande::Triercom(QString choix1){
    QSqlQueryModel *model=new QSqlQueryModel();


    if (choix1=="id_com"){
         model->setQuery("SELECT * FROM Commande ORDER BY id_com DESC ");
    }
    else if(choix1=="date_com"){
         model->setQuery("SELECT * FROM Commande ORDER BY date_com ");
    }
    else if(choix1=="nombre_come"){
        model->setQuery("SELECT * FROM Commande ORDER BY nombre_come DESC  ");
    }


    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_com"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("date_com"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("nombre_come "));


return model;
}
bool Commande::modifC(int id_com,QString date_com,int nombre_come)
{
    QSqlQuery query;
    QString res=QString::number(id_com);
    QString res2=QString::number(nombre_come);

    query.prepare("update Commande set id_com=:id_com,date_com=:date_com,nombre_come=:nombre_come where id_com= :id_com");
    query.bindValue(":id_cli",res);
    query.bindValue(":date_com",date_com);
    query.bindValue(":nombre_come",res2);



    return query.exec();
}
