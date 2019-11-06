#include "administador_gestionar_usuarios.h"
#include "ui_administador_gestionar_usuarios.h"
#include "Widgets/Administrador/administrador_tarjeta_gestion.h"
#include "Widgets/Administrador/administrador_crear_usuario.h"
#include "QMessageBox"
#include "QDebug"
#include "QSqlQuery"
administador_gestionar_usuarios::administador_gestionar_usuarios(QWidget *parent) : QWidget(parent),
                                                                                    ui(new Ui::administador_gestionar_usuarios)
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
        qDebug() << "ERROR con Base de Datos, esto es: GESTIONAR USUARIOS";
        return;
    }
    else
    {
        qDebug() << "Base de datos continua abierta, esto es: GESTIONAR USUARIOS";
    }

    QSqlQuery infoPersona(mDatabase);
    infoPersona.prepare("SELECT * from persona INNER JOIN usuario ON persona.id_usuario = usuario.id_usuario");
    infoPersona.exec();
    limiparCatalogo();

    int i = 0;
    int row = 0;
    int col = 0;

    while (infoPersona.next())
    {
        QString id_persona = infoPersona.value(0).toString();
        QString nombre_persona = infoPersona.value(1).toString() + " " + infoPersona.value(2).toString() + " " + infoPersona.value(3).toString();
        QString img_persona = infoPersona.value(7).toString();
        QString id_usuario = infoPersona.value(9).toString();

        row = i / 3;
        col = i % 3;

        administrador_tarjeta_gestion *tarjeta = new administrador_tarjeta_gestion(id_usuario, nombre_persona, img_persona, this);
        i++;
        ui->gridLayout->addWidget(tarjeta, row, col);
    }
}

administador_gestionar_usuarios::~administador_gestionar_usuarios()
{
    delete ui;
}

void administador_gestionar_usuarios::limiparCatalogo()
{
    while (QLayoutItem *item = ui->gridLayout->takeAt(0))
    {
        Q_ASSERT(!item->layout()); // otherwise the layout will leak
        delete item->widget();
        delete item;
    }
}

void administador_gestionar_usuarios::on_btn_medicos_clicked()
{
    QSqlQuery infoMedico(mDatabase);
    infoMedico.prepare("SELECT * from persona INNER JOIN usuario ON persona.id_usuario = usuario.id_usuario WHERE usuario.id_tipo_usuario = 1");
    infoMedico.exec();
    limiparCatalogo();

    int i = 0;
    int row = 0;
    int col = 0;

    while (infoMedico.next())
    {
        QString id_persona = infoMedico.value(0).toString();
        QString nombre_persona = infoMedico.value(1).toString() + " " + infoMedico.value(2).toString() + " " + infoMedico.value(3).toString();
        QString img_persona = infoMedico.value(7).toString();
        QString id_usuario = infoMedico.value(9).toString();

        row = i / 3;
        col = i % 3;

        administrador_tarjeta_gestion *tarjeta = new administrador_tarjeta_gestion(id_usuario, nombre_persona, img_persona);
        i++;
        ui->gridLayout->addWidget(tarjeta, row, col);
    }
}

void administador_gestionar_usuarios::on_btn_pacientes_clicked()
{
    QSqlQuery infoPaciente(mDatabase);
    infoPaciente.prepare("SELECT * from persona INNER JOIN usuario ON persona.id_usuario = usuario.id_usuario WHERE usuario.id_tipo_usuario = 2");
    infoPaciente.exec();
    limiparCatalogo();

    int i = 0;
    int row = 0;
    int col = 0;

    while (infoPaciente.next())
    {
        QString id_persona = infoPaciente.value(0).toString();
        QString nombre_persona = infoPaciente.value(1).toString() + " " + infoPaciente.value(2).toString() + " " + infoPaciente.value(3).toString();
        QString img_persona = infoPaciente.value(7).toString();
        QString id_usuario = infoPaciente.value(9).toString();

        row = i / 3;
        col = i % 3;

        administrador_tarjeta_gestion *tarjeta = new administrador_tarjeta_gestion(id_usuario, nombre_persona, img_persona);
        i++;
        ui->gridLayout->addWidget(tarjeta, row, col);
    }
}

void administador_gestionar_usuarios::on_btn_staff_clicked()
{
    QSqlQuery infoStaff(mDatabase);
    infoStaff.prepare("SELECT * from persona INNER JOIN usuario ON persona.id_usuario = usuario.id_usuario WHERE usuario.id_tipo_usuario = 4");
    infoStaff.exec();
    limiparCatalogo();

    int i = 0;
    int row = 0;
    int col = 0;

    while (infoStaff.next())
    {
        QString id_persona = infoStaff.value(0).toString();
        QString nombre_persona = infoStaff.value(1).toString() + " " + infoStaff.value(2).toString() + " " + infoStaff.value(3).toString();
        QString img_persona = infoStaff.value(7).toString();
        QString id_usuario = infoStaff.value(9).toString();

        row = i / 3;
        col = i % 3;

        administrador_tarjeta_gestion *tarjeta = new administrador_tarjeta_gestion(id_usuario, nombre_persona, img_persona);
        i++;
        ui->gridLayout->addWidget(tarjeta, row, col);
    }
}

void administador_gestionar_usuarios::on_buscar_textChanged(const QString &arg1)
{
    char caracter = '%';
    QSqlQuery infoPersona(mDatabase);
    infoPersona.prepare("SELECT * from persona INNER JOIN usuario ON persona.id_usuario = usuario.id_usuario WHERE persona.nombre like '" + arg1 + caracter + "'");
    infoPersona.exec();
    limiparCatalogo();

    int i = 0;
    int row = 0;
    int col = 0;

    while (infoPersona.next())
    {
        QString id_persona = infoPersona.value(0).toString();
        QString nombre_persona = infoPersona.value(1).toString() + " " + infoPersona.value(2).toString() + " " + infoPersona.value(3).toString();
        QString img_persona = infoPersona.value(7).toString();
        QString id_usuario = infoPersona.value(9).toString();

        row = i / 3;
        col = i % 3;

        administrador_tarjeta_gestion *tarjeta = new administrador_tarjeta_gestion(id_usuario, nombre_persona, img_persona);
        i++;
        ui->gridLayout->addWidget(tarjeta, row, col);
    }
}

void administador_gestionar_usuarios::on_btn_registra_usuario_clicked()
{
    administrador_crear_usuario crearUsuario;
    crearUsuario.exec();
    limiparCatalogo();
}
