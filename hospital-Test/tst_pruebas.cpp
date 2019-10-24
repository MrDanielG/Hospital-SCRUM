#include <QtTest>

// add necessary includes here

class pruebas : public QObject
{
    Q_OBJECT

public:
    pruebas();
    ~pruebas();

private slots:
    void test_case1();

};

pruebas::pruebas()
{

}

pruebas::~pruebas()
{

}

void pruebas::test_case1()
{

}

QTEST_APPLESS_MAIN(pruebas)

#include "tst_pruebas.moc"
