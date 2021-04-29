#ifndef STOCKS_H
#define STOCKS_H
#include <QString>
#include <QSqlQueryModel>
#include <ui_gsf.h>
#include <QPrintDialog>
#include <QPrinter>
#include <QSystemTrayIcon>
#include "qcustomplot.h"

class stocks
{
public:
    stocks();
    stocks(int,QString,int,int,QString,QString);


     QString get_dat();
       int get_prix();
       int get_quantite();
       int getid();
        void setid(int);
        QString get_noms();
        QString get_type();

        bool ajouter();
        QSqlQueryModel * afficher();
        bool supprimer (int);
        bool modifier(Ui::gsf *ui);
        void Rechercherstocks(int id);//
        QSqlQueryModel *Trier(QString );
          void pdffonction(QString);
          int get_total();
           bool suppAffectation(QString);
         void set_noms(QString nom){this->nom=nom;};
private:
    QString dat,nom,type,code;
    int id,prix,quantite;

};

#endif // STOCKS_H
