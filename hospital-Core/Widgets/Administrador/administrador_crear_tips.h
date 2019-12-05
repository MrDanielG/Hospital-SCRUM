#ifndef ADMINISTRADOR_CREAR_TIPS_H
#define ADMINISTRADOR_CREAR_TIPS_H

#include <QDialog>
#include <QSqlDatabase>

namespace Ui {
class administrador_crear_tips;
}

class administrador_crear_tips : public QDialog
{
    Q_OBJECT

public:
    explicit administrador_crear_tips(QWidget *parent = nullptr);
    ~administrador_crear_tips();

private slots:
    void on_btn_crear_2_clicked();

    void on_btn_crear_clicked();

    void on_btn_cancelar_clicked();

private:
    Ui::administrador_crear_tips *ui;
    QSqlDatabase mDatabase;
    QString imagen;
};

#endif // ADMINISTRADOR_CREAR_TIPS_H
