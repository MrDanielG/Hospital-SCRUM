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
        QMessageBox::warning(this, tr("ERROR INFO"), tr("Campos Incompletos\n Por favor llene todos los campos."),
                             QMessageBox::Ok);
    }else
    {
        QString nuevoNombre,nuevoTexto;
        nuevoNombre = ui->lineEditNom->text();
        nuevoTexto = ui->textEditDes->toPlainText();

        QMessageBox::StandardButton Confirmacion;
        Confirmacion = QMessageBox::question(this, "ADVERTENCIA", "¿Está seguro de guardar esta información?",
                                             QMessageBox::Yes | QMessageBox::No);

        if(Confirmacion == QMessageBox::Yes)
        {
            QSqlQuery query1(mDatabase);
            query1.prepare("UPDATE info SET nombre = '"+nuevoNombre+"',descripcion = '"+nuevoTexto+"' "
                          " WHERE id_info = '"+idTip+"';");
            query1.exec();

            QMessageBox::information(this, tr("Modificar Tip"),tr("Tip Actualizado Correctamente"),
                                          QMessageBox::Ok);

            this->close();
        }
    }
}

void administrador_info_tip::on_btn_cancelar_clicked()
{
    this->close();
}
