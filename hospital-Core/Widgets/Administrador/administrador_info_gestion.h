#ifndef ADMINISTRADOR_INFO_GESTION_H
#define ADMINISTRADOR_INFO_GESTION_H

#include <QDialog>

namespace Ui {
class administrador_info_gestion;
}

class administrador_info_gestion : public QDialog
{
    Q_OBJECT

public:
    explicit administrador_info_gestion(QWidget *parent = nullptr);
    ~administrador_info_gestion();

private:
    Ui::administrador_info_gestion *ui;
};

#endif // ADMINISTRADOR_INFO_GESTION_H
