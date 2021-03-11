#ifndef LIVRAISON_H
#define LIVRAISON_H
#include <QString>
#include <QSqlQueryModel>


class livraison
{
public:
    livraison();
    livraison(QString,QString);
    int getid();
        void setid(int);
        QString get_adr();
        QString get_date();
        bool ajouter();
        QSqlQueryModel * afficher();
        bool supprimer (int);
    private:
    QString adr,date;
    int id;
};

#endif // LIVRAISON_H
