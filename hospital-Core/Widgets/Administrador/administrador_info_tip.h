#ifndef ADMINISTRADOR_INFO_TIP_H
#define ADMINISTRADOR_INFO_TIP_H

#include <QDialog>
#include <QSqlDatabase>

namespace Ui {
class administrador_info_tip;
}

class administrador_info_tip : public QDialog
{
    Q_OBJECT

public:
    explicit administrador_info_tip(QString,QWidget *parent = nullptr);
    ~administrador_info_tip();
    void inicializa();

private slots:
    void on_btn_guardar_clicked();

    void on_btn_cancelar_clicked();

private:
    Ui::administrador_info_tip *ui;
    QSqlDatabase mDatabase;
    QString idTip;
};

#endif // ADMINISTRADOR_INFO_TIP_H
