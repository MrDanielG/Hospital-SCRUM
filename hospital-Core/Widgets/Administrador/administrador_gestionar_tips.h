#ifndef ADMINISTRADOR_GESTIONAR_TIPS_H
#define ADMINISTRADOR_GESTIONAR_TIPS_H

#include <QWidget>

namespace Ui {
class administrador_gestionar_tips;
}

class administrador_gestionar_tips : public QWidget
{
    Q_OBJECT

public:
    explicit administrador_gestionar_tips(QWidget *parent = nullptr);
    ~administrador_gestionar_tips();

private:
    Ui::administrador_gestionar_tips *ui;
};

#endif // ADMINISTRADOR_GESTIONAR_TIPS_H
