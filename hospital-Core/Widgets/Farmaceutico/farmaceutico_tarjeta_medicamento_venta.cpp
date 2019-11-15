#include "farmaceutico_tarjeta_medicamento_venta.h"
#include "ui_farmaceutico_tarjeta_medicamento_venta.h"

farmaceutico_tarjeta_medicamento_venta::farmaceutico_tarjeta_medicamento_venta(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::farmaceutico_tarjeta_medicamento_venta)
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
            qDebug() << "base de datos sigue conectada en INICIAR SESION";
        }


}

farmaceutico_tarjeta_medicamento_venta::~farmaceutico_tarjeta_medicamento_venta()
{
    delete ui;
}

void farmaceutico_tarjeta_medicamento_venta::insertarDatos(QString nombre, QString precio, QString cantidad, QString premedicado, QString id)
{
    QString pre = "";
    if(premedicado == "1"){
        pre = "SI";
    }else{
        pre = "NO";
    }
    ui->nombre_medicamento->setText(nombre);
    ui->precio_medicamento->setText(precio);
    ui->cantidad_medicamento->setText(cantidad);
    ui->premedicado_medicamento->setText(pre);
    this->id=id;

}

QString farmaceutico_tarjeta_medicamento_venta::getID(){
    return this->id;
}

void farmaceutico_tarjeta_medicamento_venta::on_btn_agregaracola_clicked()
{
    getID();

}
