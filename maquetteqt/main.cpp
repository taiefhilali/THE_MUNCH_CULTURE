#include "gestion_prd.h"
#include <QFile>
#include <QApplication>
#include <QMessageBox>
#include <QDebug>
#include "connexion.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connection c;
    bool test=c.ouvrirConnexion();
   gestion_prd w;
    QFile styleSheetFile(":/StyleSheet/MacOS.qss");
                  styleSheetFile.open(QFile::ReadOnly);
                  QString styleSheet = QLatin1String(styleSheetFile.readAll());
                  a.setStyleSheet(styleSheet);
    if(test)
    {w.show();
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);



    return a.exec();
}

