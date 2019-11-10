#include "medico_modificar.h"
#include "ui_medico_modificar.h"

medico_modificar::medico_modificar(QString id, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::medico_modificar)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);

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
          qDebug()<<"Error Base de Datos";
           return;
    }else{
            qDebug()<<"Base de datos continua abierta, esto es:  Medico Modificar";
    }
    //Query para mostrar los datos en los lineedit
    QSqlQuery MostrarDatos(mDatabase);

    MostrarDatos.prepare("select medico.experiencia, "
                         "medico.logros, medico.estudios, "
                         "medico.cedula, persona.nombre, "
                         "persona.paterno, persona.materno, persona.correo, persona.foto, "
                         "persona.direccion, usuario.contrasenia, "
                         "usuario.mascota from usuario "
                         "INNER JOIN persona "
                         "ON usuario.id_usuario = persona.id_usuario "
                         "INNER JOIN empleado "
                         "ON persona.id_persona = empleado.id_persona "
                         "INNER JOIN medico "
                         "ON empleado.id_empleado = medico.id_empleado "
                         "where usuario.id_usuario = 'carlos'");
    MostrarDatos.exec();

    while (MostrarDatos.next()){
        QString experiencia = MostrarDatos.value(0).toString();
        QString logros = MostrarDatos.value(1).toString();
        QString estudios = MostrarDatos.value(2).toString();
        QString cedula = MostrarDatos.value(3).toString();
        QString nombre = MostrarDatos.value(4).toString();
        QString paterno = MostrarDatos.value(5).toString();
        QString materno = MostrarDatos.value(6).toString();
        QString correo = MostrarDatos.value(7).toString();
        QString foto = MostrarDatos.value(8).toString();
        QString direccion = MostrarDatos.value(9).toString();
        QString contrasenia = MostrarDatos.value(10).toString();
        QString mascota = MostrarDatos.value(11).toString();
        insertarDatos(experiencia,logros,estudios,cedula,nombre,paterno,materno,correo,foto,direccion,contrasenia,mascota);
    }



}

medico_modificar::~medico_modificar()
{
    delete ui;
}

void medico_modificar::insertarDatos(QString experiencia, QString logros, QString estudios, QString cedula, QString nombre,
                                     QString paterno, QString materno, QString correo, QString foto, QString direccion
                                     , QString contrasenia, QString mascota){
    ui->LineCedula->setText(cedula);
    ui->LineCorreo->setText(correo);
    ui->LineLogros->setText(logros);
    ui->LineNombre->setText(nombre);
    ui->LineMascota->setText(mascota);
    ui->LineMaterno->setText(materno);
    ui->LinePaterno->setText(paterno);
    ui->LineEstudios->setText(estudios);
    ui->LineDireccion->setText(direccion);
    ui->LineContrasenia->setText(contrasenia);
    ui->LineExperiencia->setText(experiencia);
    QPixmap img(foto);
    ui->LabelFoto->setPixmap(img.scaled(120,120, Qt::IgnoreAspectRatio));


}

void medico_modificar::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void medico_modificar::on_btnModificarDatos_clicked()
{
    QSqlQuery ModificarDatos(mDatabase);

    QString Cedula = ui->LineCedula->text();
    QString Correo = ui->LineCorreo->text();
    QString Logros = ui->LineLogros->text();
    QString Nombre = ui->LineNombre->text();
    QString Mascota = ui->LineMascota->text();
    QString Materno = ui->LineMaterno->text();
    QString Paterno = ui->LinePaterno->text();
    QString Estudios = ui->LineEstudios->text();
    QString Direccion = ui->LineDireccion->text();
    QString Contrasenia = ui->LineContrasenia->text();
    QString Experiencia = ui->LineExperiencia->text();
    QString Foto = ui->LabelFoto->text();


    QMessageBox msgBox;
    msgBox.setWindowTitle("Actualizar Medico");
    msgBox.setText("¿Desea actualizar la informacion ingresada?");
    msgBox.setInformativeText("Esta accion no podra ser revertida");
    msgBox.setStandardButtons(QMessageBox::Yes);
    msgBox.addButton(QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::Yes);

    if(msgBox.exec() == QMessageBox::Yes){

        ModificarDatos.prepare("UPDATE usuario INNER JOIN persona "
                             "ON usuario.id_usuario = persona.id_usuario "
                             "INNER JOIN empleado "
                             "ON persona.id_persona = empleado.id_persona "
                             "INNER JOIN medico "
                             "ON empleado.id_empleado = medico.id_empleado "
                             "SET medico.experiencia='"+Experiencia+"', "
                             "medico.logros='"+Logros+"', medico.estudios = '"+Estudios+"', "
                             "medico.cedula='"+Cedula+"', "
                             "persona.nombre='"+Nombre+"', persona.paterno='"+Paterno+"', "
                             "persona.materno= '"+Materno+"', persona.correo='"+Correo+"', "
                             "persona.foto='"+Foto+"', persona.direccion='"+Direccion+"', "
                             "usuario.contrasenia='"+Contrasenia+"', usuario.mascota='"+Mascota+"' "
                             "WHERE usuario.id_usuario='sebastian'");

        ModificarDatos.exec();


        QMessageBox::information(this, tr("Actualizacion"),tr("Usuario Actualizado."),
                                      QMessageBox::Ok);
        this->close();
    } else {
        QMessageBox::information(this, tr("Actualizacion"),tr("Usuario NO Actualizado."),
                                      QMessageBox::Ok);
    }





}
