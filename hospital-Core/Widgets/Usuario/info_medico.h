#ifndef INFO_MEDICO_H
#define INFO_MEDICO_H

#include <QDialog>

namespace Ui {
class info_medico;
}

class info_medico : public QDialog
{
    Q_OBJECT

public:
    explicit info_medico(QWidget *parent = nullptr);
    ~info_medico();

private:
    Ui::info_medico *ui;
};

#endif // INFO_MEDICO_H
