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

private:
    Ui::administrador_info_servicios *ui;
    QSqlDatabase mDatabase;
};

#endif // ADMINISTRADOR_INFO_SERVICIOS_H
