#ifndef REVENU_H
#define REVENU_H
#include <QString>

#include <QSqlQueryModel>
class Revenu
{
public:
    Revenu();
    Revenu (int,int,int,int);
    int getid_rev();
    int gettot_rev();
    int getid_dep();
    int gettot_dep();

    void setid_rev(int);
    void settot_rev(int);
    void setid_dep(int);
    void settot_dep(int);

    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);

private:
    int id_revenu,id_dep, tot_dep,tot_rev;

};

#endif // REVENU_H
