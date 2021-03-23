#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "client.h"
#include "commande.h"


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

    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

     void on_push_recherche_clicked();


    //void on_combo_activated();

    //void on_combo_activated(const QString &arg1);

    void on_trie_activated();

    void on_modifier_clicked();
    //comment

private:
    Ui::MainWindow *ui;
    Client C;
    Commande F;
};
#endif // MAINWINDOW_H
