#ifndef RECEPCION_TARJETA_CITAS_H
#define RECEPCION_TARJETA_CITAS_H

#include <QWidget>

namespace Ui {
class recepcion_tarjeta_citas;
}

class recepcion_tarjeta_citas : public QWidget
{
    Q_OBJECT

public:
    explicit recepcion_tarjeta_citas(QWidget *parent = nullptr);
    ~recepcion_tarjeta_citas();
    void insertarDatos(QString, QString, QString, QString);

private:
    Ui::recepcion_tarjeta_citas *ui;
};

#endif // RECEPCION_TARJETA_CITAS_H
