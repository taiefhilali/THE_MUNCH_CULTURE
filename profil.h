#ifndef profil_H
#define profil_H

#include <QString>
#include <QSqlQueryModel>
class profil
{
public:
    profil();
    profil(QString,QString,QString);
    QString getid();
    QString getlogin();

    QString getmdp() ;

    void setid(QString);
    void setlogin(QString);

    void setmdp(QString) ;

    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(QString);
    bool modifier(QString id, QString login, QString mdp);
    QSqlQueryModel *afficherselonid();
private:

    QString id,login,mdp;

};

#endif // profil_H
