#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlDatabase>


class Connection
{
private:
    QSqlDatabase db;
public:
    Connection();
    bool ouvrirConnexion();
    void fermerConnexion();
};

#endif // CONNECTION_H
