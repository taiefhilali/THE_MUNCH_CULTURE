#include "bilan.h"
#include "ui_bilan.h"
#include "youssef.h"
#include "revenu.h"
#include "depense.h"

#include <QMessageBox>
#include <QIntValidator>
#include <QTabWidget>
#include <QString>
#include <QFile>
#include <QSqlQuery>
#include <QPixmap>
#include <QDebug>
#include <QInputDialog>
#include "QSqlRecord"
#include "QSqlQuery"
#include <QSqlDatabase>
#include <QSqlError>
#include<QPdfWriter>
#include <QFileDialog>
#include<QTextDocument>
#include<QFile>
//#include"smtp.h"
#include <QFileDialog>
#include <QTextStream>
#include <QTextEdit>
#include <QSound>
#include <QTimer>
#include <QPrinter>
#include <QMessageBox>
#include <QIntValidator>
#include <QTabWidget>
#include <QTranslator>
#include <QMessageBox>
#include <QString>
#include <QFile>
#include <QSqlQuery>
#include <QPixmap>
#include <QDebug>
#include"QSqlRecord"
#include"QSqlQuery"
#include <QLabel>
#include <QPixmap>
#include <QSqlDatabase>
#include <QSqlError>
#include<QtPrintSupport/QPrinter>
#include<QPdfWriter>
#include <QFileDialog>
#include<QTextDocument>
#include <QDateTime>
#include <QPainter>
#include <QSound>
#include <string>
double firstNum;
bool userIsTypingSecondNum = false;
bilan::bilan(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::bilan)
{
    ui->setupUi(this);

}

void bilan::on_total_clicked()
{
   //ui->total_2->setNum(R.get_total());

  // ui->total_2->setNum(D.get_total());

    QString x=ui->tot->currentText();
    qDebug()<<x;

    if(x=="depense"){
         ui->total_2->setNum(D.get_total());
    }else{
       ui->total_2->setNum(R.get_total());
    }

}






void bilan::on_pbResult_clicked()
{
    QMessageBox msgBox;
    int x=D.get_total();
    int y=R.get_total();

    if((y-x)>0){
         ui->res->setNum(y-x);
          msgBox.setText("mrigel");
    }else{
         ui->res->setNum(y-x);
          msgBox.setText("ERROR");

    }


}
