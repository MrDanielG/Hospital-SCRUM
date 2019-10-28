#include "catalogo_doctores.h"
#include "ui_catalogo_doctores.h"
#include <QSqlQuery>
#include "Widgets/Usuario/tarjeta_doctor.h"

catalogo_doctores::catalogo_doctores(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::catalogo_doctores)
{
    ui->setupUi(this);

    QSqlQuery query(mDatabase);
//    query.prepare("select descripcion, fotografia, estado, no_estrellas, "
//                  "id_casa from casa INNER JOIN direccion ON casa.id_direccion = direccion.id_direccion");
//    query.exec();

    int i=0;
    int row = 0;
    int col = 0;

    while (query.next()){
        QString descripcion = query.value(0).toString();
        QString fotografia = query.value(1).toString();
        QString estado = query.value(2).toString();
        QString estrellas = query.value(3).toString();
        QString idCasa = query.value(4).toString();
        row = i/4;
        col= i%4;

        tarjeta_doctor *tarjeta = new tarjeta_doctor(foto, nombre, especialidad, estrellas);
        i++;

        ui->gridLayout->addWidget(tarjeta, row, col);

    }
}

catalogo_doctores::~catalogo_doctores()
{
    delete ui;
}
