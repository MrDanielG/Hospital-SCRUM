#ifndef ADMINISTRADOR_MODIFICAR_USUARIO_H
#define ADMINISTRADOR_MODIFICAR_USUARIO_H

#include <QDialog>

namespace Ui {
class administrador_modificar_usuario;
}

class administrador_modificar_usuario : public QDialog
{
    Q_OBJECT

public:
    explicit administrador_modificar_usuario(QWidget *parent = nullptr);
    ~administrador_modificar_usuario();

private:
    Ui::administrador_modificar_usuario *ui;
};

#endif // ADMINISTRADOR_MODIFICAR_USUARIO_H
