#ifndef CATALOGO_SERVICIOS_H
#define CATALOGO_SERVICIOS_H

#include <QWidget>

namespace Ui {
class Catalogo_servicios;
}

class Catalogo_servicios : public QWidget
{
    Q_OBJECT

public:
    explicit Catalogo_servicios(QWidget *parent = nullptr);
    ~Catalogo_servicios();

private:
    Ui::Catalogo_servicios *ui;
};

#endif // CATALOGO_SERVICIOS_H
