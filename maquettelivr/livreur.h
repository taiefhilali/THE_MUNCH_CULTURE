#ifndef LIVREUR_H
#define LIVREUR_H
#include <QString>
#include <QSqlQueryModel>


class livreur
{
public:
    livreur();
    livreur(QString,QString,int,int);
    void setid(int);
        int getid();
    QString get_nom();
       QString get_prenom();
       int get_numtel();
       int get_salaire();
       bool ajouter();
         QSqlQueryModel * afficher();
         bool supprimer (int);
         bool modif(int,QString,QString,int,int);
           int get_total();
 private:
    QString nom,prenom;
    int id,salaire,numtel;
};

#endif // LIVREUR_H
