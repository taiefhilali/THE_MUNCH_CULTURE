#ifndef FOURN_H
#define FOURN_H
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQueryModel>
#include <ui_gsf.h>

class fourn
{
public:
    fourn();
    fourn(int,QString,QString,int,QString);


     QString get_nom();
      QString get_prenom();
       QString get_adresse();
        int getid();
        void setid(int);
        int get_tel();
        bool ajouter();
        bool modifier(Ui::gsf *ui);
        void Rechercherfourns(int id);
        QSqlQueryModel * afficher();
        bool delete_2 (int);
         QSqlQueryModel *Trier(QString);
private:
    QString nom,prenom,adresse;
    int id,tel;

};

#endif // FOURN_H
//
