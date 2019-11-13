#ifndef PDF_RECETA_H
#define PDF_RECETA_H
#include <QString>

class pdf_receta
{
public:
    pdf_receta(QString _nombrePaciente, QString _fecha, QString _concepto, QString _descripcion, QString _idCita, QString _medicamentos);

private:
    QString nombrePaciente, fecha, concepto, descripcion, idCita, medicamentos;
    QString html;
};

#endif // PDF_RECETA_H
