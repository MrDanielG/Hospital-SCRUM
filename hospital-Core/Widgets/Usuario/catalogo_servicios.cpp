#include "catalogo_servicios.h"
#include "ui_catalogo_servicios.h"
#include "Widgets/Usuario/tarjeta_servicios.h"
#include <QDebug>

Catalogo_servicios::Catalogo_servicios(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Catalogo_servicios)
{
    ui->setupUi(this);
    mDatabase = QSqlDatabase::database("Connection");
    if (!mDatabase.isOpen()){
        qDebug() << "ERROR";
    }else{
        qDebug() << "base de datos sigue conectada en INICIAR SESION";
    }
    QSqlQuery query(mDatabase);

    query.prepare("select * from info where id_tipo_info = 3");
    query.exec();

    int i=0;
    int row = 0;
    int col = 0;

    while (query.next()) {
        //aqui se ponen los valores de la query
         QString id = query.value(0).toString();
         QString foto = query.value(5).toString();
         QString nombre = query.value(1).toString();
         row = i/4;
         col= i%4;

         Tarjeta_Servicios *tarjeta = new Tarjeta_Servicios(id, foto, nombre);
         tarjeta->insertarDatos();

         i++;
         ui->gridLayoutServicios->addWidget(tarjeta, row, col);
    }




}

Catalogo_servicios::~Catalogo_servicios()
{
    delete ui;
}
