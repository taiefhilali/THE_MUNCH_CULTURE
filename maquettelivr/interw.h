#ifndef INTERW_H
#define INTERW_H
#include "livreur.h"
#include "livraison.h"
#include "notif.h"
#include <QSound>
#include <QTimer>
#include <QMainWindow>
#include "mainwindowvideo.h"
#include <QMediaPlayer>
#include <QVideoWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class interw; }
QT_END_NAMESPACE

class interw : public QMainWindow
{
    Q_OBJECT

public:
    interw(QWidget *parent = nullptr);
    ~interw();
public slots:
    void clockTimer();
    void clocktimer_2();

private slots:
    void on_ajouter1_clicked();

    void on_supprimer_2_clicked();

    void on_modifier3_clicked();

    void on_Ajouter_clicked();

    void on_supprimer_clicked();

    void on_PDF_clicked();

    void on_pushButton_3_clicked();

    void on_commandLinkButton_clicked();

    void on_colone_tri_activated(const QString &arg1);

    void on_commandLinkButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_colone_tri_2_activated(const QString &arg1);

    void on_PDF_2_clicked();

    void on_modifier_2_clicked();

    void on_imprimer_2_clicked();

    void on_imprimer_clicked();

    void on_pushButton_5_clicked();



    void on_nom_textChanged(const QString &arg1);

    void on_nom_2_cursorPositionChanged(int arg1, int arg2);


    void on_ajouter_1_clicked();

    void on_Ajouter_2_clicked();

    void on_pushButton_clicked();
    
    void on_excel_clicked();

    void on_excell_clicked();

    void on_export_2_clicked();

    void on_exportt_clicked();

    void on_upload_clicked();

private:
    Ui::interw *ui;
   livreur l;
   livraison liv;
   notif n;
   QSound*son;
   QSound*son2;
   QString filename;
   QTimer *qTimer;
   MainWindowvideo*video;
     QMediaPlayer* player;
        QVideoWidget* vw;
};

#endif // INTER_H
