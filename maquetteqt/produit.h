#ifndef REVENU_H
#define PRODUIT_H
#include <QString>

#include <QSqlQueryModel>
class Produit
{
public:
    Produit();

    Produit (int,QString,QString,int,QString);
    int getid_produit();
    QString getnom_produit();
    QString gettype_produit();
    int gettot_produit();
    QString getproduit_rester();

    void setid_produit(int);
    void setnom_produit(int);
    void settype_produit(QString);
    void settot_produit(int);
    void setproduit_rester(QString);


    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier(int , QString, QString , int , QString);
    QSqlQueryModel * recherche_4(int id_produit);
    QSqlQueryModel * Trierproduit(const QString &critere, const QString &mode);

private:
    int id_produit,tot_produit;
    QString nom_produit,type_produit,produit_rester;
};

#endif //Produit.H

