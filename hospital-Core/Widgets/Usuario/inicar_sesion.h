#ifndef INICAR_SESION_H
#define INICAR_SESION_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>

namespace Ui {
class inicar_sesion;
}

class inicar_sesion : public QDialog
{
    Q_OBJECT

public:
    explicit inicar_sesion(QWidget *parent = nullptr);
    ~inicar_sesion();
    int getindex();

private slots:
    void on_btn_iniciarsesion_sesion_clicked();

private:
    Ui::inicar_sesion *ui;
    QSqlDatabase mDatabase;
    int tipodeusuario;

};

#endif // INICAR_SESION_H
