#ifndef HISTO_H
#define HISTO_H


#include <iostream>
#include <QString>
#include <QObject>
#include <QFile>
#include <QDebug>
#include <QTextStream>
#include <QTimer>
#include <QDateTime>
class Histo
{
public:
    Histo();
    void write(QString);
    QString read();
private:
    QString mFilename;

};



#endif // HISTO_H
