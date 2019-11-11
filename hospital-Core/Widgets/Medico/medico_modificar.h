#ifndef MEDICO_MODIFICAR_H
#define MEDICO_MODIFICAR_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QMessageBox>

namespace Ui {
class medico_modificar;
}

class medico_modificar : public QDialog
{
    Q_OBJECT

public:
    explicit medico_modificar(QString id, QWidget *parent = nullptr);
    ~medico_modificar();
    void insertarDatos(QString experiencia, QString logros, QString estudios, QString cedula, QString nombre,
                       QString paterno, QString materno, QString correo, QString foto, QString direccion,
                       QString contrasenia, QString mascota);

private slots:
    void on_pushButton_2_clicked();

    void on_btnModificarDatos_clicked();

    void on_btnFoto_clicked();

private:
    Ui::medico_modificar *ui;
    QSqlDatabase mDatabase;
    QString id;
    QString Foto;

};

#endif // MEDICO_MODIFICAR_H
