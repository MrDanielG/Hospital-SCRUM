#ifndef RECEPCIONISTA_COBRAR_ESTANCIA_H
#define RECEPCIONISTA_COBRAR_ESTANCIA_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
namespace Ui {
class recepcionista_cobrar_estancia;
}

class recepcionista_cobrar_estancia : public QWidget
{
    Q_OBJECT

public:
    explicit recepcionista_cobrar_estancia(QWidget *parent = nullptr);
    ~recepcionista_cobrar_estancia();
    void inicializarCatalogo();
    void inicializarRececta(QString);
private slots:
    void on_spinBoxCosto_valueChanged(int arg1);

private:
    Ui::recepcionista_cobrar_estancia *ui;
    QSqlDatabase mDatabase;
    QString idInternado;
    QString idMedico;
    QString nombreMedico;
    QString nombrePaciente;
    QString fechaInicio;
    QString habitacion;
};

#endif // RECEPCIONISTA_COBRAR_ESTANCIA_H
