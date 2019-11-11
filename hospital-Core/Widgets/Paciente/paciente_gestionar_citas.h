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
private slots:
    void on_btn_agenda_cita_clicked();

    void on_comboMedicos_activated(const QString &arg1);

private:
    Ui::paciente_gestionar_citas *ui;
    QSqlDatabase mDatabase;
    QString idUsuarioPaciente;
    QString idDoc;
};

#endif // PACIENTE_GESTIONAR_CITAS_H
