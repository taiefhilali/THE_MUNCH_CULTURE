#ifndef INTER_H
#define INTER_H
#include "livreur.h"
#include "livraison.h"
#include "notif.h"
#include <QSound>

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class inter; }
QT_END_NAMESPACE

class inter : public QMainWindow
{
    Q_OBJECT

public:
    inter(QWidget *parent = nullptr);
    ~inter();

private slots:
    void on_ajouter1_clicked();

    void on_supprimer_2_clicked();

    void on_modifier3_clicked();

    void on_Ajouter_clicked();

    void on_supprimer_clicked();

    void on_PDF_clicked();

    void on_pushButton_3_clicked();

    void on_commandLinkButton_clicked();

    void on_colone_tri_activated(const QString &arg1);

    void on_commandLinkButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_colone_tri_2_activated(const QString &arg1);

    void on_PDF_2_clicked();

    void on_modifier_2_clicked();

    void on_imprimer_2_clicked();

    void on_imprimer_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::inter *ui;
   livreur l;
   livraison liv;
   notif n;
   QSound*son;
};

#endif // INTER_H
