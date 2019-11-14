#ifndef FARMACEUTICO_TARJETASVENTASENCOLA_H
#define FARMACEUTICO_TARJETASVENTASENCOLA_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QMessageBox>

namespace Ui {
class farmaceutico_tarjetasventasencola;
}

class farmaceutico_tarjetasventasencola : public QWidget
{
    Q_OBJECT

public:
    explicit farmaceutico_tarjetasventasencola(QWidget *parent = nullptr);
    ~farmaceutico_tarjetasventasencola();
    void insertarDatos(QString,QString,QString);

private:
    Ui::farmaceutico_tarjetasventasencola *ui;
};

#endif // FARMACEUTICO_TARJETASVENTASENCOLA_H
