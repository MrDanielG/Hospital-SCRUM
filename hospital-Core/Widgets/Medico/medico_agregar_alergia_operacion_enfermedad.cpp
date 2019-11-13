#include "medico_agregar_alergia_operacion_enfermedad.h"
#include "ui_medico_agregar_alergia_operacion_enfermedad.h"
#include "QDateTime"
#include "qmessagebox.h"

medico_agregar_alergia_operacion_enfermedad::medico_agregar_alergia_operacion_enfermedad(QString idExpediente,QString tipoInsercion,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::medico_agregar_alergia_operacion_enfermedad)
{
    ui->setupUi(this);

#ifdef Q_OS_WIN
  mDatabase = QSqlDatabase::database("Connection");
#elif defined(Q_OS_MAC)
  mDatabase = QSqlDatabase::database();
  mDatabase.setHostName("localhost");
  mDatabase.setDatabaseName("hospital");
  mDatabase.setUserName("root");
  mDatabase.setPassword("luisdrew1394");
#endif
    if(!mDatabase.isOpen()){
        qDebug() << "ERROR";
    }else{
        qDebug() << "base de datos sigue conectada en MEDICO_AGREGAR_ALERGIA_OPERACION_ENFERMEDAD";
    }

    this->idExpediente=idExpediente;

    if(tipoInsercion=="alergia")
    {
        ui->stackedWidget->setCurrentIndex(2);

    }else {
        if(tipoInsercion=="operacion")
        {
            ui->stackedWidget->setCurrentIndex(1);
            ui->fecha_opercacion->setDate(QDate::currentDate());
        }else
        {
            ui->stackedWidget->setCurrentIndex(0);
        }

    }
}

medico_agregar_alergia_operacion_enfermedad::~medico_agregar_alergia_operacion_enfermedad()
{
    delete ui;
}

void medico_agregar_alergia_operacion_enfermedad::on_btn_cancelar_alergia_clicked()
{
    this->close();
}

void medico_agregar_alergia_operacion_enfermedad::on_btn_cancelar_enfermedad_clicked()
{
    this->close();
}

void medico_agregar_alergia_operacion_enfermedad::on_btn_cancelar_operacion_clicked()
{
    this->close();
}


void medico_agregar_alergia_operacion_enfermedad::on_btn_agregar_alergia_clicked()
{
    QMessageBox info;
    QSqlQuery query(mDatabase);

    if(ui->line_alergia->text()!="")
    {
        QMessageBox msgBox(QMessageBox::Question,"Confimacion","¿Estas seguro de agregar esta alergia?",QMessageBox::Yes|QMessageBox::No);
        msgBox.setButtonText(QMessageBox::Yes,"Sí");
        msgBox.setButtonText(QMessageBox::No,"No");

        if(msgBox.exec()==QMessageBox::Yes)
        {
            query.prepare("INSERT INTO alergias(tipo, id_expediente) VALUES ('"+ui->line_alergia->text()+"','"+this->idExpediente+"')");
            query.exec();
            this->close();
        }

    }else
    {
        info.setWindowTitle("Información");
        info.setText("El campo de la alergia no puede ir vacío.");
        info.setStandardButtons(QMessageBox::Ok);
        info.setDefaultButton(QMessageBox::Ok);
        info.setButtonText(QMessageBox::Ok,"Aceptar");
        info.exec();
    }
}

void medico_agregar_alergia_operacion_enfermedad::on_btn_agregar_enfermedad_clicked()
{
    QMessageBox info;
    QSqlQuery query(mDatabase);

    if(ui->line_enfermedad->text()!="" && ui->txt_descripcion_enfermedad->toPlainText()!="")
    {
        QMessageBox msgBox(QMessageBox::Question,"Confimacion","¿Estas seguro de agregar esta alergia?",QMessageBox::Yes|QMessageBox::No);
        msgBox.setButtonText(QMessageBox::Yes,"Sí");
        msgBox.setButtonText(QMessageBox::No,"No");

        if(msgBox.exec()==QMessageBox::Yes)
        {
            query.prepare("INSERT INTO enfermedades(tipo, descripcion, id_expediente) VALUES ('"+ui->line_enfermedad->text()+"','"+ui->txt_descripcion_enfermedad->toPlainText()+"','"+this->idExpediente+"')");
            query.exec();
            this->close();
        }

    }else {
        info.setWindowTitle("Información");
        info.setText("Los campos no pueden ir vacios.");
        info.setStandardButtons(QMessageBox::Ok);
        info.setDefaultButton(QMessageBox::Ok);
        info.setButtonText(QMessageBox::Ok,"Aceptar");
        info.exec();
    }

}


void medico_agregar_alergia_operacion_enfermedad::on_btn_agregar_operacion_clicked()
{
    QMessageBox info;
    QSqlQuery query(mDatabase);
    QString fecha= QString::number(ui->fecha_opercacion->date().year())+"-"+QString::number(ui->fecha_opercacion->date().month())+"-"+QString::number(ui->fecha_opercacion->date().day());

    if(ui->fecha_opercacion->date()<= QDate::currentDate())
    {
        if(ui->line_operacion->text()!="")
        {
            QMessageBox msgBox(QMessageBox::Question,"Confimacion","¿Estas seguro de agregar esta operación?",QMessageBox::Yes|QMessageBox::No);
            msgBox.setButtonText(QMessageBox::Yes,"Sí");
            msgBox.setButtonText(QMessageBox::No,"No");

            if(msgBox.exec()==QMessageBox::Yes)
            {
                query.prepare("INSERT INTO operaciones(descripcion, fecha, id_expediente) VALUES ('"+ui->line_operacion->text()+"','"+fecha+"','"+this->idExpediente+"')");
                query.exec();
                this->close();
            }
        }else
        {
            info.setWindowTitle("Información");
            info.setText("El campo de operación no puede ir vacío.");
            info.setStandardButtons(QMessageBox::Ok);
            info.setDefaultButton(QMessageBox::Ok);
            info.setButtonText(QMessageBox::Ok,"Aceptar");
            info.exec();
        }

    }else
    {
        info.setWindowTitle("Información");
        info.setText("La fecha de la operación no puede ser futura.");
        info.setStandardButtons(QMessageBox::Ok);
        info.setDefaultButton(QMessageBox::Ok);
        info.setButtonText(QMessageBox::Ok,"Aceptar");
        info.exec();
    }
}
