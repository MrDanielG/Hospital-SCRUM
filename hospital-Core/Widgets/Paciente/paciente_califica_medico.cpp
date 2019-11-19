#include "paciente_califica_medico.h"
#include "ui_paciente_califica_medico.h"
#include <QSqlQuery>
#include <QPixmap>
#include <QDebug>
#include <QMessageBox>

Paciente_Califica_Medico::Paciente_Califica_Medico(QString cita,QString Med,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Paciente_Califica_Medico)
{
    ui->setupUi(this);
    id_cita = cita;
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
        qDebug() << "ERROR con Base de Datos, esto es: CALIFICAR MEDICO";
        return;
    }else{
        qDebug() << "Base de datos continua abierta, esto es: CALIFICAR MEDICO";
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

    ruta=":/imagenes/Imagenes/starn.png";
    ruta1=":/imagenes/Imagenes/star.png";
}

Paciente_Califica_Medico::~Paciente_Califica_Medico()
{
    delete ui;
}

void Paciente_Califica_Medico::on_btn1Estrella_clicked()
{
    QIcon icon(ruta);
    QIcon icon1(ruta1);
    ui->btn1Estrella->setIcon(icon);
    ui->btn2Estrellas->setIcon(icon1);
    ui->btn3Estrellas->setIcon(icon1);
    ui->btn4Estrellas->setIcon(icon1);
    ui->btn5Estrellas->setIcon(icon1);
    NumEstrellas = "1";
}

void Paciente_Califica_Medico::on_btn2Estrellas_clicked()
{
    QIcon icon(ruta);
    QIcon icon1(ruta1);
    ui->btn1Estrella->setIcon(icon);
    ui->btn2Estrellas->setIcon(icon);
    ui->btn3Estrellas->setIcon(icon1);
    ui->btn4Estrellas->setIcon(icon1);
    ui->btn5Estrellas->setIcon(icon1);
    NumEstrellas = "2";
}

void Paciente_Califica_Medico::on_btn3Estrellas_clicked()
{
    QIcon icon(ruta);
    QIcon icon1(ruta1);
    ui->btn1Estrella->setIcon(icon);
    ui->btn2Estrellas->setIcon(icon);
    ui->btn3Estrellas->setIcon(icon);
    ui->btn4Estrellas->setIcon(icon1);
    ui->btn5Estrellas->setIcon(icon1);
    NumEstrellas = "3";
}

void Paciente_Califica_Medico::on_btn4Estrellas_clicked()
{
    QIcon icon(ruta);
    QIcon icon1(ruta1);
    ui->btn1Estrella->setIcon(icon);
    ui->btn2Estrellas->setIcon(icon);
    ui->btn3Estrellas->setIcon(icon);
    ui->btn4Estrellas->setIcon(icon);
    ui->btn5Estrellas->setIcon(icon1);
    NumEstrellas = "4";
}

void Paciente_Califica_Medico::on_btn5Estrellas_clicked()
{
    QIcon icon(ruta);
    ui->btn1Estrella->setIcon(icon);
    ui->btn2Estrellas->setIcon(icon);
    ui->btn3Estrellas->setIcon(icon);
    ui->btn4Estrellas->setIcon(icon);
    ui->btn5Estrellas->setIcon(icon);
    NumEstrellas = "5";
}

void Paciente_Califica_Medico::on_btn_enviarCalif_clicked()
{
    if(NumEstrellas == "0")
    {
        QMessageBox::warning(this, tr("ERROR"), tr("Por favor, seleccione una calificación"),
                             QMessageBox::Ok);
    }else
    {
        QSqlQuery insertaCalif(mDatabase);
        insertaCalif.prepare("update cita_medica set calificacion = '"+NumEstrellas+"'"
                             " where id_cita_medica='"+id_cita+"';");
        insertaCalif.exec();

        if(insertaCalif.exec())
        {
            QSqlQuery CalculaPromedio(mDatabase);
            CalculaPromedio.prepare("select avg(calificacion) as promedio from "
                                    "cita_medica where id_medico='"+idMed+"' and calificacion != 0;");
            CalculaPromedio.exec();

            float prom;
            while(CalculaPromedio.next())
            {
                prom = qRound(CalculaPromedio.value(0).toFloat());
            }

            qDebug() << "Promedio calculado: "<<prom;

            QString valor = QString::number(prom);
            QSqlQuery CambiaProm(mDatabase);
            CambiaProm.prepare("update medico set calificacion_prom='"+valor+"' "
                               "where id_medico='"+idMed+"'");
            CambiaProm.exec();
            CambiaProm.finish();

            QMessageBox::information(this, tr("Calificación enviada"),tr("¡Gracias por su preferencia!"),
                                     QMessageBox::Ok);
        }
        this->close();
    }
}
