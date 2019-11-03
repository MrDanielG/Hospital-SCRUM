#include "administrador_tarjeta_servicios.h"
#include "ui_administrador_tarjeta_servicios.h"
#include "Widgets/Administrador/administrador_info_servicios.h"
#include "QDebug"
administrador_tarjeta_servicios::administrador_tarjeta_servicios(QString id, QString servicio, QString foto, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::administrador_tarjeta_servicios)
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
          qDebug()<<"Error Base de Datos, esto es: ADMINISTRADOR TARJETA SERVICIOS";
           return;
    }else{
            qDebug()<<"Base de datos continua abierta, esto es: ADMINISTRADOR TARJETA SERVICIOS";
    }

    this->id = id;
    this->servicio = servicio;
    this->foto = foto;

    //Se agregan a la UI
    ui->lbl_servicio->setText(servicio);
    QPixmap img(foto);
    ui->img->setPixmap(img);
}

administrador_tarjeta_servicios::~administrador_tarjeta_servicios()
{
    delete ui;
}

void administrador_tarjeta_servicios::on_btn_gestionar_clicked()
{
    QSqlQuery query(mDatabase);
    query.prepare("select * from info where id_tipo_info = 3 and info.id_info = "+this->id+"");
    query.exec();

    while (query.next()) {
        //aqui se ponen los valores de la query
        this->id = query.value(0).toString();
        this->foto = query.value(5).toString();
        this->servicio = query.value(1).toString();
        this->info = query.value(2).toString();

    }
    administrador_info_servicios infoServicio(this->id, this->servicio, this->info, this->foto);
    infoServicio.exec();
}
