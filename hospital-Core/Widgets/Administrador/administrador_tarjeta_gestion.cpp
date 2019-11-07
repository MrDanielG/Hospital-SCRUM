#include "administrador_tarjeta_gestion.h"
#include "ui_administrador_tarjeta_gestion.h"
#include "Widgets/Administrador/administador_gestionar_usuarios.h"
#include "Widgets/Administrador/administrador_info_gestion.h"
#include "QDebug"
administrador_tarjeta_gestion::administrador_tarjeta_gestion(QString id, QString nombre, QString img, QWidget *parent) : QWidget(parent),
                                                                                                                         ui(new Ui::administrador_tarjeta_gestion)
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
    if (!mDatabase.isOpen())
    {
        qDebug() << "ERROR con Base de Datos, esto es: TARJETA GESTION";
        return;
    }
    else
    {
        qDebug() << "Base de datos continua abierta, esto es: TARJETA GESTION";
    }

    this->id = id;
    this->nombre = nombre;
    this->img = img;

    QPixmap imagen(img);
    ui->img_persona->setPixmap(imagen);
    ui->lbl_nombre->setText(this->nombre);
}

administrador_tarjeta_gestion::~administrador_tarjeta_gestion()
{
    delete ui;
}

void administrador_tarjeta_gestion::limpiar()
{
    administador_gestionar_usuarios* padre = qobject_cast<administador_gestionar_usuarios*>(this->parentWidget());
    padre->limiparCatalogo();
}

void administrador_tarjeta_gestion::on_btn_gestionar_clicked()
{
    QSqlQuery query(mDatabase);
    QString nombreUsuario = this->id;
    query.prepare("SELECT * from persona INNER JOIN usuario ON persona.id_usuario = usuario.id_usuario WHERE usuario.id_usuario = '" + nombreUsuario + "'");
    query.exec();

    query.next();
    QString nombre = query.value(1).toString() + " " + query.value(2).toString() + " " + query.value(3).toString();
    QString img = query.value(7).toString();
    int indexUsr = query.value(13).toInt();
    QString tipo_usr = "xd";
    QString info1 = "CURP: " + query.value(10).toString();
    QString info2 = query.value(5).toString();
    QString info3 = query.value(8).toString();
    QString id_usuario = query.value(9).toString();
    switch (indexUsr)
    {
    case 1:
        tipo_usr = "Medico";
        break;

    case 2:
        tipo_usr = "Paceinte";
        break;

    case 4:
        tipo_usr = "Staff";
        break;

    default:
        tipo_usr = "No jalo esto compa";
        break;
    }

    administrador_info_gestion infoGestion(nombre, tipo_usr, info1, info2, info3, img, id_usuario);
    infoGestion.exec();
}
