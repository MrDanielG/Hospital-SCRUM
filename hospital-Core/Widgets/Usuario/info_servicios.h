#ifndef INFO_SERVICIOS_H
#define INFO_SERVICIOS_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>

namespace Ui {
class info_servicios;
}

class info_servicios : public QDialog
{
    Q_OBJECT

public:
    explicit info_servicios(QString, QWidget *parent = nullptr);
    ~info_servicios();
    void insertarDatos(QString nombre, QString imagen, QString descripcion);

private:
    Ui::info_servicios *ui;
    QSqlDatabase mDatabase;
    QString idinfo;

};

#endif // INFO_SERVICIOS_H
