#ifndef FARMACEUTICO_LANDPAGE_H
#define FARMACEUTICO_LANDPAGE_H

#include <QWidget>

namespace Ui {
class farmaceutico_landpage;
}

class farmaceutico_landpage : public QWidget
{
    Q_OBJECT

public:
    explicit farmaceutico_landpage(QWidget *parent = nullptr);
    ~farmaceutico_landpage();

private:
    Ui::farmaceutico_landpage *ui;
};

#endif // FARMACEUTICO_LANDPAGE_H
