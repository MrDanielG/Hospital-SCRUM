#include "administrador_justificacion_staff.h"
#include "ui_administrador_justificacion_staff.h"
#include "Widgets/Administrador/administrador_tarjeta_justificacion_staf.h"
#include <QDebug>

administrador_justificacion_staff::administrador_justificacion_staff(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::administrador_justificacion_staff)
{
    ui->setupUi(this);
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

    limpiarCatalogo();
    QSqlQuery query(mDatabase);
    QString sql = "select "
                  "P.id_permiso, "
                  "P.descripcion, "
                  "P.fecha_inicio, "
                  "P.fecha_fin, "
                  "pe.nombre, "
                  "pe.paterno, "
                  "pe.materno, "
                  "pe.foto, "
                  "tu.nombre_tipo "
                  "from permiso as P "
                  "inner join empleado on "
                  "empleado.id_empleado = P.id_empleado "
                  "inner join persona  as pe on "
                  "empleado.id_persona = pe.id_persona "
                  "inner join usuario on "
                  "pe.id_usuario = usuario.id_usuario "
                  "inner join tipo_usuario as tu on "
                  "usuario.id_tipo_usuario = tu.id_tipo_usuario "
                  "where P.aprobado = 1;";
    query.prepare(sql);
    query.exec();
    limpiarCatalogo();
    int i=0;
    int row = 0;
    int col = 0;

    while (query.next()) {
        QString id = query.value(0).toString();
        QString descripcion = query.value(1).toString();
        QString f_inicio = query.value(2).toString();
        QString f_fin = query.value(3).toString();
        QString nombre = query.value(4).toString()+" "+query.value(5).toString()+" "+query.value(6).toString();
        QString foto = query.value(7).toString();
        QString tipo = query.value(8).toString();

         row = i/3;
         col= i%3;

         administrador_tarjeta_justificacion_staf *tarjeta = new administrador_tarjeta_justificacion_staf(id, descripcion, f_inicio, f_fin, nombre, foto, tipo, this);
         tarjeta->insertarDatos();

         i++;
         ui->gridLayout_justificaciones->addWidget(tarjeta, row, col);
  }
}

administrador_justificacion_staff::~administrador_justificacion_staff()
{
    delete ui;
}

void administrador_justificacion_staff::limpiarCatalogo()
{
    while (QLayoutItem *item = ui->gridLayout_justificaciones->takeAt(0))
    {
        Q_ASSERT(!item->layout());
        delete item->widget();
        delete item;
    }

}

void administrador_justificacion_staff::actualizarCatalogo()
{
    limpiarCatalogo();
    QSqlQuery query(mDatabase);
    QString sql = "select "
                  "P.id_permiso, "
                  "P.descripcion, "
                  "P.fecha_inicio, "
                  "P.fecha_fin, "
                  "pe.nombre, "
                  "pe.paterno, "
                  "pe.materno, "
                  "pe.foto, "
                  "tu.nombre_tipo "
                  "from permiso as P "
                  "inner join empleado on "
                  "empleado.id_empleado = P.id_empleado "
                  "inner join persona  as pe on "
                  "empleado.id_persona = pe.id_persona "
                  "inner join usuario on "
                  "pe.id_usuario = usuario.id_usuario "
                  "inner join tipo_usuario as tu on "
                  "usuario.id_tipo_usuario = tu.id_tipo_usuario "
                  "where P.aprobado = 1;";
    query.prepare(sql);
    query.exec();

    int i=0;
    int row = 0;
    int col = 0;

    while (query.next()) {
        QString id = query.value(0).toString();
        QString descripcion = query.value(1).toString();
        QString f_inicio = query.value(2).toString();
        QString f_fin = query.value(3).toString();
        QString nombre = query.value(4).toString()+" "+query.value(5).toString()+" "+query.value(6).toString();
        QString foto = query.value(7).toString();
        QString tipo = query.value(8).toString();

         row = i/3;
         col= i%3;

         administrador_tarjeta_justificacion_staf *tarjeta = new administrador_tarjeta_justificacion_staf(id, descripcion, f_inicio, f_fin, nombre, foto, tipo, this);
         tarjeta->insertarDatos();

         i++;
         ui->gridLayout_justificaciones->addWidget(tarjeta, row, col);
  }
}
