#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "livreur.h"
#include "livraison.h"
#include "notif.h"

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

private:
    Ui::MainWindow *ui;
   livreur l;
   livraison liv;
   notif n;
};

#endif // MAINWINDOW_H
