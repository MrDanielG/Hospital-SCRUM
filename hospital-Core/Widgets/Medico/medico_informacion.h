#ifndef MEDICO_INFORMACION_H
#define MEDICO_INFORMACION_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>


namespace Ui {
class medico_informacion;
}

class medico_informacion : public QWidget
{
    Q_OBJECT

public:
    explicit medico_informacion(QWidget *parent = nullptr);
    ~medico_informacion();
    void insertarDatos(QString, QString, QString, QString, QString, QString);
    void insertarDatosMedico(QString, QString, QString);
    void setID(QString);

private:
    Ui::medico_informacion *ui;
    QSqlDatabase mDatabase;
    QString idinfo;
    QString idpersona;
};

#endif // MEDICO_INFORMACION_H
