#ifndef COMMANDE_H
#define COMMANDE_H
#include <QString>
#include <QSqlQueryModel>
#include <QDebug>
class Commande
{
public:
   Commande();
    Commande(int,QString,int,QString);
    int getid_com();
    QString getdate_com();
    int getnombre_come();
    QString gettype_com();
    void setid_com(int);
    void setdate_com(QString);
    void setnombre_come(int);
    void settype_com(QString);
    bool ajoutercom();
    QSqlQueryModel* affichercom();
    bool supprimercom(int);
    QSqlQueryModel *Triercom(const QString &critere, const QString &mode);
    QSqlQueryModel * recherche_com(int id_com);
    bool modifC(int , QString,int,QString);
    int get_total();
private:
    int id_com;
    QString date_com , type_com;
    int nombre_come;

};



#endif // COMMANDE_H
