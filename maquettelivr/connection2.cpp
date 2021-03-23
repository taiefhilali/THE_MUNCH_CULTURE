#include "connection2.h"
connection2::connection2()
{

}

bool connection2::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Projet_2A");//inserer le nom de la source de données ODBC
db.setUserName("ghada");//inserer nom de l'utilisateur
db.setPassword("ghada");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
