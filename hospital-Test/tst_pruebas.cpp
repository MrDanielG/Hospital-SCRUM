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
    //void ObtenerDatosMedico();
    //void EnviarCalificacion();

    //Pruebas Sara Spintr VI
    void crearTip();
    void modificaTip();
    void eliminaTip();

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
/*void pruebas::ObtenerDatosMedico()
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
    if(query.exec())
    {
        qDebug() << "Datos obtenidos";
    }else
    {
        qDebug() << "Error";
    }
}*/

/*void pruebas::EnviarCalificacion()
{
    QString NumEstrellas="4",id_cita="3",id_Medico="7";

        row = i/3;
        col= i%3;
        band = "true";

       /* tarjeta_remedios *tarjeta = new tarjeta_remedios();
        tarjeta->insertarDatos(id, nombre, descripcion, imagen);

        i++;
        ui->gridLayout->addWidget(tarjeta, row, col);*/

    }
    QVERIFY(band == "true");
                qDebug() << "Calificacion actualizada";
            }
        }
    }else
        qDebug() << "Ingrese calificacion";
}*/

void pruebas::crearTip()
{
    QString titulo = "Toma agua";
    QString descripcion = "Toma dos litros de agua al día";
    QString imagen = ":/imagenes/Imagenes/imgTipTest.png";
    QSqlQuery query(mDatabase);
    query.prepare("insert into info(nombre,descripcion,id_tipo_info,id_administrador,imagen) "
                  "values('"+titulo+"','"+descripcion+"',1,1,'"+imagen+"');");
    QVERIFY(query.exec());
    if(query.exec())
    {
        qDebug() << "Tip registrado";
    }else
    {
        qDebug() << "Error";
    }
}

void pruebas::modificaTip()
{
    QString nombre = "Evita el refresco ";
    QString texto = "El alto consumo de refresco provoca daños a la salud";
    QString id="4";

    QSqlQuery query1(mDatabase);
    query1.prepare("UPDATE info SET nombre = '"+nombre+"',descripcion = '"+texto+"' "
                  " WHERE id_info = '"+id+"';");
    QVERIFY(query1.exec());

    if(query1.exec())
    {
        qDebug() << "Tip modificado";
    }else
    {
        qDebug() << "Error";
    }
}


void pruebas::eliminaTip()
{
    QString id="2";
    QSqlQuery query2(mDatabase);
    query2.prepare("DELETE FROM info WHERE id_info='"+id+"' LIMIT 1;");
    query2.exec();

    QVERIFY(query2.exec());

    if(query2.exec())
    {
        qDebug() << "Tip eiminado";
    }else
    {
        qDebug() << "Error";
    }

}

QTEST_APPLESS_MAIN(pruebas)

#include "tst_pruebas.moc"
