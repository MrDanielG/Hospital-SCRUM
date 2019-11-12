#ifndef MEDICO_GENERAR_RECETA_H
#define MEDICO_GENERAR_RECETA_H

#include <QWidget>

namespace Ui {
class medico_generar_receta;
}

class medico_generar_receta : public QWidget
{
    Q_OBJECT

public:
    explicit medico_generar_receta(QWidget *parent = nullptr);
    ~medico_generar_receta();

private:
    Ui::medico_generar_receta *ui;
};

#endif // MEDICO_GENERAR_RECETA_H
