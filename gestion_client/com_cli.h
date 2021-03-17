#ifndef COM_CLI_H
#define COM_CLI_H

#include <QDialog>

namespace Ui {
class com_cli;
}

class com_cli : public QDialog
{
    Q_OBJECT

public:
    explicit com_cli(QWidget *parent = nullptr);
    ~com_cli();

private:
    Ui::com_cli *ui;
};

#endif // COM_CLI_H
