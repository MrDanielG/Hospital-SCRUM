#include "administrador_crear_tips.h"
#include "ui_administrador_crear_tips.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QSqlQuery>
#include <QDebug>

administrador_crear_tips::administrador_crear_tips(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::administrador_crear_tips)
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
    if (!mDatabase.isOpen()){
        qDebug() << "ERROR con Base de Datos, esto es: CREAR TIPS";
        return;
    }else{
        qDebug() << "Base de datos continua abierta, esto es: CREAR TIPS";
    }
}

administrador_crear_tips::~administrador_crear_tips()
{
    delete ui;
}

void administrador_crear_tips::on_btn_crear_2_clicked()
{
    QString DirImg = QFileDialog::getOpenFileName(this,"Seleccione una imagen",QDir::rootPath(),"imagenes(*.png *.jpg);; ");
    if(!DirImg.isEmpty())
    {
        QPixmap imag(DirImg);
        ui->img->setPixmap(imag);
    }

    imagen = DirImg;
}

void administrador_crear_tips::on_btn_crear_clicked()
{
    if(ui->lineNombreTip->text().isEmpty() || ui->textTip->toPlainText().isEmpty())
    {
        QMessageBox msgBox3(QMessageBox::Warning,tr("Campos"), tr("Ingresa todos los campos"), QMessageBox::Yes);
        msgBox3.setButtonText(QMessageBox::Yes, tr("Entendido"));
        msgBox3.exec();
    }else
    {
        if(imagen.isEmpty())
        {
            imagen = ":/imagenes/Imagenes/imgTipTest.png";
        }
        QString titulo, descripcion;
        titulo = ui->lineNombreTip->text();
        descripcion = ui->textTip->toPlainText();

        QMessageBox messageBox(QMessageBox::Question,tr("Confirmacion"), tr("Deseas guardar esta informacion?"), QMessageBox::Yes | QMessageBox::No);
        messageBox.setButtonText(QMessageBox::Yes, tr("Sí"));
        messageBox.setButtonText(QMessageBox::No, tr("No"));

        if(messageBox.exec() == QMessageBox::Yes)
        {
            QSqlQuery query(mDatabase);
            query.prepare("insert into info(nombre,descripcion,id_tipo_info,id_administrador,imagen) "
                          "values('"+titulo+"','"+descripcion+"',1,2,'"+imagen+"');");
            query.exec();

            QMessageBox msgBox(QMessageBox::Warning,tr("Exito"), tr("Tip registrado Correctamente"), QMessageBox::Yes);
            msgBox.setButtonText(QMessageBox::Yes, tr("Entendido"));
            msgBox.exec();
        }

        this->close();
    }
}

void administrador_crear_tips::on_btn_cancelar_clicked()
{
    this->close();
}
