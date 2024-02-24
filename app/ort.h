#ifndef ORT_H
#define ORT_H
#include <iostream>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <string>
class Ort
{

protected:
    const int id;
    const double breiteg;
    const double laengeg;

public:
    double const erdradius = 6370;
    Ort(double breiteg, double laengeg, int id);
    virtual ~Ort();
    double distanz( Ort& a);
    virtual std::string getPara()=0;
    double getBreiteg();
    double getLaengeg();
    int getID();
    bool istmeineID(int id);
};
#endif // ORT_H
