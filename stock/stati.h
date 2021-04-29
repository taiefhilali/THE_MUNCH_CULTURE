#ifndef STATI_H
#define STATI_H

#include <QDialog>

namespace Ui {
class stati;
}

class stati : public QDialog
{
    Q_OBJECT

public:
    explicit stati(QWidget *parent = nullptr);
    ~stati();
 void makePolt();
private:
    Ui::stati *ui;
};

#endif // STATI_H
