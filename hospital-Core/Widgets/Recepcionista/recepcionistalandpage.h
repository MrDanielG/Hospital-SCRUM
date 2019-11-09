#ifndef RECEPCIONISTALANDPAGE_H
#define RECEPCIONISTALANDPAGE_H

#include <QWidget>

namespace Ui {
class recepcionistaLandpage;
}

class recepcionistaLandpage : public QWidget
{
    Q_OBJECT

public:
    explicit recepcionistaLandpage(QWidget *parent = nullptr);
    ~recepcionistaLandpage();

private:
    Ui::recepcionistaLandpage *ui;
};

#endif // RECEPCIONISTALANDPAGE_H
