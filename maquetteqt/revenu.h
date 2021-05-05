#ifndef REVENU_H
#define REVENU_H
#include <QString>
//#include<QDate>
#include <QSqlQueryModel>
class Revenu
{
public:
    Revenu();
    Revenu (int,int,QString,QString);
    int getid_rev();
    int gettot_rev();
    QString gettype_rev();
    QString getdate_rev();


    void setid_rev(int);
    void settot_rev(int);
    void settype_rev(QString);
    void setdate_rev(QString);


    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier(int , int,QString,QString);
    QSqlQuery  recherche_2(int id_rev);
   // QSqlQueryModel * Trierrev(QString choix1);
    QSqlQueryModel * Trierrev(const QString &critere, const QString &mode );
    int get_total();

private:
    int id_rev , tot_rev;
    QString type_rev, date_rev;

};

#endif // REVENU_H
