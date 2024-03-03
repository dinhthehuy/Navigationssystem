#include "karte.h"
#include "ui_karte.h"
#include <QPushButton>

#include "mainwindow.h"


// Erzeuge die Karte und alle Buttons
Karte::Karte(QWidget *parent, vector<Ort*> *v) :
    QDialog(parent),
    ui(new Ui::Karte),
    orte(v)
{
    ui->setupUi(this);
    QPixmap *img = new QPixmap(":/images/../images/karte.png");

    ui->graphicsView->setScene(scene);
    scene->addPixmap(*img);
    scene->setBackgroundBrush(Qt::white);
    group->setExclusive(false);

    QPushButton *entfernung = new QPushButton("Entfernung");
    QPushButton *information = new QPushButton("Information");
    QPushButton *alleOrte = new QPushButton("Alle Orte");
    QPushButton *laden = new QPushButton("Laden");
    QPushButton *ortLoeschen = new QPushButton("Ort loeschen");
    QPushButton *ortHinzufuegen = new QPushButton("Ort hinzufuegen");
    QPushButton *routing = new QPushButton("Routing");
    QPushButton *speichern= new QPushButton("Speichern");
    QPushButton *verbinden = new QPushButton("Verbinden");
    label = new QLabel();

    ortArten->addItem("Adr");
    ortArten->addItem("PoI");

    ortLoeschen->setGeometry(950, 100, 110, 23);
    ortHinzufuegen->setGeometry(950, 150, 110, 23);
    ortArten->setGeometry(950, 173, 110, 23);
    information->setGeometry(950, 223, 110, 23);
    alleOrte->setGeometry(950, 273, 110, 23);
    entfernung->setGeometry(950, 323, 110, 23);
    routing->setGeometry(950, 373, 110, 23);
    laden->setGeometry(950, 423, 110, 23);
    speichern->setGeometry(950, 473, 110, 23);
    verbinden->setGeometry(950, 523, 110, 23);
    label->setGeometry(900, 50, 150, 30);
    label->setStyleSheet("background-color: white");

    scene->addWidget(ortArten);
    scene->addWidget(ortLoeschen);
    scene->addWidget(ortHinzufuegen);
    scene->addWidget(information);
    scene->addWidget(alleOrte);
    scene->addWidget(entfernung);
    scene->addWidget(routing);
    scene->addWidget(laden);
    scene->addWidget(speichern);
    scene->addWidget(verbinden);
    scene->addWidget(label);

    connect(entfernung, SIGNAL(clicked()), this, SLOT(Entfernung()));
    connect(information, SIGNAL(clicked()), this, SLOT(Information()));
    connect(alleOrte, SIGNAL(clicked()), this, SLOT(AlleOrte_Clicked()));
    connect(laden, SIGNAL(clicked()), this, SLOT(Laden_Clicked()));
    connect(routing, SIGNAL(clicked()), this, SLOT(Routing()));
    connect(speichern, SIGNAL(clicked()), this, SLOT(Speichern_Clicked()));
    connect(verbinden, SIGNAL(clicked()), this, SLOT(Verbinden_Clicked()));
    connect(ortHinzufuegen, SIGNAL(clicked()), this, SLOT(OrtAnlegen()));
    connect(ortLoeschen, SIGNAL(clicked()), this, SLOT(OrtLoeschen()));
}

Karte::~Karte() { delete ui; }

// Einfach deaktiviere den Button aber nicht loeschen
void Karte::OrtLoeschen() {
    int id;
    for(int i = 0;i < radioButtonsList.size(); i++) {
        if(radioButtonsList[i]->isChecked()) {
            id = i;
            radioButtonsList[i]->setChecked(false);
            count--;
            radioButtonsList[i]->setCheckable(false);
            radioButtonsList[i]->setVisible(false);

            // Loesche alle Verbindungen mit diesem Ort
            for(unsigned int j = 0; j < verbindenGraph[0].size(); j++) {
                verbindenGraph[id][j] = 0;
                verbindenGraph[j][id] = 0;
            }
            break;
        }
    }
}

void Karte::OrtAnlegen() {
    if(ortArten->currentText() == "Adr" ) {
        kA->show();
    } else {
        kP->show();
    }
}

// Rekursiv speichere Orte im Vektor als Pfad
void Karte::getPath(vector<int> &parent, int v, vector<int> &path)
{
    if (v == -1)
        return;
    getPath(parent, parent[v], path);
    path.push_back(v);
}

int Karte::miniDist(int distance[], bool visited[]) // finding minimum distance - distance and visited list
{
    int minimum = INT_MAX, ind;

    for(unsigned int k=0; k < orte->size(); k++) {
        if(!visited[k] && distance[k] <= minimum) {
            minimum=distance[k];
            ind=k;
        }
    }
    return ind;
}

void Karte::DijkstraAlgo(int startNode, unsigned int endNode, vector<int>& path) // adjacency matrix, start node src
{

    int distance[orte->size()]; // // array to calculate the minimum distance for each node
    bool visited[orte->size()];// boolean array to mark visited and unvisited for each node
    vector<int> parent(orte->size(), -1);

    for(unsigned int k = 0; k < orte->size(); k++) {
        distance[k] = INT_MAX;
        visited[k] = false;
    }

    distance[startNode] = 0;   // Source vertex distance is set 0

    for(unsigned int k = 0; k < orte->size(); k++) {
        int m = miniDist(distance, visited);
        visited[m]=true;

        for(unsigned int l = 0; l < orte->size(); l++) {
            // updating the distance of neighbouring vertex
            if (!visited[l] && verbindenGraph[m][l] && distance[m]!=INT_MAX && distance[m]+verbindenGraph[m][l]<distance[l]) {
                distance[l]=distance[m]+verbindenGraph[m][l];
                parent[l] = m;
            }
        }
    }

    for (unsigned int v = 0; v < orte->size(); ++v) {
        if(v == endNode) {
            getPath(parent, v, path);
            break;
        }
    }
}

// Finde kurzeste Weg zwischen 2 Orte mittels Dijkstra, dann zeichne den Pfad auf der Karte und zeige detailierter Pfad und Gesamtentfernung auf Pop Up Window
void Karte::Routing()
{
    vector<int> path;

    for(int i = 0; i < radioButtonsList.size(); i++) {
        if(radioButtonsList[i]->isChecked()) {
            for(int j = i+1; j < radioButtonsList.size(); j++) {
                if(radioButtonsList[j]->isChecked()) {
                    DijkstraAlgo(i, j, path);
                    string str = "";
                    double gesamt = 0;
                    QDialog *dialog = new QDialog();

                    QLabel *label = new QLabel(dialog);

                    QPen pen(Qt::red);
                    pen.setWidth(5);

                    for(unsigned int i = 0; i < path.size() - 1; i++) {
                        scene->addLine(radioButtonsList[path[i]]->x()+10, radioButtonsList[path[i]]->y()+10, radioButtonsList[path[i+1]]->x()+10, radioButtonsList[path[i+1]]->y()+10, pen);
                        gesamt += orte->at(path[i])->distanz(*orte->at(path[i+1]));
                        //str += orte->at(path[i])->getPara() + "->" + orte->at(path[i+1])->getPara() + ": " + to_string(orte->at(path[i])->distanz(*orte->at(path[i+1]))) + " km \n";
                        str += orte->at(path[i])->getPara() + " => ";
                    }
                    str += "\n Gesamtentfernung: " +  to_string(gesamt) + " km" + "\n";

                    label->setText(QString::fromStdString(str));
                    label->setAlignment(Qt::AlignRight);

                    QVBoxLayout *layout = new QVBoxLayout(dialog);
                    layout->addWidget(label);
                    dialog->setLayout(layout);
                    dialog->show();
                    break;
                }
            }
            break;
        }
    }
}

// Aktualisere den 2D Vektor, beim Verbinden zweier Orte, und zeichne Linie auf der Karte
void Karte::verbinden(Ort *o1, Ort *o2)
{
    verbindenGraph[o1->getID()-1][o2->getID()-1] = o1->distanz(*o2);
    verbindenGraph[o2->getID()-1][o1->getID()-1] = o1->distanz(*o2);

    QPen pen(Qt::gray);
    pen.setWidth(5);
    scene->addLine(radioButtonsList[o1->getID()-1]->x()+10, radioButtonsList[o1->getID()-1]->y()+10, radioButtonsList[o2->getID()-1]->x()+10, radioButtonsList[o2->getID()-1]->y()+10, pen);
}

// Importiere Orte aus csv Datei und initializiere den 2D Vektor
void Karte::Laden_Clicked()
{
    if(radioButtonsList.isEmpty()) {
        ifstream input("../build/nav.csv");
        if(!input){
            return;
        }
        orte->clear();
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

                orte->push_back(new Adresse(Längengrad, Breitengrad, Id, Straße, Hausnummer, Postleitzahl, Stadt));

            } else {
                string Kategorie;
                string Bemerkung;

                pos = line.find(",");
                Kategorie = line.substr(0, pos);
                line.erase(0, pos+1);

                Bemerkung = line;

                orte->push_back(new PoI(Längengrad, Breitengrad, Id, Kategorie, Bemerkung));
            }
        }

        // Erzeuge gewichtete Adjazenzmatrix
        verbindenGraph.resize(orte->size() * orte->size());
        for(unsigned int i = 0; i < orte->size(); i++) {
            for(unsigned int j = 0; j < orte->size(); j++) {
                verbindenGraph[i].push_back(0);
            }
        }
        this->update();
    }
}

// Verbinde zwei QRadioButton auf der Karte
void Karte::Verbinden_Clicked()
{
    Ort* op1;
    Ort* op2;

    for(int i = 0;i < radioButtonsList.size(); i++) {
        if(radioButtonsList[i]->isChecked()) {
            op1 = orte->at(i);

            for(int j = i+1; j < radioButtonsList.size(); j++) {
                if(radioButtonsList[j]->isChecked()) {
                    op2 = orte->at(j);
                    verbinden(op1, op2);
                    break;
                }
            }
            break;
        }
    }
}

void Karte::Speichern_Clicked()
{
    ofstream output ("../build/nav.csv");
    if(!output){
        return;
    }
    for(auto o: *orte) {
        Adresse* A = dynamic_cast<Adresse*>(o);
        if(A != nullptr) {
            output << "A" << ","<< A->getID() << ",";
            output << setprecision(8) << A->getLaengeg() << "," << A->getBreiteg() << ",";
            output << A->getStrasse() << "," << A->gethHausNr() << "," << A->getPlz() << "," << A->getStadt() << endl;
            continue;
        }
        PoI* P = dynamic_cast<PoI*>(o);
        if (P != nullptr){
            output << "P" << "," << P->getID() << ",";
            output << setprecision(8) << P->getLaengeg() << "," << P->getBreiteg() << ",";
            output << P->getKategorie() << "," << P->getBemerkung() << endl;
        }
    }
    output.close();
}

void Karte::update()
{
    double topLeftLong = 5.866306;
    double topLeftLat = 55.099167;
    double bottomRightLong = 15.041932;
    double bottomRightLat = 47.270111;
    double latToPixel = (1246) / (bottomRightLat - topLeftLat);
    double longToPixel = (923) / (bottomRightLong - topLeftLong);
    QPen pen(Qt::gray);
    pen.setWidth(5);

    for(unsigned int i = 0; i < orte->size(); i++) {
        PoI* p = dynamic_cast<PoI*>(orte->at(i));
        if(p != nullptr) {
            QRadioButton *button = new QRadioButton(QString::fromStdString(p->getBemerkung()));
            int y = latToPixel * (p->getBreiteg() - topLeftLat);
            int x = longToPixel * (p->getLaengeg() - topLeftLong);

            button->setGeometry(x, y, 99, 21);
            button->setStyleSheet(
                        "QRadioButton { color: black; background-color: transparent;  }"
                        "QRadioButton::indicator { width: 16px; height: 16px; border-radius: 8px; background-color: gray;}"
                        "QRadioButton::indicator:checked { background-color: red; }"
                        );
            group->addButton(button, i);
            scene->addWidget(button);
            radioButtonsList.push_back(button);
            continue;
        }

        Adresse* a = dynamic_cast<Adresse*>(orte->at(i));
        if(a!= nullptr) {
            QRadioButton *button = new QRadioButton(QString::fromStdString(a->getStrasse()));
            int y = latToPixel * (a->getBreiteg() - topLeftLat);
            int x = longToPixel * (a->getLaengeg() - topLeftLong);

            button->setGeometry(x, y, 99, 21);
            button->setStyleSheet(
                        "QRadioButton { color: black; background-color: transparent;  }"
                        "QRadioButton::indicator { width: 16px; height: 16px; border-radius: 8px; background-color: gray;}"
                        "QRadioButton::indicator:checked { background-color: red; }"
                        );
            group->addButton(button, i);
            scene->addWidget(button);
            radioButtonsList.push_back(button);
            continue;
        }
    }

    QObject::connect(group, SIGNAL(buttonClicked(int)), this, SLOT(QRadioButton_Clicked(int)));
}

void Karte::QRadioButton_Clicked(int id)
{
    if(count < 2 && radioButtonsList[id]->isChecked()) {
        count++;
        radioButtonsList[id]->setChecked(true);

    } else if(radioButtonsList[id]->isChecked() == false) {
        radioButtonsList[id]->setChecked(false);
        count--;

    } else {
        radioButtonsList[id]->setChecked(false);
    }
}

void Karte::Entfernung()
{

    Ort* op1;
    Ort* op2;

    for(int i = 0;i < radioButtonsList.size(); i++) {
        if(radioButtonsList[i]->isChecked()) {
            op1 = orte->at(i);

            for(int j = i+1; j < radioButtonsList.size(); j++) {
                if(radioButtonsList[j]->isChecked()) {
                    op2 = orte->at(j);
                    QString str = QString::number(op1->distanz(*op2));
                    label->setText("Entfernung: " + str + " km");
                    break;
                }
            }
            break;
        }
    }
}

void Karte::Information()
{
    for(int i = 0; i < radioButtonsList.size(); i++) {
        if(radioButtonsList[i]->isChecked()) {

            QDialog *dialog = new QDialog();
            QStandardItemModel *model = new QStandardItemModel(1, 6, dialog);
            QTableView *tableView = new QTableView(dialog);
            QString str = "";

            dialog->setGeometry(0,0, 700, 100);
            tableView->setGeometry(0, 0, 700, 75);

            model->setHorizontalHeaderItem(0, new QStandardItem("Id"));
            model->setHorizontalHeaderItem(1, new QStandardItem("Typ"));
            model->setHorizontalHeaderItem(2, new QStandardItem("Breitengrad"));
            model->setHorizontalHeaderItem(3, new QStandardItem("Laengengrad"));
            model->setHorizontalHeaderItem(4, new QStandardItem("Parameter"));
            model->setHorizontalHeaderItem(5, new QStandardItem("Verbindungen"));
            tableView->setModel(model);
            tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

            model->setItem(0, 0, new QStandardItem(QString::number(orte->at(i)->getID())));
            model->setItem(0, 2, new QStandardItem(QString::number(orte->at(i)->getBreiteg())));
            model->setItem(0, 3, new QStandardItem(QString::number(orte->at(i)->getLaengeg())));
            model->setItem(0, 4, new QStandardItem(QString::fromStdString(orte->at(i)->getPara())));

            PoI* p = dynamic_cast<PoI*>(orte->at(i));
            if(p != nullptr) {
                model->setItem(0, 1, new QStandardItem(QString("PoI")));
                for(unsigned int j = 0; j < orte->size(); j++) {
                    if(verbindenGraph[i][j] > 0) {
                        str = str +  QString::fromStdString(orte->at(j)->getPara() +  ": ");
                        str = str + QString::number(verbindenGraph[i][j])+ " km; ";
                    }
                }
            }

            Adresse* a = dynamic_cast<Adresse*>(orte->at(i));
            if(a!= nullptr) {
                model->setItem(0, 1, new QStandardItem(QString("Adr")));
                for(unsigned int j = 0; j < orte->size(); j++) {
                    if(verbindenGraph[i][j] > 0) {
                        str = str +  QString::fromStdString(orte->at(j)->getPara() +  ": ");
                        str = str + QString::number(verbindenGraph[i][j])+ " km; ";
                    }
                }
            }
            model->setItem(0, 5, new QStandardItem(str));
            tableView->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
            tableView->horizontalHeader()->setSectionResizeMode(1, QHeaderView::ResizeToContents);
            tableView->horizontalHeader()->setSectionResizeMode(2, QHeaderView::ResizeToContents);
            tableView->horizontalHeader()->setSectionResizeMode(3, QHeaderView::ResizeToContents);
            tableView->horizontalHeader()->setSectionResizeMode(4, QHeaderView::ResizeToContents);
            tableView->horizontalHeader()->setSectionResizeMode(5, QHeaderView::ResizeToContents);
            dialog->show();
            break;
        }
    }
}

void Karte::AlleOrte_Clicked()
{
    QDialog *dialog = new QDialog();
    QVBoxLayout *layout = new QVBoxLayout(dialog);
    QStandardItemModel *model = new QStandardItemModel(orte->size(), 4, dialog);
    QTableView *tableView = new QTableView(dialog);

    dialog->setGeometry(0,0,400,900);
    layout->addWidget(tableView);
    dialog->setLayout(layout);

    model->setHorizontalHeaderItem(0, new QStandardItem("Id"));
    model->setHorizontalHeaderItem(1, new QStandardItem("Typ"));
    model->setHorizontalHeaderItem(2, new QStandardItem("Stadt"));
    model->setHorizontalHeaderItem(3, new QStandardItem("Bemerkung"));
    tableView->setModel(model);
    tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    for(unsigned int i = 0; i < orte->size(); i++) {
        if(radioButtonsList[i]->isCheckable()) { // Zeige nur Orte, die auf der Karte sichtbar sind.
            Adresse *A = dynamic_cast<Adresse*>(orte->at(i));
            if(A != nullptr) {
                model->setItem(i,0, new QStandardItem(QString::number(A->getID())));
                model->setItem(i,1, new QStandardItem(QString("Adr")));
                model->setItem(i,2, new QStandardItem(QString::fromStdString(A->getStadt())));
                continue;
            }

            PoI *P = dynamic_cast<PoI*>(orte->at(i));
            if(P != nullptr) {
                model->setItem(i,0, new QStandardItem(QString::number(P->getID())));
                model->setItem(i,1, new QStandardItem(QString("PoI")));
                model->setItem(i,3, new QStandardItem(QString::fromStdString(P->getBemerkung())));
                continue;
            }
        }
    }
    tableView->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
    tableView->horizontalHeader()->setSectionResizeMode(1, QHeaderView::ResizeToContents);
    tableView->horizontalHeader()->setSectionResizeMode(2, QHeaderView::ResizeToContents);
    tableView->horizontalHeader()->setSectionResizeMode(3, QHeaderView::ResizeToContents);

    dialog->show();
}
