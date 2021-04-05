#ifndef REVENU_H
#define PRODUIT_H
#include <QString>

#include <QSqlQueryModel>
class Produit
{
public:
    Produit();
    Produit (int,int,QString);
    int getid_produit();
    int gettot_produit();
    QString gettype_produit();

    void setid_produit(int);
    void settot_produit(int);
    void settype_produit(QString);


    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier(int , int , QString);
    QSqlQueryModel * recherche_4(int id_produit);
    QSqlQueryModel * Trierproduit(QString choix1);

private:
    int id_produit,tot_produit;
    QString type_produit;
};

#endif //Produit.H

