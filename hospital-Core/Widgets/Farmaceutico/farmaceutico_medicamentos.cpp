#include "farmaceutico_medicamentos.h"
#include "ui_farmaceutico_medicamentos.h"
#include "Widgets/Farmaceutico/farmaceutico_tarjeta_medicamento.h"
#include "Widgets/Farmaceutico/farmaceutico_agregar_medicamento.h"
#include <QDebug>

farmaceutico_medicamentos::farmaceutico_medicamentos(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::farmaceutico_medicamentos)
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
        if(!mDatabase.isOpen()){
            qDebug() << "ERROR";
        }else{
            qDebug() << "base de datos sigue conectada en MEDICAMENTOS FARMACEUTICO";
        }

    QSqlQuery query(mDatabase);

    query.prepare("select * from medicamentos_farmacia;");
    query.exec();

    int i=0;
    int row = 0;
    int col = 0;

    while (query.next()) {
        QString id = query.value(0).toString();
        QString nombre = query.value(1).toString();
        QString tipo = query.value(2).toString();
        QString descripcion = query.value(3).toString();
        QString costo = query.value(4).toString();
        QString cantidad = query.value(5).toString();
        QString premedicado = query.value(6).toString();

         row = i/4;
         col= i%4;

         farmaceutico_tarjeta_medicamento *tarjeta = new farmaceutico_tarjeta_medicamento(id, nombre, tipo, descripcion, costo, cantidad, premedicado, this);
         tarjeta->insertarDatos();

         i++;
         ui->gridLayout_medicamentos->addWidget(tarjeta, row, col);
    }
}

farmaceutico_medicamentos::~farmaceutico_medicamentos()
{
    delete ui;
}

void farmaceutico_medicamentos::limiparCatalogo()
{
    while (QLayoutItem *item = ui->gridLayout_medicamentos->takeAt(0))
    {
        Q_ASSERT(!item->layout());
        delete item->widget();
        delete item;
    }
}

void farmaceutico_medicamentos::insertarDatos()
{
    QSqlQuery query(mDatabase);

    query.prepare("select * from medicamentos_farmacia;");
    query.exec();

    int i=0;
    int row = 0;
    int col = 0;

    while (query.next()) {
        QString id = query.value(0).toString();
        QString nombre = query.value(1).toString();
        QString tipo = query.value(2).toString();
        QString descripcion = query.value(3).toString();
        QString costo = query.value(4).toString();
        QString cantidad = query.value(5).toString();
        QString premedicado = query.value(6).toString();

         row = i/4;
         col= i%4;

         farmaceutico_tarjeta_medicamento *tarjeta = new farmaceutico_tarjeta_medicamento(id, nombre, tipo, descripcion, costo, cantidad, premedicado, this);
         tarjeta->insertarDatos();

         i++;
         ui->gridLayout_medicamentos->addWidget(tarjeta, row, col);
    }
}

void farmaceutico_medicamentos::on_buscar_medicamento_LE_textChanged(const QString &arg1)
{
    limiparCatalogo();
    QSqlQuery query(mDatabase);
    QString sql = "select * from medicamentos_farmacia where nombre like '"+arg1+"%';";
    query.prepare(sql);
    query.exec();

    int i=0;
    int row = 0;
    int col = 0;

    while (query.next()) {
        QString id = query.value(0).toString();
        QString nombre = query.value(1).toString();
        QString tipo = query.value(2).toString();
        QString descripcion = query.value(3).toString();
        QString costo = query.value(4).toString();
        QString cantidad = query.value(5).toString();
        QString premedicado = query.value(6).toString();

         row = i/4;
         col= i%4;

         farmaceutico_tarjeta_medicamento *tarjeta = new farmaceutico_tarjeta_medicamento(id, nombre, tipo, descripcion, costo, cantidad, premedicado, this);
         tarjeta->insertarDatos();

         i++;
         ui->gridLayout_medicamentos->addWidget(tarjeta, row, col);
    }
}

void farmaceutico_medicamentos::on_btn_agregar_medicamento_clicked()
{
    farmaceutico_agregar_medicamento dialogo("1");
    dialogo.exec();
    this->limiparCatalogo();
    QSqlQuery query(mDatabase);

    query.prepare("select * from medicamentos_farmacia;");
    query.exec();

    int i=0;
    int row = 0;
    int col = 0;

    while (query.next()) {
        QString id = query.value(0).toString();
        QString nombre = query.value(1).toString();
        QString tipo = query.value(2).toString();
        QString descripcion = query.value(3).toString();
        QString costo = query.value(4).toString();
        QString cantidad = query.value(5).toString();
        QString premedicado = query.value(6).toString();

         row = i/4;
         col= i%4;

         farmaceutico_tarjeta_medicamento *tarjeta = new farmaceutico_tarjeta_medicamento(id, nombre, tipo, descripcion, costo, cantidad, premedicado, this);
         tarjeta->insertarDatos();

         i++;
         ui->gridLayout_medicamentos->addWidget(tarjeta, row, col);
    }
}
