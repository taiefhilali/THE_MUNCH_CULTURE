#ifndef REVENU_H
#define PRODUIT_H
#include <QString>

#include <QSqlQueryModel>
class Produit
{
public:
    Produit();
    Produit (int,int);
    int getid_produit();
    int gettot_produit();


    void setid_produit(int);
    void settot_produit(int);


    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);

private:
    int id_produit,tot_produit;

};

#endif //Produit.H

