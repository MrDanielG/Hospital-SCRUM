#ifndef CATALOGO_DOCTORES_H
#define CATALOGO_DOCTORES_H

#include <QWidget>

namespace Ui {
class catalogo_doctores;
}

class catalogo_doctores : public QWidget
{
    Q_OBJECT

public:
    explicit catalogo_doctores(QWidget *parent = nullptr);
    ~catalogo_doctores();

private:
    Ui::catalogo_doctores *ui;
};

#endif // CATALOGO_DOCTORES_H
