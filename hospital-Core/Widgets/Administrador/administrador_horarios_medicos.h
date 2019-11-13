#ifndef ADMINISTRADOR_HORARIOS_MEDICOS_H
#define ADMINISTRADOR_HORARIOS_MEDICOS_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
namespace Ui {
class administrador_horarios_medicos;
}

class administrador_horarios_medicos : public QWidget
{
    Q_OBJECT

public:
    explicit administrador_horarios_medicos(QWidget *parent = nullptr);
    ~administrador_horarios_medicos();
    void limiparCatalogo();
    void inicializarCatalogo();
private slots:
    void on_comboBox_ID_currentIndexChanged(int index);

    void on_dateEdit_userDateChanged(const QDate &date);

private:
    Ui::administrador_horarios_medicos *ui;
    QSqlDatabase mDatabase;
};

#endif // ADMINISTRADOR_HORARIOS_MEDICOS_H
