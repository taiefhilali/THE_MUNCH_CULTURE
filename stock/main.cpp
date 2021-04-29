
#include <QFile>
#include <QApplication>
#include <QMessageBox>
#include <QTranslator>
#include <QDebug>
#include <QInputDialog>
#include <QtWidgets/QApplication>
#include "connexion.h"
#include "mainwindow.h"

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
   MainWindow w;
      Connection c;

      QTranslator T;
       QTranslator guiTranslator;
      QStringList langs;
      langs <<"arabic"<<"dutsch"<<"francais";
      const QString lang =QInputDialog ::getItem(NULL,"language","select a language",langs);
      if (lang=="arabic" )
       {T.load(":/arabic.ts");
          guiTranslator.load("C:Qt/Qt5.9.9/5.9.9/mingw53_32/translations/qt_ar.qm");
      }
          else if
       (lang=="deutsch")
      {T.load(":/deutsch.qm");}
      bool test=c.createconnect();
        if
   (lang=="francais")
  {T.load(":/francais.qm");}


      if (lang!="francais")
      {a.installTranslator(&T);
      a.installTranslator(&guiTranslator);}

   // ThemeWidget *widget = new ThemeWidget();
    //window.setCentralWidget(widget);
   // window.resize(900, 600);
   // window.show();
    QFile styleSheetFile(":/StyleSheet/MacOS.qss");
              styleSheetFile.open(QFile::ReadOnly);
              QString styleSheet = QLatin1String(styleSheetFile.readAll());
              a.setStyleSheet(styleSheet);

        bool test1=c.createconnect();
        if(test1)
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
