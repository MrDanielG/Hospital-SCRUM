#include "recepcionista_tarjeta_pacientes_internados.h"
#include "ui_recepcionista_tarjeta_pacientes_internados.h"
#include <QClipboard>

recepcionista_tarjeta_pacientes_internados::recepcionista_tarjeta_pacientes_internados(QString id, QString nombre, QString paterno, QString materno, QString foto, QString curp, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::recepcionista_tarjeta_pacientes_internados)
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
        qDebug() << "ERROR";
    }else{
        qDebug() << "base de datos sigue conectada en INICIAR SESION";
    }

    this->id = id;
    this->nombre = nombre;
    this->paterno = paterno;
    this->materno = materno;
    this->foto = foto;
    this->curp = curp;
}

recepcionista_tarjeta_pacientes_internados::~recepcionista_tarjeta_pacientes_internados()
{
    delete ui;
}

void recepcionista_tarjeta_pacientes_internados::insertarDatos()
{
    QPixmap imag(this->foto);
    ui->fotografia->setPixmap(imag);
    ui->nombre_paciente->setText(nombre);
    ui->curp_paciente->setText(curp);
}

void recepcionista_tarjeta_pacientes_internados::on_btn_visualizar_clicked()
{
    QClipboard *clipboard = QApplication::clipboard( );
    clipboard->setText(id);
}
