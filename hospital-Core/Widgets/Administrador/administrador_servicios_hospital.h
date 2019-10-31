#ifndef ADMINISTRADOR_SERVICIOS_HOSPITAL_H
#define ADMINISTRADOR_SERVICIOS_HOSPITAL_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
namespace Ui {
class administrador_servicios_hospital;
}

class administrador_servicios_hospital : public QWidget
{
    Q_OBJECT

public:
    explicit administrador_servicios_hospital(QWidget *parent = nullptr);
    ~administrador_servicios_hospital();
    void limiparCatalogo();
    void regargaCatalogo();

private slots:
    void on_btn_crear_servicio_clicked();

private:
    Ui::administrador_servicios_hospital *ui;
    QSqlDatabase mDatabase;
};

#endif // ADMINISTRADOR_SERVICIOS_HOSPITAL_H
