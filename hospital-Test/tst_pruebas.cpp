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

pruebas::~pruebas(){
}

QTEST_APPLESS_MAIN(pruebas)

#include "tst_pruebas.moc"
