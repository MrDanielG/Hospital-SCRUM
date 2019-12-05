#ifndef ADMINISTRADOR_JUSTIFICACION_STAFF_H
#define ADMINISTRADOR_JUSTIFICACION_STAFF_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>

namespace Ui {
class administrador_justificacion_staff;
}

class administrador_justificacion_staff : public QWidget
{
    Q_OBJECT

public:
    explicit administrador_justificacion_staff(QWidget *parent = nullptr);
    ~administrador_justificacion_staff();
    void limpiarCatalogo();
    void actualizarCatalogo();

private:
    Ui::administrador_justificacion_staff *ui;
    QSqlDatabase mDatabase;
};

#endif // ADMINISTRADOR_JUSTIFICACION_STAFF_H
