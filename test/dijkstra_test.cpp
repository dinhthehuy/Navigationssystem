#include "dijkstra_test.h"

DijkstraTest::DijkstraTest(QObject *parent, vector<Ort*> list)
    : QObject{parent}, v(list)
{

}

void DijkstraTest::import() {
    ifstream input("../build/nav.csv");
    if(!input){
        return;
    }

    v.clear();
    string line = "";
    setlocale(LC_ALL, "C");
    while(getline(input, line)) {

        int pos = 0;
        string type;
        int Id;
        double Längengrad;
        double Breitengrad;

        pos = line.find(",");
        type = line.substr(0, pos);
        line.erase(0, pos+1);

        pos = line.find(",");
        Id = stoi(line.substr(0, pos));
        line.erase(0, pos+1);

        pos = line.find(",");
        Längengrad = stod(line.substr(0, pos));
        line.erase(0, pos+1);

        pos = line.find(",");
        Breitengrad = stod(line.substr(0, pos));
        line.erase(0, pos+1);

        if(type == "A") {
            string Straße;
            int Hausnummer;
            int Postleitzahl;
            string Stadt;

            pos = line.find(",");
            Straße = line.substr(0, pos);
            line.erase(0, pos+1);

            pos = line.find(",");
            Hausnummer = stoi(line.substr(0, pos));
            line.erase(0, pos+1);

            pos = line.find(",");
            Postleitzahl = stoi(line.substr(0, pos));
            line.erase(0, pos+1);

            Stadt = line;

            v.push_back(new Adresse(Längengrad, Breitengrad, Id, Straße, Hausnummer, Postleitzahl, Stadt));

        } else {
            string Kategorie;
            string Bemerkung;

            pos = line.find(",");
            Kategorie = line.substr(0, pos);
            line.erase(0, pos+1);

            Bemerkung = line;

            v.push_back(new PoI(Längengrad, Breitengrad, Id, Kategorie, Bemerkung));
        }
    }
}

void DijkstraTest::test_distance_between_two_places() { // zwischen Cottbus und Saarbruecken
    v.push_back(new PoI(14.326664, 51.762889, 17, "Stadt", "Cottbus"));
    v.push_back(new PoI(6.996933, 49.240157, 12, "Hauptstadt", "Saarbruecken"));
    double entfernung = v.at(0)->distanz(*v.at(1));
    QVERIFY(entfernung <= 590.55*1.05 || entfernung >= 590.55*99.5);
    v.clear();
}

void DijkstraTest::test_zero_distance() {
    v.push_back(new PoI(14.326664, 51.762889, 17, "Stadt", "Cottbus"));
    double entfernung = v.at(0)->distanz(*v.at(0));
    QVERIFY(entfernung == 0);
    v.clear();
}

void DijkstraTest::test_import_csv_file() { // zwischen Stuttgart und Wiesbaden
    import();
    int size = v.size();
    QVERIFY(size == 25);
    v.clear();
}

void DijkstraTest::test_places_from_csv_file() { // zwischen Dresden und Magdeburg
    import();
    double entfernung = v.at(12)->distanz(*v.at(13));
    double entfernung2 = v.at(5)->distanz(*v.at(5));
    QVERIFY(entfernung <= 189.27*1.05 || entfernung >= 189.27*99.5);
    QVERIFY(entfernung2 == 0);
    v.clear();
}

