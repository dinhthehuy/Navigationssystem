#ifndef DIJKSTRA_TEST_H
#define DIJKSTRA_TEST_H

#include <QObject>
#include <QTest>
#include <stdexcept>
#include <exception>
#include "ort.h"
#include <iostream>
#include <fstream>
#include "adresse.h"
#include "poi.h"

using namespace std;

class DijkstraTest : public QObject
{
    Q_OBJECT
public:
    explicit DijkstraTest(QObject *parent = nullptr, vector<Ort*> v = {});

private:
    vector<Ort*> v;
    void import();

private slots:
    void test_distance_between_two_places();
    void test_zero_distance();
    void test_import_csv_file();
    void test_places_from_csv_file();
};

#endif // DIJKSTRA_TEST_H
