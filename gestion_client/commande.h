#ifndef COMMANDE_H
#define COMMANDE_H
#include <QString>
#include <QSqlQueryModel>
#include <QDebug>
class Commande
{
public:
   Commande();
    Commande(int,QString,int);
    int getid_com();
    QString getdate_com();
    int getnombre_come();
    void setid_com(int);
    void setdate_com(QString);
    void setnombre_come(int);
    bool ajoutercom();
    QSqlQueryModel* affichercom();
    bool supprimercom(int);
    QSqlQueryModel *Triercom(QString );
    QSqlQueryModel * recherche_com(int id_com);
    bool modifC(int , QString,int);
private:
    int id_com;
    QString date_com;
    int nombre_come;

};



#endif // COMMANDE_H
