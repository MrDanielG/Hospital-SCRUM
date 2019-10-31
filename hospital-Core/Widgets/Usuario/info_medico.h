#ifndef INFO_MEDICO_H
#define INFO_MEDICO_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include "Widgets/Usuario/tarjeta_doctor.h"

namespace Ui {
class info_medico;
}

class info_medico : public QDialog
{
    Q_OBJECT

public:
    explicit info_medico(QString, QWidget *parent = nullptr);
    ~info_medico();
    void insertarDatos(QString, QString, QString, QString, QString, QString);
     void insertarDatosMedico(QString, QString, QString);


private:
    Ui::info_medico *ui;
    QSqlDatabase mDatabase;
    QString idinfo;
    QString idpersona;
};

#endif // INFO_MEDICO_H
