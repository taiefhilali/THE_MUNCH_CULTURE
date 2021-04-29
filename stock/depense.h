#ifndef DEPENSE_H
#define DEPENSE_H
#include <QString>


#include <QSqlQueryModel>
class Depense
{
public:
    Depense();
    Depense (int,int,QString,QString);

    int getid_dep();
    int gettot_dep();
    QString gettype_dep();
    QString getdate_dep();

    void setid_dep(int);
    void settot_dep(int);
    void settype_dep(QString);
    void setdate_dep(QString);

    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier(int , int ,QString,QString);
QSqlQueryModel * recherche_2(int id_dep);
QSqlQueryModel * Trierdep(const QString &critere, const QString &mode);

private:
    int  id_dep, tot_dep;
    QString type_dep, date_dep;

};

#endif // DEPENSE_H
