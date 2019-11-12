#ifndef RECEPCIONISTA_COBRAR_ESTANCIA_H
#define RECEPCIONISTA_COBRAR_ESTANCIA_H

#include <QWidget>

namespace Ui {
class recepcionista_cobrar_estancia;
}

class recepcionista_cobrar_estancia : public QWidget
{
    Q_OBJECT

public:
    explicit recepcionista_cobrar_estancia(QWidget *parent = nullptr);
    ~recepcionista_cobrar_estancia();

private:
    Ui::recepcionista_cobrar_estancia *ui;
};

#endif // RECEPCIONISTA_COBRAR_ESTANCIA_H
