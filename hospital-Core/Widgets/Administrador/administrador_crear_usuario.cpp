#include "administrador_crear_usuario.h"
#include "ui_administrador_crear_usuario.h"

administrador_crear_usuario::administrador_crear_usuario(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::administrador_crear_usuario)
{
    ui->setupUi(this);
}

administrador_crear_usuario::~administrador_crear_usuario()
{
    delete ui;
}
