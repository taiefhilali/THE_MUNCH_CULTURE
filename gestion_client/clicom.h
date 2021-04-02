#ifndef CLICOM_H
#define CLICOM_H

#include <QDialog>
#include "client.h"
#include "commande.h"


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

private slots:
    void on_Ajouter_clicked();

    void on_supprimer_3_clicked();

    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_trie_activated();

    void on_modifier_clicked();

    void on_triecommande_activated();

    void on_modifiercom_clicked();

    void on_push_recherche_3_clicked();

    void on_rech_but_clicked();

    void sendMail();

    void mailSent(QString status);


    void on_pushButton_clicked();

private:


    Ui::Clicom *ui;
    Client C;
    Commande F;
};

#endif // CLICOM_H
