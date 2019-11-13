#ifndef RECEPCIONISTA_TARJETA_COBRO_H
#define RECEPCIONISTA_TARJETA_COBRO_H

#include <QWidget>

namespace Ui {
class recepcionista_tarjeta_cobro;
}

class recepcionista_tarjeta_cobro : public QWidget
{
    Q_OBJECT

public:
    explicit recepcionista_tarjeta_cobro(QString, QString, QString, QString, QString, QWidget *parent = nullptr);
    ~recepcionista_tarjeta_cobro();

private:
    Ui::recepcionista_tarjeta_cobro *ui;
    QString idInterno;
};

#endif // RECEPCIONISTA_TARJETA_COBRO_H
