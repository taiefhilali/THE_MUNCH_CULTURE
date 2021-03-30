#ifndef GSF_H
#define GSF_H

#include <QDialog>
#include "stocks.h"
#include "fourn.h"
#include <QSound>
namespace Ui {
class gsf;
}

class gsf : public QDialog
{
    Q_OBJECT

public:
    explicit gsf(QWidget *parent = nullptr);
    ~gsf();
private slots:
    void on_Ajouter_clicked();

    void on_supprimer_clicked();

    void on_ajouter1_clicked();


    //void on_supprimer_2_clicked();

    void on_modifier_2_clicked();

    void on_rechercher_clicked();

    void on_refresh_clicked();

   // void on_pushButton_3_clicked();

    void on_PDF_2_clicked();

   // void on_colone_tri_activated(const QString &arg1);

    void on_combo_activated();

  //  void makePlot();
   // void on_stat_clicked();

    void on_pushButton_2_clicked();

    void on_modifier3_clicked();

    void on_refresh_2_clicked();

    void on_rechercher_2_clicked();

    void on_trie_2_activated();

    void on_pdf2_clicked();

    void on_combo_2_activated();

  //  void on_imprimer_2_clicked();

   // void on_stat_2_clicked();

    void on_delete_2_clicked();

    void on_pushButton_clicked();

    void on_commandLinkButton_clicked();

    void on_commandLinkButton_2_clicked();

    void on_pushButton_3_clicked();


    void on_IMPORT_clicked();

    void on_pushButton_4_clicked();

    void on_play_clicked();

    void on_EXPORT_clicked();

    void on_excel_clicked();

private:
    Ui::gsf *ui;
    stocks S;
    fourn f;
    QSound *son;
    QLabel *label1;
};

#endif // GSF_H