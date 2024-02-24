#include "test.h"

Test::Test(QObject *parent, vector<Ort*> *list)
    : QObject{parent}, v(list)
{

}

void Test::test1() { // zwischen Cottbus und Saarbruecken
    double entfernung = v->at(11)->distanz(*v->at(16));
    QVERIFY(entfernung <= 590.55*1.05 || entfernung >= 590.55*99.5);
}

void Test::test2() { // zwischen Muenchen und Kiel
    double entfernung = v->at(2)->distanz(*v->at(14));
    QVERIFY(entfernung <= 693.14*1.05 || entfernung >= 693.14*99.5);
}

void Test::test3() { // zwischen Stuttgart und Wiesbaden
    double entfernung = v->at(1)->distanz(*v->at(6));
    QVERIFY(entfernung <= 156.77*1.05 || entfernung >= 156.77*99.5);
}

void Test::test4() { // zwischen Dresden und Magdeburg
    double entfernung = v->at(12)->distanz(*v->at(13));
    QVERIFY(entfernung <= 189.27*1.05 || entfernung >= 189.27*99.5);
}

void Test::test5() { // zwischen Wiesbaden und Mainz
    double entfernung = v->at(6)->distanz(*v->at(10));
    QVERIFY(entfernung <= 7.87*1.05 || entfernung >= 7.87*99.5);
}
