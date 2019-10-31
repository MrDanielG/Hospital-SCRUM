#ifndef ADMINISTRADOR_INFO_SERVICIOS_H
#define ADMINISTRADOR_INFO_SERVICIOS_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
namespace Ui {
class administrador_info_servicios;
}

class administrador_info_servicios : public QDialog
{
    Q_OBJECT

public:
    explicit administrador_info_servicios(QString, QString, QString, QString, QWidget *parent = nullptr);
    ~administrador_info_servicios();

private slots:
    void on_btn_modificar_clicked();

private:
    Ui::administrador_info_servicios *ui;
    QSqlDatabase mDatabase;
    QString id, servicio, info, foto;
};

#endif // ADMINISTRADOR_INFO_SERVICIOS_H
