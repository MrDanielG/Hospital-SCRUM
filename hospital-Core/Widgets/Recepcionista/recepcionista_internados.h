#ifndef RECEPCIONISTA_INTERNADOS_H
#define RECEPCIONISTA_INTERNADOS_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>

namespace Ui {
class recepcionista_internados;
}

class recepcionista_internados : public QWidget
{
    Q_OBJECT

public:
    explicit recepcionista_internados(QWidget *parent = nullptr);
    ~recepcionista_internados();
    void limiparCatalogo();
    void actualizarCatalogo();
    void insertaPaciente(QString idPaciente);
    void insertaMedico(QString idPaciente);

private slots:
    void on_btn_agregar_internado_clicked();

    void on_btn_cancelar_internado_clicked();

    void on_btn_agregar_internado_2_clicked();

private:
    Ui::recepcionista_internados *ui;
    QSqlDatabase mDatabase;
};

#endif // RECEPCIONISTA_INTERNADOS_H
