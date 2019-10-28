#ifndef ADMINISTRADOR_CREAR_TIPS_H
#define ADMINISTRADOR_CREAR_TIPS_H

#include <QDialog>

namespace Ui {
class administrador_crear_tips;
}

class administrador_crear_tips : public QDialog
{
    Q_OBJECT

public:
    explicit administrador_crear_tips(QWidget *parent = nullptr);
    ~administrador_crear_tips();

private:
    Ui::administrador_crear_tips *ui;
};

#endif // ADMINISTRADOR_CREAR_TIPS_H
