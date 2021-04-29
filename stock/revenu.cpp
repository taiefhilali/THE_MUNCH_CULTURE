#include "revenu.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QDateEdit>

Revenu::Revenu()
{
id_rev=0;
tot_rev=0;
type_rev="";
date_rev="";
}
Revenu::Revenu(int id_rev,int tot_rev,QString type_rev, QString date_rev)
{this-> id_rev=id_rev; this-> tot_rev=tot_rev;  this-> type_rev=type_rev; this-> date_rev=date_rev; }
int Revenu::getid_rev(){return id_rev;}
int Revenu::gettot_rev(){return tot_rev;}
QString Revenu::gettype_rev(){return type_rev;}
QString Revenu::getdate_rev(){return date_rev;}


void Revenu::setid_rev(int id_rev){this-> id_rev=id_rev;}
void Revenu::settot_rev(int tot_rev){this-> tot_rev=tot_rev;}
void Revenu::settype_rev(QString type_rev){this-> type_rev=type_rev;}
void Revenu::setdate_rev(QString date_rev){this-> date_rev=date_rev;}


bool Revenu::ajouter()
{
    QSqlQuery query;

  QString idrev= QString::number(id_rev);
  QString totrev= QString::number(tot_rev);
  QString typerev= QString(type_rev);
  QString daterev= QString(date_rev);


         query.prepare("INSERT INTO REVENU (id_rev,tot_rev,type_rev,date_rev) "
                                   "VALUES ( :id_rev,:tot_rev,:type_rev,:date_rev)");

         query.bindValue(":id_rev", id_rev);
         query.bindValue(":tot_rev", tot_rev);
         query.bindValue(":type_rev", type_rev);
         query.bindValue(":date_rev", date_rev);

        return query.exec();
}
bool Revenu::supprimer(int  id_rev)
{
    QSqlQuery query;
         query.prepare(" Delete from REVENU where id_rev=:id_rev");
         query.bindValue(0,  id_rev);

        return query.exec();


}
QSqlQueryModel* Revenu::afficher()
{
  QSqlQueryModel* model=new QSqlQueryModel();


   model->setQuery("SELECT* FROM REVENU");

   model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_rev"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("tot_rev"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("type_rev"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("date_rev"));



  return  model;

}

bool Revenu::modifier(int id_rev,int tot_rev,QString type_rev,QString date_rev)
{
    QSqlQuery query;

    QString res3=QString::number(id_rev);
    QString res4=QString::number(tot_rev);
    QString res5=QString(type_rev);
    QString res6=QString(date_rev);



    query.prepare("update REVENU set id_rev=id_rev,tot_rev=tot_rev,type_rev=type=rev,date_rev=date_rev where id_rev= :id_rev");

    query.bindValue(":id_rev",res3);
    query.bindValue(":tot_rev",res4);
    query.bindValue(":type_rev",res5);
    query.bindValue(":date_rev",res6);




    return query.exec();
}
QSqlQueryModel * recherche14(int id_rev)
 {
     QSqlQueryModel* model = new QSqlQueryModel();
      model->setQuery("select * from REVENU where (id_rev LIKE id_rev='"+QString::number(id_rev)+"'");
      model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_rev"));
      model->setHeaderData(1, Qt::Horizontal, QObject::tr("tot_rev "));
      model->setHeaderData(2, Qt::Horizontal, QObject::tr("type_rev "));
      model->setHeaderData(3, Qt::Horizontal, QObject::tr("date_rev "));


          return model;




 }


QSqlQueryModel * Revenu::Trierrev(const QString &critere, const QString &mode){
    QSqlQueryModel *model=new QSqlQueryModel();




model->setQuery("select * from revenu order by "+critere+" "+mode+"");

    return model;
}
