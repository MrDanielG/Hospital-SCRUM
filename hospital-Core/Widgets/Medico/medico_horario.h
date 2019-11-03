#ifndef MEDICO_HORARIO_H
#define MEDICO_HORARIO_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>


namespace Ui {
class medico_horario;
}

class medico_horario : public QWidget
{
    Q_OBJECT

public:
    explicit medico_horario(QWidget *parent = nullptr);
    ~medico_horario();

private:
    Ui::medico_horario *ui;
    QSqlDatabase mDatabase;
};

#endif // MEDICO_HORARIO_H
