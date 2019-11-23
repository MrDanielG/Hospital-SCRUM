#ifndef USUARIO_TIP_H
#define USUARIO_TIP_H

#include <QDialog>

namespace Ui {
class usuario_tip;
}

class usuario_tip : public QDialog
{
    Q_OBJECT

public:
    explicit usuario_tip(QWidget *parent = nullptr);
    ~usuario_tip();

private:
    Ui::usuario_tip *ui;
};

#endif // USUARIO_TIP_H
