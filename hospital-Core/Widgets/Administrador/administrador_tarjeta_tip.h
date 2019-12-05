#ifndef ADMINISTRADOR_TARJETA_TIP_H
#define ADMINISTRADOR_TARJETA_TIP_H

#include <QWidget>
#include <QSqlDatabase>

namespace Ui {
class administrador_tarjeta_tip;
}

class administrador_tarjeta_tip : public QWidget
{
    Q_OBJECT

public:
    explicit administrador_tarjeta_tip(QString,QString,QString,QString,QWidget *parent = nullptr);
    ~administrador_tarjeta_tip();
    void inicializarTarjeta();

private slots:
    void on_btnModificar_clicked();

    void on_btnEliminar_clicked();

private:
    Ui::administrador_tarjeta_tip *ui;
    QSqlDatabase mDatabase;
    QString id, titulo, descripcion, img;
};

#endif // ADMINISTRADOR_TARJETA_TIP_H
