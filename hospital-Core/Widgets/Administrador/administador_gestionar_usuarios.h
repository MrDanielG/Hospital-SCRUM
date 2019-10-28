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

private:
    Ui::administador_gestionar_usuarios *ui;
    QSqlDatabase mDatabase;
};

#endif // ADMINISTADOR_GESTIONAR_USUARIOS_H
