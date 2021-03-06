#include "administrador_crear_usuario.h"
#include "ui_administrador_crear_usuario.h"
#include "QMessageBox"
#include "QDebug"
administrador_crear_usuario::administrador_crear_usuario(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::administrador_crear_usuario)
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
        qDebug() << "ERROR con Base de Datos, esto es: ADMINISTRADOR CREAR USUARIOS";
        return;
    }
    else
    {
        qDebug() << "Base de datos continua abierta, esto es: ADMINISTRADOR CREAR USUARIOS";
    }
    ui->stackedWidget->setCurrentIndex(0);
}

administrador_crear_usuario::~administrador_crear_usuario()
{
    delete ui;
}

void administrador_crear_usuario::on_btn_continuar_clicked()
{
    //Verificamos que todo este lleno y que las contrasenias oincidan
    if(ui->lineEdit_contra->text() == ui->lineEdit_confirma_contra->text() &&
            ui->lineEdit_contra->text() != "" &&
            ui->lineEdit_confirma_contra->text() != "" &&
            ui->lineEdit_usuario->text() != "" &&
            ui->lineEdit_mascota->text() != ""){

        this->nombreUsuario = ui->lineEdit_usuario->text();
        this->contra = ui->lineEdit_contra->text();
        this->mascota = ui->lineEdit_mascota->text();
        //Asignamos un tipo usuario conforme al combo box
        if(ui->comboBox_tipo_usuario->currentText() == "Medico"){
            this->tipoUsuario = "1";
        } else if (ui->comboBox_tipo_usuario->currentText() == "Paciente") {
            this->tipoUsuario = "2";
        } else if (ui->comboBox_tipo_usuario->currentText() == "Staff") {
            this->tipoUsuario = "4";
        }

        ui->stackedWidget->setCurrentIndex(1);
    } else {
        QMessageBox::warning(this, tr("Error Datos"),tr("Datos no Coinciden.\nVerificar"),
                                      QMessageBox::Ok);
    }
}

void administrador_crear_usuario::on_btn_crear_usuario_clicked()
{
    //Verificamos que los datos esten llenos
    if(ui->lineEdit_nombre->text() != "" &&
            ui->lineEdit_paterno->text() != "" &&
            ui->lineEdit_materno->text() != "" &&
            ui->lineEdit_correo->text() != "" &&
            ui->lineEdit_direccion->text() != "" &&
            ui->lineEdit_curp->text() != ""){

        this->nombre = ui->lineEdit_nombre->text();
        this->paterno = ui->lineEdit_paterno->text();
        this->materno = ui->lineEdit_materno->text();
        this->correo = ui->lineEdit_correo->text();
        this->direccion = ui->lineEdit_direccion->text();
        this->nacimiento = ui->dateEdit_fechaNacimiento->text();
        this->sexo = ui->comboBox_sexo->currentText();
        this->curp = ui->lineEdit_curp->text();

        //Se crean las Querys, primero se crea Usuario
        QSqlQuery crearUsuario(mDatabase);
        crearUsuario.prepare("INSERT INTO usuario(id_usuario, contrasenia, id_tipo_usuario, mascota) VALUES ('"+this->nombreUsuario+"','"+this->contra+"','"+this->tipoUsuario+"', '"+this->mascota+"')");
        crearUsuario.exec();

        QSqlQuery crearPersona(mDatabase);
        crearPersona.prepare("INSERT INTO `persona`(`nombre`, `paterno`, `materno`, `fNacimiento`, `correo`, `sexo`, `foto`, `direccion`, `id_usuario`, `curp`) "
                             "VALUES ('"+this->nombre+"','"+this->paterno+"','"+this->materno+"','"+this->nacimiento+"','"+this->correo+"','"+this->sexo+"', '"+this->foto+"', '"+this->direccion+"' ,'"+this->nombreUsuario+"', '"+this->curp+"')");
        crearPersona.exec();

        this->close();
    }
}

void administrador_crear_usuario::on_btn_foto_clicked()
{
    QString dir = QFileDialog::getOpenFileName(this,tr("Seleccione una imagen"), "/C:/", tr("Archivos de Imagen (* .png,* .jpg)"));
    qDebug()<<dir << "/directorio";
    if(!dir.isEmpty()){
        this->foto = dir;
        QMessageBox::information(this, tr("Correcto"),
                     tr("Imagen agregada correctamente"));
    }else{
        this->foto = "C:/img/imgServicio1.png"; //Img por Defecto
        QMessageBox::information(this, tr("Error"),
                     tr("No se inserto ninguna imagen"));
    }
}
