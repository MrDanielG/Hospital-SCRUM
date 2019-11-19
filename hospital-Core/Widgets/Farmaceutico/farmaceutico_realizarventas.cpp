#include "farmaceutico_realizarventas.h"
#include "ui_farmaceutico_realizarventas.h"

farmaceutico_realizarVentas::farmaceutico_realizarVentas(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::farmaceutico_realizarVentas)
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

        QSqlQuery query(mDatabase);
        query.prepare("select nombre, costo, cantidad, premedicado, id_medicamentos_farmacia from medicamentos_farmacia");
        query.exec();

        int i=0;
        int row = 0;
        int col = 0;

        while(query.next()){
             QString nombre = query.value(0).toString();
             QString costo = query.value(1).toString();
             QString cantidad = query.value(2).toString();
             QString premedicado = query.value(3).toString();
             QString id = query.value(4).toString();

             row = i/2;
             col= i%2;

             farmaceutico_tarjeta_medicamento_venta *tarjeta = new farmaceutico_tarjeta_medicamento_venta();
             tarjeta->insertarDatos(nombre, costo, cantidad, premedicado, id);
             i++;
             ui->gridLayout->addWidget(tarjeta, row, col);

        }
}

farmaceutico_realizarVentas::~farmaceutico_realizarVentas()
{
    delete ui;
}

void farmaceutico_realizarVentas::limpiarCatalogo()
{
    while ( QLayoutItem* item = ui->gridLayout->takeAt( 0 ) ){
            Q_ASSERT( ! item->layout() ); // otherwise the layout will leak
            delete item->widget();
            delete item;
    }
}

void farmaceutico_realizarVentas::insertarVentas(QString id)
{

    QSqlQuery query(mDatabase);
    query.prepare("select nombre, costo from medicamentos_farmacia where id_medicamentos_farmacia = 5");
    query.exec();

    int i=0;
    int row = 0;
    int col = 0;

    while(query.next()){
         QString nombre = query.value(0).toString();
         QString costo = query.value(1).toString();

         row = i/2;
         col= i%2;

         farmaceutico_tarjetasventasencola *tarjeta = new farmaceutico_tarjetasventasencola(this);
         tarjeta->insertarDatos(nombre, "2", costo);
         ui->gridLayout_3->addWidget(tarjeta, row, col);

    }





}


void farmaceutico_realizarVentas::on_BuscarMedicamento_textChanged(const QString &arg1)
{

    char caracter = '%';

    QSqlQuery MostrarDatos(mDatabase);
    MostrarDatos.prepare("select nombre, costo, cantidad, premedicado, id_medicamentos_farmacia "
                         "from medicamentos_farmacia where nombre like '"+arg1+""+caracter+"'");
    MostrarDatos.exec();

    int row = 0;
    int col = 0;
    int i=0;
    limpiarCatalogo();

    while (MostrarDatos.next()){
        QString nombre = MostrarDatos.value(0).toString();
        QString costo = MostrarDatos.value(1).toString();
        QString cantidad = MostrarDatos.value(2).toString();
        QString premedicado = MostrarDatos.value(3).toString();
        QString id = MostrarDatos.value(4).toString();
        row = i/2;
        col= i%2;

        farmaceutico_tarjeta_medicamento_venta *tarjeta = new farmaceutico_tarjeta_medicamento_venta();
       tarjeta->insertarDatos(nombre, costo, cantidad, premedicado, id);
        i++;
        ui->gridLayout->addWidget(tarjeta, row, col);
    }

}
