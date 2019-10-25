#ifndef INICAR_SESION_H
#define INICAR_SESION_H

#include <QDialog>

namespace Ui {
class inicar_sesion;
}

class inicar_sesion : public QDialog
{
    Q_OBJECT

public:
    explicit inicar_sesion(QWidget *parent = nullptr);
    ~inicar_sesion();

private:
    Ui::inicar_sesion *ui;
};

#endif // INICAR_SESION_H
