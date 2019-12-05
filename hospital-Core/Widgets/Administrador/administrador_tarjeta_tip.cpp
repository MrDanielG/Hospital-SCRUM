#include "administrador_tarjeta_tip.h"
#include "ui_administrador_tarjeta_tip.h"
#include "Widgets/Administrador/administrador_info_tip.h"
#include "Widgets/Administrador/administrador_gestionar_tips.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QDebug>


administrador_tarjeta_tip::administrador_tarjeta_tip(QString idTip, QString tit, QString text, QString foto, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::administrador_tarjeta_tip)
{
    ui->setupUi(this);
    id = idTip;
    titulo = tit;
    descripcion = text;
    img = foto;

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

    inicializarTarjeta();
}

administrador_tarjeta_tip::~administrador_tarjeta_tip()
{
    delete ui;
}

void administrador_tarjeta_tip::inicializarTarjeta()
{
    QPixmap pic(img);
    ui->lblNombre->setText(titulo);
    ui->plainText->setPlainText(descripcion);
    ui->imagen->setPixmap(pic);
}

void administrador_tarjeta_tip::on_btnModificar_clicked()
{
    administrador_info_tip InfoTip(id,this);
    InfoTip.exec();

    QSqlQuery query1(mDatabase);
    query1.prepare("SELECT * FROM info WHERE id_info = '"+id+"';");
    query1.exec();
    while(query1.next())
    {
        QString nombre = query1.value(1).toString();
        QString texto = query1.value(2).toString();
        ui->lblNombre->setText(nombre);
        ui->plainText->setPlainText(texto);
    }
}

void administrador_tarjeta_tip::on_btnEliminar_clicked()
{
    QMessageBox::StandardButton Confirmacion;
    Confirmacion = QMessageBox::question(this, "ADVERTENCIA", "¿Está seguro de eliminar esta información?",
                                         QMessageBox::Yes | QMessageBox::No);

    if(Confirmacion == QMessageBox::Yes)
    {
        QSqlQuery query(mDatabase);
        query.prepare("DELETE FROM info WHERE id_info='"+id+"' LIMIT 1;");
        query.exec();

        administrador_gestionar_tips tips;
        tips.limpia();
        tips.inicializarCatalogo();

        QMessageBox::information(this, tr("Tip del día"),tr("Tip elminado"),
                                      QMessageBox::Ok);
         this->close();
    }
}
