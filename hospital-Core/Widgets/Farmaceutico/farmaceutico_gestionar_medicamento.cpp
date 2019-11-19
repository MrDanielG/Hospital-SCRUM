#include "farmaceutico_gestionar_medicamento.h"
#include "ui_farmaceutico_gestionar_medicamento.h"
#include "Widgets/Farmaceutico/farmaceutico_modificar_medicamentos.h"
#include <QMessageBox>

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
    farmaceutico_modificar_medicamentos dialogo(id, nombre, tipo, descripcion, costo, cantidad, premedicado);
    dialogo.insertarDatos();
    dialogo.exec();
    this->close();
}

void farmaceutico_gestionar_medicamento::on_btn_eliminar_medicamento_clicked()
{
    QMessageBox messageBox(QMessageBox::Question,tr("Critical Error"), tr("Estás seguro de eliminar éste medicamento?"), QMessageBox::Yes | QMessageBox::No);

    messageBox.setButtonText(QMessageBox::Yes, tr("Sí"));
    messageBox.setButtonText(QMessageBox::No, tr("No"));

    if (messageBox.exec() == QMessageBox::Yes){
        QSqlQuery query(mDatabase);
        QString sql = "delete from medicamentos_farmacia where id_medicamentos_farmacia = "+id+";";
        query.prepare(sql);
        query.exec();
    }

    this->close();
}
