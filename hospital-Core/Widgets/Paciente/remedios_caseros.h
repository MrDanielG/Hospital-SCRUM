#ifndef REMEDIOS_CASEROS_H
#define REMEDIOS_CASEROS_H

#include <QWidget>

namespace Ui {
class remedios_caseros;
}

class remedios_caseros : public QWidget
{
    Q_OBJECT

public:
    explicit remedios_caseros(QWidget *parent = nullptr);
    ~remedios_caseros();

private:
    Ui::remedios_caseros *ui;
};

#endif // REMEDIOS_CASEROS_H
