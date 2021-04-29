#ifndef MENU_H
#define MENU_H

#include <QDialog>
#include"personnel.h"
#include <QMainWindow>
#include"profil.h"
#include"arduino.h"
#include <QtWidgets/QMessageBox>
#include<QPainter>
#include<QPdfWriter>
#include<QDesktopServices>
#include<QUrl>
#include<QSqlTableModel>
namespace Ui {
class menu;
}

class menu : public QDialog
{
    Q_OBJECT

public:
    explicit menu(QWidget *parent = nullptr);
    ~menu();
    int led,alert,messageboxactive;
    void update_label();


private slots:
    void on_Ajouter_clicked();

    void on_ajouter1_clicked();


    void on_supprimer_employee_clicked();

    void on_modifier_employee_clicked();

    void on_supprimer_profil_clicked();

    void on_modifier_profil_clicked();

    void on_tri_employee_clicked();




    void on_colone_tri_textActivated(const QString &arg1);
//    void recherche_personnel();


    void on_pushButton_3_clicked();

    void on_table_personnel_activated(const QModelIndex &index);

    void on_le_recherche_cursorPositionChanged(int arg1, int arg2);

    void on_supprimer_clicked();

    void on_modifier_2_clicked();

    void on_button_tri_2_clicked();

    void on_pdf_clicked();

    void on_pushButton_clicked();

private:
    Ui::menu *ui;
    personnel tmp_personnel ;
    profil tmp_profil ;
    QString fileNameImage ;
    QPixmap photo ;
    QByteArray image;
    QByteArray data;
  Arduino A;

};

#endif // MENU_H
