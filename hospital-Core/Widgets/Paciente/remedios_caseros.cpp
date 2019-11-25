#include "remedios_caseros.h"
#include "ui_remedios_caseros.h"

remedios_caseros::remedios_caseros(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::remedios_caseros)
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
            qDebug() << "ERROR";
        }else{
            qDebug() << "base de datos sigue conectada en INICIAR SESION";
        }

        crearCatalogo();
}

remedios_caseros::~remedios_caseros()
{
    delete ui;
}

void remedios_caseros::crearCatalogo()
{

    QSqlQuery crear(mDatabase);
    crear.prepare("select * from info where id_tipo_info = 2");
    crear.exec();

    int i=0;
    int row=0;
    int col=0;

    while(crear.next()){
        QString id = crear.value(0).toString();
        QString nombre = crear.value(1).toString();
        QString descripcion = crear.value(2).toString();
        QString imagen = crear.value(5).toString();

        row = i/3;
        col= i%3;

        tarjeta_remedios *tarjeta = new tarjeta_remedios();
        tarjeta->insertarDatos(id, nombre, descripcion, imagen);

        i++;
        ui->gridLayout->addWidget(tarjeta, row, col);

    }
}

void remedios_caseros::limpiarCatalogo()
{
    while (QLayoutItem *item = ui->gridLayout->takeAt(0))
    {
        Q_ASSERT(!item->layout()); // otherwise the layout will leak
        delete item->widget();
        delete item;
    }
}

void remedios_caseros::on_lineEdit_textChanged(const QString &arg1)
{
    limpiarCatalogo();
    char caracter = '%';
    QSqlQuery crear(mDatabase);
    crear.prepare("select * from info where id_tipo_info = 2 and nombre like '"+arg1+""+caracter+"'");
    crear.exec();

    int i=0;
    int row=0;
    int col=0;

    while(crear.next()){
        QString id = crear.value(0).toString();
        QString nombre = crear.value(1).toString();
        QString descripcion = crear.value(2).toString();
        QString imagen = crear.value(5).toString();

        row = i/3;
        col= i%3;

        tarjeta_remedios *tarjeta = new tarjeta_remedios();
        tarjeta->insertarDatos(id, nombre, descripcion, imagen);

        i++;
        ui->gridLayout->addWidget(tarjeta, row, col);

    }

}
