#ifndef YOUSSEF_H
#define YOUSSEF_H
#include "produit.h"
#include "depense.h"
#include "revenu.h"
#include <QDialog>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>
#include <QMediaPlayer>
#include <QMediaPlaylist>

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


    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_10_clicked();


    void on_impression_clicked();

    void on_pdf_clicked();

    void on_impression_2_clicked();

    void on_pdff_clicked();

    void on_impression_3_clicked();

    void on_pdfff_clicked();






private:
    Ui::youssef *ui;

    Revenu R;
    Produit P;
    Depense D;
    QMediaPlayer *click;

};

#endif // YOUSSEF_H
