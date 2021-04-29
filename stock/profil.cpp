#include "profil.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QString>


profil::profil()
{
    id="";
    login=" ";
    mdp="";
}

profil::profil(QString id,QString login,QString mdp)
{this->id=id;
    this->login=login;
    this->mdp=mdp;

}
QString profil::getid(){return id;}
QString profil::getlogin(){return  login;}
QString profil::getmdp(){return mdp;}



void profil :: setid(QString id)
{
    this->id=id;
}
void profil :: setlogin(QString login )
{this->login=login;}
void profil :: setmdp(QString mdp)
{this->mdp=mdp;}

bool profil::ajouter()
{

    QSqlQuery query;
    query.prepare("INSERT INTO profil (id, login, mdp) "
                       "VALUES (:id, :login, :mdp)");
    query.bindValue(":id",id);
    query.bindValue(":login", login);
    query.bindValue(":mdp", mdp);


    return query.exec();

}
bool profil::supprimer(QString id)
{
    QSqlQuery query;
    query.prepare(" Delete from profil where id=:id");
    query.bindValue(0, id);

    return query.exec();


}
QSqlQueryModel* profil::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();


    model->setQuery("SELECT* FROM profil");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("login"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("mdp"));


    return  model;
}
bool profil:: modifier(QString id,QString login,QString mdp )
{       QSqlQuery query;
        query.prepare("UPDATE profil set ID=:id,LOGIN=:login,MDP=:mdp where ID= :id ");
            query.bindValue(":id",id);
                query.bindValue(":login", login);
                    query.bindValue(":mdp",mdp);


                        return    query.exec();

}
QSqlQueryModel* profil::afficherselonid()// tri

{
    QSqlQueryModel* model=new QSqlQueryModel() ;
   QSqlQuery *query=new QSqlQuery;
   query->prepare("select * from profil ORDER BY ID  ") ;
   query->exec() ;
   model->setQuery(*query) ;



return model;

}
