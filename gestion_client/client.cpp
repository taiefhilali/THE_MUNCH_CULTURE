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
id_cli=0; nom_cli=" "; prenom_cli=""; num_tel=0; adresse="";
}

Client::Client(int id_cli,QString nom_cli,QString prenom_cli,int num_tel ,QString adresse)
{this->id_cli=id_cli; this->nom_cli=nom_cli; this->prenom_cli=prenom_cli; this->num_tel=num_tel;  this->adresse=adresse;}
int Client::getid_cli(){return id_cli;}
QString Client::getnom_cli(){return  nom_cli;}
QString Client::getprenom_cli(){return prenom_cli;}
int Client::getnum_tel(){return num_tel;}
QString Client::getadresse(){return adresse;}


void Client::setid_cli(int id_cli){this->id_cli=id_cli;}
void Client::setnom_cli(QString nom_cli){this->nom_cli=nom_cli;}
void Client::setprenom_cli(QString prenom_cli){this->prenom_cli=prenom_cli;}
void Client::setnum_tel(int num_tel){this->num_tel=num_tel;}
void Client::setadresse(QString adresse){this->adresse=adresse;}
bool Client::ajouter()
{

    QSqlQuery query;
  QString id_string= QString::number(id_cli);
         query.prepare("INSERT INTO client (id_cli, nom_cli, prenom_cli, num_tel, adresse) "
                       "VALUES (:id, :forename, :surname, :nombre, :adress)");
         query.bindValue(":id",id_string);
         query.bindValue(":forename", nom_cli);
         query.bindValue(":surname", prenom_cli);
         query.bindValue(":nombre", num_tel);
         query.bindValue(":adress", adresse);

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
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("num_tel"));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr("adresse"));



  return  model;
}

QSqlQueryModel * Client::Trier(const QString &critere, const QString &mode){

    QSqlQueryModel *model=new QSqlQueryModel();




model->setQuery("select * from client order by "+critere+" "+mode+"");

    return model;
}
bool Client::modifE(int id_cli,QString nom_cli,QString prenom_cli,int num_tel,QString adresse)
{
    QSqlQuery query;
    QString res=QString::number(id_cli);
    QString res2=QString::number(num_tel);

    query.prepare("update client set id_cli=:id_cli,nom_cli=:nom_cli,prenom_cli=:prenom_cli,num_tel=:num_tel, adresse=:adresse where id_cli= :id_cli");
    query.bindValue(":id_cli",res);
    query.bindValue(":nom_cli",nom_cli);
    query.bindValue(":prenom_cli",prenom_cli);
    query.bindValue(":num_tel",res2);
    query.bindValue(":adresse",adresse);



    return query.exec();
}
 QSqlQueryModel * recherche_2(int id_cli)
 {
     QSqlQueryModel* model = new QSqlQueryModel();
      model->setQuery("select * from client where (id_cli LIKE id_cli='"+QString::number(id_cli)+"'");
      model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_cli"));
      model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom_cli "));
      model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom_cli"));
      model->setHeaderData(3, Qt::Horizontal, QObject::tr("nombre_com"));

          return model;




 }
