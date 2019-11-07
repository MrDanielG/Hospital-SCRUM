#ifndef ADMINISTADOR_GESTIONAR_USUARIOS_H
#define ADMINISTADOR_GESTIONAR_USUARIOS_H

#include <QWidget>
#include <QSqlDatabase>
namespace Ui {
class administador_gestionar_usuarios;
}

class administador_gestionar_usuarios : public QWidget
{
    Q_OBJECT

public:
    explicit administador_gestionar_usuarios(QWidget *parent = nullptr);
    ~administador_gestionar_usuarios();
    void limiparCatalogo();
    void hola();

private slots:
    void on_btn_medicos_clicked();

    void on_btn_pacientes_clicked();

    void on_btn_staff_clicked();

    void on_buscar_textChanged(const QString &arg1);

    void on_btn_registra_usuario_clicked();

private:
    Ui::administador_gestionar_usuarios *ui;
    QSqlDatabase mDatabase;
};

#endif // ADMINISTADOR_GESTIONAR_USUARIOS_H
