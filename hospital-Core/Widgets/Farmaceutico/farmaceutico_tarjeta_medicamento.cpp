#include "farmaceutico_tarjeta_medicamento.h"
#include "ui_farmaceutico_tarjeta_medicamento.h"
#include "Widgets/Farmaceutico/farmaceutico_gestionar_medicamento.h"

farmaceutico_tarjeta_medicamento::farmaceutico_tarjeta_medicamento(QString id, QString nombre, QString tipo, QString descripcion, QString costo, QString cantidad, QString premedicado, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::farmaceutico_tarjeta_medicamento)
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
          qDebug()<<"Error";
           return;
    }else{
            qDebug()<<"abierta";
    }

    this->id = id;
    this->nombre = nombre;
    this->tipo = tipo;
    this->descripcion = descripcion;
    this->costo = costo;
    this->cantidad = cantidad;
    this->premedicado = premedicado;
}

farmaceutico_tarjeta_medicamento::~farmaceutico_tarjeta_medicamento()
{
    delete ui;
}

void farmaceutico_tarjeta_medicamento::insertarDatos()
{
    QString premmedicado;
    if (premedicado == "1"){
        premmedicado = "Si";
    }
    else if (premedicado == "0") {
        premmedicado = "No";
    }

    ui->nombre_medicamento->setText(nombre);
    ui->precio_medicamento->setText(costo);
    ui->tipo_medicamento->setText(tipo);
    ui->predicado_medicamento->setText(premmedicado);
}

void farmaceutico_tarjeta_medicamento::on_btn_agregar_medicamento_clicked()
{
    farmaceutico_gestionar_medicamento dialogo(id, nombre, tipo, descripcion, costo, cantidad, premedicado);
    dialogo.insertarDatos();
    dialogo.exec();
}
