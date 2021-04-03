#include "pdf.h"
#include "ui_pdf.h"
#include<QSqlQuery>

pdf::pdf(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pdf)
{
    ui->setupUi(this);
    //on_pdf_clicked();

}

pdf::~pdf()
{
    delete ui;
}



void pdf::pdffonction()
{
        QPrinter printer;
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setOutputFileName("C:/Users/taief/Documents/stock/hamda.pdf");
        QPainter painter;
        painter.begin(&printer);

        QFont font;
        QString code=ui->lineEdit_code_pdf_3->text();
        QSqlQuery query;
        QString idd, id,qt,nom,typeanim_pdf,id_pdf,nb_pdf,type_pdf,idanimation_pdf,lieu_pdf,dateanim_pdf,duree_pdf,cin_pdf;


        if (ui->comboBox_type_pdf_3->currentText()=="stock")
        {
            query.prepare("select * from stock where id='"+code+"'");
            if (query.exec())
            {
                while (query.next())
                {   id=query.value(0).toString();
                    nb_pdf=query.value(1).toString();
                    type_pdf=query.value(3).toString();
                    idanimation_pdf=query.value(2).toString();
                    nom=query.value(4).toString();

                }
            }
            font.setPixelSize(50);
            painter.setFont(font);
            painter.setPen(Qt::red);
            painter.drawText(350,150,"stock");

            font.setPixelSize(35);
            painter.setFont(font);
            painter.setPen(Qt::blue);
            painter.drawText(20,300,"id: ");
            painter.drawText(20,500,"dat:");
            painter.drawText(20,650,"prix:");
            painter.drawText(20,800,"quantite:");
            painter.drawText(20,950,"nom:");


            font.setPixelSize(22);
            painter.setFont(font);
            painter.setPen(Qt::black);
            painter.drawText(300,500,nb_pdf);
            painter.drawText(300,300,id);
            painter.drawText(300,650,idanimation_pdf);
             painter.drawText(300,800,type_pdf);
              painter.drawText(300,950,nom);

        }
        else
        {
            query.prepare("select * from fourn where id='"+code+"'");
            if (query.exec())
            {
                while (query.next())
                {   idd=query.value(0).toString();
                    typeanim_pdf=query.value(1).toString();
                    lieu_pdf=query.value(2).toString();
                    dateanim_pdf=query.value(3).toString();
                    duree_pdf=query.value(4).toString();
                    cin_pdf=query.value(5).toString();
                }
            }
            font.setPixelSize(50);
            painter.setFont(font);
            painter.setPen(Qt::red);
            painter.drawText(350,150,"fourn");

            font.setPixelSize(35);
            painter.setFont(font);
            painter.setPen(Qt::blue);
            painter.drawText(20,300,"id: ");
            painter.drawText(20,500,"nom:");
            painter.drawText(20,650,"prenom:");
            painter.drawText(20,850,"tel:");
            painter.drawText(20,1000,"adresse:");




            font.setPixelSize(22);
            painter.setFont(font);
            painter.setPen(Qt::black);


            painter.drawText(400,300,idd);
            painter.drawText(400,500,typeanim_pdf);
            painter.drawText(400,650,lieu_pdf);
            painter.drawText(400,850,dateanim_pdf);
             painter.drawText(400,1000,duree_pdf);




            //painter.drawText(150,350,taux_pdf+"%");
        }

        /*QImage image("C:/User/taief/Documents/stock/pdf.png");
        painter.drawImage(10,10,image);
        painter.end();
        qDebug()<<"le pdf a ete cree";
        QMessageBox::information(this,"pdf cree","ce pdf a ete cree");*/
        /*QImage image("C:/Users/taief/Documents/stock/pdf.png");
             painter.drawImage(30,30,image);*/
             QImage image1("C:/Users/taief/Documents/stock/s.png");
             painter.drawImage(10,10,image1);

             painter.end();
             qDebug()<<"le pdf a ete cree";
             QMessageBox::information(this,"pdf cree","ce pdf a ete cree");
}



void pdf::on_pushButton_imprimer_4_clicked()
{
    pdffonction();
}
