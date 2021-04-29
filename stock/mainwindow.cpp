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
     c.createconnect();
    ui->user->setPlaceholderText("Entrer votre Identifiant :") ;
   ui->pass->setPlaceholderText("Entrer votre Mot de passe :") ;


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
    QString username = ui->user->text();
    QString password = ui->pass->text();

    //check if user is in default list
    QString users="taief/ghada/daly/youssef/mahdi"; // you add your ID in format admin(first 2 letters of your departement name)
    bool user_ex = users.contains(username);

    //check if password is in default list
    QString pass ="admin/1234"; // you add your password in format ADM-(first 2 letters of your departement name)
    bool pass_ex = password.contains(password);





if(user_ex && pass_ex){
close();

//open taief Space
/*
 ---------------pour tester------------
 username : taief
 mdp : admin
 --------------------------------------
*/

if (username=="taief"){
gsf *ws;
ws = new gsf();
ws->setWindowTitle("the munch_culture");
ws->show();
}

//open ghada Space
/*
 ---------------pour tester------------
 username : ghada
 mdp : admin
 --------------------------------------
*/

if (username=="ghada"){
interw *ws;
ws = new interw();
ws->setWindowTitle("the munch_culture");
ws->show();
}

//open daly Space
/*
 ---------------pour tester------------
 username : daly
 mdp : admin ou 1234
 --------------------------------------
*/

if (username=="daly"){
Clicom *ws;
ws = new Clicom();
ws->setWindowTitle("the munch_culture");
ws->show();
}

//open youssef Space
/*
 ---------------pour tester------------
 username : youssef
 mdp : admin
 --------------------------------------
*/

if (username=="youssef"){
youssef *ws;
ws = new youssef();
ws->setWindowTitle("the munch_culture");
ws->show();
}

//open mahdi Space
/*
 ---------------pour tester------------
 username : mahdi
 mdp : admin
 --------------------------------------
*/

if (username=="mahdi"){
menu *ws;
ws = new menu();
ws->setWindowTitle("the munch_culture");
ws->show();
}


}//end test login
else if( username.length()<2 )
       ui->statusbar->showMessage("Check userID format",3000);
    else if( password.length()<4 )
           ui->statusbar->showMessage("Password too short",3000);
else ui->statusbar->showMessage("login and password don't match",3000);

}

    /*QSqlQuery qry;
    qry.prepare("Select * from personnel where ID=:ID");
    qry.bindValue(":ID",username);
    qry.exec();
    while (qry.next())

    {
        if ( qry.value(0).toString()==username && qry.value(3).toString()==password  )
        {
            hide();//La fenetre d'authentification se ferme automatiquement
            menu a;
            a.exec() ;

        }


        else
            QMessageBox::warning(this, "Connexion Impossible", "Identifiant ou mot de passe incorrect ! ") ;
    }
}*/

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
