#ifndef ADMINISTRADOR_VISUALIZAR_JUSTIFICACION_STAFF_H
#define ADMINISTRADOR_VISUALIZAR_JUSTIFICACION_STAFF_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>

namespace Ui {
class administrador_visualizar_justificacion_staff;
}

class administrador_visualizar_justificacion_staff : public QDialog
{
    Q_OBJECT

public:
    explicit administrador_visualizar_justificacion_staff(QString id, QString nombre, QString motivo, QWidget *parent = nullptr);
    ~administrador_visualizar_justificacion_staff();
    void insertarDatos();

private slots:
    void on_pbtn_cancelar_clicked();

    void on_pbtn_aprobar_clicked();

private:
    Ui::administrador_visualizar_justificacion_staff *ui;
    QSqlDatabase mDatabase;
    QString id, nombre, motivo;
};

#endif // ADMINISTRADOR_VISUALIZAR_JUSTIFICACION_STAFF_H
