#include "mainwindow.h"
#include <QApplication>
#include <QtSql/QSqlDatabase>

int main(int argc, char *argv[])
{
    QSqlDatabase mDatabase;
#ifdef Q_OS_WIN
  mDatabase = QSqlDatabase::addDatabase("QODBC","Connection");
  //mDatabase = QSqlDatabase::addDatabase("QMYSQL","Connection");
#elif defined(Q_OS_MAC)
  mDatabase = QSqlDatabase::addDatabase("QMYSQL");
  mDatabase.setHostName("localhost");
  mDatabase.setUserName("root");
  mDatabase.setPassword("luisdrew1394");
#endif

    mDatabase.setDatabaseName("hospital");
//    mDatabase.setHostName("localhost");
//    mDatabase.setPort(3306);
//    mDatabase.setUserName("root");
//    mDatabase.setPassword("");
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
