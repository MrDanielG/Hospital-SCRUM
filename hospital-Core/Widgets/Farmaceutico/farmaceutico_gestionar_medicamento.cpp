#include "farmaceutico_gestionar_medicamento.h"
#include "ui_farmaceutico_gestionar_medicamento.h"

farmaceutico_gestionar_medicamento::farmaceutico_gestionar_medicamento(QString id, QString nombre, QString tipo, QString descripcion, QString costo, QString cantidad, QString premedicado, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::farmaceutico_gestionar_medicamento)
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
            qDebug() << "Conectada";
        }

    this->id = id;
    this->nombre = nombre;
    this->tipo = tipo;
    this->descripcion = descripcion;
    this->costo = costo;
    this->cantidad = cantidad;
    this->premedicado = premedicado;

}

farmaceutico_gestionar_medicamento::~farmaceutico_gestionar_medicamento()
{
    delete ui;
}

void farmaceutico_gestionar_medicamento::insertarDatos()
{
    ui->nombre_medicamento->setText(nombre);
    ui->descripcion_medicamento->setText(descripcion);
}

void farmaceutico_gestionar_medicamento::on_btn_modificar_medicamento_clicked()
{
    this->close();
}
