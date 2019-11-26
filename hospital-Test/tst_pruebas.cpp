#include <QtTest>
#include <QSqlDatabase>
#include <QSqlQuery>

// add necessary includes here

class pruebas : public QObject
{
    Q_OBJECT

public:
    pruebas();
    ~pruebas();
    //void insertarDatos(QString experiencia,QString logros,QString estudios,QString cedula,QString nombre,QString paterno,QString materno,QString correo,QString foto,QString direccion,QString contrasenia,QString mascota);
private:
    QSqlDatabase mDatabase;

private slots:
    void abrirBase();
    void mostrarTip();
    void mostrarRemedios();
};

pruebas::pruebas()
{
#ifdef Q_OS_WIN

    mDatabase = QSqlDatabase::addDatabase("QODBC", "Connection");
    mDatabase.setDatabaseName("hospital");
#elif defined(Q_OS_MAC)
    mDatabase = QSqlDatabase::addDatabase("QMYSQL");
    mDatabase.setDatabaseName("hospital");
    mDatabase.setHostName("localhost");
    mDatabase.setUserName("root");
    mDatabase.setPassword("luisdrew1394");
#endif
}

pruebas::~pruebas()
{
}



void pruebas::abrirBase()
{
    int conectada = 0;
    if (!mDatabase.open())
    {
        qDebug() << "ERROR :(";
        conectada = 0;
    }
    else
    {
        qDebug() << "CONECTADA";
        conectada = 1;
    }

    QVERIFY(conectada == 1);
}

void pruebas::mostrarTip()
{
    QString band ="false";
    QSqlQuery buscarid(mDatabase);
    QStringList numeros;
    buscarid.prepare("select id_info from info where id_tipo_info = 1");
    buscarid.exec();

    while (buscarid.next())
    {
        numeros.append(buscarid.value(0).toString());
    }
    int tama = numeros.size();
    int numerorand = qrand() % tama;

    if(tama > 0){
        QSqlQuery tip(mDatabase);
        tip.prepare("select * from info where id_tipo_info = 1 and id_info= " + numeros[numerorand]);
        tip.exec();
        while (tip.next())
        {
            QString id = tip.value(0).toString();
            QString nombre = tip.value(1).toString();
            QString descripcion = tip.value(2).toString();
            QString foto = tip.value(5).toString();
            band = "true";

        }
    }
    QVERIFY(band == "true");
}

void pruebas::mostrarRemedios()
{
    QSqlQuery crear(mDatabase);
    crear.prepare("select * from info where id_tipo_info = 2");
    crear.exec();
    QString band ="false";

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
        band = "true";

       /* tarjeta_remedios *tarjeta = new tarjeta_remedios();
        tarjeta->insertarDatos(id, nombre, descripcion, imagen);

        i++;
        ui->gridLayout->addWidget(tarjeta, row, col);*/

    }
    QVERIFY(band == "true");
}

QTEST_APPLESS_MAIN(pruebas)

#include "tst_pruebas.moc"
