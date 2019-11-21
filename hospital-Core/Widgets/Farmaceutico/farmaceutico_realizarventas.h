#ifndef FARMACEUTICO_REALIZARVENTAS_H
#define FARMACEUTICO_REALIZARVENTAS_H


#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QMessageBox>
#include <QDate>
#include <QTextDocument>
#include <QPrinter>
#include <QDesktopServices>

#include "Widgets/Farmaceutico/farmaceutico_tarjeta_medicamento_venta.h"
#include "Widgets/Farmaceutico/farmaceutico_tarjetasventasencola.h"

namespace Ui {
class farmaceutico_realizarVentas;
}

class farmaceutico_realizarVentas : public QWidget
{
    Q_OBJECT

public:
    explicit farmaceutico_realizarVentas(QWidget *parent = nullptr);
    ~farmaceutico_realizarVentas();
    void limpiarCatalogo();
    void limpiarCatalogo2();
    void insertarVentas(QString);
    void imprimirTicket(QString total, QString efectivo, QString cambio);
    void insertarTotal(float, QString, int);

private slots:
    void on_BuscarMedicamento_textChanged(const QString &arg1);

    void on_btnRealizarVentas_clicked();

private:
    Ui::farmaceutico_realizarVentas *ui;
    QSqlDatabase mDatabase;
    int i = 0;
    float Total = 0;
    int cant = 0;
    QString id = "";
    QStringList ides;
    QStringList cants;
};

#endif // FARMACEUTICO_REALIZARVENTAS_H
