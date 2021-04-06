
#include "connexion.h"

Connexion::Connexion()
{}

bool Connexion::ouvrirConnexion()
{ db=QSqlDatabase::addDatabase("QODBC");

db.setDatabaseName("projrt2A");
db.setUserName("daly");//inserer nom de l'utilisateur
db.setPassword("daly");//inserer mot de passe de cet utilisateur

if (db.open())
return true;
    return  false;
}

void Connexion::fermerConnexion()
{db.close();}
