#include "administrador_servicios_hospital.h"
#include "ui_administrador_servicios_hospital.h"
#include "Widgets/Administrador/administrador_tarjeta_servicios.h"
#include "Widgets/Administrador/administrador_crear_servicio.h"
#include "QDebug"
#include<QSqlError>

administrador_servicios_hospital::administrador_servicios_hospital(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::administrador_servicios_hospital)
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
        qDebug() << "ERROR conexion a la Base, esto es CATALOGO SERVICIOS ADMIN";
    }else{
        qDebug() << "Base de datos sigue conectada en CATALOGO SERVICIOS ADMIN";
    }


    QSqlQuery query(mDatabase);

    query.prepare("select * from info where id_tipo_info = 3");
    query.exec();
    limiparCatalogo();

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

         administrador_tarjeta_servicios *tarjeta = new administrador_tarjeta_servicios(id, nombre, foto);

         i++;
         ui->gridLayout->addWidget(tarjeta, row, col);
    }
}

administrador_servicios_hospital::~administrador_servicios_hospital()
{
    delete ui;
}

void administrador_servicios_hospital::limiparCatalogo()
{
    while (QLayoutItem *item = ui->gridLayout->takeAt(0))
    {
        Q_ASSERT(!item->layout()); // otherwise the layout will leak
        delete item->widget();
        delete item;
    }
}

void administrador_servicios_hospital::regargaCatalogo()
{
    QSqlQuery query(mDatabase);

    query.prepare("select * from info where id_tipo_info = 3");
    query.exec();
    limiparCatalogo();

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

         administrador_tarjeta_servicios *tarjeta = new administrador_tarjeta_servicios(id, nombre, foto);

         i++;
         ui->gridLayout->addWidget(tarjeta, row, col);
    }
}

void administrador_servicios_hospital::on_btn_crear_servicio_clicked()
{
    administrador_crear_servicio crearServicio;
    crearServicio.exec();
    regargaCatalogo();
}
