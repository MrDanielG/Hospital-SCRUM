#include "farmaceutico_modificar_medicamentos.h"
#include "ui_farmaceutico_modificar_medicamentos.h"
#include <QMessageBox>



farmaceutico_modificar_medicamentos::farmaceutico_modificar_medicamentos(QString id, QString nombre, QString tipo, QString descripcion, QString costo, QString cantidad, QString premedicado, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::farmaceutico_modificar_medicamentos)
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

farmaceutico_modificar_medicamentos::~farmaceutico_modificar_medicamentos()
{
    delete ui;
}
void farmaceutico_modificar_medicamentos::insertarDatos()
{
    QString premmedicado;
    if (premedicado == "1"){
        premmedicado = "Si";
    }
    else if (premedicado == "0") {
        premmedicado = "No";
    }

    ui->nombre_label->setText(nombre);
    ui->tipo_lineEdit->setText(tipo);
    ui->descripcion_textEdit->setText(descripcion);
    ui->costo_lineEdit->setText(costo);
    ui->premedicado_lineEdit->setText(premmedicado);
}

void farmaceutico_modificar_medicamentos::on_btn_modificar_medicamento_clicked()
{
    QString nPremedicado;
    QString preMedic = ui->premedicado_lineEdit->text();
    if(preMedic == "Si" || preMedic == "si"){
        nPremedicado = "1";
    }
    else if (preMedic == "No" || preMedic == "no") {
        nPremedicado = "0";
    }

    QString nTipo = ui->tipo_lineEdit->text();
    QString nDescripcion = ui->descripcion_textEdit->toPlainText();
    QString nCosto = ui->costo_lineEdit->text();

    if(nTipo == "" || nDescripcion == "" || nCosto == "" || nPremedicado == ""){
         QMessageBox::warning(this,"Datos incompletos", "Por favor llena todos los campos");
    }
    else {
        QMessageBox messageBox(QMessageBox::Question,tr("Critical Error"), tr("Estás seguro de registrar éste internado"), QMessageBox::Yes | QMessageBox::No);

        messageBox.setButtonText(QMessageBox::Yes, tr("Sí"));
        messageBox.setButtonText(QMessageBox::No, tr("No"));

        if (messageBox.exec() == QMessageBox::Yes){
            QSqlQuery query(mDatabase);
            QString sql = "update medicamentos_farmacia set tipo = '"+nTipo+"', descripcion = '"+nDescripcion+"', costo = "+nCosto+", premedicado = "+nPremedicado+" where id_medicamentos_farmacia = "+id+";";
            query.prepare(sql);
            query.exec();
        }
    }

//    ui->tipo_lineEdit->setText("");
//    ui->descripcion_textEdit->setText("");
//    ui->costo_lineEdit->setText("");
//    ui->premedicado_lineEdit->setText("");
    this->close();
}

void farmaceutico_modificar_medicamentos::on_btn_cancelar_modificacion_clicked()
{
    this->close();
}
