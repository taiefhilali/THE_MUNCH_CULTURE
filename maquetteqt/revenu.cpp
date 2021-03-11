#include "revenu.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
Revenu::Revenu()
{
id_revenu=0; tot_rev=0; id_dep=0; tot_dep=0; ;
}
Revenu::Revenu(int id_revenu,int tot_rev,int id_dep,int tot_dep)
{this-> id_revenu=id_revenu; this-> tot_rev=tot_rev; this-> id_dep=id_dep; this-> tot_dep=tot_dep; }
int Revenu::getid_rev(){return id_revenu;}
int Revenu::gettot_rev(){return tot_rev;}
int Revenu::getid_dep(){return id_dep;}
int Revenu::gettot_dep(){return tot_dep;}

void Revenu::setid_rev(int id_revenu){this-> id_revenu=id_revenu;}
void Revenu::settot_rev(int tot_rev){this-> tot_rev=tot_rev;}
void Revenu::setid_dep(int id_dep){this-> id_dep=id_dep;}
void Revenu::settot_dep(int tot_dep){this-> tot_dep=tot_dep;}

bool Revenu::ajouter()
{
    QSqlQuery query;
  QString id_string= QString::number(id_dep);
  QString totrev= QString::number(tot_dep);
  QString iddep= QString::number(id_revenu);
  QString totdep= QString::number(tot_rev);

         query.prepare("INSERT INTO REVENUDEPENSE (id_dep,tot_dep,id_revenu,tot_rev) "
                                   "VALUES (:id_dep, :tot_dep, :id_revenu,:tot_rev)");
         query.bindValue(":id_dep",id_string);
         query.bindValue(":tot_dep", totdep);
         query.bindValue(":id_revenu", iddep);
         query.bindValue(":tot_rev", totrev);

        return query.exec();
}
bool Revenu::supprimer(int  id_dep)
{
    QSqlQuery query;
         query.prepare(" Delete from REVENUDEPENSE where id_dep=:id_dep");
         query.bindValue(0,  id_dep);

        return query.exec();


}
QSqlQueryModel* Revenu::afficher()
{
  QSqlQueryModel* model=new QSqlQueryModel();


   model->setQuery("SELECT* FROM REVENUDEPENSE");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_dep"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("tot_dep"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("id_revenu"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("tot_rev"));



  return  model;
}
