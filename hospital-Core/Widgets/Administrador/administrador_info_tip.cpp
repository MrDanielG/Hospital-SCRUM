#include "administrador_info_tip.h"
#include "ui_administrador_info_tip.h"
#include <QSqlQuery>
#include <QDebug>
#include <QMessageBox>

administrador_info_tip::administrador_info_tip(QString id,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::administrador_info_tip)
{
    ui->setupUi(this);
    idTip = id;

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
        qDebug() << "ERROR con Base de Datos, esto es: INFO TIP";
        return;
    }else{
        qDebug() << "Base de datos continua abierta, esto es: INFO TIP";
    }

    inicializa();
}

administrador_info_tip::~administrador_info_tip()
{
    delete ui;
}

void administrador_info_tip::inicializa()
{
    QSqlQuery query(mDatabase);
    query.prepare("select * from info where id_info = '"+idTip+"';");
    query.exec();

    QString nombre,texto,foto;
    while(query.next())
    {
        nombre = query.value(1).toString();
        texto = query.value(2).toString();
        foto = query.value(5).toString();
    }

    QPixmap pic(foto);
    ui->lineEditNom->setText(nombre);
    ui->textEditDes->setPlainText(texto);
    ui->img->setPixmap(pic);
}

void administrador_info_tip::on_btn_guardar_clicked()
{
    if(ui->lineEditNom->text().isEmpty() || ui->textEditDes->toPlainText().isEmpty())
    {
        QMessageBox msgBox(QMessageBox::Warning,tr("Campos"), tr("Ingrese todos los Campos"), QMessageBox::Yes);
        msgBox.setButtonText(QMessageBox::Yes, tr("Entendido"));
        msgBox.exec();
    }else
    {
        QString nuevoNombre,nuevoTexto;
        nuevoNombre = ui->lineEditNom->text();
        nuevoTexto = ui->textEditDes->toPlainText();

        QMessageBox msgBox(QMessageBox::Warning,tr("Confirmar"), tr("Desea guardar esta información"), QMessageBox::Yes | QMessageBox::No);
        msgBox.setButtonText(QMessageBox::Yes, tr("Si"));

        if(msgBox.exec() == QMessageBox::Yes)
        {
            QSqlQuery query1(mDatabase);
            query1.prepare("UPDATE info SET nombre = '"+nuevoNombre+"',descripcion = '"+nuevoTexto+"' "
                          " WHERE id_info = '"+idTip+"';");
            query1.exec();

            QMessageBox msgBox(QMessageBox::Warning,tr("Éxito"), tr("Tip Actualizado Correctamente"), QMessageBox::Yes);
            msgBox.setButtonText(QMessageBox::Yes, tr("Entendido"));
            msgBox.exec();

            this->close();
        }
    }
}

void administrador_info_tip::on_btn_cancelar_clicked()
{
    this->close();
}
