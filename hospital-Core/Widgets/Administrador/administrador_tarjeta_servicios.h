#ifndef ADMINISTRADOR_TARJETA_SERVICIOS_H
#define ADMINISTRADOR_TARJETA_SERVICIOS_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQuery>
namespace Ui {
class administrador_tarjeta_servicios;
}

class administrador_tarjeta_servicios : public QWidget
{
    Q_OBJECT

public:
    explicit administrador_tarjeta_servicios(QString, QString, QString, QWidget *parent = nullptr);
    ~administrador_tarjeta_servicios();

private slots:
    void on_btn_gestionar_clicked();

private:
    Ui::administrador_tarjeta_servicios *ui;
    QSqlDatabase mDatabase;
    QString id, servicio, foto, info;
};

#endif // ADMINISTRADOR_TARJETA_SERVICIOS_H
