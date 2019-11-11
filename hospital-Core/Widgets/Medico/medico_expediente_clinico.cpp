#include "medico_expediente_clinico.h"
#include "ui_medico_expediente_clinico.h"
#include "QSqlTableModel"
#include "qmessagebox.h"
#include "medico_agregar_alergia_operacion_enfermedad.h"

medico_expediente_clinico::medico_expediente_clinico(QString nombre, QString paterno, QString materno,QString foto,QString idCita,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::medico_expediente_clinico)
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
        qDebug() << "base de datos sigue conectada en MEDICO_EXPEDIENTE_CLINICO";
    }

QSqlQuery query(mDatabase);
query.prepare("SELECT id_medico ,id_paciente FROM cita_medica WHERE id_cita_medica="+idCita);
query.exec();
query.next();

this->idMedico=query.value(0).toString();
this->idPaciente=query.value(1).toString();
this->nombre=nombre+" "+paterno+" "+materno;
this->foto=foto;
this->idExpediente="";
this->idAlergia="";
this->idOperacion="";
this->idEnfermedad="";

qDebug()<<"idCita"<<idCita;
qDebug()<<"idMedico"<<this->idMedico;
qDebug()<<"idPaciente"<<this->idPaciente;

QPixmap imag(this->foto);
ui->lbl_imagen->setPixmap(imag);
ui->lbl_imagen_2->setPixmap(imag);
ui->lbl_nombre->setText(this->nombre);
ui->lbl_nombre_2->setText(this->nombre);
ui->lbl_peso->clear();
ui->lbl_estatura->clear();
ui->lbl_tipoSangre->clear();

ui->stackedWidget->setCurrentIndex(0);

query.prepare("SELECT id_expediente FROM paciente WHERE id_paciente="+this->idPaciente);
query.exec();
query.next();

if(query.value(0).toString()!='0')
{
    this->idExpediente=query.value(0).toString();
}

qDebug()<<"idExpediente"<<this->idExpediente;

if(this->idExpediente=="")
{
    ui->btn_modificarDatos->setVisible(false);

}else
{
    ui->btn_GenerarExpediente->setVisible(false);
    query.prepare("SELECT * FROM expediente WHERE id_expediente="+this->idExpediente);
    query.exec();
    query.next();
    ui->lbl_peso->setText(query.value(1).toString());
    ui->line_peso->setText(query.value(1).toString());
    ui->lbl_estatura->setText(query.value(2).toString());
    ui->line_estatura->setText(query.value(2).toString());
    ui->lbl_tipoSangre->setText(query.value(3).toString());
    ui->line_tipoSangre->setText(query.value(3).toString());
    ui->txt_descripcion->setPlainText(query.value(4).toString());
    ui->txt_descripcion_2->setPlainText(query.value(4).toString());

}


}

medico_expediente_clinico::~medico_expediente_clinico()
{
    delete ui;
}



void medico_expediente_clinico::on_btn_informacion_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void medico_expediente_clinico::on_btn_alergias_clicked()
{
    cargarTablaAlergias();
    ui->stackedWidget->setCurrentIndex(2);
}

void medico_expediente_clinico::on_btn_enfermedad_clicked()
{
    cargarTablaEnfermedades();
    ui->stackedWidget->setCurrentIndex(3);
}

void medico_expediente_clinico::on_btn_operacion_clicked()
{
    cargarTablaOperaciones();
    ui->stackedWidget->setCurrentIndex(4);
}

void medico_expediente_clinico::on_btn_modificarDatos_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void medico_expediente_clinico::on_btn_GenerarExpediente_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void medico_expediente_clinico::cargarTablaAlergias()
{
    ui->table_alergias->setContextMenuPolicy(Qt::ActionsContextMenu);
    modeloAlergias= new QSqlTableModel;
    ui->table_alergias->setModel(modeloAlergias);
    QSqlQuery query(mDatabase);
    query.prepare("SELECT id_alergias, tipo as '        Alergia         ' FROM alergias WHERE id_expediente="+this->idExpediente);
    query.exec();
    modeloAlergias->setQuery(query);
    ui->table_alergias->hideColumn(0);

}

void medico_expediente_clinico::cargarTablaOperaciones()
{
    ui->table_operaciones->setContextMenuPolicy(Qt::ActionsContextMenu);
    modeloOperaciones=new QSqlTableModel;
    ui->table_operaciones->setModel(modeloOperaciones);
    QSqlQuery query(mDatabase);
    query.prepare("SELECT id_operaciones, fecha as 'Fecha', descripcion as 'Operación' FROM operaciones WHERE id_expediente="+this->idExpediente);
    query.exec();
    modeloOperaciones->setQuery(query);
    ui->table_operaciones->hideColumn(0);

}

void medico_expediente_clinico::cargarTablaEnfermedades()
{
    ui->table_enfermedades->setContextMenuPolicy(Qt::ActionsContextMenu);
    modeloEnfermedades=new QSqlTableModel;
    ui->table_enfermedades->setModel(modeloEnfermedades);
    QSqlQuery query(mDatabase);
    query.prepare("SELECT id_enfermedades, tipo as 'Enfermedad', descripcion as 'Descripción' FROM enfermedades WHERE id_expediente="+this->idExpediente);
    query.exec();
    modeloEnfermedades->setQuery(query);
    ui->table_enfermedades->hideColumn(0);
}



void medico_expediente_clinico::on_table_alergias_clicked(const QModelIndex &index)
{
    if(!index.isValid()){
            return;
        }

    this->idAlergia=modeloAlergias->index(index.row(),0).data().toString();
}


void medico_expediente_clinico::on_table_enfermedades_clicked(const QModelIndex &index)
{
    if(!index.isValid()){
            return;
        }

    this->idEnfermedad=modeloEnfermedades->index(index.row(),0).data().toString();
}

void medico_expediente_clinico::on_table_operaciones_clicked(const QModelIndex &index)
{
    if(!index.isValid()){
            return;
        }

    this->idOperacion=modeloOperaciones->index(index.row(),0).data().toString();
}



void medico_expediente_clinico::on_btn_guardarCambios_clicked()
{
     QMessageBox info;
     QSqlQuery query(mDatabase);
    if(ui->line_peso->text()!="" && ui->line_estatura->text()!="" && ui->line_tipoSangre->text()!="" && ui->txt_descripcion_2->toPlainText()!="")
    {
        QMessageBox msgBox(QMessageBox::Question,"Confimacion","¿Estas seguro de guardar los cambios?",QMessageBox::Yes|QMessageBox::No);
        msgBox.setButtonText(QMessageBox::Yes,"Sí");
        msgBox.setButtonText(QMessageBox::No,"No");

        if(msgBox.exec()==QMessageBox::Yes)
        {
            if(this->idExpediente=="")
            {
                query.prepare("INSERT INTO expediente(peso, estatura, tipo_sangre, descripcion) VALUES ('"+ui->line_peso->text()+"','"+ui->line_estatura->text()+"','"+ui->line_tipoSangre->text()+"','"+ui->txt_descripcion_2->toPlainText()+"')");
                query.exec();

                query.prepare("SELECT * FROM expediente order by id_expediente desc");
                query.exec();
                query.next();

                this->idExpediente=query.value(0).toString();

                query.prepare("UPDATE paciente SET id_expediente='"+this->idExpediente+"' WHERE id_paciente="+this->idPaciente);
                query.exec();

                ui->btn_GenerarExpediente->setVisible(false);
                ui->btn_modificarDatos->setVisible(true);


            }else
            {
                query.prepare("UPDATE expediente SET peso='"+ui->line_peso->text()+"',estatura='"+ui->line_estatura->text()+"',tipo_sangre='"+ui->line_tipoSangre->text()+"',descripcion='"+ui->txt_descripcion_2->toPlainText()+"'  WHERE id_expediente="+this->idExpediente);
                query.exec();
            }
            info.setWindowTitle("Información");
            info.setText("Cambios guardados con éxito.");
            info.setStandardButtons(QMessageBox::Ok);
            info.setDefaultButton(QMessageBox::Ok);
            info.setButtonText(QMessageBox::Ok,"Aceptar");
            info.exec();

            ui->lbl_peso->setText(ui->line_peso->text());
            ui->lbl_estatura->setText(ui->line_estatura->text());
            ui->lbl_tipoSangre->setText(ui->line_tipoSangre->text());
            ui->txt_descripcion->setPlainText(ui->txt_descripcion_2->toPlainText());
            ui->stackedWidget->setCurrentIndex(0);

        }

    }else
    {
        info.setWindowTitle("Información");
        info.setText("No puede haber campos vacíos, verifique nuevamente.");
        info.setStandardButtons(QMessageBox::Ok);
        info.setDefaultButton(QMessageBox::Ok);
        info.setButtonText(QMessageBox::Ok,"Aceptar");
        info.exec();
    }
}

void medico_expediente_clinico::on_btn_eliminar_alergia_clicked()
{
    QSqlQuery query(mDatabase);
    QMessageBox info;
    if(this->idAlergia!="")
    {
        query.prepare("SELECT tipo FROM alergias WHERE id_alergias="+this->idAlergia);
        query.exec();
        query.next();
        QMessageBox msgBox(QMessageBox::Question,"Confimacion","¿Estas seguro de eliminar la alergia '"+query.value(0).toString()+"'?",QMessageBox::Yes|QMessageBox::No);
        msgBox.setButtonText(QMessageBox::Yes,"Sí");
        msgBox.setButtonText(QMessageBox::No,"No");

        if(msgBox.exec()==QMessageBox::Yes)
        {
            query.prepare("DELETE FROM alergias WHERE id_alergias="+this->idAlergia);
            query.exec();
            cargarTablaAlergias();
            this->idAlergia="";
        }

    }else
    {
        info.setWindowTitle("Información");
        info.setText("Debe seleccionar una alergia para eliminar.");
        info.setStandardButtons(QMessageBox::Ok);
        info.setDefaultButton(QMessageBox::Ok);
        info.setButtonText(QMessageBox::Ok,"Aceptar");
        info.exec();
    }
}

void medico_expediente_clinico::on_btn_eliminar_enfermedad_clicked()
{
    QSqlQuery query(mDatabase);
    QMessageBox info;

    if(this->idEnfermedad!="")
    {
        query.prepare("SELECT tipo FROM enfermedades WHERE id_enfermedades="+this->idEnfermedad);
        query.exec();
        query.next();
        QMessageBox msgBox(QMessageBox::Question,"Confimacion","¿Estas seguro de eliminar la enfermedad '"+query.value(0).toString()+"'?",QMessageBox::Yes|QMessageBox::No);
        msgBox.setButtonText(QMessageBox::Yes,"Sí");
        msgBox.setButtonText(QMessageBox::No,"No");

        if(msgBox.exec()==QMessageBox::Yes)
        {
            query.prepare("DELETE FROM enfermedades WHERE id_enfermedades="+this->idEnfermedad);
            query.exec();
            cargarTablaEnfermedades();
            this->idEnfermedad="";
        }

    }else
    {
        info.setWindowTitle("Información");
        info.setText("Debe seleccionar una enfermedad para eliminar.");
        info.setStandardButtons(QMessageBox::Ok);
        info.setDefaultButton(QMessageBox::Ok);
        info.setButtonText(QMessageBox::Ok,"Aceptar");
        info.exec();
    }
}

void medico_expediente_clinico::on_btn_eliminar_operacion_clicked()
{
    QSqlQuery query(mDatabase);
    QMessageBox info;

    if(this->idOperacion!="")
    {
        query.prepare("SELECT descripcion FROM operaciones WHERE id_operaciones="+this->idOperacion);
        query.exec();
        query.next();
        QMessageBox msgBox(QMessageBox::Question,"Confimacion","¿Estas seguro de eliminar la operación '"+query.value(0).toString()+"'?",QMessageBox::Yes|QMessageBox::No);
        msgBox.setButtonText(QMessageBox::Yes,"Sí");
        msgBox.setButtonText(QMessageBox::No,"No");

        if(msgBox.exec()==QMessageBox::Yes)
        {
            query.prepare("DELETE FROM operaciones WHERE id_operaciones="+this->idOperacion);
            query.exec();
            cargarTablaOperaciones();
            this->idOperacion="";

        }
    }else
    {
        info.setWindowTitle("Información");
        info.setText("Debe seleccionar una operación para eliminar.");
        info.setStandardButtons(QMessageBox::Ok);
        info.setDefaultButton(QMessageBox::Ok);
        info.setButtonText(QMessageBox::Ok,"Aceptar");
        info.exec();
    }
}

void medico_expediente_clinico::on_btn_agregar_alergia_clicked()
{
    QMessageBox info;
    if(idExpediente!="")
    {
        medico_agregar_alergia_operacion_enfermedad agregar(this->idExpediente,"alergia");
        agregar.exec();
    }else
    {
        info.setWindowTitle("Información");
        info.setText("Debe generar el expediente primero.");
        info.setStandardButtons(QMessageBox::Ok);
        info.setDefaultButton(QMessageBox::Ok);
        info.setButtonText(QMessageBox::Ok,"Aceptar");
        info.exec();
    }


    cargarTablaAlergias();
}

void medico_expediente_clinico::on_btn_agregar_enfermedad_clicked()
{
    QMessageBox info;
    if(idExpediente!="")
    {
        medico_agregar_alergia_operacion_enfermedad agregar(this->idExpediente,"enfermedad");
        agregar.exec();
    }else
    {
        info.setWindowTitle("Información");
        info.setText("Debe generar el expediente primero.");
        info.setStandardButtons(QMessageBox::Ok);
        info.setDefaultButton(QMessageBox::Ok);
        info.setButtonText(QMessageBox::Ok,"Aceptar");
        info.exec();
    }

    cargarTablaEnfermedades();
}

void medico_expediente_clinico::on_btn_agregar_operacion_clicked()
{
    QMessageBox info;
    if(idExpediente!="")
    {
        medico_agregar_alergia_operacion_enfermedad agregar(this->idExpediente,"operacion");
        agregar.exec();
    }else
    {
        info.setWindowTitle("Información");
        info.setText("Debe generar el expediente primero.");
        info.setStandardButtons(QMessageBox::Ok);
        info.setDefaultButton(QMessageBox::Ok);
        info.setButtonText(QMessageBox::Ok,"Aceptar");
        info.exec();
    }

    cargarTablaOperaciones();
}

void medico_expediente_clinico::on_btn_Cancelar_modificar_expediente_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
