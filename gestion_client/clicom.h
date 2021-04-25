#ifndef CLICOM_H
#define CLICOM_H

#include <QDialog>
#include "client.h"
#include "commande.h"
#include <QSound>
#include <QTimer>
QT_BEGIN_NAMESPACE
namespace Ui {
class Clicom;
}
QT_END_NAMESPACE
class Clicom : public QDialog
{
    Q_OBJECT

public:
    explicit Clicom(QWidget *parent = nullptr);
    ~Clicom();
public slots:
    void clockTimer();

private slots:
    void on_Ajouter_clicked();

    void on_supprimer_3_clicked();

    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_modifier_clicked();

    void on_modifiercom_clicked();

    void on_push_recherche_3_clicked();

    void on_rech_but_clicked();

    void sendMail();

    void mailSent(QString status);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_trierClient_clicked();

    void on_triercom_clicked();

    void on_pushButton_4_clicked();

    void on_gestiondescommandesnavbar_clicked();

    void on_mailingnavbar_clicked();

    void on_pushButton_5_clicked();

    void on_acualiser_1_clicked();

private:

    Ui::Clicom *ui;
    Client C;
    Commande F;
    QSound*son;
    QTimer *qTimer;
};

#endif // CLICOM_H
