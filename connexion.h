#ifndef CONNEXION_H
#define CONNEXION_H
#include <QSqlDatabase>
#include<QtSql>
class Connexion
{
private:
    QSqlDatabase db;
public:
    Connexion();
    bool ouvrirConnexion();
    void fermerConnexion();

};

#endif // CONNEXION_H
