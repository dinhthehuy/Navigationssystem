#ifndef POI_H
#define POI_H
#include "ort.h"
#include <string>
using namespace std;

class PoI: public Ort
{
    string kategorie;
    string bemerkung;
public:

    PoI(double laengeg, double breiteg, int id, string kat,string bem);

    void print();
    std::string getPara();
    string getKategorie();
    string getBemerkung();
};

#endif // POI_H
