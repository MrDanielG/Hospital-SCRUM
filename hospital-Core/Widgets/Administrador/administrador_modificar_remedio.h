#ifndef ADMINISTRADOR_MODIFICAR_REMEDIO_H
#define ADMINISTRADOR_MODIFICAR_REMEDIO_H

#include <QDialog>

namespace Ui {
class administrador_modificar_remedio;
}

class administrador_modificar_remedio : public QDialog
{
    Q_OBJECT

public:
    explicit administrador_modificar_remedio(QWidget *parent = nullptr);
    ~administrador_modificar_remedio();

private:
    Ui::administrador_modificar_remedio *ui;
};

#endif // ADMINISTRADOR_MODIFICAR_REMEDIO_H
