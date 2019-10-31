#include "recuperar_contra.h"
#include "ui_recuperar_contra.h"

recuperar_contra::recuperar_contra(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::recuperar_contra)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
}

recuperar_contra::~recuperar_contra(){
    delete ui;
}
