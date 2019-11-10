#ifndef RECEPCIONISTA_AGREGAR_INTERNADO_H
#define RECEPCIONISTA_AGREGAR_INTERNADO_H

#include <QWidget>

namespace Ui {
class recepcionista_agregar_internado;
}

class recepcionista_agregar_internado : public QWidget
{
    Q_OBJECT

public:
    explicit recepcionista_agregar_internado(QWidget *parent = nullptr);
    ~recepcionista_agregar_internado();

private:
    Ui::recepcionista_agregar_internado *ui;
};

#endif // RECEPCIONISTA_AGREGAR_INTERNADO_H
