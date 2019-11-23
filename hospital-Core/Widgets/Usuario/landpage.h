#ifndef LANDPAGE_H
#define LANDPAGE_H

#include <QWidget>
#include "Widgets/Usuario/registrar.h"

namespace Ui {
class landpage;
}

class landpage : public QWidget
{
    Q_OBJECT

public:
    explicit landpage(QWidget *parent = nullptr);
    ~landpage();

private slots:
    void on_btn_registrarse_clicked();

private:
    Ui::landpage *ui;
};

#endif // LANDPAGE_H
