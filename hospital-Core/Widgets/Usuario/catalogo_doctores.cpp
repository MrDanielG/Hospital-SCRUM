#include "catalogo_doctores.h"
#include "ui_catalogo_doctores.h"
#include <QSqlQuery>
#include "Widgets/Usuario/tarjeta_doctor.h"
#include "Clases/doctor.h"

catalogo_doctores::catalogo_doctores(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::catalogo_doctores)
{
    ui->setupUi(this);

    QSqlQuery query(mDatabase);
    query.prepare("select * from info where id_tipo_info = 3");
    query.exec();

    int i=0;
    int row = 0;
    int col = 0;



       //aqui se ponen los valores de la query
        QString foto = "C:/Users/Angel/Documents/Escuela/5toSemestre/SoftwareEngineer2/Hospital-SCRUM/hospital-Core/Imagenes/imgcircular.png";
        QString nombre = "Angel Genis";
        QString especialidad = "Cirujano";
        int estrellas = 5;

        for(int j=0; j<13; j++){
            row = i/4;
            col= i%4;

            tarjeta_doctor *tarjeta = new tarjeta_doctor(foto, nombre, especialidad, estrellas);
            i++;
            ui->gridLayout->addWidget(tarjeta, row, col);
        }





}

catalogo_doctores::~catalogo_doctores()
{
    delete ui;
}
