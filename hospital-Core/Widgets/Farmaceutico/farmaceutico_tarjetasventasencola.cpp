#include "farmaceutico_tarjetasventasencola.h"
#include "ui_farmaceutico_tarjetasventasencola.h"

farmaceutico_tarjetasventasencola::farmaceutico_tarjetasventasencola(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::farmaceutico_tarjetasventasencola)
{
    ui->setupUi(this);
}

farmaceutico_tarjetasventasencola::~farmaceutico_tarjetasventasencola()
{
    delete ui;
}

void farmaceutico_tarjetasventasencola::insertarDatos(QString nombre, QString cantidad,QString precio)
{
    ui->Nombre->setText(nombre);
    ui->Cantidad->setText(cantidad);
    QString total;
    float prec = precio.toFloat();
    float can = cantidad.toFloat();
    total = can*prec;
    ui->Total->setText(total);

}
