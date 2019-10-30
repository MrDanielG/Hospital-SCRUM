#ifndef CATALOGO_SERVICIOS_H
#define CATALOGO_SERVICIOS_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>

namespace Ui {
class Catalogo_servicios;
}

class Catalogo_servicios : public QWidget
{
    Q_OBJECT

public:
    explicit Catalogo_servicios(QWidget *parent = nullptr);
    ~Catalogo_servicios();

private:
    Ui::Catalogo_servicios *ui;
    QSqlDatabase mDatabase;
};

#endif // CATALOGO_SERVICIOS_H
