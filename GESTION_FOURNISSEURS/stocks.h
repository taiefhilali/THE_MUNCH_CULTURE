#ifndef STOCKS_H
#define STOCKS_H
#include <QString>
#include <QSqlQueryModel>
#include <ui_gsf.h>

class stocks
{
public:
    stocks();
    stocks(int,QString,int,int,QString);


     QString get_dat();
       int get_prix();
       int get_quantite();
       int getid();
        void setid(int);
        QString get_noms();


        bool ajouter();
        QSqlQueryModel * afficher();
        bool supprimer (int);
        bool modifier(Ui::gsf *ui);
        void Rechercherstocks(int id);//
        QSqlQueryModel *Trier(QString );
private:
    QString dat,nom;
    int id,prix,quantite;

};

#endif // STOCKS_H
