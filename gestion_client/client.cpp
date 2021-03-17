#include "client.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
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
