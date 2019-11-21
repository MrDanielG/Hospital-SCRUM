#include "farmaceutico_realizarventas.h"
#include "ui_farmaceutico_realizarventas.h"
#include <QtPrintSupport/QPrinter>

farmaceutico_realizarVentas::farmaceutico_realizarVentas(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::farmaceutico_realizarVentas)
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
            qDebug() << "base de datos sigue conectada en INICIAR SESION";
        }

        QSqlQuery query(mDatabase);
        query.prepare("select nombre, costo, cantidad, premedicado, id_medicamentos_farmacia from medicamentos_farmacia");
        query.exec();

        int i=0;
        int row = 0;
        int col = 0;

        while(query.next()){
             QString nombre = query.value(0).toString();
             QString costo = query.value(1).toString();
             QString cantidad = query.value(2).toString();
             QString premedicado = query.value(3).toString();
             QString id = query.value(4).toString();

             row = i/2;
             col= i%2;

             farmaceutico_tarjeta_medicamento_venta *tarjeta = new farmaceutico_tarjeta_medicamento_venta(this);
             tarjeta->insertarDatos(nombre, costo, cantidad, premedicado, id);
             i++;
             ui->gridLayout->addWidget(tarjeta, row, col);

        }

}

farmaceutico_realizarVentas::~farmaceutico_realizarVentas()
{
    delete ui;
}

void farmaceutico_realizarVentas::limpiarCatalogo()
{
    while ( QLayoutItem* item = ui->gridLayout->takeAt( 0 ) ){
            Q_ASSERT( ! item->layout() ); // otherwise the layout will leak
            delete item->widget();
            delete item;
    }
}
void farmaceutico_realizarVentas::limpiarCatalogo2()
{
    while ( QLayoutItem* item = ui->gridLayout_3->takeAt( 0 ) ){
            Q_ASSERT( ! item->layout() ); // otherwise the layout will leak
            delete item->widget();
            delete item;
    }
}

void farmaceutico_realizarVentas::insertarVentas(QString id){

    QSqlQuery query(mDatabase);
    query.prepare("select nombre, costo, id_medicamentos_farmacia from medicamentos_farmacia where id_medicamentos_farmacia = "+id);
    query.exec();

    int row = 0;
    int col = 0;

    while(query.next()){
         QString nombre = query.value(0).toString();
         QString costo = query.value(1).toString();
         QString id = query.value(2).toString();

         row = i/2;
         col= i%2;

         farmaceutico_tarjetasventasencola *tarjeta = new farmaceutico_tarjetasventasencola(this);
         tarjeta->insertarDatos(nombre, costo, id);

         i++;
         ui->gridLayout_3->addWidget(tarjeta, row, col);

    }

}

void farmaceutico_realizarVentas::insertarTotal(float total, QString id, int cant){
    this->Total += total;
    ides.append(id);
    cants.append(QString::number(cant));
    ui->total->setText(QString::number(this->Total));
}


void farmaceutico_realizarVentas::on_BuscarMedicamento_textChanged(const QString &arg1)
{

    char caracter = '%';

    QSqlQuery MostrarDatos(mDatabase);
    MostrarDatos.prepare("select nombre, costo, cantidad, premedicado, id_medicamentos_farmacia "
                         "from medicamentos_farmacia where nombre like '"+arg1+""+caracter+"'");
    MostrarDatos.exec();

    int row = 0;
    int col = 0;
    int i=0;
    limpiarCatalogo();

    while (MostrarDatos.next()){
        QString nombre = MostrarDatos.value(0).toString();
        QString costo = MostrarDatos.value(1).toString();
        QString cantidad = MostrarDatos.value(2).toString();
        QString premedicado = MostrarDatos.value(3).toString();
        QString id = MostrarDatos.value(4).toString();
        row = i/2;
        col= i%2;

        farmaceutico_tarjeta_medicamento_venta *tarjeta = new farmaceutico_tarjeta_medicamento_venta(this);
       tarjeta->insertarDatos(nombre, costo, cantidad, premedicado, id);
        i++;
        ui->gridLayout->addWidget(tarjeta, row, col);
    }

}

void farmaceutico_realizarVentas::imprimirTicket(QString total, QString efectivo, QString cambio)
{
    QString html;
    QString folio;
    QDateTime fecha=QDateTime::currentDateTime();
    QSqlQuery query(mDatabase);
    QSqlQuery query2(mDatabase);
    query.prepare("select * from venta order by folio desc;");
    query.exec();
    query.next();
    folio=query.value(0).toString();

    html=
            "<body  style='margin: 0; padding: 0; font-family: Montserrat;'>"
            "<h1 align=center>Comprobante De Pago </h1>"
            "<div align=center>"
            "<p style='font-size: 11px;font-weight: 400;'>Farmacia 'Hospital Puebla' <br>"
            "Benemérita Universidad Autónoma de Puebla <br>"
            "Fecha: "+fecha.toString()+"<br>"
            "Folio: "+folio+
            "</p>"
            "</div>"

            "<div align=center style='margin: 0.5em;font-size: 10px;'>"
            "<table style='border-collapse: collapse; width: 100%;'>"
            "<tr>"
            "<th style='background-color: #1F1C1D; color: white;  border: 1px solid #dddddd; text-align: center; padding: 8px; '>Cantidad </th>"
            "<th style='background-color: #1F1C1D; color: white;  border: 1px solid #dddddd; text-align: center; padding: 8px; '>Medicamento</th>"
            "<th style='background-color: #1F1C1D; color: white;  border: 1px solid #dddddd; text-align: center; padding: 8px; '>Precio Unitario</th>"
            "<th style='background-color: #1F1C1D; color: white;  border: 1px solid #dddddd; text-align: center; padding: 8px; '>Importe</th>"
            "</tr>";

            query.prepare("SELECT * FROM medicamentosventa WHERE venta_folio="+folio);
            query.exec();

            while(query.next())
            {
                query2.prepare("SELECT * FROM medicamentos_farmacia WHERE id_medicamentos_farmacia="+query.value(0).toString());
                query2.exec();
                query2.next();
                double importe=query.value(2).toInt()*query2.value(3).toDouble();
                html+="<tr>"
                "<td style='border: 1px solid #dddddd; text-align: left; padding: 8px;'>"+query.value(2).toString()+"</td>"
                "<td style='border: 1px solid #dddddd; text-align: left; padding: 8px;'>"+query2.value(1).toString()+"</td>"
                "<td style='border: 1px solid #dddddd; text-align: left; padding: 8px;'>$ "+query2.value(3).toString()+"</td>"
                "<td style='border: 1px solid #dddddd; text-align: left; padding: 8px;'>$ "+QString::number(importe)+"</td>"
                "</tr>";

           }

            html+=    "<tr>"
            "<td style='background-color: white; color: white; border: 1px solid #dddddd; text-align: left; padding: 8px;'></td>"
            "<td style='background-color: white; color: white; border: 1px solid #dddddd; text-align: left; padding: 8px;'></td>"
            "<td style='background-color: #1F1C1D; color: white; border: 1px solid #dddddd; text-align: left; padding: 8px;'>Total</td>"
            "<td style='background-color: #1F1C1D; color: white; border: 1px solid #dddddd; text-align: left; padding: 8px;'>$ "+total+"</td>"
            "</tr>"

            "<tr>"
            "<td style='background-color: white; color: white; border: 1px solid #dddddd; text-align: left; padding: 8px;'></td>"
            "<td style='background-color: white; color: white; border: 1px solid #dddddd; text-align: left; padding: 8px;'></td>"
            "<td style='background-color: #1F1C1D; color: white; border: 1px solid #dddddd; text-align: left; padding: 8px;'>Efectivo</td>"
            "<td style='background-color: #1F1C1D; color: white; border: 1px solid #dddddd; text-align: left; padding: 8px;'>$ "+efectivo+"</td>"
            "</tr>"

            "<tr>"
            "<td style='background-color: white; color: white; border: 1px solid #dddddd; text-align: left; padding: 8px;'></td>"
            "<td style='background-color: white; color: white; border: 1px solid #dddddd; text-align: left; padding: 8px;'></td>"
            "<td style='background-color: #1F1C1D; color: white; border: 1px solid #dddddd; text-align: left; padding: 8px;'>Cambio</td>"
            "<td style='background-color: #1F1C1D; color: white; border: 1px solid #dddddd; text-align: left; padding: 8px;'>$ "+cambio+"</td>"
            "</tr>"

            "</table>"
            "<br> <br> <br>"
            "</div>"

            "<div style='text-align: center;font-size: 10px;'>"
            " Farmacia 'Hospital Puebla' agradece su compra <br>"
            "Todos los Derechos Reservados S. A. de C. V. <br>"
            "Gracias por su preferencia"
            "</div>"
            "</body>";

    QTextDocument document;
    document.setHtml(html);
    QString filename="C:/img/ticketCobro.pdf";
    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName(filename);
    document.print(&printer);
    QDesktopServices::openUrl(QUrl::fromLocalFile("C:/img/ticketCobro.pdf"));
}

void farmaceutico_realizarVentas::on_btnRealizarVentas_clicked()
{
    QSqlQuery insertventa(mDatabase);
    QSqlQuery medicamentosVenta(mDatabase);
    QSqlQuery buscarVenta(mDatabase);
    QString total = ui->total->text();

    QMessageBox msgBox;
    msgBox.setWindowTitle("Realizar Venta");
    msgBox.setText("¿Esta seguro de realizar la siguiente venta?");
    msgBox.setStandardButtons(QMessageBox::Yes);
    msgBox.addButton(QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::Yes);
    QDateTime fecha=QDateTime::currentDateTime();
    QString date = fecha.toString();

    if(msgBox.exec() == QMessageBox::Yes){
        //Query

        insertventa.prepare("insert into venta(fecha) values('"+date+"')");
        insertventa.exec();

        buscarVenta.prepare("SELECT * FROM venta ORDER by folio desc LIMIT 1");
        buscarVenta.exec();
        QString ventaid = "";
        while (buscarVenta.next()) {
            ventaid = buscarVenta.value(0).toString();
        }


        for(int i=0; i<ides.size(); i++){
            medicamentosVenta.prepare("insert into medicamentosventa(id_medicamentos_farmacia, venta_folio, cantidad) "
                                      "values("+this->ides[i]+", "+ventaid+", "+ cants[i]+" )");
            medicamentosVenta.exec();
        }

        imprimirTicket(total, "100", "10");
        limpiarCatalogo2();
        ui->total->setText("0");

        QMessageBox::information(this, tr("Venta"),tr("Venta Realizada exitosamente."),
                                      QMessageBox::Ok);

    } else {
        QMessageBox::information(this, tr("Cancelada"),tr("La venta fue cancelada."),
                                      QMessageBox::Ok);
    }



}

