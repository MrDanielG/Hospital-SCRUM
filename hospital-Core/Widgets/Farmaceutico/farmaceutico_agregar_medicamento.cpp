#include "farmaceutico_agregar_medicamento.h"
#include "ui_farmaceutico_agregar_medicamento.h"
#include <QMessageBox>

farmaceutico_agregar_medicamento::farmaceutico_agregar_medicamento()
{

}

farmaceutico_agregar_medicamento::farmaceutico_agregar_medicamento(QString farmacia, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::farmaceutico_agregar_medicamento)
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
            qDebug() << "base de datos sigue conectada en Farmaceutico_agregar_medicamento";
        }

     this->farmacia = farmacia;
     ui->cantidad_spinBox->setRange(1, 1000000);
}

farmaceutico_agregar_medicamento::~farmaceutico_agregar_medicamento()
{
    delete ui;
}

void farmaceutico_agregar_medicamento::on_btn_cancelar_clicked()
{
    ui->nombre_lineEdit->setText("");
    ui->tipo_lineEdit->setText("");
    ui->costo_lineEdit->setText("");
    ui->cantidad_spinBox->setValue(0);
    ui->si_checkBox->setChecked(false);
    ui->no_checkBox->setChecked(false);
    ui->descripcion_plainTextEdit->setPlainText("");
    this->close();
}

void farmaceutico_agregar_medicamento::on_si_checkBox_stateChanged(int arg1)
{
    if(arg1 == 2){
        ui->no_checkBox->setChecked(false);
    }
}

void farmaceutico_agregar_medicamento::on_no_checkBox_stateChanged(int arg1)
{
    if(arg1 == 2){
        ui->si_checkBox->setChecked(false);
    }
}

void farmaceutico_agregar_medicamento::on_btn_agregar_medicamento_clicked()
{
    QString nombre = ui->nombre_lineEdit->text();
    QString tipo = ui->tipo_lineEdit->text();
    QString costo = ui->costo_lineEdit->text();
    QString cantidad = QString::number(ui->cantidad_spinBox->value());
    QString descripcion = ui->descripcion_plainTextEdit->toPlainText();
    QString premedicado;

    if(ui->si_checkBox->isChecked()){
        premedicado = "1";
    }
    else if (ui->no_checkBox->isChecked()) {
        premedicado = "0";
    }
    else {
        premedicado = "";
    }

    if(nombre == "" || tipo == "" || costo == "" || cantidad == "0" || descripcion == "" || premedicado == ""){
        QMessageBox::warning(this,"Datos incompletos", "Por favor llena todos los campos");
    }else {
        QSqlQuery query(mDatabase);
        QString sql = "insert into medicamentos_farmacia(nombre, tipo, descripcion, costo, cantidad, premedicado, id_farmacia) values('"+nombre+"', '"+tipo+"', '"+descripcion+"', "+costo+", "+cantidad+", "+premedicado+", "+farmacia+");";
        query.prepare(sql);
        query.exec();
    }

    this->close();
    ui->nombre_lineEdit->setText("");
    ui->tipo_lineEdit->setText("");
    ui->costo_lineEdit->setText("");
    ui->cantidad_spinBox->setValue(0);
    ui->si_checkBox->setChecked(false);
    ui->no_checkBox->setChecked(false);
    ui->descripcion_plainTextEdit->setPlainText("");

}
