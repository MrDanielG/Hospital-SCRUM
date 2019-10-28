#ifndef ADMINISTRADOR_LANDPAGE_H
#define ADMINISTRADOR_LANDPAGE_H

#include <QWidget>

namespace Ui {
class administrador_landpage;
}

class administrador_landpage : public QWidget
{
    Q_OBJECT

public:
    explicit administrador_landpage(QWidget *parent = nullptr);
    ~administrador_landpage();

private:
    Ui::administrador_landpage *ui;
};

#endif // ADMINISTRADOR_LANDPAGE_H
