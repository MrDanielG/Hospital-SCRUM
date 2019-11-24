#include "administrador_catalogo_remedios.h"
#include "ui_administrador_catalogo_remedios.h"
#include "Widgets/Administrador/administrador_tarjeta_remedio.h"
#include "QDebug"

administrador_catalogo_remedios::administrador_catalogo_remedios(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::administrador_catalogo_remedios)
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
        qDebug() << "ERROR en CATALOGO REMEDIOS";
    }else{
        qDebug() << "base de datos sigue conectada en CATALOGO REMEDIOS";
    }

    actualizarCatalogo();
}

administrador_catalogo_remedios::~administrador_catalogo_remedios()
{
    delete ui;
}

void administrador_catalogo_remedios::actualizarCatalogo()
{
    QSqlQuery query(mDatabase);
    query.prepare("SELECT * FROM info WHERE id_tipo_info = 2"); //Asi tiene que estar en la tabla tipo info 1 = Remedio
    query.exec();
    limpiarCatalogo();
    int i=0;
    int row = 0;
    int col = 0;

    while (query.next()) {
        QString id = query.value(0).toString();
        QString nombre = query.value(1).toString();
        QString descripcion = query.value(2).toString();
        QString foto = query.value(5).toString();

         row = i/2;
         col= i%2;

         administrador_tarjeta_remedio *tarjeta = new administrador_tarjeta_remedio(id, nombre, descripcion, foto, this);

         i++;
         ui->gridLayout->addWidget(tarjeta, row, col);
         tarjeta->llenarTarjeta();
    }
}

void administrador_catalogo_remedios::limpiarCatalogo()
{
    while (QLayoutItem *item = ui->gridLayout->takeAt(0))
    {
        Q_ASSERT(!item->layout());
        delete item->widget();
        delete item;
    }
}
