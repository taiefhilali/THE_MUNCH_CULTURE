#include "connexion.h"

//test tutorial git

Connexion::Connexion()
{}

bool Connexion::ouvrirConnexion()
{ db=QSqlDatabase::addDatabase("QODBC");

db.setDatabaseName("Projet_2A");
db.setUserName("mahdi");//inserer nom de l'utilisateur
db.setPassword("mahdi");//inserer mot de passe de cet utilisateur

if (db.open())
return true;
else
    return  false;
}

void Connexion::fermerConnexion()
{db.close();}
