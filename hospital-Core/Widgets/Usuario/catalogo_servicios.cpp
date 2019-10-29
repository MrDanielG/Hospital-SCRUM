#include "catalogo_servicios.h"
#include "ui_catalogo_servicios.h"
#include "Widgets/Usuario/tarjeta_servicios.h"

Catalogo_servicios::Catalogo_servicios(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Catalogo_servicios)
{
    ui->setupUi(this);
    int i=0;
    int row = 0;
    int col = 0;


   //aqui se ponen los valores de la query
    QString foto = "C:/Users/Angel/Documents/Escuela/5toSemestre/SoftwareEngineer2/Hospital-SCRUM/hospital-Core/Imagenes/imgServicio1.png";
    QString nombre = "Angel Genis";

    for(int j=0; j<10; j++){
        row = i/4;
        col= i%4;

        Tarjeta_Servicios *tarjeta = new Tarjeta_Servicios(foto, nombre);
        tarjeta->insertarDatos();
        i++;
        ui->gridLayoutServicios->addWidget(tarjeta, row, col);
    }

}

Catalogo_servicios::~Catalogo_servicios()
{
    delete ui;
}
