#ifndef CLIENT_H
#define CLIENT_H
#include <QString>
#include <QSqlQueryModel>
#include <QDebug>
class Client
{
public:
    Client();
    Client(int,QString,QString,int,QString);
    int getid_cli();
    QString getnom_cli();
    QString getprenom_cli();
    int getnum_tel();
    QString getadresse();
    void setid_cli(int);
    void setnom_cli(QString);
    void setprenom_cli(QString);
    void setnum_tel(int);
    void setadresse(QString);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    QSqlQueryModel * recherche_2(int id_cli);
    QSqlQueryModel *Trier(const QString &critere, const QString &mode);
    bool modifE(int , QString,QString,int,QString);

private:
    int id_cli;
    QString nom_cli, prenom_cli,adresse;
    int num_tel;

};

#endif // CLIENT_H


