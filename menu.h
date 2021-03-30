#ifndef MENU_H
#define MENU_H

#include <QDialog>
#include"personnel.h"
#include"profil.h"

namespace Ui {
class menu;
}

class menu : public QDialog
{
    Q_OBJECT

public:
    explicit menu(QWidget *parent = nullptr);
    ~menu();

private slots:
    void on_Ajouter_clicked();

    void on_ajouter1_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::menu *ui;
    personnel p ;
    profil e ;
};

#endif // MENU_H
