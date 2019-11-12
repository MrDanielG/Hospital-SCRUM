#include "medico_generar_receta.h"
#include "ui_medico_generar_receta.h"
#include "Widgets/Medico/medico_tarjeta_cita.h"
#include "Clases/pdf_receta.h"
#include "QDebug"
medico_generar_receta::medico_generar_receta(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::medico_generar_receta)
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
        qDebug() << "ERROR en GENERAR RECETA";
    }else{
        qDebug() << "Base de datos sigue conectada en GENERAR RECETA";
    }

    ui->lineEdit_modo_2->hide();
    ui->lineEdit_modo_3->hide();
    ui->lineEdit_tipo_2->hide();
    ui->lineEdit_tipo_3->hide();
    ui->btn_agregar_2->hide();
    ui->btn_agregar_3->hide();
}

medico_generar_receta::~medico_generar_receta()
{
    delete ui;
}

void medico_generar_receta::inicializarCatalogo()
{
    QSqlQuery query(mDatabase);
    query.prepare("SELECT id_cita_medica, fecha, motivo, nombre, paterno, materno, foto FROM cita_medica "
                  "INNER JOIN paciente ON cita_medica.id_paciente = paciente.id_paciente "
                  "INNER JOIN persona ON paciente.id_persona = persona.id_persona "
                  "WHERE id_medico = '"+this->idMedico+"'");
    query.exec();

    int i=0;
    int row = 0;
    int col = 0;

    while (query.next()) {
        QString nombre = query.value("nombre").toString() + " " +query.value("paterno").toString();
        QString fecha = query.value("fecha").toString();
        QString motivo = query.value("motivo").toString();
        QString foto = query.value("foto").toString();
        QString idCita = query.value("id_cita_medica").toString();
        this->idCita = query.value("id_cita_medica").toString();
         row = i/1;
         col= i%1;

         medico_tarjeta_cita *tarjeta = new medico_tarjeta_cita(nombre, motivo, foto, idCita, fecha, this);

         i++;
         ui->gridLayout_horario->addWidget(tarjeta, row, col);
    }
}

void medico_generar_receta::setUsuario(QString _idUsuario)
{
    this->idUsuario = _idUsuario;
    QSqlQuery query(mDatabase); //Se busca ID Medico conforme al usuario
    query.exec("SELECT id_medico FROM medico INNER JOIN empleado ON medico.id_empleado = empleado.id_empleado INNER JOIN persona ON empleado.id_persona = persona.id_persona WHERE persona.id_usuario = '"+this->idUsuario+"'");
    query.next();
    this->idMedico = query.value(0).toString();
}

void medico_generar_receta::setReceta(QString _idCita)
{
    QSqlQuery query(mDatabase);
    query.exec("SELECT descripcion FROM cita_medica WHERE id_cita_medica = '"+_idCita+"'");
    query.next();
    QString descripcion = query.value("descripcion").toString();
    ui->descripcion->setPlainText(descripcion);
}


void medico_generar_receta::on_btn_agregar_clicked()
{
    ui->lineEdit_modo_2->show();
    ui->lineEdit_tipo_2->show();
    ui->btn_agregar_2->show();
}

void medico_generar_receta::on_btn_generar_receta_clicked()
{
    this->medicamentos =
            "<b>Nombre Medicamento: </b> "+ui->lineEdit_tipo->text()+"<br>"
            "<b>Modo de Empleo: </b> "+ui->lineEdit_modo->text()+"<br><br>"

            "<b>Nombre Medicamento: </b> "+ui->lineEdit_tipo_2->text()+"<br>"
            "<b>Modo de Empleo: </b> "+ui->lineEdit_modo_2->text()+"<br><br>"

            "<b>Nombre Medicamento: </b> "+ui->lineEdit_tipo_3->text()+"<br>"
            "<b>Modo de Empleo: </b> "+ui->lineEdit_modo_3->text()+"<br><br>";

    QSqlQuery query(mDatabase);
    query.prepare("SELECT id_cita_medica, fecha, motivo, descripcion, nombre, paterno, materno, foto FROM cita_medica "
                  "INNER JOIN paciente ON cita_medica.id_paciente = paciente.id_paciente "
                  "INNER JOIN persona ON paciente.id_persona = persona.id_persona "
                  "WHERE id_cita_medica = '"+this->idCita+"'");
    query.exec();

    query.next();
        QString nombre = query.value("nombre").toString() + " " +query.value("paterno").toString() + " " +query.value("materno").toString();
        QString fecha = query.value("fecha").toString();
        QString concepto = query.value("motivo").toString();
        QString descripcion = query.value("descripcion").toString();
        QString foto = query.value("foto").toString();
        QString idCita = query.value("id_cita_medica").toString();

    pdf_receta receta(nombre, fecha, concepto, descripcion, idCita, this->medicamentos);
}

void medico_generar_receta::on_btn_agregar_2_clicked()
{
    ui->lineEdit_modo_3->show();
    ui->lineEdit_tipo_3->show();
    ui->btn_agregar_3->show();
}
