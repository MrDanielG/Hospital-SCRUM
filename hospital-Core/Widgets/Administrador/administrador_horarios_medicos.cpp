#include "administrador_horarios_medicos.h"
#include "ui_administrador_horarios_medicos.h"

administrador_horarios_medicos::administrador_horarios_medicos(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::administrador_horarios_medicos)
{
    ui->setupUi(this);
}

administrador_horarios_medicos::~administrador_horarios_medicos()
{
    delete ui;
}
