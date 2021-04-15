#include "fourn.h"
#include "ui_pdf.h"
#include<QSqlQuery>
#include<QMessageBox>
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QString>



fourn::fourn()
{
    id=0;
    nom="";
    prenom="";
    tel=0;
    adresse="";
}
fourn::fourn(int id,QString nom,QString prenom,int tel,QString adresse)
{
  this->id=id;
    this->nom=nom;
    this->prenom=prenom;
    this->tel=tel;
    this->adresse=adresse;
}
int fourn::getid(){return id;}
void fourn::setid(int id){this->id=id;}
QString fourn::get_nom(){return nom;}
QString fourn::get_prenom(){return prenom;}
int fourn::get_tel(){return tel;}
QString fourn::get_adresse(){return adresse;}

bool fourn::ajouter()
{
    QSqlQuery query;
    QString res= QString::number(id);
    query.prepare("INSERT INTO fourn (nom,prenom,tel,adresse) VALUES (:nom,:prenom,:tel,:adresse)");
 //   query.bindValue(":id",res);+
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":tel",tel);
    query.bindValue(":adresse",adresse);
return  query.exec();

}

QSqlQueryModel * fourn::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from fourn");
   // model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("tel"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("adresse"));
 return model;

}

bool fourn::delete_2(int id)
{
    QSqlQuery query;
    QString rec= QString::number(id);
    query.prepare("delete from FOURN where id = :id");
    query.bindValue(":id",rec);
    return query.exec();
}

bool fourn::modifier(Ui::gsf *ui){


     int id= ui->id_2->text().toInt();
     QString nom = ui->nom_2->text();
      QString prenom = ui->prenom_2->text();
     int tel= ui->tel_2->text().toInt();
     QString adresse = ui->adresse_2->text();
     fourn f(id,nom,prenom,tel,adresse);

     QSqlQuery query;
        query.prepare("UPDATE fourn SET nom ='"+nom+"',prenom ='"+prenom+"',tel='"+QString::number(tel)+"', adresse ='"+adresse+"' WHERE id= '"+QString::number(id)+"'");
        query.bindValue(":id",getid());
        query.bindValue(":nom",get_nom());
        query.bindValue(":prenom",get_prenom());
        query.bindValue(":tel",get_tel());
        query.bindValue(":adresse",get_adresse());

              return query.exec();

       }

void fourn::Rechercherfourns(int id){
        QSqlQuery query2;


        query2.prepare ("SELECT * FROM fourn WHERE id= '"+QString::number(id)+"'");
        query2.exec();

        while(query2.next()){
            id= query2.value(0).toInt();
            nom= query2.value(1).toString();
            prenom= query2.value(2).toString();
            tel=query2.value(3).toInt();
            adresse= query2.value(4).toString();
        }


    }
QSqlQueryModel*fourn::Trier(QString choix2){
    QSqlQueryModel *model=new QSqlQueryModel();


    if (choix2=="id"){
         model->setQuery("SELECT * FROM fourn ORDER BY id DESC ");
    }
    else if(choix2=="nom"){
         model->setQuery("SELECT * FROM fourn ORDER BY nom  ");
    }
    else if(choix2=="prenom"){
        model->setQuery("SELECT * FROM fourn ORDER BY prenom  ");
    }
    else if(choix2=="tel"){
        model->setQuery("SELECT * FROM fourn ORDER BY tel ASC ");
    }
    else if(choix2=="adresse"){
        model->setQuery("SELECT * FROM fourn ORDER BY adresse  ");}


    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom "));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("tel"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("adresse"));

return model;
}


void fourn::pdffonction( int code ,QString type)

    {
            QPrinter printer;
            printer.setOutputFormat(QPrinter::PdfFormat);
            printer.setOutputFileName("C:/Users/taief/Documents/stock/taief.pdf");
            QPainter painter;
            painter.begin(&printer);

            QFont font;
          //  QString code;//=ui->lineEdit_code_pdf_3->text();
            QSqlQuery query;
            QString typeanim_pdf,id_pdf,nb_pdf,type_pdf,idanimation_pdf,lieu_pdf,dateanim_pdf,duree_pdf,cin_pdf,datefin_pdf,
                    idd_pdf,iddd_pdf,a_pdf,b_pdf,c_pdf,d_pdf,e_pdf,f_pdf;
    QString code1=QString::number(code);
     // qDebug() << ":" << code;
      if (type=="fourn")
            {
                query.prepare("select * from fourn where id='"+code1+"'");
                if (query.exec())
                {
                    while (query.next())
                    {
                        iddd_pdf=query.value(0).toString();
                        nb_pdf=query.value(1).toString();
                        type_pdf=query.value(3).toString();
                        idanimation_pdf=query.value(2).toString();
                         a_pdf=query.value(4).toString();
                        /* b_pdf=query.value(5).toString();
                         c_pdf=query.value(6).toString();
                         d_pdf=query.value(7).toString();
                         e_pdf=query.value(8).toString();
                         f_pdf=query.value(9).toString();*/
                    }
                }
                font.setPixelSize(50);
                painter.setFont(font);
                painter.setPen(Qt::red);
                painter.drawText(300,150,"FOURNISSEUR");

                font.setPixelSize(35);
                painter.setFont(font);
                painter.setPen(Qt::blue);
                painter.drawText(25,300,"ID :");
                painter.drawText(25,380,"Nom :");
                painter.drawText(25,460,"Prenom :");
                painter.drawText(25,540,"Adresse :");
                painter.drawText(25,620,"tel :");
                font.setPixelSize(22);
                painter.setFont(font);
                painter.setPen(Qt::black);
                painter.drawText(350,300,iddd_pdf);
                   painter.drawText(350,380,nb_pdf);
                   painter.drawText(350,460,idanimation_pdf);
                   painter.drawText(350,540,type_pdf);
                   painter.drawText(350,620,a_pdf);
                   painter.drawText(350,700,b_pdf);
                   painter.drawText(350,780,c_pdf);
                   painter.drawText(350,860,d_pdf);
                   painter.drawText(350,940,e_pdf);
                   painter.drawText(350,1020,f_pdf);

            }
        if(type=="stock")
            {
                query.prepare("select * from stock where id='"+code1+"'");
                if (query.exec())
                {
                    while (query.next())
                    {
                        idd_pdf=query.value(0).toString();
                        typeanim_pdf=query.value(1).toString();
                        lieu_pdf=query.value(2).toString();
                        dateanim_pdf=query.value(3).toString();
                        duree_pdf=query.value(4).toString();
                        cin_pdf=query.value(5).toString();
                       // datefin_pdf=query.value(6).toString();
                    }
                }
                font.setPixelSize(45);
                painter.setFont(font);
                painter.setPen(Qt::red);
                painter.drawText(300,150,"STOCK");

                font.setPixelSize(30);
                painter.setFont(font);
                painter.setPen(Qt::blue);
                painter.drawText(25,300,"ID :");
                painter.drawText(25,400,"dat :");
                painter.drawText(25,500,"prix :");
                painter.drawText(25,600,"quantite :");
                painter.drawText(25,700,"nom :");
                painter.drawText(25,800,"type :");
               // painter.drawText(25,780,"Date de fin :");


                font.setPixelSize(22);
                painter.setFont(font);
                painter.setPen(Qt::black);

                painter.drawText(400,300,idd_pdf);
                painter.drawText(400,400,typeanim_pdf);
                painter.drawText(400,500,lieu_pdf);
                 painter.drawText(400,700,duree_pdf);
                 painter.drawText(400,800,cin_pdf);
                 painter.drawText(400,600,dateanim_pdf);

                //painter.drawText(150,350,taux_pdf+"%");
            }

            QImage image("C:/Users/taief/Documents/stock/111.png");
            painter.drawImage(-30,-100,image);
           // QImage image1("C:/Users/YedesHamda/Documents/RH_NEWS/img/prs.png");
           // painter.drawImage(720,0,image1);

            painter.end();
            qDebug()<<"le pdf a ete cree";
            //QMessageBox::information(this,"pdf cree","ce pdf a ete cree");

    }
