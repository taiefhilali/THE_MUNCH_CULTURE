#ifndef FOURN_H
#define FOURN_H
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQueryModel>
#include <ui_mainwindow.h>

class fourn
{
public:
    fourn();
    fourn(int,QString,QString,int,QString);


     QString get_nom();
      QString get_prenom();
       QString get_adresse();
        int getid();
        void setid(int);
        int get_tel();
        bool ajouter();
        bool modifier(Ui::MainWindow *ui);
        void Rechercherfourns(int id);
        QSqlQueryModel * afficher();
        bool supprimer (int);
         QSqlQueryModel *Trier(QString);
private:
    QString nom,prenom,adresse;
    int tel,id;

};

#endif // FOURN_H
