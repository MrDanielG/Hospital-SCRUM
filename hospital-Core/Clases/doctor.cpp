#include "doctor.h"

Doctor::Doctor(){

}

Doctor::Doctor(QString fotografia, QString nombre, QString especialidad, int estrellas){
    this->fotografia=fotografia;
    this->nombre = nombre;
    this->especialidad = especialidad;
    this->estrellas = estrellas;
}
