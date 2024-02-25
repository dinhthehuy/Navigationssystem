#include "mainwindow.h"
#include "../test/dijkstra_test.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    DijkstraTest t;
    QTest::qExec(&t);

    return a.exec();
}
