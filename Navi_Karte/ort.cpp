#include "ort.h"

Ort::Ort(double breiteg, double laengeg, int id): id(id), breiteg(breiteg), laengeg(laengeg){}

Ort::~Ort(){}

double Ort::distanz( Ort& a){
    double theta = this->laengeg-a.laengeg;
    double distance = 60*1.1515*(180/M_PI) *acos(sin(this->breiteg*(M_PI/180))*sin(a.breiteg*M_PI/180)
         + cos(this->breiteg*M_PI/180)*cos(a.breiteg*M_PI/180)*cos(theta*M_PI/180));
    return distance* 1.609;
}
double Ort::getBreiteg(){
    return breiteg;
}
double Ort::getLaengeg(){
    return laengeg;
}
bool Ort::istmeineID(int id){
    return this->id == id;
}
int Ort::getID(){
    return id;
}
