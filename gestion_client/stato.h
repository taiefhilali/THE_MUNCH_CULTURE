#ifndef STATO_H
#define STATO_H

#include <QDialog>
#include "qcustomplot.h"
#include <QWidget>

#include <QMainWindow>

namespace Ui {
class stato;
}

class stato : public QDialog
{
    Q_OBJECT

public:
    explicit stato(QWidget *parent = nullptr);
    ~stato();
    void makePolt();

private slots:
  //  void on_deconecterr_clicked();

private:
    Ui::stato *ui;
};

#endif // STATISTIQ_H
