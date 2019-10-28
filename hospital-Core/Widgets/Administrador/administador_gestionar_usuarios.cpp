#include "administador_gestionar_usuarios.h"
#include "ui_administador_gestionar_usuarios.h"

administador_gestionar_usuarios::administador_gestionar_usuarios(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::administador_gestionar_usuarios)
{
    ui->setupUi(this);
}

administador_gestionar_usuarios::~administador_gestionar_usuarios()
{
    delete ui;
}
