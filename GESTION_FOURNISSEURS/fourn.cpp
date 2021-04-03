#include "fourn.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QString>
fourn::fourn()
{
    id=0;
    nom="";
    prenom="";
    tel=0;
    adresse="";
}
fourn::fourn(int id,QString nom,QString prenom,int tel,QString adresse)
{
  this->id=id;
    this->nom=nom;
    this->prenom=prenom;
    this->tel=tel;
    this->adresse=adresse;
}
int fourn::getid(){return id;}
void fourn::setid(int id){this->id=id;}
QString fourn::get_nom(){return nom;}
QString fourn::get_prenom(){return prenom;}
int fourn::get_tel(){return tel;}
QString fourn::get_adresse(){return adresse;}

bool fourn::ajouter()
{
    QSqlQuery query;
    QString res= QString::number(id);
    query.prepare("INSERT INTO fourn (nom,prenom,tel,adresse) VALUES (:nom,:prenom,:tel,:adresse)");
 //   query.bindValue(":id",res);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":tel",tel);
    query.bindValue(":adresse",adresse);
return  query.exec();

}

QSqlQueryModel * fourn::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from fourn");
   // model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("tel"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("adresse"));
 return model;

}

bool fourn::delete_2(int id)
{
    QSqlQuery query;
    QString rec= QString::number(id);
    query.prepare("delete from FOURN where id = :id");
    query.bindValue(":id",rec);
    return query.exec();
}

bool fourn::modifier(Ui::gsf *ui){


     int id= ui->id_2->text().toInt();
     QString nom = ui->nom_2->text();
      QString prenom = ui->prenom_2->text();
     int tel= ui->tel_2->text().toInt();
     QString adresse = ui->adresse_2->text();
     fourn f(id,nom,prenom,tel,adresse);

     QSqlQuery query;
        query.prepare("UPDATE fourn SET nom ='"+nom+"',prenom ='"+prenom+"',tel='"+QString::number(tel)+"', adresse ='"+adresse+"' WHERE id= '"+QString::number(id)+"'");
        query.bindValue(":id",getid());
        query.bindValue(":nom",get_nom());
        query.bindValue(":prenom",get_prenom());
        query.bindValue(":tel",get_tel());
        query.bindValue(":adresse",get_adresse());

              return query.exec();

       }

void fourn::Rechercherfourns(int id){
        QSqlQuery query2;


        query2.prepare ("SELECT * FROM fourn WHERE id= '"+QString::number(id)+"'");
        query2.exec();

        while(query2.next()){
            id= query2.value(0).toInt();
            nom= query2.value(1).toString();
            prenom= query2.value(2).toString();
            tel=query2.value(3).toInt();
            adresse= query2.value(4).toString();
        }


    }
QSqlQueryModel*fourn::Trier(QString choix2){
    QSqlQueryModel *model=new QSqlQueryModel();


    if (choix2=="id"){
         model->setQuery("SELECT * FROM fourn ORDER BY id DESC ");
    }
    else if(choix2=="nom"){
         model->setQuery("SELECT * FROM fourn ORDER BY nom  ");
    }
    else if(choix2=="prenom"){
        model->setQuery("SELECT * FROM fourn ORDER BY prenom  ");
    }
    else if(choix2=="tel"){
        model->setQuery("SELECT * FROM fourn ORDER BY tel ASC ");
    }
    else if(choix2=="adresse"){
        model->setQuery("SELECT * FROM fourn ORDER BY adresse  ");}


    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom "));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("tel"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("adresse"));

return model;
}


