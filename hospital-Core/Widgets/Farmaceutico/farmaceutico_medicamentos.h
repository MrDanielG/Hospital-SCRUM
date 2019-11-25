#ifndef FARMACEUTICO_MEDICAMENTOS_H
#define FARMACEUTICO_MEDICAMENTOS_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>

namespace Ui {
class farmaceutico_medicamentos;
}

class farmaceutico_medicamentos : public QWidget
{
    Q_OBJECT

public:
    explicit farmaceutico_medicamentos(QWidget *parent = nullptr);
    ~farmaceutico_medicamentos();
    void limiparCatalogo();

private slots:
    void on_buscar_medicamento_LE_textChanged(const QString &arg1);

    void on_btn_agregar_medicamento_clicked();

private:
    Ui::farmaceutico_medicamentos *ui;
    QSqlDatabase mDatabase;
};

#endif // FARMACEUTICO_MEDICAMENTOS_H
