#include "statistiq.h"
#include "ui_statistiq.h"
#include"QSqlRecord"
#include "qcustomplot.h"
#include"QSqlQuery"
#include <QSqlQueryModel>
#include <QDebug>
#include <QSqlError>
statistiq::statistiq(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::statistiq)
{
    ui->setupUi(this);
    this->setWindowTitle("statistiques");
    makePolt();
}

statistiq::~statistiq()
{
    delete ui;
}

void statistiq::makePolt()
{
    QLinearGradient gradient(0, 0, 0, 400);
    gradient.setColorAt(0, QColor(90, 90, 90));
    gradient.setColorAt(0.38, QColor(105, 105, 105));
    gradient.setColorAt(1, QColor(70, 70, 70));
    ui->customPlot->setBackground(QBrush(gradient));
    QCPBars *regen = new QCPBars(ui->customPlot->xAxis, ui->customPlot->yAxis);
    regen->setAntialiased(false);
    regen->setStackingGap(1);
    regen->setName("prix de stock par rapport a 100dt");
    regen->setPen(QPen(QColor(111, 9, 176).lighter(170)));
    regen->setBrush(QColor(111, 9, 176));


    // prepare x axis with country labels:
    QVector<double> ticks;
    QVector<QString> labels;
    ticks << 1 << 2 << 3 ;
    labels << "inf à 100" << "egale à 100 " << "sup à 100 "  ;
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTicks(ticks, labels);
    ui->customPlot->xAxis->setTicker(textTicker);
    ui->customPlot->xAxis->setTickLabelRotation(60);
    ui->customPlot->xAxis->setSubTicks(false);
    ui->customPlot->xAxis->setTickLength(0, 4);
    ui->customPlot->xAxis->setRange(0, 8);
    ui->customPlot->xAxis->setBasePen(QPen(Qt::white));
    ui->customPlot->xAxis->setTickPen(QPen(Qt::white));
    ui->customPlot->xAxis->grid()->setVisible(true);
    ui->customPlot->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
    ui->customPlot->xAxis->setTickLabelColor(Qt::white);
    ui->customPlot->xAxis->setLabelColor(Qt::white);

    // prepare y axis:
    ui->customPlot->yAxis->setRange(0,20);
    ui->customPlot->yAxis->setPadding(5); // a bit more space to the left border
     ui->customPlot->yAxis->setLabel("Nombre de produit \n ");
    ui->customPlot->yAxis->setBasePen(QPen(Qt::white));
    ui->customPlot->yAxis->setTickPen(QPen(Qt::white));
    ui->customPlot->yAxis->setSubTickPen(QPen(Qt::white));
    ui->customPlot->yAxis->grid()->setSubGridVisible(true);
    ui->customPlot->yAxis->setTickLabelColor(Qt::white);
    ui->customPlot->yAxis->setLabelColor(Qt::white);
    ui->customPlot->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
    ui->customPlot->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));

    // Add data:
    QVector<double> regenData;


QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM stock where prix <100 ");
    query.exec();

    if (!query.isActive())
        QMessageBox::warning(this, tr("Database Error"),query.lastError().text());
    query.next();
    int numberOfPages = query.value(0).toInt();
    qDebug()<<numberOfPages;


    QSqlQuery query1;
        query1.prepare("SELECT COUNT(*) FROM stock where prix =100 ");
        query1.exec();

        if (!query1.isActive())
            QMessageBox::warning(this, tr("Database Error"),query.lastError().text());
        query1.next();
        int numberOfPages1 = query1.value(0).toInt();
        qDebug()<<numberOfPages1;

        //

        QSqlQuery query2;
            query2.prepare("SELECT COUNT(*) FROM stock where prix >100 ");
            query2.exec();

            if (!query2.isActive())
                QMessageBox::warning(this, tr("Database Error"),query.lastError().text());
            query2.next();
            int numberOfPages2 = query2.value(0).toInt();
            qDebug()<<numberOfPages2;





QSqlQueryModel * model= new QSqlQueryModel();




    regenData << numberOfPages << numberOfPages1 << numberOfPages2 ;
    regen->setData(ticks, regenData);

    // setup legend:
    ui->customPlot->legend->setVisible(true);
    ui->customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
    ui->customPlot->legend->setBrush(QColor(255, 255, 255, 100));
    ui->customPlot->legend->setBorderPen(Qt::NoPen);
    QFont legendFont = font();
    legendFont.setPointSize(10);
    ui->customPlot->legend->setFont(legendFont);
    ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
}
