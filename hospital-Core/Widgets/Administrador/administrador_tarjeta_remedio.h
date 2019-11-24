#ifndef ADMINISTRADOR_TARJETA_REMEDIO_H
#define ADMINISTRADOR_TARJETA_REMEDIO_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>

class administrador_catalogo_remedios;
namespace Ui {
class administrador_tarjeta_remedio;
}

class administrador_tarjeta_remedio : public QWidget
{
    Q_OBJECT

public:
    explicit administrador_tarjeta_remedio(QString, QString, QString, QString, administrador_catalogo_remedios *parent = nullptr);
    ~administrador_tarjeta_remedio();
    void llenarTarjeta();

private slots:

    void on_btn_modificar_clicked();

    void on_btn_eliminar_clicked();

private:
    Ui::administrador_tarjeta_remedio *ui;
    QSqlDatabase mDatabase;
    administrador_catalogo_remedios *padre;
    QString id;
    QString nombre;
    QString descripcion;
    QString foto;
};

#endif // ADMINISTRADOR_TARJETA_REMEDIO_H
