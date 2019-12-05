#include "mainwindow.h"
#include <QApplication>
#include <QtSql/QSqlDatabase>
#include <QTranslator>
#include <QLibraryInfo>

int main(int argc, char *argv[])
{
    QSqlDatabase mDatabase;
#ifdef Q_OS_WIN
  mDatabase = QSqlDatabase::addDatabase("QODBC","Connection");
#elif defined(Q_OS_MAC)
  mDatabase = QSqlDatabase::addDatabase("QMYSQL");
  mDatabase.setHostName("localhost");
  mDatabase.setUserName("root");
  mDatabase.setPassword("luisdrew1394");
#endif

    mDatabase.setDatabaseName("hospital");
    QApplication a(argc, argv);

    QTranslator qtTranslator;
    qtTranslator.load("qt_" + QLocale::system().name(),
            QLibraryInfo::location(QLibraryInfo::TranslationsPath));
    a.installTranslator(&qtTranslator);
    MainWindow w;
    w.show();

    return a.exec();
}
