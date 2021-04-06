#ifndef YOUSSEF_H
#define YOUSSEF_H
#include "produit.h"
#include "depense.h"
#include "revenu.h"
#include <QDialog>

namespace Ui {
class youssef;
}

class youssef : public QDialog
{
    Q_OBJECT

public:
    explicit youssef(QWidget *parent = nullptr);
    ~youssef();

private slots:
    void on_Ajouter_clicked();

    void on_modifier_3_clicked();

    void on_supprimer_3_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_EXCEL_clicked();

    void on_pushButton_1_clicked();

    void on_supprimer_6_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_EXCEL_4_clicked();

    void on_ajouter1_clicked();

    void on_supprimer_2_clicked();

    void on_modifier3_2_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_4_clicked();

    void on_EXCEL_3_clicked();

    void makePolt();

    void on_le_type_produit_2_cursorPositionChanged(int arg1, int arg2);

    void on_pushButton_5_clicked();

private:
    Ui::youssef *ui;

    Revenu R;
    Produit P;
    Depense D;
};

#endif // YOUSSEF_H
