#include "menu.h"
#include "ui_menu.h"
#include "arduino.h"
#include "mainwindow.h"
#include <QMessageBox>
#include "personnel.h"
#include "profil.h"
#include <QSqlQuery>
#include "QDebug"
#include <QFileDialog>
#include <QBuffer>
#include <cstdlib>
#include <QImage>
#include <QPrinter>
#include<QPrintDialog>









//fin arduino
menu::menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::menu)
{
    ui->setupUi(this);
    int ret = A.connect_arduino();
            switch (ret)
            {
                case(0):qDebug()<<"arduino is available and connected to :" << A.getarduino_port_name();
                break;
                case(1):qDebug()<<"arduino is available but not connected to :" << A.getarduino_port_name();
                break;
                case(-1):qDebug()<<"arduino is not available";
                break;

            }
            QObject::connect(A.getserial(), SIGNAL(readyRead()), this, SLOT(update_label()));

     ui->table_profil->setModel(tmp_profil.afficher());
    ui->table_personnel->setModel(tmp_personnel.afficher());


}

menu::~menu()
{
    delete ui;
}
//arduino

void menu::update_label()
{
    data=A.read_from_arduino();
    QString DataAsString = QString(data);
    qDebug()<< data;

    ui->label_21->setText("temp : "+data);

    if (data=="21"||data=="22"||data=="23"||data=="24"||data=="25"){
        if (messageboxactive==0){
            alert=1;
        }


    }
    if (alert==1){
        alert=0;
        messageboxactive=1;
        int reponse = QMessageBox::question(this, "led", "allumer led", QMessageBox::Yes |  QMessageBox::No);
        if (reponse == QMessageBox::Yes)
        {
            led=1;
        }
        if (reponse == QMessageBox::No)
        {
            led=0;
        }

    }
    if (led==1){
        A.write_to_arduino("1");
    }
    if (data=="20"||data=="19"||data=="18"||data=="17"||data=="16"){
        A.write_to_arduino("0");
        led=0;
    }

}
void menu::on_Ajouter_clicked()
{
    QString id=ui->id->text();
    QString nom=ui->nom->text();
    QString prenom=ui->prenom->text();
    QString mdp=ui->mdp->text();
    QString date_emb=ui->date_emb->text();
    QString salaire=ui->salaire->text();
    QString type=ui->type->text();

 personnel p(id,nom,prenom,mdp,date_emb,salaire,type);
 p.AjoutImage(fileNameImage);
 bool test=p.ajouter();
 QMessageBox msgBox;

 if(test)
   {  msgBox.setText("Ajout avec succes.");
//     ui->tab_etudiant->setModel(E.afficher());
    ui->table_personnel->setModel(tmp_personnel.afficher());
 }
 else
     msgBox.setText("Echec d'ajout");
     msgBox.exec();
}

void menu::on_ajouter1_clicked()

    {
        QString ID=ui->id_profil->text();
        QString login=ui->login->text();
        QString mdp=ui->mdp_2->text();


     profil p(ID,login,mdp);
     bool test=p.ajouter();
     QMessageBox msgBox;

     if(test)
       {  msgBox.setText("Ajout avec succes.");
         ui->table_profil->setModel(tmp_profil.afficher());
    //     ui->tab_etudiant->setModel(E.afficher());
     }
     else
        {
         msgBox.setText("Echec d'ajout");
         msgBox.exec();
    }

}

void menu::on_supprimer_employee_clicked()
{
    QString id=ui->i_stock->text() ;
    QString str = " Vous voulez vraiment supprimer \n l'employe :";
    int ret = QMessageBox::question(this, tr("employe"),str,QMessageBox::Ok|QMessageBox::Cancel);

    switch (ret) {
    case QMessageBox::Ok:
        bool test=tmp_personnel.supprimer(id) ;
        if(test)
        {
            ui->table_personnel->setModel(tmp_personnel.afficher()) ;
        }
        else
        {

            QMessageBox::critical(0, qApp->tr("Suppression"),
                                  qApp->tr("error "), QMessageBox::Cancel);
        }



        break;

    }
}

void menu::on_modifier_employee_clicked()
{
    QString id=ui->id_employee->text();
    QString nom=ui->nom_2->text();
    QString prenom=ui->prenom_2->text();
    QString mdp=ui->mdp_3->text();
    QString date_emb=ui->date_emb_2->text();
    QString salaire=ui->salaire_2->text();
    QString type=ui->type_2->text();

 personnel p(id,nom,prenom,mdp,date_emb,salaire,type);


      bool test=p.modifier(nom, prenom, mdp, date_emb, salaire, type, id);
         if (test)
         {
             ui->table_personnel->setModel(tmp_personnel.afficher()) ;
             QMessageBox::information(nullptr, QObject::tr("Modifier un personnelb"),
                         QObject::tr("personnel modifié.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);

         }
         else
             QMessageBox::critical(nullptr, QObject::tr("Modifier un personnaelsba"),
                         QObject::tr("Erreur !.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
}

void menu::on_supprimer_profil_clicked()
{
    QString id=ui->id_profil_3->text() ;
    QString str = " Vous voulez vraiment supprimer \n le profil :";
    int ret = QMessageBox::question(this, tr("profil"),str,QMessageBox::Ok|QMessageBox::Cancel);

    switch (ret) {
    case QMessageBox::Ok:
        bool test=tmp_profil.supprimer(id) ;
        if(test)
        {
            ui->table_profil->setModel(tmp_profil.afficher()) ;
        }
        else
        {

            QMessageBox::critical(0, qApp->tr("Suppression"),
                                  qApp->tr("error "), QMessageBox::Cancel);
        }

        break;

    }
}

void menu::on_modifier_profil_clicked()
{
    QString id=ui->id_employee_2->text();
    QString login=ui->login_3->text();
    QString mdp=ui->mdp_5->text();

 profil p(id,login,mdp);


      bool test=p.modifier(id,login, mdp);
         if (test)
         {
             ui->table_profil->setModel(tmp_profil.afficher()) ;
             QMessageBox::information(nullptr, QObject::tr("Modifier un personnelb"),
                         QObject::tr("personnel modifié.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);

         }
         else
             QMessageBox::critical(nullptr, QObject::tr("Modifier un personnaelsba"),
                         QObject::tr("Erreur !.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
}

void menu::on_tri_employee_clicked()
{
      ui->table_personnel->setModel(tmp_personnel.afficherselonid());
}


//void menu::on_colone_tri_textActivated(const QString &arg1)
//{
//    QString type=arg1;
//      //   QString val=ui->rechercheM_4->text();
//     //    val="%"+val+"%";
//         if (type=="Id_employee"){
//             QSqlQueryModel * modal= new QSqlQueryModel();
//             QSqlQuery request;
//                 request.prepare("select * from personnel order by id DESC");
//                 request.exec();
//                 modal->setQuery(request);
//                 ui->table_personnel->setModel(modal);    }
//         else if (type=="date de naissance employee"){
//             QSqlQueryModel * modal= new QSqlQueryModel();
//             QSqlQuery request;
//                 request.prepare("select * from personnel order by DATE_EMB DESC");
//                 request.exec();
//                 modal->setQuery(request);
//                 ui->table_personnel->setModel(modal); }else if (type=="prenom"){
//             QSqlQueryModel * modal= new QSqlQueryModel();
//             QSqlQuery request;
//                 request.prepare("select * from personnel order by prenom DESC");
//                 request.exec();
//                 modal->setQuery(request);
//                 ui->table_personnel->setModel(modal);
//     }else if (type=="numéro"){
//             QSqlQueryModel * modal= new QSqlQueryModel();
//             QSqlQuery request;
//                 request.prepare("select * from employer order by numtel DESC");
//                 request.exec();
//                 modal->setQuery(request);
//                 ui->table_personnel->setModel(modal); }
//}


//void menu::mailSent(QString status)
//{
//    if(status == "Message sent")
//        QMessageBox::warning( 0, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
//}


//void menu::recherche_personnel()

//{

//   * QString valeur=ui->recherche_personnel->text();

//    if (valeur=="nom_personnel")

//        ui->tab_personnel->setModel(tmp_personnel.rechercher_nom_personnel(valeur));


//    else if (valeur=="cin_personnel")

//        ui->tab_personnel->setModel(tmp_personnel.rechercher_id_personnel(valeur));*/
//     QString nom=ui->recherche_personnel->text();
//     ui->tab_personnel->setModel(tmp_personnel.rechercher_nom_personnel(nom));


//   * QString valeur=ui->recherche_personnel->text();

//    bool test = false, test1 = false;
//    if (valeur == "cin_personnel")
//        test = tmp_personnel.rechercher_id_personnel(valeur);
//    else if (valeur == "nom_personnel")
//        test1 = tmp_personnel.rechercher_nom_personnel(valeur);*/


//}

void menu::on_pushButton_3_clicked()
{
    QSqlQuery query ;
    QString fileName=QFileDialog::getOpenFileName( this, tr("Open Document"), QDir::currentPath(), tr("Document files (*.doc *.rtf);;All files (*.*)"),0 );
    QPixmap inPixmap;
    if (QFile::exists(fileName))
    {
        fileNameImage=fileName;
        inPixmap=fileName;
        ui->label_photo->setPixmap(inPixmap);
    }

}


void menu::on_table_personnel_activated(const QModelIndex &index)
{
    QPixmap pixmap;
    QByteArray array;
    QString id=ui->table_personnel->model()->data(index).toString() ;
    QSqlQuery query ;
    query.prepare("select * from personnel where ID='"+id+"'  ");
    if(query.exec())
    {
    while(query.next())
    {
        array = query.value(7).toByteArray();

        QBuffer buffer(&array);
        image=(array);
        QPixmap outPixmap = QPixmap();
           outPixmap.loadFromData( image );
        ui->label_image->setPixmap(outPixmap) ;
//    ui->label_image->setText(query.value(7).toString()) ;

}
    }
}

void menu::on_le_recherche_cursorPositionChanged(int arg1, int arg2)
{
    QString id = ui->le_recherche->text();
    ui->table_personnel->setModel(tmp_personnel.rechercheid(id));
}

void menu::on_supprimer_clicked()
{

}



void menu::on_button_tri_2_clicked()
{
      ui->table_profil->setModel(tmp_profil.afficherselonid());
}

void menu::on_pdf_clicked()
{
    QPdfWriter pdf("D:/Desktop/restaurant/Pdf.pdf");
    QPainter painter(&pdf);
    int i = 4000;
    painter.setPen(Qt::blue);
    painter.setFont(QFont("Arial", 30));
    painter.drawText(1100,1200,"Liste Des employe ");
    painter.setPen(Qt::black);
    painter.setFont(QFont("Arial", 50));
    painter.drawRect(100,100,7300,2600);
//    painter.drawPixmap(QRect(7600,70,2000,2600),QPixmap("C:/Users/MSI/Downloads/logo.png"));
    painter.drawRect(0,3000,9600,500);
    painter.setFont(QFont("Arial", 9));
    painter.drawText(200,3300,"nom");
    painter.drawText(1700,3300,"prenom");
    painter.drawText(3200,3300,"mdp");
    painter.drawText(4900,3300,"date embauche");
    painter.drawText(6600,3300,"salaire");
    painter.drawText(8100,3300,"type");

    QSqlQuery query;
    query.prepare("select * from personnel");
    query.exec();
    while (query.next())
    {
        painter.drawText(200,i,query.value(1).toString());
        painter.drawText(1700,i,query.value(2).toString());
        painter.drawText(3200,i,query.value(3).toString());
        painter.drawText(4900,i,query.value(4).toString());
        painter.drawText(6600,i,query.value(5).toString());
        painter.drawText(8100,i,query.value(6).toString());

        i = i + 500;
    }
    int reponse = QMessageBox::question(this, "Génerer PDF", "<PDF Enregistré>...Vous Voulez Affichez Le PDF ?", QMessageBox::Yes |  QMessageBox::No);
    if (reponse == QMessageBox::Yes)
    {
        QDesktopServices::openUrl(QUrl::fromLocalFile("D:/Desktop/restaurant/Pdf.pdf"));
        painter.end();
    }
    if (reponse == QMessageBox::No)
    {
        painter.end();
    }
}

void menu::on_pushButton_clicked()
{
    ui->temprature->setCurrentIndex(1) ;
}
