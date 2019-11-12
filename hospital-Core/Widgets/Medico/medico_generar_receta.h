#ifndef MEDICO_GENERAR_RECETA_H
#define MEDICO_GENERAR_RECETA_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
namespace Ui {
class medico_generar_receta;
}

class medico_generar_receta : public QWidget
{
    Q_OBJECT

public:
    explicit medico_generar_receta(QWidget *parent = nullptr);
    ~medico_generar_receta();
    void inicializarCatalogo();
    void setUsuario(QString);
private slots:
    void on_btn_agregar_clicked();

private:
    Ui::medico_generar_receta *ui;
    QSqlDatabase mDatabase;
    QString idUsuario;
    QString idMedico;
};

#endif // MEDICO_GENERAR_RECETA_H
