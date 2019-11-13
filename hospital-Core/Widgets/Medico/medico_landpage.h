#ifndef MEDICO_LANDPAGE_H
#define MEDICO_LANDPAGE_H

#include <QWidget>

namespace Ui {
class medico_landPage;
}

class medico_landPage : public QWidget
{
    Q_OBJECT

public:
    explicit medico_landPage(QWidget *parent = nullptr);
    ~medico_landPage();

private:
    Ui::medico_landPage *ui;

};

#endif // MEDICO_LANDPAGE_H
