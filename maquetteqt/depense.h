#ifndef DEPENSE_H
#define DEPENSE_H
#include <QString>


#include <QSqlQueryModel>
class Depense
{
public:
    Depense();
    Depense (int,int);

    int getid_dep();
    int gettot_dep();

    void setid_dep(int);
    void settot_dep(int);

    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier(int , int);
QSqlQueryModel * recherche_2(int id_dep);
QSqlQueryModel * Trierdep(const QString &critere, const QString &mode);

private:
    int  id_dep, tot_dep;

};

#endif // DEPENSE_H
