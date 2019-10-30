#ifndef ADMINISTRADOR_CREAR_USUARIO_H
#define ADMINISTRADOR_CREAR_USUARIO_H

#include <QDialog>

namespace Ui {
class administrador_crear_usuario;
}

class administrador_crear_usuario : public QDialog
{
    Q_OBJECT

public:
    explicit administrador_crear_usuario(QWidget *parent = nullptr);
    ~administrador_crear_usuario();

private:
    Ui::administrador_crear_usuario *ui;
};

#endif // ADMINISTRADOR_CREAR_USUARIO_H
