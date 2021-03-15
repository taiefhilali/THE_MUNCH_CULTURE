#ifndef STOCKS_H
#define STOCKS_H
#include <QString>
#include <QSqlQueryModel>
#include <QMainWindow>
#include <QMainWindow>
#include "ui_mainwindow.h"
class stocks
{
public:
    stocks();
    stocks(int,QString,int,int);


     QString get_dat();
       int get_prix();
       int get_quantite();
       int getid();
        void setid(int);


        bool ajouter();
        QSqlQueryModel * afficher();
        bool supprimer (int);
        bool modifier(Ui::MainWindow *ui);
        void Rechercherstocks(int id);
        QSqlQueryModel *Trier(QString );
private:
    QString dat;
    int id,prix,quantite;

};

#endif // STOCKS_H
