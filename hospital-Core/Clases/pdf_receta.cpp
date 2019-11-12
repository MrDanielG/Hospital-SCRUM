#include "pdf_receta.h"
#include <QDate>
#include <QTextDocument>
#include <QPrinter>
#include <QDesktopServices>
pdf_receta::pdf_receta(QString _nombrePaciente, QString _fecha, QString _concepto, QString _descripcion, QString _idCita, QString _medicamentos)
{
    html =

    "<div style=\"font-size:12px; font-family:Verdana;\" align=center>"

        "<h2 text-align=center>HOSPITAL PUEBLA</h2>"
            "<p>Receta Médica: "+_idCita+"<br> Corresponde a la fecha: "+_fecha+"</p>"

            "<h2> Correspondiente al Paciente: </h2>"
            "<p>"+_nombrePaciente+"</p>"

            "<h2> Concepto Cita: </h2>"
            "<p>"+_concepto+"</p>"

            "<h2> Descripcion o Síntomas: </h2>"
            "<p>"+_descripcion+" </p>"

            "<h2> Medicamentos: </h2>"
            "<p>"+_medicamentos+"</p>"
            "--------------------------------"
            "</br>"
    "</div>";

    QTextDocument document;
    document.setHtml(html);
    QString filename="C:/img/receta.pdf";
    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName(filename);
    document.print(&printer);
    QDesktopServices::openUrl(QUrl::fromLocalFile("C:/img/receta.pdf"));

}
