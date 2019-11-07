#ifndef ADMINISTRADOR_CATALOGO_CANCELACION_CITA_H
#define ADMINISTRADOR_CATALOGO_CANCELACION_CITA_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>

namespace Ui {
class administrador_catalogo_cancelacion_cita;
}

class administrador_catalogo_cancelacion_cita : public QWidget
{
    Q_OBJECT

public:
    explicit administrador_catalogo_cancelacion_cita(QWidget *parent = nullptr);
    ~administrador_catalogo_cancelacion_cita();
    void limpiarCatalogo();

private:
    Ui::administrador_catalogo_cancelacion_cita *ui;
    QSqlDatabase mDatabase;
};

#endif // ADMINISTRADOR_CATALOGO_CANCELACION_CITA_H
