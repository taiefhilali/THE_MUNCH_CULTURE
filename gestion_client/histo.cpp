#include "histo.h"

Histo::Histo()
{

    mFilename="C:/Users/User/Desktop/the munch culture/gestion_client/histo.txt";
    }

    QString Histo::read()
    {
    QFile mFile(mFilename);
    if (!mFile.open(QFile::ReadOnly | QFile::Text))
    {
        qDebug () <<"il ne peut pas";
    }
    QTextStream in (&mFile);
    QString text=mFile.readAll();
    mFile.close();
    return  text;
    }
    void Histo::write(QString text)
    {
        QString aux=read();

        QDateTime datetime = QDateTime::currentDateTime();
        QString date =datetime.toString();
        date+= " ";
        aux+=date;
    QFile mFile(mFilename);
    if (!mFile.open(QFile::WriteOnly | QFile::Text))
    {
        qDebug () <<"il ne peut pas";
    }
    QTextStream out (&mFile);


    aux+=text;
    out << aux << "\n";
    mFile.flush();
    mFile.close();

    }

