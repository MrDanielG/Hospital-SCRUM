#ifndef MEDICO_MODIFICAR_H
#define MEDICO_MODIFICAR_H

#include <QDialog>

namespace Ui {
class medico_modificar;
}

class medico_modificar : public QDialog
{
    Q_OBJECT

public:
    explicit medico_modificar(QWidget *parent = nullptr);
    ~medico_modificar();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::medico_modificar *ui;
};

#endif // MEDICO_MODIFICAR_H
