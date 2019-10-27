#ifndef REGISTRAR_H
#define REGISTRAR_H

#include <QDialog>

namespace Ui {
class registrar;
}

class registrar : public QDialog
{
    Q_OBJECT

public:
    explicit registrar(QWidget *parent = nullptr);
    ~registrar();

private:
    Ui::registrar *ui;
};

#endif // REGISTRAR_H
