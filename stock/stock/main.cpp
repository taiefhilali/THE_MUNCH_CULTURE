
#include <QFile>
#include <QApplication>
#include <QMessageBox>
#include <QDebug>
#include <QtWidgets/QApplication>
#include "connexion.h"
#include "gsf.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    gsf w;
   // ThemeWidget *widget = new ThemeWidget();
    //window.setCentralWidget(widget);
   // window.resize(900, 600);
   // window.show();
    QFile styleSheetFile(":/StyleSheet/MacOS.qss");
              styleSheetFile.open(QFile::ReadOnly);
              QString styleSheet = QLatin1String(styleSheetFile.readAll());
              a.setStyleSheet(styleSheet);

    Connection c;
        bool test=c.createconnect();
        if(test)
        {w.show();
            QMessageBox::information(nullptr, QObject::tr("database is open"),
                        QObject::tr("connection successful.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

    }
        else
            QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                        QObject::tr("connection failed.\n"
                                    "Click Cancel to exit."),
    QMessageBox::Cancel);

        return a.exec();

    w.show();
    return a.exec();
}
