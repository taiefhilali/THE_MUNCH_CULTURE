#ifndef STAT_H
#define STAT_H

#include <QDialog>
#include "qcustomplot.h"
#include <QWidget>

#include <QMainWindow>

namespace Ui {
class stat;
}

class Stat : public QDialog
{
    Q_OBJECT

public:
    explicit Stat(QWidget *parent = nullptr);
    ~Stat();
    void makePolt();

private slots:
  //  void on_deconecterr_clicked();

private:
    Ui::stat *ui;
};

#endif // STAT_H
