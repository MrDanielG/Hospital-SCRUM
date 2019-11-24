#ifndef ADMINISTRADOR_CATALOGO_REMEDIOS_H
#define ADMINISTRADOR_CATALOGO_REMEDIOS_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
namespace Ui {
class administrador_catalogo_remedios;
}

class administrador_catalogo_remedios : public QWidget
{
    Q_OBJECT

public:
    explicit administrador_catalogo_remedios(QWidget *parent = nullptr);
    ~administrador_catalogo_remedios();
    void limpiarCatalogo();
    void actualizarCatalogo();

private:
    Ui::administrador_catalogo_remedios *ui;
    QSqlDatabase mDatabase;
};

#endif // ADMINISTRADOR_CATALOGO_REMEDIOS_H
