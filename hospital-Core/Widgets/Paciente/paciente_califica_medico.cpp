#include "paciente_califica_medico.h"
#include "ui_paciente_califica_medico.h"
#include <QSqlQuery>
#include <QPixmap>
#include <QDebug>

Paciente_Califica_Medico::Paciente_Califica_Medico(QString Med,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Paciente_Califica_Medico)
{
    ui->setupUi(this);
    idMed = Med;

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
        qDebug() << "ERROR con Base de Datos, esto es: TARJETA CITAS";
        return;
    }else{
        qDebug() << "Base de datos continua abierta, esto es: TARJETA CITAS";
    }

    //Para traer el nombre y especialidad del médico que le atendió en su cita
    QSqlQuery query(mDatabase);
    query.prepare("select concat(p.nombre,' ',p.paterno,' ',p.materno) as Nombre, "
                  "esp.nombre as Especialidad, p.foto as Foto from persona as p "
                  "inner join empleado as e on p.id_persona=e.id_persona "
                  "inner join medico as m on e.id_empleado=m.id_empleado "
                  "inner join medico_has_especialidad as me on m.id_medico=me.id_medico "
                  "inner join especialidad as esp on me.id_especialidad=esp.id_especialidad "
                  "where m.id_medico='"+idMed+"';");
    query.exec();

    QString nombre,especialidad,foto;
    while(query.next())
    {
        nombre = query.value(0).toString();
        especialidad = query.value(1).toString();
        foto = query.value(2).toString();
    }

    QPixmap pic(foto);
    ui->lbl_NombreDoctor->setText(nombre);
    ui->lbl_especialidad->setText(especialidad);
    ui->lbl_foto->setPixmap(pic);
}

Paciente_Califica_Medico::~Paciente_Califica_Medico()
{
    delete ui;
}
