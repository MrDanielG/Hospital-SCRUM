#include "administrador_tarjeta_remedio.h"
#include "ui_administrador_tarjeta_remedio.h"
#include "Widgets/Administrador/administrador_catalogo_remedios.h"
#include "QPixmap"
administrador_tarjeta_remedio::administrador_tarjeta_remedio(QString id, QString nombre, QString descripcion, QString foto, administrador_catalogo_remedios *parent) :
    QWidget(parent),
    ui(new Ui::administrador_tarjeta_remedio)
{
    ui->setupUi(this);

    this->id = id;
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->foto = foto;
    this->padre = parent;
}

void administrador_tarjeta_remedio::llenarTarjeta()
{
    QPixmap img(this->foto);
    ui->nombre_remedio->setText(this->nombre);
    ui->plainTextEdit->setPlainText(this->descripcion);
    ui->img_remedio->setPixmap(img);
}

administrador_tarjeta_remedio::~administrador_tarjeta_remedio()
{
    delete ui;
}

void administrador_tarjeta_remedio::on_btn_modificar_clicked()
{
    QSqlQuery query(mDatabase);
    query.exec("UPDATE info SET ");
}

void administrador_tarjeta_remedio::on_btn_eliminar_clicked()
{
    QSqlQuery query(mDatabase);
    query.exec("DELETE FROM info WHERE id_info = '"+this->id+"'");
}