#ifndef ADMINISTRADOR_CREAR_REMEDIO_H
#define ADMINISTRADOR_CREAR_REMEDIO_H

#include <QDialog>

namespace Ui {
class administrador_crear_remedio;
}

class administrador_crear_remedio : public QDialog
{
    Q_OBJECT

public:
    explicit administrador_crear_remedio(QWidget *parent = nullptr);
    ~administrador_crear_remedio();

private:
    Ui::administrador_crear_remedio *ui;
};

#endif // ADMINISTRADOR_CREAR_REMEDIO_H
