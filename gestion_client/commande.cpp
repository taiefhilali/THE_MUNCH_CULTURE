#include "commande.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QString>
#include <QSqlDatabase>
#include <QSqlError>
#include <QFile>
#include <QSqlQueryModel>
Commande::Commande()
{
id_com=0; date_com=" ";  nombre_come=0; type_com="";
}

Commande::Commande(int id_com,QString date_com,int nombre_come,QString type_com)
{this->id_com=id_com; this->date_com=date_com; this->nombre_come=nombre_come; this->type_com=type_com; }
int Commande::getid_com(){return id_com;}
QString Commande::getdate_com(){return  date_com;}
int Commande::getnombre_come(){return nombre_come;}
QString Commande::gettype_com(){return type_com;}


void Commande::setid_com(int id_com){this->id_com=id_com;}
void Commande::setdate_com(QString date_com){this->date_com=date_com;}
void Commande::setnombre_come(int nombre_come){this->nombre_come=nombre_come;}
void Commande::settype_com(QString type_com){this->type_com=type_com;}

bool Commande::ajoutercom()
{

    QSqlQuery query;
  QString id_string= QString::number(id_com);
         query.prepare("INSERT INTO commande (id_com, date_com, nombre_come,type_com) "
                       "VALUES (:id, :forename, :nombrec ,:typecom)");
         query.bindValue(":id",id_string);
         query.bindValue(":forename", date_com);
          query.bindValue(":nombrec", nombre_come);
           query.bindValue(":typecom", type_com);
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
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("type_com"));


  return  model;
}
QSqlQueryModel * Commande::Triercom(const QString &critere, const QString &mode){
    QSqlQueryModel *model=new QSqlQueryModel();

model->setQuery("select * from Commande order by "+critere+" "+mode+"");


return model;
}
bool Commande::modifC(int id_com,QString date_com,int nombre_come,QString type_com)
{
    QSqlQuery query;
    QString res=QString::number(id_com);
    QString res2=QString::number(nombre_come);

    query.prepare("update Commande set id_com=:id_com,date_com=:date_com,nombre_come=:nombre_come,type_com=:type_com where id_com= :id_com");
    query.bindValue(":id_cli",res);
    query.bindValue(":date_com",date_com);
    query.bindValue(":nombre_come",res2);
     query.bindValue(":type_com",type_com);



    return query.exec();
}
QSqlQueryModel * Commande::recherche_com(int id_com)
{
    QSqlQueryModel* model = new QSqlQueryModel();
     model->setQuery("select * from Commande where (id_com LIKE id_com='"+QString::number(id_com)+"'");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_com"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("date_com "));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("nombre_come"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("type_com"));

         return model;
}

int Commande::get_total()
{
    QSqlQuery query;
    query.prepare("SELECT nombre_come FROM Commande ");
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
