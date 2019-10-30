#include "administrador_modificar_usuario.h"
#include "ui_administrador_modificar_usuario.h"

administrador_modificar_usuario::administrador_modificar_usuario(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::administrador_modificar_usuario)
{
    ui->setupUi(this);
}

administrador_modificar_usuario::~administrador_modificar_usuario()
{
    delete ui;
}
