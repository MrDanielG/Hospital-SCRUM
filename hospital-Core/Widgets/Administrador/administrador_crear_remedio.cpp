#include "administrador_crear_remedio.h"
#include "ui_administrador_crear_remedio.h"
#include "QMessageBox"
#include "QDebug"
administrador_crear_remedio::administrador_crear_remedio(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::administrador_crear_remedio)
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
        qDebug() << "ERROR en CREAR REMEDIOS";
    }else{
        qDebug() << "base de datos sigue conectada en CREAR REMEDIOS";
    }
}

administrador_crear_remedio::~administrador_crear_remedio()
{
    delete ui;
}

void administrador_crear_remedio::on_btn_crear_clicked()
{
    if( ui->nombreRemedio->text().isEmpty() ||
            ui->descripcion->toPlainText().isEmpty()){

        QMessageBox::information(this, tr("Error"),
                     tr("Completa todos los campos"));

    } else {
        QMessageBox msgBox(QMessageBox::Question,"Confimacion","¿Desea crear un nuevo Remedio?",QMessageBox::Yes|QMessageBox::No);
        msgBox.setButtonText(QMessageBox::Yes,"Sí");
        msgBox.setButtonText(QMessageBox::No,"No");


        if(msgBox.exec()==QMessageBox::Yes){
            this->nombre = ui->nombreRemedio->text();
            this->descripcion = ui->descripcion->toPlainText();

            QSqlQuery query(mDatabase);
            query.exec("INSERT INTO `info`(`nombre`, `descripcion`, `id_tipo_info`, `id_administrador`, `imagen`) VALUES ('"+this->nombre+"','"+this->descripcion+"',2,2,'"+this->foto+"')");

            QMessageBox::information(this, tr("Error"),
                         tr("Se agrego creo un Nuevo Remedio"));
            this->close();
        } else {
            QMessageBox::information(this, tr("Error"),
                         tr("No se creo un nuevo remedio"));
            this->close();
        }
    }
}

void administrador_crear_remedio::on_btn_foto_clicked()
{
    QString dir = QFileDialog::getOpenFileName(this,tr("Seleccione una imagen"), "/C:/", tr("Archivos de Imagen (* .png,* .jpg)"));
    qDebug()<<dir << "/directorio";
    if(!dir.isEmpty()){
        this->foto = dir;
        QMessageBox::information(this, tr("Correcto"),
                     tr("Imagen agregada correctamente"));
        ui->foto->setPixmap(dir);
    }else{
        this->foto = "C:/img/imgTipTest.png"; //Img por Defecto
        QMessageBox::information(this, tr("Error"),
                     tr("No se inserto ninguna imagen"));
    }
}
