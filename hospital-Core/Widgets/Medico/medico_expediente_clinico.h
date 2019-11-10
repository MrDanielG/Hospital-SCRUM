#ifndef MEDICO_EXPEDIENTE_CLINICO_H
#define MEDICO_EXPEDIENTE_CLINICO_H

#include <QWidget>

namespace Ui {
class medico_expediente_clinico;
}

class medico_expediente_clinico : public QWidget
{
    Q_OBJECT

public:
    explicit medico_expediente_clinico(QWidget *parent = nullptr);
    ~medico_expediente_clinico();

private:
    Ui::medico_expediente_clinico *ui;
};

#endif // MEDICO_EXPEDIENTE_CLINICO_H
