#ifndef TEST_H
#define TEST_H

#include <QObject>
#include <QtTest>
#include <stdexcept>
#include <exception>
#include "ort.h"
#include <iostream>

using namespace std;

class Test : public QObject
{
    Q_OBJECT
public:
    explicit Test(QObject *parent = nullptr, vector<Ort*> *v = nullptr);

private:
    vector<Ort*> *v;

private slots:
    void test1();
    void test2();
    void test3();
    void test4();
    void test5();

};

#endif // TEST_H
