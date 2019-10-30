#include "tarjeta_doctor.h"
#include "ui_tarjeta_doctor.h"
#include <QDebug>
#include "Widgets/Usuario/info_medico.h"

tarjeta_doctor::tarjeta_doctor(QString foto, QString nombre, QString especialidad, int estrellas, QWidget *parent) : QWidget(parent),
    ui(new Ui::tarjeta_doctor){
    ui->setupUi(this);

    this->foto=foto;
    this->nombre = nombre;
    this->especialidad = especialidad;
    this->estrellas = estrellas;

    ui->estrella1_5->hide();
    ui->estrella1_4->hide();
    ui->estrella1_3->hide();
    ui->estrella1_2->hide();
    ui->estrella1->hide();

    QStringList imagenrecortada = foto.split(" ");
    QPixmap imag(imagenrecortada[0]);

    ui->tarjetadoctor_doctor->setText(nombre);
    ui->fotografia->setPixmap(imag.scaled(100,100, Qt::IgnoreAspectRatio));
    ui->especialidad->setText(especialidad);

    int tamanio = estrellas;

    if(tamanio == 1){
        ui->estrella1->show();
    }
    if(tamanio == 2){
        ui->estrella1_2->show();
        ui->estrella1_3->show();
    }
    if(tamanio == 3){
        ui->estrella1_2->show();
        ui->estrella1_3->show();
        ui->estrella1_4->show();
    }
    if(tamanio == 4){
        ui->estrella1_2->show();
        ui->estrella1_3->show();
        ui->estrella1_4->show();
        ui->estrella1_5->show();
    }
    if(tamanio == 5){
        ui->estrella1_2->show();
        ui->estrella1_3->show();
        ui->estrella1_4->show();
        ui->estrella1_5->show();
        ui->estrella1->show();
    }

}

tarjeta_doctor::~tarjeta_doctor(){
    delete ui;
}


void tarjeta_doctor::on_btn_visualizar_clicked(){
    info_medico visualizarInfo;
    visualizarInfo.exec();
}
