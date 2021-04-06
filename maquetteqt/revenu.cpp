#include "revenu.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>

Revenu::Revenu()
{
id_rev=0; tot_rev=0; ;
}
Revenu::Revenu(int id_rev,int tot_rev)
{this-> id_rev=id_rev; this-> tot_rev=tot_rev;  }
int Revenu::getid_rev(){return id_rev;}
int Revenu::gettot_rev(){return tot_rev;}


void Revenu::setid_rev(int id_rev){this-> id_rev=id_rev;}
void Revenu::settot_rev(int tot_rev){this-> tot_rev=tot_rev;}


bool Revenu::ajouter()
{
    QSqlQuery query;

  QString idrev= QString::number(id_rev);
  QString totrev= QString::number(tot_rev);

         query.prepare("INSERT INTO REVENU (id_rev,tot_rev) "
                                   "VALUES ( :id_rev,:tot_rev)");

         query.bindValue(":id_rev", id_rev);
         query.bindValue(":tot_rev", tot_rev);

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

   model->setHeaderData(2, Qt::Horizontal, QObject::tr("id_rev"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("tot_rev"));



  return  model;

}

bool Revenu::modifier(int id_rev,int tot_rev)
{
    QSqlQuery query;

    QString res3=QString::number(id_rev);
    QString res4=QString::number(tot_rev);



    query.prepare("update REVENU set id_rev=id_rev,tot_rev=tot_rev where id_rev= :id_rev");

    query.bindValue(":id_rev",res3);
    query.bindValue(":tot_rev",res4);



    return query.exec();
}
QSqlQueryModel * recherche_2(int id_rev)
 {
     QSqlQueryModel* model = new QSqlQueryModel();
      model->setQuery("select * from REVENU where (id_rev LIKE id_rev='"+QString::number(id_rev)+"'");
      model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_rev"));
      model->setHeaderData(1, Qt::Horizontal, QObject::tr("tot_rev "));


          return model;




 }


QSqlQueryModel * Revenu::Trierrev(const QString &critere, const QString &mode){
    QSqlQueryModel *model=new QSqlQueryModel();




model->setQuery("select * from revenu order by "+critere+" "+mode+"");

    return model;
}
