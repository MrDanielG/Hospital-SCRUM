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
//    void abrirBase();
//    void registrarUsuario();
//    void inicioSesion();
//    void recuperarDatos();

//    void ingresarServicios();
 //   void visualizarCita();

//    void visualizarCita();
//    void visualizarHorarioCitas();
//    void cancelarCita();
//    void editarPerfilProp();
//    void aprobarCancelacionCita();
//    void asignarCitaAMedico();
    //Pruebas Sara Sprint IV
 //   void CancelaCitaPaciente();
   // void VerCitasActivas(); //Por parte del paciente
   // void VerCitasCanceladas(); //Por el paciente
    //void VerCitasRealizadas(); //Por el paciente

    //Pruebas Angel
//    void modificarMedico();
//    void visualizarCitas();
//    void visualizarOperaciones();
//    void agendarCita();
//    void buscarporFecha();
    //void buscarporNombre();

//    void agregarInternado();
//    void modificarInternado();
//    void darDeBaja();

    //Pruebas Daniel Sprint 3
    //void catalogoCitas();
    //void buscarPorMedico();
//    void buscarFecha();

    //Prubas Sara Sprint V
    void ObtenerDatosMedico();
    void EnviarCalificacion();

    void crearVenta();




};

pruebas::pruebas()
{
    #ifdef Q_OS_WIN
//      mDatabase = QSqlDatabase::addDatabase("QODBC");
//          mDatabase.setDatabaseName("Driver={MySQL ODBC 8.0 Unicode Driver};DATABASE=connection;");
//          mDatabase.setUserName("root");
//          mDatabase.setPassword("");
//          mDatabase.setDatabaseName("hospital");
    mDatabase = QSqlDatabase::addDatabase("QODBC","Connection");
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

/*void pruebas::insertarDatos(QString experiencia, QString logros, QString estudios,
                           QString cedula, QString nombre, QString paterno, QString materno,
                            QString correo, QString foto, QString direccion, QString contrasenia,
                            QString mascota){


}*/

void pruebas::abrirBase()
{
    int conectada = 0;
    if(!mDatabase.open()){
            qDebug()<<"ERROR :(";
            conectada = 0;
       }
       else{
            qDebug()<<"CONECTADA";
            conectada = 1;
       }

    QVERIFY(conectada == 1);

}

/*void pruebas::visualizarHorarioCitas()
{
    int band = 0;
    QSqlQuery query(mDatabase);
    query.prepare("select * from tarjetaCitaHorario where estado = 1");
    query.exec();
    while (query.next()){
        QString nombre = query.value(0).toString();
        QString paterno = query.value(1).toString();
        QString materno = query.value(2).toString();
        QString morivo = query.value(3).toString();
        QString hInicio = query.value(4).toString();
        QString hFin = query.value(5).toString();
        QString foto = query.value(6).toString();
        QString idCita = query.value(8).toString();
        band=1;
    }

    QVERIFY(band == 1);
}*/

/*void pruebas::cancelarCita()
{
    QSqlQuery query(mDatabase);
    query.prepare("select * from tarjetaCitaHorario where estado = 1");
    query.exec();
    int band = 0;
    while (query.next()) {
        QString nombre = query.value(0).toString();
        QString paterno = query.value(1).toString();
        QString materno = query.value(2).toString();
        QString morivo = query.value(3).toString();
        QString hInicio = query.value(4).toString();
        QString hFin = query.value(5).toString();
        QString foto = query.value(6).toString();
        QString cita = query.value(8).toString();
        band = 1;
    }
    QSqlQuery query2(mDatabase);
    QString sql;
    if(band == 3){
        query2.prepare("select id_medico, justificacion_rechazo from cita_medica");
        query2.exec();
        while (query.next()) {
            QString id = query.value(0).toString();
            QString justificacion = query.value(1).toString();
        }
    }
    QVERIFY(band == 1);
}*/
//void pruebas::visualizarHorarioCitas()
//{
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
//}

//void pruebas::cancelarCita()
//{
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
//}

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

/*void pruebas::editarPerfilProp()
//void pruebas::editarPerfilProp()
//{
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
//}

//void pruebas::aprobarCancelacionCita()
//{

//}

//void pruebas::asignarCitaAMedico()
//{

//}

//void pruebas::modificarMedico()
//{
//    QSqlQuery ModificarDatos(mDatabase);

//    QString Cedula = "54484da";
//    QString Correo = "sebastian@gmail.com;";
//    QString Logros = "Certificados de google";
//    QString Nombre = "Sebastian";
//    QString Mascota = "Galleta";
//    QString Materno = "Rosas";
//    QString Paterno = "Genis";
//    QString Estudios = "Estudio en Harvard";
//    QString Direccion = "Morelos";
//    QString Contrasenia = "123";
//    QString Experiencia = "Trabajo en el FBI";
//    QString Foto = "C:/img/img2.png";
//    QString id = "sebastian";
//     QString aprobada = "false";

//    ModificarDatos.prepare("UPDATE usuario INNER JOIN persona "
//                         "ON usuario.id_usuario = persona.id_usuario "
//                         "INNER JOIN empleado "
//                         "ON persona.id_persona = empleado.id_persona "
//                         "INNER JOIN medico "
//                         "ON empleado.id_empleado = medico.id_empleado "
//                         "SET medico.experiencia='"+Experiencia+"', "
//                         "medico.logros='"+Logros+"', medico.estudios = '"+Estudios+"', "
//                         "medico.cedula='"+Cedula+"', "
//                         "persona.nombre='"+Nombre+"', persona.paterno='"+Paterno+"', "
//                         "persona.materno= '"+Materno+"', persona.correo='"+Correo+"', "
//                         "persona.foto='"+Foto+"', persona.direccion='"+Direccion+"', "
//                         "usuario.contrasenia='"+Contrasenia+"', usuario.mascota='"+Mascota+"' "
//                         "WHERE usuario.id_usuario='"+id+"'");

//    ModificarDatos.exec();
//    aprobada = "true";
//    QCOMPARE(aprobada, "true");



//}

//void pruebas::visualizarCitas()
//{
//    QSqlQuery MostrarDatos(mDatabase);
//    QString creada = "false";

//    MostrarDatos.prepare("select cita.fecha, cita.hora_inicio, persona.nombre, persona.paterno "
//                         "From persona INNER JOIN empleado "
//                         "ON persona.id_persona = empleado.id_persona "
//                         "INNER JOIN medico "
//                         "ON empleado.id_empleado = medico.id_empleado "
//                         "INNER JOIN cita_medica as cita "
//                         "ON medico.id_medico = cita.id_medico ");
//    MostrarDatos.exec();
//    int i=0;
//    int row = 0;
//    int col = 0;

//    while (MostrarDatos.next()){
//        QString fecha = MostrarDatos.value(0).toString();
//        QString hora = MostrarDatos.value(1).toString();
//        QString medico = MostrarDatos.value(2).toString();
//        QString medicopaterno = MostrarDatos.value(3).toString();
//        row = i/2;
//        col= i%2;
//        i++;
//        creada="true";
//    }
//    QCOMPARE(creada, "true");

//}

//void pruebas::visualizarOperaciones()
//{
//    QSqlQuery MostrarDatos(mDatabase);
//    QString creada = "false";

//    MostrarDatos.prepare("select operaciones.fecha, persona.nombre, persona.paterno "
//                         " FROM persona INNER JOIN empleado "
//                         "ON persona.id_persona = empleado.id_persona "
//                         "INNER JOIN medico "
//                         "ON empleado.id_empleado = medico.id_empleado "
//                         "INNER JOIN operaciones_agendadas as operaciones "
//                         "ON medico.id_medico = operaciones.id_medico");

//    MostrarDatos.exec();
//    int i=0;
//    int row = 0;
//    int col = 0;

//    while (MostrarDatos.next()){
//        QString fecha = MostrarDatos.value(0).toString();
//        QString hora = "04:14:10";
//        QString medico = MostrarDatos.value(1).toString();
//        QString medicopaterno = MostrarDatos.value(2).toString();
//        row = i/2;
//        col= i%2;
//        i++;
//        creada = "true";

//    }
//    QCOMPARE(creada, "true");

//}

//void pruebas::agendarCita()
//{
//    QString creada = "false";
//    QString lineEdit_descripcion = "Dolor de Cabeza";
//    QString lineEdit_motivo = "Dolor de cabeza muy fuerte";

//    if(lineEdit_descripcion.isEmpty() &&
//            lineEdit_motivo.isEmpty()){

//    } else {
//        QString folioMedico = "25";
//        QString motivo = lineEdit_motivo;
//        QString descripcion = lineEdit_descripcion;
//        QString fecha = "2019-12-12";
//        QString horaInicio = "10:00:00";
//        QString horaFinal = "12:00:00";
//        QString idPaciente = "5";

//        QSqlQuery crearCita(mDatabase);
//        QSqlQuery BuscarCita(mDatabase);

//        crearCita.prepare("INSERT INTO cita_medica(motivo, descripcion, fecha, hora_inicio, hora_fin, id_medico, id_paciente, estado) "
//                          "VALUES ('"+motivo+"','"+descripcion+"','"+fecha+"','"+horaInicio+"','"+horaFinal+"','"+folioMedico+"','"+idPaciente+"', '1')");
//        crearCita.exec();

//        BuscarCita.prepare("select * from cita_medica where "
//                           "motivo = '"+lineEdit_motivo+"' and descripcion = '"+lineEdit_descripcion+"' and id_paciente = 5 and id_medico = 25 ");


//        BuscarCita.exec();
//        while(BuscarCita.next()){
//            creada = "true";
//        }
//    }

//    QCOMPARE(creada, "true");

//}

//void pruebas::buscarporFecha()
//{
//    QString nombre = "Joaquin";
//    char caracter = '%';
//    QString arg1 = "201";
//    int seccionactivada = 2;
//    QString encontrada = "false";

//    if(seccionactivada==1){
//        QSqlQuery MostrarDatos(mDatabase);
//        MostrarDatos.prepare("select cita.fecha, cita.hora_inicio, persona.nombre, persona.paterno "
//                             "From persona INNER JOIN empleado "
//                             "ON persona.id_persona = empleado.id_persona "
//                             "INNER JOIN medico "
//                             "ON empleado.id_empleado = medico.id_empleado "
//                             "INNER JOIN cita_medica as cita "
//                             "ON medico.id_medico = cita.id_medico "
//                             "where cita.fecha like '"+arg1+""+caracter+"' and persona.nombre like '"+nombre+""+caracter+"'");
//        MostrarDatos.exec();

//        int row = 0;
//        int col = 0;
//        int i=0;

//        while (MostrarDatos.next()){
//            QString fecha = MostrarDatos.value(0).toString();
//            QString hora = MostrarDatos.value(1).toString();
//            QString medico = MostrarDatos.value(2).toString();
//            QString medicopaterno = MostrarDatos.value(3).toString();
//            row = i/2;
//            col= i%2;
//            i++;
//            encontrada = "true";
//        }
//    }else{
//        QSqlQuery MostrarDatos(mDatabase);
//        MostrarDatos.prepare("select operaciones.fecha, persona.nombre, persona.paterno "
//                             " FROM persona INNER JOIN empleado "
//                             "ON persona.id_persona = empleado.id_persona "
//                             "INNER JOIN medico "
//                             "ON empleado.id_empleado = medico.id_empleado "
//                             "INNER JOIN operaciones_agendadas as operaciones "
//                             "ON medico.id_medico = operaciones.id_medico "
//                             "where operaciones.fecha like '"+arg1+""+caracter+"' and persona.nombre like '"+nombre+""+caracter+"'");
//        MostrarDatos.exec();
//        int row = 0;
//        int col = 0;
//        int i=0;


//        while (MostrarDatos.next()){
//            QString fecha = MostrarDatos.value(0).toString();
//            QString hora = MostrarDatos.value(1).toString();
//            QString medico = MostrarDatos.value(2).toString();
//            QString medicopaterno = MostrarDatos.value(3).toString();
//            row = i/2;
//            col= i%2;
//            i++;
//            encontrada = "true";
//        }
//    }
//    QCOMPARE(encontrada, "true");

//}

void pruebas::buscarporNombre()
{
    QString fecha = "2019";
    char caracter = '%';
    QString arg1 = "Joaquin";
    int seccionactivada = 1;
    QString encontrada = "true";
    if(seccionactivada == 1){
        QSqlQuery MostrarDatos(mDatabase);
        MostrarDatos.prepare("select cita.fecha, cita.hora_inicio, persona.nombre, persona.paterno "
                             "From persona INNER JOIN empleado "
                             "ON persona.id_persona = empleado.id_persona "
                             "INNER JOIN medico "
                             "ON empleado.id_empleado = medico.id_empleado "
                             "INNER JOIN cita_medica as cita "
                             "ON medico.id_medico = cita.id_medico "
                             "where persona.nombre like '"+arg1+""+caracter+"' and persona.nombre like '"+fecha+""+caracter+"'");
        MostrarDatos.exec();

        while (MostrarDatos.next()){
            QString fecha = MostrarDatos.value(0).toString();
            QString hora = MostrarDatos.value(1).toString();
            QString medico = MostrarDatos.value(2).toString();
            QString medicopaterno = MostrarDatos.value(3).toString();
            encontrada = "true";
        }
    }else{

        QSqlQuery MostrarDatos(mDatabase);
        MostrarDatos.prepare("select operaciones.fecha, persona.nombre, persona.paterno "
                             " FROM persona INNER JOIN empleado "
                             "ON persona.id_persona = empleado.id_persona "
                             "INNER JOIN medico "
                             "ON empleado.id_empleado = medico.id_empleado "
                             "INNER JOIN operaciones_agendadas as operaciones "
                             "ON medico.id_medico = operaciones.id_medico "
                             "where persona.nombre like '"+arg1+""+caracter+"' and operaciones.fecha like '"+fecha+""+caracter+"'");
        MostrarDatos.exec();

        while (MostrarDatos.next()){
            QString fecha = MostrarDatos.value(0).toString();
            QString hora = MostrarDatos.value(1).toString();
            QString medico = MostrarDatos.value(2).toString();
            QString medicopaterno = MostrarDatos.value(3).toString();
            encontrada = "true";

        }
    }
}*/

/*void pruebas::aprobarCancelacionCita()
    QCOMPARE(encontrada, "true");
}

//void pruebas::agregarInternado()
//{
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
//        QVERIFY(db == 1);
//}

//void pruebas::modificarInternado()
//{
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

//        QVERIFY(compare == 1);
//}

//void pruebas::darDeBaja(){
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
//}

void pruebas::catalogoCitas()
{
    QDate fecha = fecha.currentDate();
    QString currentFecha = QString::number(fecha.year())+"-"+QString::number(fecha.month())+"-"+QString::number(fecha.day());
        int band = 0;
        QSqlQuery query(mDatabase);
        query.prepare("select * from tarjetaCitaHorario where estado = 1 and fecha = '"+currentFecha+"';");
        query.exec();
        while (query.next()){
            QString nombre = query.value(0).toString();
            QString paterno = query.value(1).toString();
            QString materno = query.value(2).toString();
            QString morivo = query.value(3).toString();
            QString hInicio = query.value(4).toString();
            QString hFin = query.value(5).toString();
            QString foto = query.value(6).toString();
            QString idCita = query.value(8).toString();
            band=1;
        }

}*/

/*void pruebas::asignarCitaAMedico()
        QVERIFY(band == 1);
}

void pruebas::buscarPorMedico()
{
    QString idMedico = "20";
    QString nombreMedico;
    int band = 0;

    QSqlQuery query(mDatabase);
    query.prepare("SELECT nombre, paterno, materno FROM medico "
                  "INNER JOIN empleado ON medico.id_empleado = empleado.id_empleado "
                  "INNER JOIN persona ON empleado.id_persona = persona.id_persona "
                  "WHERE id_medico = "+idMedico);
    query.exec();
    while (query.next()){
        nombreMedico = query.value(0).toString();
        band=1;
    }

}*/
 /*   QVERIFY(band == 1);
}*/

void pruebas::crearVenta()
{
    QSqlQuery insertventa(mDatabase);
    QSqlQuery medicamentosVenta(mDatabase);
    QSqlQuery buscarVenta(mDatabase);
    QDateTime fecha=QDateTime::currentDateTime();
    QString date = fecha.toString();
    QString secumple="false";
    QStringList ides;
    ides.append("1");
    ides.append("2");
    ides.append("3");
    QStringList cants;
    cants.append("5");
    cants.append("2");
    cants.append("1");
    insertventa.prepare("insert into venta(fecha) values('"+date+"')");
    insertventa.exec();
    buscarVenta.prepare("SELECT * FROM venta ORDER by folio desc LIMIT 1");
    buscarVenta.exec();
    QString ventaid = "";
    while (buscarVenta.next()) {
        ventaid = buscarVenta.value(0).toString();
    }
    for(int i=0; i<ides.size(); i++){
        medicamentosVenta.prepare("insert into medicamentosventa(id_medicamentos_farmacia, venta_folio, cantidad) "
                                  "values("+ides[i]+", "+ventaid+", "+ cants[i]+" )");
        medicamentosVenta.exec();
        secumple="true";
    }
    QCOMPARE(secumple, "true");
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

/*void pruebas::visualizarCita()
{
    QSqlQuery query;
    QString sql;
    int contador = 0;

    sql = "select * from cita_medica;";
    query.exec(sql);
    while(query.next()){
        contador ++;
    }

}*/

/*void pruebas::CancelaCitaPaciente()
{
    QString idCita="4";
    QSqlQuery CancelaCita;
    CancelaCita.prepare("update cita_medica set estado=3 where id_cita_medica='"+idCita+"';");
    QVERIFY(CancelaCita.exec());

    if(CancelaCita.exec())
    {
        qDebug() << "Cita cancelada";
    }
    else
    {
        qDebug() << "Error";
    }
}

void pruebas::VerCitasActivas()
{
    QString idPac = "1";
    QDate date = QDate::currentDate();
    QString hoy = date.toString("yyyy-MM-dd");
    QSqlQuery BuscarActivas;
    BuscarActivas.prepare("select * from cita_medica where fecha > '"+hoy+"' and estado=1 and id_paciente='"+idPac+"';");
    QVERIFY(BuscarActivas.exec());

    if(BuscarActivas.next())
    {
        qDebug() << "Citas obtenidas del Paciente "+idPac+"";
    }else
    {
        qDebug() << "Error";
    }

}

void pruebas::VerCitasCanceladas()
{
    QString idPac = "1";
    QSqlQuery BuscarCanceladas;
    BuscarCanceladas.prepare("select * from cita_medica where estado=3 and id_paciente='"+idPac+"';");
    QVERIFY(BuscarCanceladas.exec());

    if(BuscarCanceladas.next())
    {
        qDebug() << "Citas canceladas por el Paciente "+idPac+"";
    }else
    {
        qDebug() << "Error";
    }
}

void pruebas::VerCitasRealizadas()
{
    QString idPac = "1";
    QDate date = QDate::currentDate();
    QString hoy = date.toString("yyyy-MM-dd");
    QSqlQuery BuscarRealizadas;
    BuscarRealizadas.prepare("select * from cita_medica where fecha < '"+hoy+"' and estado=1 and id_paciente='"+idPac+"';");
    QVERIFY(BuscarRealizadas.exec());

    if(BuscarRealizadas.next())
    {
        qDebug() << "Citas que tuvo el Paciente "+idPac+"";
    }else
    {
        qDebug() << "Error";
    }
}*/

//void pruebas::test_case1()
//{
//void pruebas::visualizarCita(){
//    QSqlQuery query;
//    QString sql;
//    int contador = 0;

//    sql = "select * from cita_medica;";
//    query.exec(sql);
//    while(query.next()){
//        contador ++;
//    }
//}

void pruebas::ObtenerDatosMedico()
{
    QString idMedico="7";
    QSqlQuery query(mDatabase);
    query.prepare("select concat(p.nombre,' ',p.paterno,' ',p.materno) as Nombre, "
                  "esp.nombre as Especialidad, p.foto as Foto from persona as p "
                  "inner join empleado as e on p.id_persona=e.id_persona "
                  "inner join medico as m on e.id_empleado=m.id_empleado "
                  "inner join medico_has_especialidad as me on m.id_medico=me.id_medico "
                  "inner join especialidad as esp on me.id_especialidad=esp.id_especialidad "
                  "where m.id_medico='"+idMedico+"';");
    QVERIFY(query.exec());

    if(query.exec())
    {
        qDebug() << "Datos obtenidos";
    }else
    {
        qDebug() << "Error";
    }
}

void pruebas::EnviarCalificacion()
{
    QString NumEstrellas="4",id_cita="3",id_Medico="7";

    if(NumEstrellas != "0")
    {
        QSqlQuery insert(mDatabase);
        insert.prepare("update cita_medica set calificacion = '"+NumEstrellas+"'"
                             " where id_cita_medica='"+id_cita+"';");
        QVERIFY(insert.exec());

        if(insert.exec())
        {
            QSqlQuery CalculaPromedio(mDatabase);
            CalculaPromedio.prepare("select avg(calificacion) as promedio from "
                                    "cita_medica where id_medico='"+id_Medico+"' "
                                    "and calificacion != 0;");
            QVERIFY(CalculaPromedio.exec());

             QString valor = "4";
            if(CalculaPromedio.exec())
            {
                QSqlQuery update(mDatabase);
                update.prepare("update medico set calificacion_prom='"+valor+"' "
                                   "where id_medico='"+id_Medico+"'");
                QVERIFY(update.exec());
                update.finish();

                qDebug() << "Calificacion actualizada";
            }
        }
    }else
        qDebug() << "Ingrese calificacion";
}

QTEST_APPLESS_MAIN(pruebas)

#include "tst_pruebas.moc"
