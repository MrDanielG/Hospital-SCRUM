#include "usuario_tip.h"
#include "ui_usuario_tip.h"

usuario_tip::usuario_tip(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::usuario_tip)
{
    ui->setupUi(this);
}

usuario_tip::~usuario_tip()
{
    delete ui;
}

void usuario_tip::insertarDatos(QString id, QString nombre, QString imagen, QString descripcion)
{
    QPixmap imag(imagen);
    ui->imagen->setPixmap(imag);
    ui->descripcion->setPlainText(descripcion);
    ui->categoria->setText(nombre);
    this->id = id;
}
