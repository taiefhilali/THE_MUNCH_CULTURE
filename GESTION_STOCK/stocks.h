#ifndef STOCKS_H
#define STOCKS_H
#include <QString>
#include <QSqlQueryModel>

class stocks
{
public:
    stocks();
    stocks(QString,int,int);


     QString get_dat();
int get_prix();
int get_quantite();
       int getid();
        void setid(int);


        bool ajouter();
        QSqlQueryModel * afficher();
        bool supprimer (int);
private:
    QString dat;
    int id,prix,quantite;

};

#endif // STOCKS_H
