#ifndef RECEPCIONISTA_TARJETA_MEDICOS_INTERNADO_H
#define RECEPCIONISTA_TARJETA_MEDICOS_INTERNADO_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>

class recepcionista_internados;
namespace Ui {
class recepcionista_tarjeta_medicos_internado;
}

class recepcionista_tarjeta_medicos_internado : public QWidget
{
    Q_OBJECT

public:
    explicit recepcionista_tarjeta_medicos_internado(QString idpersona, QString idmedico, QString nombre, QString paterno, QString materno, QString calificacion, QString foto, QString especialidad, recepcionista_internados *parent = nullptr);
    ~recepcionista_tarjeta_medicos_internado();
    void insertarDatos();

private slots:
    void on_btn_visualizar_clicked();

private:
    Ui::recepcionista_tarjeta_medicos_internado *ui;
    QSqlDatabase mDatabase;
    recepcionista_internados *padre;
    QString nombre, especialidad, foto, idpersona, idmedico, paterno, materno, calificacion;
};

#endif // RECEPCIONISTA_TARJETA_MEDICOS_INTERNADO_H
