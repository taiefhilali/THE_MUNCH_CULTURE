#include "mainwindow.h"
#include <QFile>
#include <QApplication>
#include <QMessageBox>
#include <QDebug>
#include "connection2.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    connection2 c;
       bool test=c.createconnect();
       if(test)
       {w.show();
           notif n("connecté avec succés","database open");
                 n.afficher();

   }
       else
           QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                       QObject::tr("connection failed.\n"
                                   "Click Cancel to exit."),
   QMessageBox::Cancel);

       return a.exec();
}
