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


private slots:
    void test_case1();
    void abrirBase();
    void registrarUsuario();
    void inicioSesion();
    void recuperarDatos();
};

pruebas::pruebas()
{

}

pruebas::~pruebas()
{

}

void pruebas::abrirBase()
{
    QSqlDatabase mDatabase;
    mDatabase = QSqlDatabase::addDatabase("QMYSQL");
    mDatabase.setHostName("localhost");
    mDatabase.setDatabaseName("hospital");
    mDatabase.setUserName("root");
    mDatabase.setPassword("luisdrew1394");
    mDatabase.open();

    if (!mDatabase.isOpen()){
        qDebug() << "No se ha podido entrar a la base de datos";
    }else{
        qDebug() << "Base de datos conectada exitosamente";
    }

    QCOMPARE(mDatabase.isOpen(),true);
}

void pruebas::registrarUsuario(){
    // variables que usaré para ejecutar la query.
    QSqlQuery query;
    QString sql;

    int contador = 0;
    //Datos para crear un usuario.
    QString id, contrasenia, tipo_usuario;

    id = "luisBanderas";
    contrasenia = "luis123";
    tipo_usuario = "1";

    sql = "select count(*) from usuario where id_usuario = '"+id+"';";
    query.exec(sql);

    while (query.next()) {
        contador = query.value(0).toInt();
    }

    if(contador > 0){
        qDebug() << "El id de usuario ya ha sido registrado ateriormente";
    }
    else{
        sql = "insert into usuario(id_usuario, contrasenia, id_tipo_usuario) values('"+id+"', '"+contrasenia+"', "+tipo_usuario+");";
        query.exec(sql);

        //Datos para crear una persona.
        QString nombre, aPaterno, aMaterno, fNacimiento, correo, sexo, foto, direccion, id_usuario;

        nombre = "Luis Rolando";
        aPaterno = "Banderas";
        aMaterno = "Barrera";
        fNacimiento = "1999-04-26";
        correo = "lbanderasbarrera@gmail.com";
        sexo = "M";
        foto = "/Users/luisbanderas/Pictures/Perfil.JPG";
        direccion = "Av. cuauhtemoc #18 Col. Barrio del Rosario Tlayacatan, Mor.";
        id_usuario = "luisBanderas";

        sql = "insert into persona(nombre, paterno, materno, fecha_nacimiento, correo, sexo, id_usuario) values('"+nombre+"', '"+aPaterno+"', '"+
                aMaterno+"', '"+fNacimiento+"', '"+correo+"', '"+sexo+"', '"+id_usuario+"');";
        query.exec(sql);
    }

    int prueba;
    sql = "select count(*) from usuario where id_usuario = '"+id+"';";
    query.exec(sql);
    while(query.next()){
        prueba = query.value(0).toInt();
    }

    QCOMPARE(prueba, 1);

}

void pruebas::inicioSesion()
{
    // variables que usaré para ejecutar la query.
    QSqlQuery query;
    QString sql;

    //Datos para iniciar sesión;
    QString usuario, contrasenia;

    usuario = "luisBanderas";
    contrasenia = "luis123";

    //Datos que regresará la query
    QString id_usuario, password;
    int tipo_usuario = 0;
    QString nombretipousuario;

    sql = "select * from usuario where id_usuario = '"+usuario+"';";
    query.exec(sql);


    while(query.next()){
        id_usuario = query.value(0).toString();
        password = query.value(1).toString();
        tipo_usuario = query.value(2).toInt();
    }

    //verificanto el tipo de usuario
    sql = "select nombre_tipo from tipo_usuario where id_tipo_usuario = "+QString::number(tipo_usuario)+";";
    query.exec(sql);
    while(query.next()){
        nombretipousuario = query.value(0).toString();
    }
    if(usuario == id_usuario && contrasenia == password){
        qDebug()<<"Ingreso exitoso, usted es un: "+nombretipousuario;
    }
    else {
        qDebug()<<"Datos incorrectos";
    }

}

void pruebas::recuperarDatos()
{
    // variables que usaré para ejecutar la query.
    QSqlQuery query;
    QString sql;

    //Datos ingresados para recuperar contraseña
    QString usuario, correo, fechaNacimiento;
    usuario = "luisBanderas";
    correo = "lbanderasbarrera@gmail.com";
    fechaNacimiento = "1999-04-26";

    //Datos regresados por la query
    QString correoQuery, contraseniaQuery, fNacimientoQuery;


    sql = "select correo, fecha_nacimiento from persona where id_usuario = '"+usuario+"';";
    query.exec(sql);
    while(query.next()){
        correoQuery = query.value(0).toString();
        fNacimientoQuery = query.value(1).toString();
    }

    if(correoQuery == correo && fNacimientoQuery == fechaNacimiento){
        sql = "select contrasenia from usuario where id_usuario = '"+usuario+"'";
        query.exec(sql);
        while (query.next()) {
            contraseniaQuery = query.value(0).toString();
        }

        qDebug()<<"contraseña: "+contraseniaQuery;
    }
    else {
        qDebug()<<"Datos incorrectos";
    }
}



void pruebas::test_case1()
{

}

QTEST_APPLESS_MAIN(pruebas)

#include "tst_pruebas.moc"
