#ifndef PDF_COBRO_H
#define PDF_COBRO_H
#include <QString>

class pdf_cobro
{
public:
    pdf_cobro(QString, QString, QString, QString, QString);

private:
    QString nombrePaciente, fecha, concepto, descripcion, idCita, medicamentos;
    QString html;
};

#endif // PDF_COBRO_H
