#ifndef PACIENTE_GESTIONAR_CITAS_H
#define PACIENTE_GESTIONAR_CITAS_H

#include <QWidget>

namespace Ui {
class paciente_gestionar_citas;
}

class paciente_gestionar_citas : public QWidget
{
    Q_OBJECT

public:
    explicit paciente_gestionar_citas(QWidget *parent = nullptr);
    ~paciente_gestionar_citas();

private:
    Ui::paciente_gestionar_citas *ui;
};

#endif // PACIENTE_GESTIONAR_CITAS_H
