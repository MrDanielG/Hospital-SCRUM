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
    ui->stackedWidget->insertWidget(10,&solicitudesMedico);
    ui->stackedWidget->insertWidget(15,&cancelacionCatalogoAdmin);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setindex(int index){
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
    horarioMedico.setIdUsuario(this->datosLogin.nombre_usuario);
    qDebug()<<"DATOS LOGIN";
    qDebug()<<this->datosLogin.nombre_usuario;
    qDebug()<<this->datosLogin.passwd;

    this->index = dialogo_iniciar_sesion.getindex(); //Retorno tipo de usuario a MainWindow para abrir interfaz correcta

    /*Aqui deben poner el index del landpage al que quieran visualizar
     * 1 = Medico
     * 2 = Paciente
     * 3 = Administrador
     * 4 = Farmaceutico
     * 5 = Staff
     *
     * esto se hace para todos los else if dependiendo el caso
    */

    if(this->index == 1){
        ui->stackedWidget->setCurrentIndex(8);
        ui->stackedWidget_2->setCurrentIndex(2);

    }
    else if(this->index == 2){
        ui->stackedWidget->setCurrentIndex(7);
        ui->stackedWidget_2->setCurrentIndex(3);
    }
    else if(this->index == 3){
        ui->stackedWidget->setCurrentIndex(1);
        //Aqui se cambia el index del navegador, se hace lo mismo para todos
        ui->stackedWidget_2->setCurrentIndex(1);
    }
    else if(this->index == 4){

    }
    else if(this->index == 5){

    }
    qDebug()<<"usuario"<<dialogo_iniciar_sesion.getUsuario();
}

void MainWindow::on_btn_registrarse_clicked(){
    registrar dialogo_registro;
    dialogo_registro.exec();
}

void MainWindow::on_btn_doctores_info_clicked(){
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
    qDebug()<<"Aun no la haces prro";
}

void MainWindow::on_btn_gestionar_servicios_admin_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
    //QWidget *ptr = ui->stackedWidget->widget(4);
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
}

void MainWindow::on_btn_solicitudes_medico_clicked()
{
    QString usuario= dialogo_iniciar_sesion.getUsuario(),idPer,idEmp,idMed;

    QSqlQuery query(mDatabase);
    QSqlQuery query1(mDatabase);
    QSqlQuery query2(mDatabase);
    qDebug()<<"Usuario: "<<usuario;
    query.prepare("select id_persona from persona where id_usuario='"+usuario+"'");
    query.exec();
    query.next();
    idPer=query.value(0).toString();
    qDebug()<<"idPer: " <<idPer;

    query1.prepare("select id_empleado from empleado where id_persona='"+idPer+"'");
    query1.exec();
    query1.next();
    idEmp=query1.value(0).toString();
    qDebug()<<"idEmp: " <<idEmp;

    query2.prepare("SELECT id_medico FROM medico WHERE id_empleado = '"+idEmp+"'");
    query2.exec();
    query2.next();
    idMed=query2.value(0).toString();

    qDebug()<<"idMedico: "<<idMed;


    solicitudesMedico.setIdMedico(idMed);
    solicitudesMedico.inicializar();
    ui->stackedWidget->setCurrentIndex(10);
}
