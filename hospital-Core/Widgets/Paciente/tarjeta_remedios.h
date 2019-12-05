#ifndef TARJETA_REMEDIOS_H
#define TARJETA_REMEDIOS_H

#include <QWidget>

namespace Ui {
class tarjeta_remedios;
}

class tarjeta_remedios : public QWidget
{
    Q_OBJECT

public:
    explicit tarjeta_remedios(QWidget *parent = nullptr);
    ~tarjeta_remedios();
    void insertarDatos(QString, QString, QString, QString);

private:
    Ui::tarjeta_remedios *ui;
    QString id;
};

#endif // TARJETA_REMEDIOS_H
