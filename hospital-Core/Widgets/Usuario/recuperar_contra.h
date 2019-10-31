#ifndef RECUPERAR_CONTRA_H
#define RECUPERAR_CONTRA_H

#include <QDialog>

namespace Ui {
class recuperar_contra;
}

class recuperar_contra : public QDialog
{
    Q_OBJECT

public:
    explicit recuperar_contra(QWidget *parent = nullptr);
    ~recuperar_contra();

private:
    Ui::recuperar_contra *ui;
};

#endif // RECUPERAR_CONTRA_H
