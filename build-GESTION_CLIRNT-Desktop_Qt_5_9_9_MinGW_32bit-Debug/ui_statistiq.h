/********************************************************************************
** Form generated from reading UI file 'statistiq.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATISTIQ_H
#define UI_STATISTIQ_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_statistiq
{
public:
    QCustomPlot *customPlot;

    void setupUi(QDialog *statistiq)
    {
        if (statistiq->objectName().isEmpty())
            statistiq->setObjectName(QStringLiteral("statistiq"));
        statistiq->resize(764, 489);
        customPlot = new QCustomPlot(statistiq);
        customPlot->setObjectName(QStringLiteral("customPlot"));
        customPlot->setGeometry(QRect(40, 10, 711, 441));

        retranslateUi(statistiq);

        QMetaObject::connectSlotsByName(statistiq);
    } // setupUi

    void retranslateUi(QDialog *statistiq)
    {
        statistiq->setWindowTitle(QApplication::translate("statistiq", "Dialog", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class statistiq: public Ui_statistiq {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATISTIQ_H
