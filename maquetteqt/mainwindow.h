#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "produit.h"

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

private:
    Ui::MainWindow *ui;
    Revenu R;
    Produit P;
};
#endif // MAINWINDOW_H
