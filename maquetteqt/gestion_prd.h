#ifndef GESTION_PRD_H
#define GESTION_PRD_H

#include <QDialog>
#include "produit.h"
#include "depense.h"
#include "revenu.h"

namespace Ui {
class gestion_prd;
}

class gestion_prd : public QDialog
{
    Q_OBJECT

public:
    explicit gestion_prd(QWidget *parent = nullptr);
    ~gestion_prd();




private slots:
    void on_Ajouter_clicked();

    void on_supprimer_3_clicked();

    void on_ajouter1_clicked();

    void on_supprimer_2_clicked();





    void on_modifier_3_clicked();



    void on_pushButton_3_clicked();

    void on_EXCEL_clicked();

    void on_pushButton_1_clicked();

    void on_supprimer_6_clicked();

    void on_pushButton_2_clicked();

    void on_modifier3_2_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

    void on_pushButton_8_clicked();

    void on_EXCEL_4_clicked();

    void on_pushButton_9_clicked();
private:
    Ui::gestion_prd *ui;
    Revenu R;
    Produit P;
    Depense D;
};

#endif // GESTION_PRD_H
