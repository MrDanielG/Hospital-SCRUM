#ifndef RECEPCIONISTA_TARJETA_COBRO_H
#define RECEPCIONISTA_TARJETA_COBRO_H

#include <QWidget>
class recepcionista_cobrar_estancia;
namespace Ui {
class recepcionista_tarjeta_cobro;
}

class recepcionista_tarjeta_cobro : public QWidget
{
    Q_OBJECT

public:
    explicit recepcionista_tarjeta_cobro(QString, QString, QString, QString, QString, recepcionista_cobrar_estancia *parent = nullptr);
    ~recepcionista_tarjeta_cobro();

private slots:
    void on_btn_seleccionar_clicked();

private:
    Ui::recepcionista_tarjeta_cobro *ui;
    QString idInterno;
    recepcionista_cobrar_estancia *padre;

};

#endif // RECEPCIONISTA_TARJETA_COBRO_H
