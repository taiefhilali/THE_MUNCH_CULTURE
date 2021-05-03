#include "interw.h"
#include <QFile>
#include <QApplication>
#include <QMessageBox>
#include <QDebug>
#include "connection2.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    interw w;
    QFile styleSheetFile(":/StyleSheet/MacOS.qss");
                  styleSheetFile.open(QFile::ReadOnly);
                  QString styleSheet = QLatin1String(styleSheetFile.readAll());
                  a.setStyleSheet(styleSheet);
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
