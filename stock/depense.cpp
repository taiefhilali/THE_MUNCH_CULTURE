#include "revenu.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include "depense.h"
Depense::Depense()
{
 id_dep=0;
 tot_dep=0;
 type_dep="";
 date_dep="";
}
Depense::Depense(int id_dep,int tot_dep,QString type_dep,QString date_dep)
{this->  id_dep=id_dep; this-> tot_dep=tot_dep; this-> type_dep=type_dep; this-> date_dep=date_dep; }

int Depense::getid_dep(){return id_dep;}
int Depense::gettot_dep(){return tot_dep;}
QString Depense::gettype_dep(){return type_dep;}
QString Depense::getdate_dep(){return date_dep;}


void Depense::setid_dep(int id_dep){this-> id_dep=id_dep;}
void Depense::settot_dep(int tot_dep){this-> tot_dep=tot_dep;}
void Depense::settype_dep(QString type_dep){this-> type_dep=type_dep;}
void Depense::setdate_dep(QString date_dep){this-> date_dep=date_dep;}

bool Depense::ajouter()
{
    QSqlQuery query;
  QString id_string= QString::number(id_dep);
  QString totrev= QString::number(tot_dep);
  QString typerev= QString(type_dep);
  QString daterev= QString(date_dep);



         query.prepare("INSERT INTO DEPENSE (id_dep,tot_dep,type_dep,date_dep) "
                                   "VALUES (:id_dep, :tot_dep , :type_dep, :date_dep)");
         query.bindValue(":id_dep",id_string);
         query.bindValue(":tot_dep", tot_dep);
         query.bindValue(":type_dep", type_dep);
         query.bindValue(":date_dep", date_dep);

        return query.exec();
}
bool Depense::supprimer(int  id_dep)
{
    QSqlQuery query;
         query.prepare(" Delete from DEPENSE where id_dep=:id_dep");
         query.bindValue(0,  id_dep);

        return query.exec();


}
QSqlQueryModel* Depense::afficher()
{
  QSqlQueryModel* model=new QSqlQueryModel();


   model->setQuery("SELECT* FROM DEPENSE");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_dep"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("tot_dep"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("type_dep"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("date_dep"));



  return  model;

}

bool Depense::modifier(int id_dep,int tot_dep,QString type_dep,QString date_dep)
{
    QSqlQuery query;
    QString res1=QString::number(id_dep);
    QString res2=QString::number(tot_dep);
    QString res3=QString(type_dep);
    QString res4=QString(date_dep);



    query.prepare("update DEPENSE set id_dep =id_dep, tot_dep=:tot_dep, type_dep=:type_dep, date_dep=:date_dep where id_dep= :id_dep");
    query.bindValue(":id_dep",res1);
    query.bindValue(":tot_dep",res2);
    query.bindValue(":type_dep",res3);
    query.bindValue(":date_dep",res4);


    return query.exec();
}
QSqlQueryModel * Depense::recherche_2(int id_dep)
{
    QSqlQueryModel* model = new QSqlQueryModel();
     model->setQuery("select * from DEPENSE where (id_dep LIKE id_dep='"+QString::number(id_dep)+"'");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_dep"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("tot_dep "));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("type_dep "));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("date_dep "));

         return model;
}
QSqlQueryModel * Depense::Trierdep(const QString &critere, const QString &mode){


    QSqlQueryModel *model=new QSqlQueryModel();




model->setQuery("select * from depense order by "+critere+" "+mode+"");

    return model;
}
