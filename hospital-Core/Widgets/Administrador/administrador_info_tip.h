#ifndef ADMINISTRADOR_INFO_TIP_H
#define ADMINISTRADOR_INFO_TIP_H

#include <QDialog>

namespace Ui {
class administrador_info_tip;
}

class administrador_info_tip : public QDialog
{
    Q_OBJECT

public:
    explicit administrador_info_tip(QWidget *parent = nullptr);
    ~administrador_info_tip();

private:
    Ui::administrador_info_tip *ui;
};

#endif // ADMINISTRADOR_INFO_TIP_H
