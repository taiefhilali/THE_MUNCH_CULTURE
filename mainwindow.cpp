#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "menu.h"
#include <QMediaPlayer>
#include<QDateTime>
#include<QTimer>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->username->setPlaceholderText("Entrer votre Identifiant :") ;
    ui->password->setPlaceholderText("Entrer votre Mot de passe :") ;


    music->setMedia(QUrl("D:/Desktop/1.mp3"));


    timer=new QTimer(this) ;
    connect(timer , SIGNAL(timeout()),this,SLOT(myfunction())) ;
    timer->start(1000) ;
    qDebug()<<music->errorString();

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString username = ui->username->text();
    QString password = ui->password->text();

    QSqlQuery qry;
    qry.prepare("Select * from personnel where ID=:ID");
    qry.bindValue(":ID",username);
    qry.exec();
    while (qry.next())

    {
        if ( qry.value(0).toString()==username && qry.value(3).toString()==password  )
        {
            hide();//La fenetre d'authentification se ferme automatiquement


        }


        else
            QMessageBox::warning(this, "Connexion Impossible", "Identifiant ou mot de passe incorrect ! ") ;
    }
}

void MainWindow::myfunction()
{
    QTime time = QTime::currentTime() ;
    QString time_text=time.toString("hh : mm : ss")  ;
    ui->label_date_time->setText(time_text) ;

}

void MainWindow::on_pushButton_2_clicked()
{
    music->play() ;
}

void MainWindow::on_pushButton_3_clicked()
{
    music->stop() ;

}
