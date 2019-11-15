#ifndef PACIENTE_CALIFICA_MEDICO_H
#define PACIENTE_CALIFICA_MEDICO_H

#include <QDialog>
#include <QSqlDatabase>

namespace Ui {
class Paciente_Califica_Medico;
}

class Paciente_Califica_Medico : public QDialog
{
    Q_OBJECT

public:
    explicit Paciente_Califica_Medico(QString med,QWidget *parent = nullptr);
    ~Paciente_Califica_Medico();

private:
    Ui::Paciente_Califica_Medico *ui;
    QSqlDatabase mDatabase;
    QString idMed;
};

#endif // PACIENTE_CALIFICA_MEDICO_H
