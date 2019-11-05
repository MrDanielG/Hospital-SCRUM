#include "catalogo_servicios.h"
#include "ui_catalogo_servicios.h"
#include "Widgets/Usuario/tarjeta_servicios.h"
#include <QDebug>
#include <QSqlError>

Catalogo_servicios::Catalogo_servicios(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Catalogo_servicios)
{
    ui->setupUi(this);
#ifdef Q_OS_WIN
  mDatabase = QSqlDatabase::database("Connection");
#elif defined(Q_OS_MAC)
  mDatabase = QSqlDatabase::database();
  mDatabase.setHostName("localhost");
  mDatabase.setDatabaseName("hospital");
  mDatabase.setUserName("root");
  mDatabase.setPassword("luisdrew1394");
#endif
    if (!mDatabase.isOpen()){
        qDebug() << "ERROR conexion a la Base, esto es CATALOGO SERVICIOS";
    }else{
        qDebug() << "Base de datos sigue conectada en CATALOGO SERVICIOS";
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
