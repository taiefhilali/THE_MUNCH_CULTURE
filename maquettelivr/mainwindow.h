#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "livreur.h"
#include "livraison.h"

#include <QMainWindow>

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
    void on_ajouter1_clicked();

    void on_supprimer_2_clicked();

    void on_modifier3_clicked();

    void on_Ajouter_clicked();

    void on_supprimer_clicked();

private:
    Ui::MainWindow *ui;
   livreur l;
   livraison liv;
};

#endif // MAINWINDOW_H
