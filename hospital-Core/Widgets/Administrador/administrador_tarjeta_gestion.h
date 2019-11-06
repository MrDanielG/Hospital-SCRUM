#ifndef ADMINISTRADOR_TARJETA_GESTION_H
#define ADMINISTRADOR_TARJETA_GESTION_H

#include <QWidget>
#include <QSqlDatabase>
class administrador_gestionar_usuarios;
namespace Ui {
class administrador_tarjeta_gestion;
}

class administrador_tarjeta_gestion : public QWidget
{
    Q_OBJECT

public:
    explicit administrador_tarjeta_gestion(QString, QString, QString, QWidget *parent = nullptr);
    ~administrador_tarjeta_gestion();
    void setPadre(administrador_gestionar_usuarios );
private slots:
    void on_btn_gestionar_clicked();

private:
    Ui::administrador_tarjeta_gestion *ui;
    QSqlDatabase mDatabase;
    QString id;
    QString nombre;
    QString img;
    administrador_gestionar_usuarios *padre;
};

#endif // ADMINISTRADOR_TARJETA_GESTION_H
