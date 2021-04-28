#ifndef PERSONNEL_H
#define PERSONNEL_H

#include <QString>
#include <QSqlQueryModel>
class personnel
{
public:
    personnel();
    personnel(QString,QString,QString,QString,QString,QString,QString);
    QString getid();
    QString getnom();
    QString getprenom();
    QString getmdp() ;
    QString getdate_emb() ;
    QString getsalaire() ;
    QString gettype() ;
    void setid(QString);
    void setnom(QString);
    void setprenom(QString);
    void setmdp(QString) ;
    void setdate_emb(QString) ;
    void setsalaire(QString) ;
    void settype(QString) ;
    bool ajouter();
    QSqlQueryModel* afficher();
     QSqlQueryModel* afficherselonid();
     void  AjoutImage(QString );

    bool supprimer(QString);
    bool modifier(QString nom, QString prenom, QString mdp, QString date_emb, QString salaire, QString type, QString id);
    QByteArray GetImage();
    QSqlQueryModel *rechercheid(QString id);
private:
    QByteArray image;

    QString nom, prenom,mdp,date_emb,salaire,type,id;

};

#endif // PERSONNEL_H
