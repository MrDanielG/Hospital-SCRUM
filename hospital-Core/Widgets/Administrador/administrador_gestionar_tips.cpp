#include "administrador_gestionar_tips.h"
#include "ui_administrador_gestionar_tips.h"
#include "Widgets/Administrador/administrador_crear_tips.h"
#include "Widgets/Administrador/administrador_tarjeta_tip.h"
#include <QDebug>
#include <QSqlQuery>

administrador_gestionar_tips::administrador_gestionar_tips(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::administrador_gestionar_tips)
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
        qDebug() << "ERROR con Base de Datos, esto es: GESTIONAR TIPS";
        return;
    }else{
        qDebug() << "Base de datos continua abierta, esto es: GESTIONAR TIPS";
    }

    inicializarCatalogo();
}

administrador_gestionar_tips::~administrador_gestionar_tips()
{
    delete ui;
}

void administrador_gestionar_tips::limpia()
{
    while (QLayoutItem *item = ui->gridLayout->takeAt(0))
    {
        Q_ASSERT(!item->layout()); // otherwise the layout will leak
        delete item->widget();
        delete item;
    }
}

void administrador_gestionar_tips::inicializarCatalogo()
{
    QSqlQuery query(mDatabase);

    query.prepare("select * from info where id_tipo_info = 1");
    query.exec();
    limpia();

    int i=0;
    int row = 0;
    int col = 0;

    while (query.next())
    {
         QString id = query.value(0).toString();
         QString nombre = query.value(1).toString();
         QString texto = query.value(2).toString();
         QString foto = query.value(5).toString();

         row = i/3;
         col= i%3;

         administrador_tarjeta_tip *tarjeta = new administrador_tarjeta_tip(id, nombre, texto,foto);

         i++;
         ui->gridLayout->addWidget(tarjeta, row, col);
    }
}

void administrador_gestionar_tips::on_btn_registra_tip_clicked()
{
    administrador_crear_tips tip;
    tip.exec();
    inicializarCatalogo();
}
