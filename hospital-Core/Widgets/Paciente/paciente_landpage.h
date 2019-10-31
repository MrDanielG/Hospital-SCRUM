#ifndef PACIENTE_LANDPAGE_H
#define PACIENTE_LANDPAGE_H

#include <QWidget>

namespace Ui {
class paciente_landpage;
}

class paciente_landpage : public QWidget
{
    Q_OBJECT

public:
    explicit paciente_landpage(QWidget *parent = nullptr);
    ~paciente_landpage();

private:
    Ui::paciente_landpage *ui;
};

#endif // PACIENTE_LANDPAGE_H
