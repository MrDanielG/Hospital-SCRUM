#ifndef ADMINISTRADOR_HORARIOS_MEDICOS_H
#define ADMINISTRADOR_HORARIOS_MEDICOS_H

#include <QWidget>

namespace Ui {
class administrador_horarios_medicos;
}

class administrador_horarios_medicos : public QWidget
{
    Q_OBJECT

public:
    explicit administrador_horarios_medicos(QWidget *parent = nullptr);
    ~administrador_horarios_medicos();

private:
    Ui::administrador_horarios_medicos *ui;
};

#endif // ADMINISTRADOR_HORARIOS_MEDICOS_H
