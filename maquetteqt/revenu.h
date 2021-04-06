#ifndef REVENU_H
#define REVENU_H
#include <QString>

#include <QSqlQueryModel>
class Revenu
{
public:
    Revenu();
    Revenu (int,int);
    int getid_rev();
    int gettot_rev();


    void setid_rev(int);
    void settot_rev(int);


    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier(int , int);
    QSqlQuery  recherche_2(int id_rev);
   // QSqlQueryModel * Trierrev(QString choix1);
    QSqlQueryModel * Trierrev(const QString &critere, const QString &mode );

private:
    int id_rev , tot_rev;

};

#endif // REVENU_H
