#ifndef MEDICO_SOLICITUDES_H
#define MEDICO_SOLICITUDES_H

#include <QWidget>

namespace Ui {
class medico_solicitudes;
}

class medico_solicitudes : public QWidget
{
    Q_OBJECT

public:
    explicit medico_solicitudes(QWidget *parent = nullptr);
    ~medico_solicitudes();

private:
    Ui::medico_solicitudes *ui;
};

#endif // MEDICO_SOLICITUDES_H
