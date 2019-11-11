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
private:
    QSqlDatabase mDatabase;



private slots:
    void test_case1();
    void abrirBase();
//    void abrirBase();
//    void registrarUsuario();
//    void inicioSesion();
//    void recuperarDatos();

//    void ingresarServicios();
    void visualizarCita();
    void visualizarHorarioCitas();
    void cancelarCita();
    void editarPerfilProp();
    void aprobarCancelacionCita();
    void asignarCitaAMedico();

    void agregarInternado();
    void modificarInternado();
    void darDeBaja();


};

pruebas::pruebas()
{
    #ifdef Q_OS_WIN
      mDatabase = QSqlDatabase::addDatabase("QODBC","Connection");
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

void pruebas::abrirBase()
{
    int conectada = 0;
    if(!mDatabase.open()){
            qDebug()<<"ERROR :(";
            conectada = 0;
       }
       else{
            qDebug()<<"CONECTADAAAAAAA";
            conectada = 1;
       }

    QVERIFY(conectada == 1);

}

void pruebas::visualizarHorarioCitas()
{
//    int band = 0;
//    QSqlQuery query(mDatabase);
//    query.prepare("select * from tarjetaCitaHorario where estado = 1");
//    query.exec();
//    while (query.next()){
//        QString nombre = query.value(0).toString();
//        QString paterno = query.value(1).toString();
//        QString materno = query.value(2).toString();
//        QString morivo = query.value(3).toString();
//        QString hInicio = query.value(4).toString();
//        QString hFin = query.value(5).toString();
//        QString foto = query.value(6).toString();
//        QString idCita = query.value(8).toString();
//        band=1;
//    }

//    QVERIFY(band == 1);
}

void pruebas::cancelarCita()
{
//    QSqlQuery query(mDatabase);
//    query.prepare("select * from tarjetaCitaHorario where estado = 1");
//    query.exec();
//    int band = 0;
//    while (query.next()) {
//        QString nombre = query.value(0).toString();
//        QString paterno = query.value(1).toString();
//        QString materno = query.value(2).toString();
//        QString morivo = query.value(3).toString();
//        QString hInicio = query.value(4).toString();
//        QString hFin = query.value(5).toString();
//        QString foto = query.value(6).toString();
//        QString cita = query.value(8).toString();
//        band = 1;
//    }
//    QSqlQuery query2(mDatabase);
//    QString sql;
//    if(band == 3){
//        query2.prepare("select id_medico, justificacion_rechazo from cita_medica");
//        query2.exec();
//        while (query.next()) {
//            QString id = query.value(0).toString();
//            QString justificacion = query.value(1).toString();
//        }
//    }
//    QVERIFY(band == 1);
}

//void pruebas::abrirBase(){
//    QSqlDatabase mDatabase;
//    mDatabase = QSqlDatabase::database("Connection");
//}

//void pruebas::registrarUsuario(){
//    // variables que usaré para ejecutar la query.
//    QSqlQuery query;
//    QString sql;

//    int contador = 0;
//    //Datos para crear un usuario.
//    QString id, contrasenia, tipo_usuario;

//    id = "luisBanderas";
//    contrasenia = "luis123";
//    tipo_usuario = "1";

//    sql = "select count(*) from usuario where id_usuario = '"+id+"';";
//    query.exec(sql);

//    while (query.next()) {
//        contador = query.value(0).toInt();
//    }

//    if(contador > 0){
//        qDebug() << "El id de usuario ya ha sido registrado ateriormente";
//    }
//    else{
//        sql = "insert into usuario(id_usuario, contrasenia, id_tipo_usuario) values('"+id+"', '"+contrasenia+"', "+tipo_usuario+");";
//        query.exec(sql);

//        //Datos para crear una persona.
//        QString nombre, aPaterno, aMaterno, fNacimiento, correo, sexo, foto, direccion, id_usuario;

//        nombre = "Luis Rolando";
//        aPaterno = "Banderas";
//        aMaterno = "Barrera";
//        fNacimiento = "1999-04-26";
//        correo = "lbanderasbarrera@gmail.com";
//        sexo = "M";
//        foto = "/Users/luisbanderas/Pictures/Perfil.JPG";
//        direccion = "Av. cuauhtemoc #18 Col. Barrio del Rosario Tlayacatan, Mor.";
//        id_usuario = "luisBanderas";

//        sql = "insert into persona(nombre, paterno, materno, fecha_nacimiento, correo, sexo, id_usuario) values('"+nombre+"', '"+aPaterno+"', '"+
//                aMaterno+"', '"+fNacimiento+"', '"+correo+"', '"+sexo+"', '"+id_usuario+"');";
//        query.exec(sql);
//    }

//    int prueba;
//    sql = "select count(*) from usuario where id_usuario = '"+id+"';";
//    query.exec(sql);
//    while(query.next()){
//        prueba = query.value(0).toInt();
//    }

//    QCOMPARE(prueba, 1);

//}

//void pruebas::inicioSesion()
//{
//    // variables que usaré para ejecutar la query.
//    QSqlQuery query;
//    QString sql;

//    //Datos para iniciar sesión;
//    QString usuario, contrasenia;

//    usuario = "luisBanderas";
//    contrasenia = "luis123";

//    //Datos que regresará la query
//    QString id_usuario, password;
//    int tipo_usuario = 0;
//    QString nombretipousuario;

//    sql = "select * from usuario where id_usuario = '"+usuario+"';";
//    query.exec(sql);


//    while(query.next()){
//        id_usuario = query.value(0).toString();
//        password = query.value(1).toString();
//        tipo_usuario = query.value(2).toInt();
//    }

//    //verificanto el tipo de usuario
//    sql = "select nombre_tipo from tipo_usuario where id_tipo_usuario = "+QString::number(tipo_usuario)+";";
//    query.exec(sql);
//    while(query.next()){
//        nombretipousuario = query.value(0).toString();
//    }
//    if(usuario == id_usuario && contrasenia == password){
//        qDebug()<<"Ingreso exitoso, usted es un: "+nombretipousuario;
//    }
//    else {
//        qDebug()<<"Datos incorrectos";
//    }

//}

//void pruebas::recuperarDatos()
//{
//    // variables que usaré para ejecutar la query.
//    QSqlQuery query;
//    QString sql;

//    //Datos ingresados para recuperar contraseña
//    QString usuario, correo, fechaNacimiento;
//    usuario = "luisBanderas";
//    correo = "lbanderasbarrera@gmail.com";
//    fechaNacimiento = "1999-04-26";

//    //Datos regresados por la query
//    QString correoQuery, contraseniaQuery, fNacimientoQuery;


//    sql = "select correo, fecha_nacimiento from persona where id_usuario = '"+usuario+"';";
//    query.exec(sql);
//    while(query.next()){
//        correoQuery = query.value(0).toString();
//        fNacimientoQuery = query.value(1).toString();
//    }

//    if(correoQuery == correo && fNacimientoQuery == fechaNacimiento){
//        sql = "select contrasenia from usuario where id_usuario = '"+usuario+"'";
//        query.exec(sql);
//        while (query.next()) {
//            contraseniaQuery = query.value(0).toString();
//        }

//        qDebug()<<"contraseña: "+contraseniaQuery;
//    }
//    else {
//        qDebug()<<"Datos incorrectos";
//    }
//}

void pruebas::editarPerfilProp()
{
//    QString usuario = "luisBanderas";
//    QString contrasenia = "luis123";
//    QString nCorreo = "luisbanderasbarrera@gmail.com";
//    QString nTelefono = "7351094081";
//    QString nDireccion = "sanmiguel 633 Vugambilias 3ra sección";
//    QSqlQuery query;
//    QString sql;
//    QString nombre, paterno, materno;
//    QString contraseniaQuery, usuarioQuery, tipousuarioQuery, nombreTipoQuery, correoInicial, telefonoInicial, direccionInicial;
//    QString telefonoCambiado, correoCambiado, direccionCambiada;

//    int contador = 0;
//    sql = "select count(*) from usuario where id_usuario = '"+usuario+"';";
//    query.exec(sql);
//    while(query.next()){
//        contador = query.value(0).toInt();
//    }
//    if(contador == 1){
//        sql = "select * from usuario where id_usuario = '"+usuario+"';";
//        query.exec(sql);
//        while(query.next()){
//            contraseniaQuery = query.value(1).toString();
//            usuarioQuery = query.value(0).toString();
//            tipousuarioQuery = query.value(2).toString();
//        }
//        sql = "select nombre_tipo from tipo_usuario where id_tipo_usuario = "+tipousuarioQuery+";";
//        query.exec(sql);
//        while (query.next()) {
//            nombreTipoQuery = query.value(0).toString();
//        }
//        if(usuario == usuarioQuery && contrasenia == contraseniaQuery){
//            sql = "select nombre, paterno, materno, correo, telefono, direccion from persona where id_usuario = '"+usuario+"';";
//            query.exec(sql);
//            while(query.next()){
//                nombre = query.value(0).toString();
//                paterno = query.value(1).toString();
//                materno = query.value(2).toString();
//                correoInicial = query.value(3).toString();
//                telefonoInicial = query.value(4).toString();
//                direccionInicial = query.value(5).toString();
//         }
//            qDebug()<<"Bienvenido "+nombre+" "+paterno+" "+materno+" usted es un usuario: "+nombreTipoQuery;
//            qDebug()<<"Datos iniciales: Correo = "+correoInicial+", Telefono = "+telefonoInicial+", Direccion = "+direccionInicial;
//            sql = "update persona set telefono = '"+nTelefono+"', correo = '"+nCorreo+"', direccion = '"+nDireccion+"' where id_usuario = '"+usuario+"';";
//            query.exec(sql);
//            sql = "select telefono, correo, direccion from persona where id_usuario = '"+usuario+"'";
//            query.exec(sql);
//            while(query.next()){
//                telefonoCambiado = query.value(0).toString();
//                correoCambiado = query.value(1).toString();
//                direccionCambiada = query.value(2).toString();
//            }
//            qDebug()<<"Tus nuevos datos son: Correo = "+correoCambiado+", Telefono = "+telefonoCambiado+", Direccion = "+direccionCambiada;
//        }
//        else {
//            qDebug()<< "contraseña incorrecta";
//        }
//    }
}

void pruebas::aprobarCancelacionCita()
{

}

void pruebas::asignarCitaAMedico()
{

}

void pruebas::agregarInternado()
{
//    int contador = 0;
//    int db = 0;
//    QString paciente = "2";
//    QString medico = "23";
//    QString habitacion = "2";
//    QString fecha_inicio = "2019-11-11";
//    QString fecha_fin = "2019-11-30";

//    QSqlQuery query(mDatabase);
//    QString sql;
//    sql = "select count(*) from internados where id_paciente = "+paciente+";";
//    query.prepare(sql);
//    query.exec();

//    while(query.next()){
//        contador = query.value(0).toInt();
//    }
//    if(contador >=1){
//        qDebug()<<"El paciente ya está registrado en un internado";
//    }else{
//         sql = "insert into internados(fecha_inicio, id_paciente, id_medico, habitacion) values('"+fecha_inicio+"', "+paciente+", "+medico+", "+habitacion+");";
//         query.prepare(sql);
//         query.exec();
//         db = 1;
//    }

//    sql = "select count (*) from internados where id_paciente = "+paciente+";";
//    query.prepare(sql);
//    query.exec();
    //    QVERIFY(db == 1);
}

void pruebas::modificarInternado()
{
//    QSqlQuery query (mDatabase);
//    QString sql;

//    QString paciente = "2";
//    QString nFecha_Fin = "2019-12-01";
//    QString nHabitacion = "1";

//    int compare = 0;

//    sql = "update internados set fecha_fin = '"+nFecha_Fin+"', habitacion = "+nHabitacion+" where id_paciente = "+paciente+";";
//    query.prepare(sql);
//    query.exec();

//    sql = "select count(*) from internados where fecha_fin = '"+nFecha_Fin+"' and habitacion = "+nHabitacion+" and id_paciente = "+paciente+";";
//    query.prepare(sql);
//    query.exec();

//    while (query.next()) {
//        compare = query.value(0).toInt();
//    }

    //    QVERIFY(compare == 1);
}

void pruebas::darDeBaja()
{
//    QSqlQuery query(mDatabase);
//    QString sql;

//    QString id_paciente = "8";

//    int contador = 0;
//    int comparador = 0;

//    sql = "select count(*) from internados where id_paciente = "+id_paciente+";";
//    query.prepare(sql);
//    query.exec();

//    while (query.next()) {
//        contador = query.value(0).toInt();
//    }

//    if(contador == 0){
//        qDebug()<<"No existe un registro con éste usuario";
//    }
//    else {
//        sql = "delete from internados where id_paciente = "+id_paciente+";";
//        query.prepare(sql);
//        query.exec();
//        qDebug()<<"Eliminado con exito";
//    }


//    sql = "select count(*) from internados where id_paciente = "+id_paciente+";";
//    query.prepare(sql);
//    query.exec();

//    while (query.next()) {
//        comparador = query.value(0).toInt();
//    }

//    QVERIFY(comparador == 0);
}

//void pruebas::ingresarServicios()
//{
//    QString usuario = "Admin";
//    QString contrasenia = "admin123";

//    QString servicio = "Rayos x";
//    QString descripcion = "El Hospital puebla Cuenta con rayos x para poder visualizar los problemas el los huesos";

//    QSqlQuery query;
//    QString sql;

//    QString contraseniaQuery, usuarioQuery, tipousuarioQuery, nombreTipoQuery;

//    QString nombre, paterno, materno;

//    int contador = 0;

//    sql = "select count(*) from usuario where id_usuario = '"+usuario+"';";
//    query.exec(sql);
//    while(query.next()){
//        contador = query.value(0).toInt();
//    }
//    if(contador == 1){
//        sql = "select * from usuario where id_usuario = '"+usuario+"';";
//        query.exec(sql);
//        while(query.next()){
//            contraseniaQuery = query.value(1).toString();
//            usuarioQuery = query.value(0).toString();
//            tipousuarioQuery = query.value(2).toString();
//        }

//        sql = "select nombre_tipo from tipo_usuario where id_tipo_usuario = "+tipousuarioQuery+";";
//        query.exec(sql);
//        while (query.next()) {
//            nombreTipoQuery = query.value(0).toString();
//        }

//        if(usuario == usuarioQuery && contrasenia == contraseniaQuery){
//            sql = "select nombre, paterno, materno from persona where id_usuario = '"+usuario+"';";
//            query.exec(sql);
//            while(query.next()){
//                nombre = query.value(0).toString();
//                paterno = query.value(1).toString();
//                materno = query.value(2).toString();
//            }
//            qDebug()<<"Bienvenido "+nombre+" "+paterno+" "+materno+" usted es un usuario: "+nombreTipoQuery;

//            sql = "insert into servicios(nombre, descripcion, id_administrador) values('"+servicio+"', '"+descripcion+"', 1);";
//            query.exec(sql);

//            sql = "select count(*) from servicios;";
//            query.exec(sql);
//            while (query.next()){
//                if(query.value(0).toInt() == 1){
//                    qDebug()<<"Registro exitoso";
//                }
//                else {
//                    qDebug()<<"Registro fallido";
//                }
//            }
//        }
//        else {
//            qDebug()<< "contrasenia incorrecta";
//        }
//   }
//   else{
//        qDebug()<< "Usuario incorrecto";
//    }
//}

void pruebas::visualizarCita()
{
//    QSqlQuery query;
//    QString sql;
//    int contador = 0;

//    sql = "select * from cita_medica;";
//    query.exec(sql);
//    while(query.next()){
//        contador ++;
//    }

}

void pruebas::test_case1()
{

}

QTEST_APPLESS_MAIN(pruebas)

#include "tst_pruebas.moc"
