#include "medico_generar_receta.h"
#include "ui_medico_generar_receta.h"
#include "Widgets/Medico/medico_tarjeta_cita.h"
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
    qDebug()<<"Catalogo Receta, IDMEdico: "<<this->idMedico<<"IDUSUArIO"<<this->idUsuario;
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

         row = i/1;
         col= i%1;

         medico_tarjeta_cita *tarjeta = new medico_tarjeta_cita(nombre, motivo, foto, idCita, fecha);

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

void medico_generar_receta::on_btn_agregar_clicked()
{
    ui->lineEdit_modo_2->show();
    ui->lineEdit_tipo_2->show();
    ui->btn_agregar_2->show();
}
