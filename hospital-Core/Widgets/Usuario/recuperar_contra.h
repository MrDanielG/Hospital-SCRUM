#ifndef RECUPERAR_CONTRA_H
#define RECUPERAR_CONTRA_H

#include <QDialog>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>

namespace Ui {
class recuperar_contra;
}

class recuperar_contra : public QDialog
{
    Q_OBJECT

public:
    explicit recuperar_contra(QWidget *parent = nullptr);
    ~recuperar_contra();

private slots:
    void on_btn_continuar_clicked();

    void on_btn_enviar_clicked();

    void on_btn_hecho_clicked();

private:
    Ui::recuperar_contra *ui;
    QSqlDatabase mDatabase;
    QString curpob;
    QString userid;
    QString id_us;
    QString pass;
};

#endif // RECUPERAR_CONTRA_H
