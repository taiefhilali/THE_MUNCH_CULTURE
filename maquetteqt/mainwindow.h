#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "produit.h"
#include "depense.h"
#include "revenu.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

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
    Ui::MainWindow *ui;
    Revenu R;
    Produit P;
    Depense D;
};
#endif // MAINWINDOW_H
