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
    void limiparCatalogo();
    void setIdUsuario(QString);

private slots:
    void on_pushButton_clicked();

private:
    Ui::medico_horario *ui;
    QSqlDatabase mDatabase;
    QString idUsuario;
    QString medico;
};

#endif // MEDICO_HORARIO_H
