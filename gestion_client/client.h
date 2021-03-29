#ifndef CLIENT_H
#define CLIENT_H
#include <QString>
#include <QSqlQueryModel>
#include <QDebug>
class Client
{
public:
    Client();
    Client(int,QString,QString,int);
    int getid_cli();
    QString getnom_cli();
    QString getprenom_cli();
    int getnombre_com();
    void setid_cli(int);
    void setnom_cli(QString);
    void setprenom_cli(QString);
    void setnombre_com(int);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    QSqlQueryModel * recherche_2(int id_cli);
    QSqlQueryModel *Trier(QString );
    bool modifE(int , QString,QString,int);

private:
    int id_cli;
    QString nom_cli, prenom_cli;
    int nombre_com;

};

#endif // CLIENT_H


