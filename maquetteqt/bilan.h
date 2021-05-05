#ifndef BILAN_H
#define BILAN_H

#include <QDialog>
#include "depense.h"

#include "revenu.h"
//#include "bilan.h"
#include <QWidget>

#include <QMainWindow>
namespace Ui {
class bilan;
}

class bilan : public QDialog
{
    Q_OBJECT

public:
    explicit bilan(QWidget *parent = nullptr);
    ~bilan();

private slots:
    void on_total_clicked();
    void digit_pressed();
        void on_pushButton_point_released();
        void unary_operation_pressed();
        void on_pushButton_C_released();
        void on_pushButton_equal_released();
        void binary_operation_pressed();

        void on_pushButton_9_clicked();



        void on_prix_tott_clicked();

        void on_pushButton_equal_clicked();



        void on_pushButton_clicked();

        void on_pbResult_clicked();

private:
    Ui::bilan *ui;
    Revenu R;
    Depense D;
    QByteArray data;

    QTimer *qTimer;
    QString*code;
    QString filename;




};

#endif // BILAN_H
