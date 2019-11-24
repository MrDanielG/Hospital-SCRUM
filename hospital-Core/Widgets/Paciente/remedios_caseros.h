#ifndef REMEDIOS_CASEROS_H
#define REMEDIOS_CASEROS_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include <QDebug>
#include "Widgets/Paciente/tarjeta_remedios.h"

namespace Ui {
class remedios_caseros;
}

class remedios_caseros : public QWidget
{
    Q_OBJECT

public:
    explicit remedios_caseros(QWidget *parent = nullptr);
    ~remedios_caseros();
    void crearCatalogo();
    void limpiarCatalogo();

private slots:
    void on_lineEdit_textChanged(const QString &arg1);

private:
    Ui::remedios_caseros *ui;
    QSqlDatabase mDatabase;
};

#endif // REMEDIOS_CASEROS_H
