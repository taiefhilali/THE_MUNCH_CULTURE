#include "client.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QString>
#include <QSqlDatabase>
#include <QSqlError>
#include <QFile>
Client::Client()
{
id_cli=0; nom_cli=" "; prenom_cli=""; nombre_com=0;
}

Client::Client(int id_cli,QString nom_cli,QString prenom_cli,int nombre_com)
{this->id_cli=id_cli; this->nom_cli=nom_cli; this->prenom_cli=prenom_cli; this->nombre_com=nombre_com; }
int Client::getid_cli(){return id_cli;}
QString Client::getnom_cli(){return  nom_cli;}
QString Client::getprenom_cli(){return prenom_cli;}
int Client::getnombre_com(){return nombre_com;}

void Client::setid_cli(int id_cli){this->id_cli=id_cli;}
void Client::setnom_cli(QString nom_cli){this->nom_cli=nom_cli;}
void Client::setprenom_cli(QString prenom_cli){this->prenom_cli=prenom_cli;}
void Client::setnombre_com(int nombre_com){this->nombre_com=nombre_com;}
bool Client::ajouter()
{

    QSqlQuery query;
  QString id_string= QString::number(id_cli);
         query.prepare("INSERT INTO client (id_cli, nom_cli, prenom_cli, nombre_com) "
                       "VALUES (:id, :forename, :surname, :nombre)");
         query.bindValue(":id",id_string);
         query.bindValue(":forename", nom_cli);
         query.bindValue(":surname", prenom_cli);
         query.bindValue(":nombre", nombre_com);
        return query.exec();

}
bool Client::supprimer(int id_cli)
{
    QSqlQuery query;
         query.prepare(" Delete from client where id_cli=:id");
         query.bindValue(0, id_cli);

        return query.exec();


}
QSqlQueryModel* Client::afficher()
{
  QSqlQueryModel* model=new QSqlQueryModel();


   model->setQuery("SELECT* FROM client");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_cli"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom_cli"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom_cli"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("nombre_com"));


  return  model;
}
void Client::Rechercherclient(int id_cli){
        QSqlQuery query2;


        query2.prepare ("SELECT * FROM client WHERE id_cli= '"+QString::number(id_cli)+"'");
        query2.exec();

        while(query2.next()){
            id_cli= query2.value(0).toInt();
           nom_cli= query2.value(1).toString();
          prenom_cli=query2.value(2).toString();
           nombre_com= query2.value(3).toInt();
        }


    }
QSqlQueryModel * Client::Trier(QString choix1){
    QSqlQueryModel *model=new QSqlQueryModel();


    if (choix1=="id_cli"){
         model->setQuery("SELECT * FROM client ORDER BY id_cli DESC ");
    }
    else if(choix1=="nom_cli"){
         model->setQuery("SELECT * FROM client ORDER BY nom_cli ");
    }
    else if(choix1=="prenom_cli"){
        model->setQuery("SELECT * FROM client ORDER BY prenom_cli  ");
    }
    else if(choix1=="nombre_com"){
        model->setQuery("SELECT * FROM client ORDER BY nombre_com DESC ");
    }


    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_cli"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom_cli"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom_cli "));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("nombre_com"));

return model;
}
bool Client::modifE(int id_cli,QString nom_cli,QString prenom_cli,int nombre_com)
{
    QSqlQuery query;
    QString res=QString::number(id_cli);
    QString res2=QString::number(nombre_com);

    query.prepare("update client set id_cli=:id_cli,nom_cli=:nom_cli,prenom_cli=:prenom_cli,nombre_com=:nombre_com where id_cli= :id_cli");
    query.bindValue(":id_cli",res);
    query.bindValue(":nom_cli",nom_cli);
    query.bindValue(":prenom_cli",prenom_cli);
    query.bindValue(":nombre_com",res2);



    return query.exec();
}
