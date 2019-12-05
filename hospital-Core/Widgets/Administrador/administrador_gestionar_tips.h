#ifndef ADMINISTRADOR_GESTIONAR_TIPS_H
#define ADMINISTRADOR_GESTIONAR_TIPS_H

#include <QWidget>
#include <QSqlDatabase>

namespace Ui {
class administrador_gestionar_tips;
}

class administrador_gestionar_tips : public QWidget
{
    Q_OBJECT

public:
    explicit administrador_gestionar_tips(QWidget *parent = nullptr);
    ~administrador_gestionar_tips();
    void limpia();
    void inicializarCatalogo();

private slots:
    void on_btn_registra_tip_clicked();

private:
    Ui::administrador_gestionar_tips *ui;
    QSqlDatabase mDatabase;
};

#endif // ADMINISTRADOR_GESTIONAR_TIPS_H
