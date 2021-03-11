#ifndef FOURN_H
#define FOURN_H
#include <QString>
#include <QSqlQueryModel>

class fourn
{
public:
    fourn();
    fourn(QString,QString,int,QString);


     QString get_nom();
      QString get_prenom();
       QString get_adresse();
        int getid();
        void setid(int);
        int get_tel();
        bool ajouter();
        QSqlQueryModel * afficher();
        bool supprimer (int);
private:
    QString nom,prenom,adresse;
    int tel,id;

};

#endif // FOURN_H
