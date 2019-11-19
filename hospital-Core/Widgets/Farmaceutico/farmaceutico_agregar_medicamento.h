#ifndef FARMACEUTICO_AGREGAR_MEDICAMENTO_H
#define FARMACEUTICO_AGREGAR_MEDICAMENTO_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>

namespace Ui {
class farmaceutico_agregar_medicamento;
}

class farmaceutico_agregar_medicamento : public QDialog
{
    Q_OBJECT

public:
    farmaceutico_agregar_medicamento();
    explicit farmaceutico_agregar_medicamento(QString farmacia, QWidget *parent = nullptr);
    ~farmaceutico_agregar_medicamento();

private slots:
    void on_btn_cancelar_clicked();

    void on_si_checkBox_stateChanged(int arg1);

    void on_no_checkBox_stateChanged(int arg1);

    void on_btn_agregar_medicamento_clicked();

private:
    Ui::farmaceutico_agregar_medicamento *ui;
    QString farmacia;
    QSqlDatabase mDatabase;
};

#endif // FARMACEUTICO_AGREGAR_MEDICAMENTO_H
