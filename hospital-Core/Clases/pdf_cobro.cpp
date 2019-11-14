#include "pdf_cobro.h"
#include <QDate>
#include <QTextDocument>
#include <QPrinter>
#include <QDesktopServices>
pdf_cobro::pdf_cobro(QString _nombrePaciente, QString _nombreDoctor, QString _fechaInicial, QString _diasTotales, QString _precioTotal)
{
    //html = '<style> * { margin: 0; padding: 0; box-sizing: border-box; } .header1 { grid-area: header1; } .header2 { grid-area: header2; } .info { grid-area: info; } .body { grid-area: body; } .footer { grid-area: footer; text-align: center; } body { font-family: Montserrat; } p { font-weight: lighter; } .grid-container { height: 100vh; display: grid; grid-template-areas: "header1 header2" "info info" "body body" "footer footer"; grid-gap: 10px; /* background-color: #DEDEDE; */ padding: 20px; } table { border-collapse: collapse; width: 100%; } td, th { border: 1px solid #dddddd; text-align: left; padding: 8px; } th { background-color: #1F1C1D; color: white; } tr:nth-child(even) { background-color: #dddddd; } .finalRow { background-color: rgb(42, 184, 37); color: white; } </style> <body> <div class="grid-container"> <div class="header1"> <h2>Hospital Puebla</h2> </div> <div class="header2"> <p>Fecha Actual <br></p> <p>Benemerita Universidad Autonoma de Puebla</p> <br> </div> <div class="info"> Nombre del Paciente: <p>'+_nombrePaciente+'</p> <br> Doctor Encargado: <p>'+_nombreDoctor+'</p> <br> Fecha Inicial Internado: <p>'+_fechaInicial+'</p> <br> </div> <div class="body"> <table> <tr> <th>Servicio</th> <th>Cantidad</th> </tr> <tr> <td>Estancia Hospital (diaria) </td> <td>Precio Estancia</td> </tr> <tr> <td>Alimentos Estancia</td> <td>$'+_precioTotal+'</td> </tr> <tr class="finalRow"> <td class="finalRow">Total</td> <td class="finalRow">'+_precioTotal+'</td> </tr> </table> </div> <div class="footer"> Hospital Puebla agradece su estancia <br> Todos los Derechos Reservados S. A. de C. V. <br> Gracias por su preferencia </div> </div> </body>';

    html =
            "<body style='margin: 0; padding: 0; font-family: Montserrat;'>"
                "<div>"

                   " <div>"
                        "<h2>Hospital Puebla</h2>"
                    "</div>"
                    "<div>"
                        "<p>"+_fechaInicial+"<br></p>"
                        "<p>Benemerita Universidad Autonoma de Puebla</p> <br>"
                    "</div>"
                    "<div>"
                        "<h3>Nombre del Paciente:</h3> <p style:'font-weight: lighter;'>"+_nombrePaciente+"</p> <br>"
                        "<h3>Doctor Encargado:</h3> <p>"+_nombreDoctor+"</p> <br>"
                        "<h3>Fecha Inicial Internado:</h3> <p>"+_fechaInicial+"</p> <br>"

                    "</div>"
                    "<div>"
                       " <table style='border-collapse: collapse; width: 100%;'>"
                            "<tr>"
                                "<th style='background-color: #1F1C1D; color: white;  border: 1px solid #dddddd; text-align: left; padding: 8px; '>"
                                    "Servicio</th>"
                                "<th style='background-color: #1F1C1D; color: white;  border: 1px solid #dddddd; text-align: left; padding: 8px;'>"
                                    "Cantidad</th>"
                            "</tr>"
                            "<tr>"
                                "<td style='border: 1px solid #dddddd; text-align: left; padding: 8px;'>Estancia Hospital (diaria)"
                               " </td>"
                                "<td style='border: 1px solid #dddddd; text-align: left; padding: 8px;'>"+_precioTotal+"</td>"
                            "</tr>"

                            "<tr>"
                                "<td style=/border: 1px solid #dddddd; text-align: left; padding: 8px;/>Alimentos Estancia</td>"
                                "<td>$0</td>"
                            "</tr>"
                            "<tr>"
                                "<td"
                                    "style='background-color: rgb(42, 184, 37); color: white; border: 1px solid #dddddd; text-align: left; padding: 8px;'>"
                                    "Total</td>"
                                "<td"
                                    "style='background-color: rgb(42, 184, 37); color: white; border: 1px solid #dddddd; text-align: left; padding: 8px;'>"
                                   " "+_precioTotal+"</td>"
                            "</tr>"
                        "</table>"
                    "</div> <br><br><br>"
                    "<div style='text-align: center;'>"
                        "Hospital Puebla agradece su estancia <br>"
                        "Todos los Derechos Reservados S. A. de C. V. <br>"
                       " Gracias por su preferencia"
                    "</div>"
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
