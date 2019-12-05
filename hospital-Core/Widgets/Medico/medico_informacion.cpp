#include "medico_informacion.h"
#include "ui_medico_informacion.h"


medico_informacion::medico_informacion(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::medico_informacion)
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
        qDebug() << "base de datos sigue conectada en INICIAR SESION";
    }

    if(!mDatabase.isOpen()){
        qDebug() << "ERROR";
    }else{
        qDebug() << "base de datos sigue conectada en INICIAR SESION";
    }



}

medico_informacion::~medico_informacion()
{
    delete ui;
}

void medico_informacion::extraerDatos(){
    QSqlQuery query(mDatabase);

    query.prepare("SELECT persona.id_persona, persona.nombre, persona.paterno, "
                  "persona.materno, persona.fNacimiento, persona.correo, persona.foto, usuario.id_usuario "
                  "FROM persona INNER JOIN usuario "
                  "ON persona.id_usuario = usuario.id_usuario "
                  "where usuario.id_usuario= '"+idinfo+"'");
    query.exec();

    while(query.next()){
         idpersona = query.value(0).toString();
         QString nombre = query.value(1).toString();
         QString paterno = query.value(2).toString();
         QString materno = query.value(3).toString();
         QString edad = query.value(4).toString();
         QString correo = query.value(5).toString();
         QString foto = query.value(6).toString();
         insertarDatos(nombre, paterno, materno, edad, correo, foto);
    }

    QSqlQuery medico(mDatabase);

    medico.prepare("SELECT medico.experiencia, medico.logros, medico.estudios, usuario.id_usuario "
                   "FROM usuario INNER JOIN persona "
                   "ON usuario.id_usuario = persona.id_usuario "
                   "INNER JOIN empleado "
                   "ON persona.id_persona = empleado.id_persona "
                   "INNER JOIN medico "
                   "ON empleado.id_empleado = medico.id_empleado "
                   "where usuario.id_usuario = '"+idinfo+"'");
    medico.exec();

    while (medico.next()){
        QString exp = medico.value(0).toString();
        QString log = medico.value(1).toString();
        QString estudios = medico.value(2).toString();
        insertarDatosMedico(exp, log, estudios);
    }
}
void medico_informacion::insertarDatos(QString nombrei, QString paternoi, QString maternoi, QString edadi, QString correoi, QString fotoi){
    //C:/Users/Angel/Documents/Escuela/5toSemestre/SoftwareEngineer2/Hospital-SCRUM/hospital-Core/Imagenes/doctor
    QPixmap img(fotoi);
    ui->foto_medico->setPixmap(img.scaled(181,181, Qt::IgnoreAspectRatio));
    ui->text_datos_personales->setPlainText("Nombre: "+nombrei+" "+paternoi+" "+maternoi);
    ui->text_datos_personales->appendPlainText("Fecha de Nacimiento: "+edadi);
    ui->text_datos_personales->appendPlainText("Correo: "+correoi);
}

void medico_informacion::insertarDatosMedico(QString experiencia, QString logros, QString estudios){
    ui->text_experiencia->setPlainText(experiencia);
    ui->text_logros->setPlainText(logros);
    ui->text_estudios->setPlainText(estudios);
}

void medico_informacion::setID(QString id)
{
    this->idinfo = id;
    extraerDatos();
}


void medico_informacion::on_btn_modificar_medico_clicked()
{
    medico_modificar ventanamodificar(this->idinfo);
    ventanamodificar.exec();
}

void medico_informacion::on_pushButton_clicked()
{
    extraerDatos();
}
