#ifndef ADMINISTRADOR_INFO_GESTION_H
#define ADMINISTRADOR_INFO_GESTION_H

#include <QDialog>
#include <QSqlQuery>
namespace Ui {
class administrador_info_gestion;
}

class administrador_info_gestion : public QDialog
{
    Q_OBJECT

public:
    explicit administrador_info_gestion(QString, QString, QString, QString, QString, QString, QString, QWidget *parent = nullptr);
    ~administrador_info_gestion();

private slots:
    void on_btn_eliminar_clicked();

    void on_btn_gestionar_clicked();

private:
    Ui::administrador_info_gestion *ui;
    QSqlDatabase mDatabase;
    QString nombre;
    QString tipo_usr;
    QString info1;
    QString info2;
    QString info3;
    QString id_usr;
};

#endif // ADMINISTRADOR_INFO_GESTION_H
