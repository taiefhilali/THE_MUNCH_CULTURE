#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include<QTimer>
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include "connexion.h"
#include "gsf.h"
#include "clicom.h"
#include "youssef.h"
#include "interw.h"
#include "menu.h"

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
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();
    void myfunction() ;

private:
    Ui::MainWindow *ui;
    QMediaPlayer * music = new QMediaPlayer();
QTimer * timer ;
   Connection c;
};
#endif // MAINWINDOW_H
