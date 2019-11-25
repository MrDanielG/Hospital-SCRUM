#include "administrador_tarjeta_remedio.h"
#include "ui_administrador_tarjeta_remedio.h"
#include "Widgets/Administrador/administrador_catalogo_remedios.h"
#include "QPixmap"
#include "QMessageBox"
#include "QDebug"
administrador_tarjeta_remedio::administrador_tarjeta_remedio(QString id, QString nombre, QString descripcion, QString foto, administrador_catalogo_remedios *parent) :
    QWidget(parent),
    ui(new Ui::administrador_tarjeta_remedio)
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
        qDebug() << "ERROR en TARJETA REMEDIOS";
    }else{
        qDebug() << "base de datos sigue conectada en TARJETA REMEDIOS";
    }


    this->id = id;
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->foto = foto;
    this->padre = parent;
}

void administrador_tarjeta_remedio::llenarTarjeta()
{
    QPixmap img(this->foto);
    ui->nombre_remedio->setText(this->nombre);
    ui->plainTextEdit->setPlainText(this->descripcion);
    ui->img_remedio->setPixmap(img);
}

administrador_tarjeta_remedio::~administrador_tarjeta_remedio()
{
    delete ui;
}

void administrador_tarjeta_remedio::on_btn_modificar_clicked()
{
    QSqlQuery query(mDatabase);
    query.exec("UPDATE info SET ");
}

void administrador_tarjeta_remedio::on_btn_eliminar_clicked()
{
    QMessageBox msgBox(QMessageBox::Question,"eliminar","¿Desea eliminar éste Remedio?",QMessageBox::Yes|QMessageBox::No);
    msgBox.setButtonText(QMessageBox::Yes,"Sí");
    msgBox.setButtonText(QMessageBox::No,"No");

    if(msgBox.exec()==QMessageBox::Yes){
        QSqlQuery query(mDatabase);
        query.exec("DELETE FROM info WHERE id_info = '"+this->id+"'");

        QMessageBox::information(this, tr("Eliminar"),
                     tr("Se eliminó correctamente el remedio"));
        this->padre->actualizarCatalogo(); //Se actualiza el catalogo desde la tarjeta
    } else {
        QMessageBox::information(this, tr("Eliminar"),
                     tr("No eliminó el remedio"));
    }
}
