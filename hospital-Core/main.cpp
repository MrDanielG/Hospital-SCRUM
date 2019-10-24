#include "mainwindow.h"
#include <QApplication>
#include <QtSql/QSqlDatabase>

int main(int argc, char *argv[])
{
    QSqlDatabase mDatabase = QSqlDatabase::addDatabase("QODBC","Connection");
    mDatabase.setDatabaseName("hospital");
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
