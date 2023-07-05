#ifndef ADRESSE_H
#define ADRESSE_H
#include"ort.h"
#include <string>
using namespace std;

class Adresse: public Ort
{
    string strasse;
    int hausnr;
    int plz;
    string stadt;
public:
    Adresse(double laengeg, double breiteg, int id,string stra,int hnr, int plz, string stadt);
    void print();
    std::string getPara();
    string getStrasse();
    int gethHausNr();
    int getPlz();
    string getStadt();
};

#endif // ADRESSE_H
