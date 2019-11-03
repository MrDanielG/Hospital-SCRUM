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
            ui->lineEdit_usuario->text() != ""){

        this->nombreUsuario = ui->lineEdit_usuario->text();
        this->contra = ui->lineEdit_contra->text();

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
            ui->lineEdit_direccion->text() != ""){

        this->nombre = ui->lineEdit_nombre->text();
        this->paterno = ui->lineEdit_paterno->text();
        this->materno = ui->lineEdit_materno->text();
        this->correo = ui->lineEdit_correo->text();
        this->direccion = ui->lineEdit_direccion->text();
        this->nacimiento = ui->dateEdit_fechaNacimiento->text();
        this->sexo = ui->comboBox_sexo->currentText();
        this->edad = QString::number(ui->spinBox_edad->value()); //Se cambia de int a Qstring
        this->foto = "C:/xampp/htdocs/GitHub/hospital/hospital-Core/Imagenes/imgPrueba.png"; //Por ahora tods la misma foto, esto se cambiara despues

        //Se crean las Querys, primero se crea Usuario
        QSqlQuery crearUsuario(mDatabase);
        crearUsuario.prepare("INSERT INTO usuario(id_usuario, contrasenia, id_tipo_usuario) VALUES ('"+this->nombreUsuario+"','"+this->contra+"','"+this->tipoUsuario+"')");
        crearUsuario.exec();

        QSqlQuery crearPersona(mDatabase);
        crearPersona.prepare("INSERT INTO `persona`(`nombre`, `paterno`, `materno`, `fNacimiento`, `correo`, `sexo`, `edad`, `foto`, `direccion`, `id_usuario`) "
                             "VALUES ('"+this->nombre+"','"+this->paterno+"','"+this->materno+"','"+this->nacimiento+"','"+this->correo+"','"+this->sexo+"','"+this->edad+"','"+this->foto+"', '"+this->direccion+"' ,'"+this->nombreUsuario+"')");
        crearPersona.exec();

        this->close();
    }
}
