#include "adresse.h"
using namespace std;

Adresse::Adresse(double laengeg, double breiteg, int id, string stra,int hnr, int plz, string stadt):
    Ort(breiteg,laengeg, id), strasse(stra), hausnr(hnr), plz(plz), stadt(stadt) {}

string Adresse::getPara()
{
    return strasse+" "+to_string(hausnr)+", "+stadt+" "+to_string(plz);
}

string Adresse::getStrasse(){
    return this->strasse;
}
int Adresse::gethHausNr(){
    return this->hausnr;
}
int Adresse::getPlz(){
    return plz;
}
string Adresse::getStadt(){
    return stadt;
}
