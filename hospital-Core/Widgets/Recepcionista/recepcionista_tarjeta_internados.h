#ifndef RECEPCIONISTA_TARJETA_INTERNADOS_H
#define RECEPCIONISTA_TARJETA_INTERNADOS_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QDate>

class recepcionista_internados;
namespace Ui {
class recepcionista_tarjeta_internados;
}

class recepcionista_tarjeta_internados : public QWidget
{
    Q_OBJECT

public:
    explicit recepcionista_tarjeta_internados(QString idPaciente, QString paciente, QString medico, QString habitacion, QDate fecha_fin, QString foto, recepcionista_internados *parent = nullptr);
    ~recepcionista_tarjeta_internados();
    void insertarDatos();

private slots:
    void on_btn_gestionar_internado_clicked();

private:
    Ui::recepcionista_tarjeta_internados *ui;
    QSqlDatabase mDatabase;
    QString idPaciente, paciente, medico, habitacion, foto;
    QDate fecha_fin;
    recepcionista_internados *padre;
};

#endif // RECEPCIONISTA_TARJETA_INTERNADOS_H
