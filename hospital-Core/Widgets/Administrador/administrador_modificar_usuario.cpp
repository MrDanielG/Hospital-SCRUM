#include "administrador_modificar_usuario.h"
#include "ui_administrador_modificar_usuario.h"
#include "QDebug"
#include "QMessageBox"
#include <QFileDialog>
administrador_modificar_usuario::administrador_modificar_usuario(QString nombreUsuario, QString tipoUsuario, QString contra, QString nombre, QString paterno, QString materno, QString nacimiento, QString correo, QString sexo, QString foto, QString direccion, QString curp, QString mascota, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::administrador_modificar_usuario)
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
        qDebug() << "ERROR con Base de Datos, esto es: MODIFICAR USUARIOS";
        return;
    }
    else
    {
        qDebug() << "Base de datos continua abierta, esto es: MODIFICAR USUARIOS";
    }

    this->nombreUsuario = nombreUsuario;
    this->tipoUsuario = tipoUsuario;
    this->contra = contra;
    this->nombre = nombre;
    this->paterno = paterno;
    this->materno = materno;
    this->nacimiento = nacimiento;
    this->correo = correo;
    this->sexo = sexo;
    this->foto = foto;
    this->direccion = direccion;
    this->curp = curp;
    this->mascota = mascota;

    ui->lineEdit_usuario->setText(nombreUsuario);
    ui->label_tipoUsuario->setText(tipoUsuario);
    ui->lineEdit_contra->setText(contra);
    ui->lineEdit_confirma_contra->setText(contra);
    ui->lineEdit_nombre->setText(nombre);
    ui->lineEdit_paterno->setText(paterno);
    ui->lineEdit_materno->setText(materno);
    ui->dateEdit_fechaNacimiento->setDate(QDate::fromString(nacimiento,"dd/MM/yyyy"));
    ui->lineEdit_correo->setText(correo);
    this->sexo = sexo;
    this->foto = foto;
    ui->lineEdit_direccion->setText(direccion);
    ui->lineEdit_mascota->setText(mascota);
    ui->lineEdit_curp->setText(curp);

    ui->stackedWidget->setCurrentIndex(0);
}

administrador_modificar_usuario::~administrador_modificar_usuario()
{
    delete ui;
}

void administrador_modificar_usuario::on_btn_crear_usuario_clicked(){
    if(ui->lineEdit_nombre->text() != "" &&
            ui->lineEdit_paterno->text() != "" &&
            ui->lineEdit_materno->text() != "" &&
            ui->lineEdit_correo->text() != "" &&
            ui->lineEdit_direccion->text() != "" &&
            ui->lineEdit_curp->text() != ""){


        QMessageBox msgBox;
        msgBox.setWindowTitle("Actualizar Usuario");
        msgBox.setText("¿Desea Actualizar este Usuario?");
        msgBox.setInformativeText("Esta accion no podra ser revertida");
        msgBox.setStandardButtons(QMessageBox::Yes);
        msgBox.addButton(QMessageBox::No);
        msgBox.setDefaultButton(QMessageBox::No);

        if(msgBox.exec() == QMessageBox::Yes){
            //Se actualizan los atributos conforme a la interfaz
            this->nombreUsuario = ui->lineEdit_usuario->text();
            this->contra = ui->lineEdit_contra->text();
            this->nombre = ui->lineEdit_nombre->text();
            this->paterno = ui->lineEdit_paterno->text();
            this->materno = ui->lineEdit_materno->text();
            this->nacimiento = ui->dateEdit_fechaNacimiento->text();
            this->correo = ui->lineEdit_correo->text();
            this->sexo = ui->comboBox_sexo->currentText();
            //this->foto = "C:/xampp/htdocs/GitHub/hospital/hospital-Core/Imagenes/imgPrueba.png"; //Por ahora tods la misma foto, esto se cambiara despues;
            this->direccion = ui->lineEdit_direccion->text();
            this->curp = ui->lineEdit_curp->text();
            this->mascota = ui->lineEdit_mascota->text();

            QSqlQuery updateUsuario(mDatabase);
            updateUsuario.prepare("UPDATE `usuario` SET `contrasenia`='"+this->contra+"', mascota ='"+this->mascota+"' WHERE id_usuario = '"+this->nombreUsuario+"'");
            updateUsuario.exec();

            QSqlQuery updatePersona(mDatabase);
            updatePersona.prepare("UPDATE `persona` SET `nombre`='"+this->nombre+"',`paterno`='"+this->paterno+"',`materno`='"+this->materno+"',`fNacimiento`='"+this->nacimiento+"',`correo`='"+this->correo+"',`sexo`='"+this->sexo+"', `foto`='"+this->foto+"',`direccion`='"+this->direccion+"',`curp`='"+this->curp+"' WHERE id_usuario = '"+this->nombreUsuario+"'");
            updatePersona.exec();

            QMessageBox::information(this, tr("Actualizacion"),tr("Usuario Actualizado."),
                                          QMessageBox::Ok);
            this->close();
        } else {
            QMessageBox::information(this, tr("Actualizacion"),tr("Usuario NO Actualizado."),
                                          QMessageBox::Ok);
            this->close();
        }

    } else {
        QMessageBox::warning(this, tr("Faltan Datos"),tr("Ingresa TODA la informacion requerida.\nVerificar"),
                                      QMessageBox::Ok);
    }

}

void administrador_modificar_usuario::on_btn_continuar_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void administrador_modificar_usuario::on_btn_foto_clicked()
{
    QString dir = QFileDialog::getOpenFileName(this,tr("Seleccione una imagen"), "/C:/", tr("Archivos de Imagen (* .png,* .jpg)"));
    if(!dir.isEmpty()){
    this->foto = dir;
        QMessageBox::information(this, tr("Correcto"),
                     tr("Imagen agregada correctamente"));

    }else{
        QMessageBox::information(this, tr("Error"),
                     tr("No se inserto ninguna imagen"));
    }
}
