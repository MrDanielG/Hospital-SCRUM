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

private:
    Ui::farmaceutico_medicamentos *ui;
    QSqlDatabase mDatabase;
};

#endif // FARMACEUTICO_MEDICAMENTOS_H
