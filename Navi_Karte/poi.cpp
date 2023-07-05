#include "poi.h"

PoI::PoI(double laengeg, double breiteg, int id, string kat, string bem):
    Ort(breiteg,laengeg, id), kategorie(kat),bemerkung(bem) {}

string PoI::getPara()
{
    return kategorie+", "+bemerkung;
}

string PoI::getKategorie(){
    return kategorie;
}
string PoI::getBemerkung(){
    return bemerkung;
}

