#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlDatabase>
#include <QDebug>
#include "Widgets/Usuario/registrar.h"
#include "Widgets/Usuario/inicar_sesion.h"
#include "Widgets/Usuario/catalogo_doctores.h"
#include "Widgets/Paciente/paciente_landpage.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
                                          ui(new Ui::MainWindow)
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

    ui->stackedWidget->setCurrentIndex(0);
    ui->stackedWidget_2->setCurrentIndex(0);
    ui->stackedWidget->insertWidget(1, &landpageadministrador);
    ui->stackedWidget->insertWidget(2, &catalogo_servicios);
    ui->stackedWidget->insertWidget(3, &catalogodoctores);
    ui->stackedWidget->insertWidget(4, &gestionServiciosAdmin);
    ui->stackedWidget->insertWidget(5, &gestionUsuariosAdmin);
    ui->stackedWidget->insertWidget(6, &gestionTipsAdmin);
    ui->stackedWidget->insertWidget(7, &landpagepaciente);
    ui->stackedWidget->insertWidget(8, &landpageMedico);
    ui->stackedWidget->insertWidget(9, &horarioMedico);
    ui->stackedWidget->insertWidget(10, &solicitudesMedico);
    ui->stackedWidget->insertWidget(11, &generarReceta);
    ui->stackedWidget->insertWidget(12, &gestionCitas);
    ui->stackedWidget->insertWidget(13, &horariosMedicos);
    ui->stackedWidget->insertWidget(15, &cancelacionCatalogoAdmin);
    ui->stackedWidget->insertWidget(16, &landpageRecepcionista);
    ui->stackedWidget->insertWidget(17, &internados);
    ui->stackedWidget->insertWidget(18, &informacionMedico);
    ui->stackedWidget->insertWidget(19, &citas);
    ui->stackedWidget->insertWidget(20, &cobrarEstancia);
    ui->stackedWidget->insertWidget(21, &catalogoRemedios);
    ui->stackedWidget->insertWidget(22, &landpageFarmaceutico);
    ui->stackedWidget->insertWidget(23, &ventaMedicamento);
    ui->stackedWidget->insertWidget(24, &remediosCaseros);

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

    QSqlQuery tip(mDatabase);
    tip.prepare("select * from info where id_tipo_info = 1 and id_info= " + numeros[numerorand]);
    tip.exec();
    while (tip.next())
    {
        QString id = tip.value(0).toString();
        QString nombre = tip.value(1).toString();
        QString descripcion = tip.value(2).toString();
        QString foto = tip.value(5).toString();

        usuario_tip tips;
        tips.insertarDatos(id, nombre, foto, descripcion);
        tips.exec();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setindex(int index)
{
    this->index = index;
}

QString MainWindow::getNombreUsuario()
{
    return this->datosLogin.nombre_usuario;
}

void MainWindow::on_btn_iniciar_sesion_clicked()
{
    inicar_sesion dialogo_iniciar_sesion(&(this->datosLogin));
    dialogo_iniciar_sesion.exec();

    this->sesion = dialogo_iniciar_sesion.getUsuario();

    qDebug() << "DATOS LOGIN";
    qDebug() << this->datosLogin.nombre_usuario;
    qDebug() << this->datosLogin.passwd;
    horarioMedico.setIdUsuario(this->datosLogin.nombre_usuario);
    gestionCitas.setIdPaciente(this->datosLogin.nombre_usuario);
    informacionMedico.setID(this->datosLogin.nombre_usuario);
    generarReceta.setUsuario(this->datosLogin.nombre_usuario);
    solicitudesMedico.setUsuario(this->datosLogin.nombre_usuario);

    this->index = dialogo_iniciar_sesion.getindex(); //Retorno tipo de usuario a MainWindow para abrir interfaz correcta

    /*Aqui deben poner el index del landpage al que quieran visualizar
     * 1 = Medico
     * 2 = Paciente
     * 3 = Administrador
     * 4 = Farmaceutico
     * 5 = Enfermera
     * 6 = Cajero
     * 7 = Recepcionista
     *
     * esto se hace para todos los else if dependiendo el caso
    */

    if (this->index == 1)
    {
        ui->stackedWidget->setCurrentIndex(8);
        ui->stackedWidget_2->setCurrentIndex(2);
    }
    else if (this->index == 2)
    {
        ui->stackedWidget->setCurrentIndex(7);
        ui->stackedWidget_2->setCurrentIndex(3);
    }
    else if (this->index == 3)
    {
        ui->stackedWidget->setCurrentIndex(1);
        //Aqui se cambia el index del navegador, se hace lo mismo para todos
        ui->stackedWidget_2->setCurrentIndex(1);
    }
    else if (this->index == 4)
    {
        //Farmaceutico
        ui->stackedWidget->setCurrentIndex(22);
        ui->stackedWidget_2->setCurrentIndex(5);
    }
    else if (this->index == 5)
    {
        // Enfermera
    }
    else if (this->index == 6)
    {
        //Cajero
    }
    else if (this->index == 7)
    {
        //Recepcionista
        ui->stackedWidget->setCurrentIndex(16);
        ui->stackedWidget_2->setCurrentIndex(4);
    }
    qDebug() << "usuario" << dialogo_iniciar_sesion.getUsuario();
}

void MainWindow::on_btn_registrarse_clicked()
{
    registrar dialogo_registro;
    dialogo_registro.exec();
}

void MainWindow::on_btn_doctores_info_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_btn_servicios_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_btn_servicios_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_btn_inicio_admin_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_btn_remedios_admin_clicked()
{
    ui->stackedWidget->setCurrentIndex(21);
}

void MainWindow::on_btn_gestionar_servicios_admin_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_btn_gestionar_usuarios_admin_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_btn_gestionar_tips_admin_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_btn_salir_admin_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->stackedWidget_2->setCurrentIndex(0);
}

void MainWindow::on_btn_salir_medico_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->stackedWidget_2->setCurrentIndex(0);
}

void MainWindow::on_btn_horario_medico_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
}

void MainWindow::on_btn_inicio_medico_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);
}

void MainWindow::on_pushButton_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(15);
    cancelacionCatalogoAdmin.actualizarCatalogo();
}

void MainWindow::on_btn_solicitudes_medico_clicked()
{
    QString usuario = solicitudesMedico.getUsuario(), idPer, idEmp, idMed;

    QSqlQuery query(mDatabase);
    QSqlQuery query1(mDatabase);
    qDebug() << "Usuario: " << usuario;
    query.prepare("select id_persona from persona where id_usuario='" + usuario + "'");
    query.exec();
    query.next();
    idPer = query.value(0).toString();
    qDebug() << "idPer: " << idPer;

    query1.prepare("select id_empleado from empleado where id_persona='" + idPer + "'");
    query1.exec();
    query1.next();
    idEmp = query1.value(0).toString();
    qDebug() << "idEmp: " << idEmp;

    solicitudesMedico.setIdEmpleado(idEmp);
    solicitudesMedico.setIdPersona(idPer);
    solicitudesMedico.inicializar();
    ui->stackedWidget->setCurrentIndex(10);
}

void MainWindow::on_btn_gestionar_citas_clicked()
{
    ui->stackedWidget->setCurrentIndex(12);
}

void MainWindow::on_btn_informacion_medico_clicked()
{
    ui->stackedWidget->setCurrentIndex(18);
}

void MainWindow::on_btn_horario_medico_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(17);
}

void MainWindow::on_btn_citas_clicked()
{
    ui->stackedWidget->setCurrentIndex(19);
}

void MainWindow::on_btn_recetas_medico_clicked()
{
    ui->stackedWidget->setCurrentIndex(11);
    this->generarReceta.inicializarCatalogo();
}

void MainWindow::on_btn_horarios_medicos_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);
}

void MainWindow::on_btn_salir_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->stackedWidget_2->setCurrentIndex(0);
    //    void MainWindow::on_btnCobroEstancia_clicked() quesesto?
    //    {
    //        ui->stackedWidget->setCurrentIndex(20);
    //    }
}

void MainWindow::on_realizarVenta_clicked()
{
    ui->stackedWidget->setCurrentIndex(23);
}

void MainWindow::on_btn_remedios_caseros_clicked()
{

    ui->stackedWidget->setCurrentIndex(24);
}
