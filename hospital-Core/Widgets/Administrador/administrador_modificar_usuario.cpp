#include "administrador_modificar_usuario.h"
#include "ui_administrador_modificar_usuario.h"
#include "QDebug"
administrador_modificar_usuario::administrador_modificar_usuario(QString nombreUsuario, QString tipoUsuario, QString contra, QString nombre, QString paterno, QString materno, QString nacimiento, QString correo, QString sexo, QString edad, QString foto, QString direccion, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::administrador_modificar_usuario)
{
    ui->setupUi(this);
    mDatabase = QSqlDatabase::database("Connection");
    if (!mDatabase.isOpen())
    {
        qDebug() << "ERROR con Base de Datos, esto es: GESTIONAR USUARIOS";
        return;
    }
    else
    {
        qDebug() << "Base de datos continua abierta, esto es: GESTIONAR USUARIOS";
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
    this->edad = edad;
    this->foto = foto;
    this->direccion = direccion;

    ui->lineEdit_usuario->setText(nombreUsuario);
    ui->label_tipoUsuario->setText(tipoUsuario);
    ui->lineEdit_contra->setText(contra);
    ui->lineEdit_nombre->setText(nombre);
    ui->lineEdit_paterno->setText(paterno);
    ui->lineEdit_materno->setText(materno);
    ui->dateEdit_fechaNacimiento->setDate(QDate::fromString(nacimiento,"dd/MM/yyyy"));
    ui->lineEdit_correo->setText(correo);
    this->sexo = sexo;
    ui->spinBox_edad->setValue(edad.toInt());
    this->foto = foto;
    ui->lineEdit_direccion->setText(direccion);

}

administrador_modificar_usuario::~administrador_modificar_usuario()
{
    delete ui;
}

void administrador_modificar_usuario::on_btn_crear_usuario_clicked()
{
    if(ui->lineEdit_nombre->text() != "" &&
            ui->lineEdit_paterno->text() != "" &&
            ui->lineEdit_materno->text() != "" &&
            ui->lineEdit_correo->text() != "" &&
            ui->lineEdit_direccion->text() != ""){

        //Falta Actualizar los atributos de la info de line edit

        QSqlQuery updateUsuario(mDatabase);
        updateUsuario.prepare("UPDATE `usuario` SET `contrasenia`='"+this->contra+"' WHERE id_usuario = '"+this->nombreUsuario+"'");
        updateUsuario.exec();

        QSqlQuery updatePersona(mDatabase);
        updatePersona.prepare("UPDATE `persona` SET `nombre`='"+this->nombre+"',`paterno`='"+this->paterno+"',`materno`='"+this->materno+"',`fNacimiento`='"+this->nacimiento+"',`correo`='"+this->correo+"',`sexo`='"+this->sexo+"',`edad`='"+this->edad+"',`foto`='"+this->foto+"',`direccion`='"+this->direccion+"' WHERE id_usuario = '"+this->nombreUsuario+"'");
        updatePersona.exec();

    }

}
