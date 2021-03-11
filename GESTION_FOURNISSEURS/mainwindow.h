#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "stocks.h"
#include "fourn.h"





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

    void on_supprimer_clicked();

    void on_ajouter1_clicked();


    void on_supprimer_2_clicked();

    void on_modifier_2_clicked();

private:
    Ui::MainWindow *ui;
    stocks S;
    fourn f;
   };
#endif // MAINWINDOW_H
