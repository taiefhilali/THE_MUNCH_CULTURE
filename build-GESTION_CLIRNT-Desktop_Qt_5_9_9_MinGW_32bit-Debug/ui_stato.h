/********************************************************************************
** Form generated from reading UI file 'stato.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATO_H
#define UI_STATO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_stato
{
public:
    QCustomPlot *customPlot;

    void setupUi(QDialog *stato)
    {
        if (stato->objectName().isEmpty())
            stato->setObjectName(QStringLiteral("stato"));
        stato->resize(764, 489);
        customPlot = new QCustomPlot(stato);
        customPlot->setObjectName(QStringLiteral("customPlot"));
        customPlot->setGeometry(QRect(10, 10, 741, 461));

        retranslateUi(stato);

        QMetaObject::connectSlotsByName(stato);
    } // setupUi

    void retranslateUi(QDialog *stato)
    {
        stato->setWindowTitle(QApplication::translate("stato", "Dialog", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class stato: public Ui_stato {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATO_H
