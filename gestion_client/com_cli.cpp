#include "com_cli.h"
#include "ui_com_cli.h"

com_cli::com_cli(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::com_cli)
{
    ui->setupUi(this);
}

com_cli::~com_cli()
{
    delete ui;
}
