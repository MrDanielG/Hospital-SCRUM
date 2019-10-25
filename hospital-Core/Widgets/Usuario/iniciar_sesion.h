#ifndef INICIAR_SESION_H
#define INICIAR_SESION_H

#include <QWidget>

namespace Ui {
class iniciar_sesion;
}

class iniciar_sesion : public QWidget
{
    Q_OBJECT

public:
    explicit iniciar_sesion(QWidget *parent = nullptr);
    ~iniciar_sesion();

private:
    Ui::iniciar_sesion *ui;
};

#endif // INICIAR_SESION_H
