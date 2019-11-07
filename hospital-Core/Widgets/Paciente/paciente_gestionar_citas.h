#ifndef PACIENTE_GESTIONAR_CITAS_H
#define PACIENTE_GESTIONAR_CITAS_H

#include <QWidget>
#include <QSqlDatabase>
namespace Ui {
class paciente_gestionar_citas;
}

class paciente_gestionar_citas : public QWidget
{
    Q_OBJECT

public:
    explicit paciente_gestionar_citas(QWidget *parent = nullptr);
    ~paciente_gestionar_citas();
    void setIdPaciente(QString);
    void inicalizaCatalogo();
    void limpiarCatalogo();
private:
    Ui::paciente_gestionar_citas *ui;
    QSqlDatabase mDatabase;
    QString idUsuarioPaciente;
};

#endif // PACIENTE_GESTIONAR_CITAS_H
