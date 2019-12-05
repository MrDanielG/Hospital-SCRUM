#ifndef USUARIO_TIP_H
#define USUARIO_TIP_H

#include <QDialog>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QDebug>

namespace Ui {
class usuario_tip;
}

class usuario_tip : public QDialog
{
    Q_OBJECT

public:
    explicit usuario_tip(QWidget *parent = nullptr);
    ~usuario_tip();
    void insertarDatos(QString ,QString , QString, QString);

private:
    Ui::usuario_tip *ui;
    QString id;
    QSqlDatabase mDatabase;
};

#endif // USUARIO_TIP_H
