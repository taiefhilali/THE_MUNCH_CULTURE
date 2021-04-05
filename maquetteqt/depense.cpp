#include "revenu.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include "depense.h"
Depense::Depense()
{
 id_dep=0; tot_dep=0; ;
}
Depense::Depense(int id_dep,int tot_dep)
{this->  id_dep=id_dep; this-> tot_dep=tot_dep; }

int Depense::getid_dep(){return id_dep;}
int Depense::gettot_dep(){return tot_dep;}


void Depense::setid_dep(int id_dep){this-> id_dep=id_dep;}
void Depense::settot_dep(int tot_dep){this-> tot_dep=tot_dep;}

bool Depense::ajouter()
{
    QSqlQuery query;
  QString id_string= QString::number(id_dep);
  QString totrev= QString::number(tot_dep);


         query.prepare("INSERT INTO DEPENSE (id_dep,tot_dep) "
                                   "VALUES (:id_dep, :tot_dep)");
         query.bindValue(":id_dep",id_string);
         query.bindValue(":tot_dep", tot_dep);

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



  return  model;

}

bool Depense::modifier(int id_dep,int tot_dep)
{
    QSqlQuery query;
    QString res1=QString::number(id_dep);
    QString res2=QString::number(tot_dep);



    query.prepare("update DEPENSE set id_dep =id_dep, tot_dep=:tot_dep where id_dep= :id_dep");
    query.bindValue(":id_dep",res1);
    query.bindValue(":tot_dep",res2);


    return query.exec();
}
QSqlQueryModel * Depense::recherche_2(int id_dep)
{
    QSqlQueryModel* model = new QSqlQueryModel();
     model->setQuery("select * from DEPENSE where (id_dep LIKE id_dep='"+QString::number(id_dep)+"'");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_dep"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("tot_dep "));

         return model;
}
QSqlQueryModel * Depense::Trierdep(QString choix1){
    QSqlQueryModel *model=new QSqlQueryModel();


    if (choix1=="id_dep"){
         model->setQuery("SELECT * FROM Depense ORDER BY id_dep DESC ");
    }
    else if(choix1=="tot_dep"){
         model->setQuery("SELECT * FROM Depense ORDER BY tot_dep ");
    }



    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_dep"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("tot_dep"));


return model;
}
