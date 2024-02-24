#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVBoxLayout>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QRadioButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    k = new Karte(this, &orte);
    connect(ui->csvExportButton, SIGNAL(clicked()), this, SLOT(csvExport()));
    connect(ui->csvImportButton, SIGNAL(clicked()), this, SLOT(csvImport()));
    connect(ui->karteButton, SIGNAL(clicked()), this, SLOT(karte()));
    connect(ui->alleOrtePushButton, SIGNAL(clicked()), this, SLOT(alleOrte()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::karte() {
    k->setGeometry(0,0, 1100, 1500);
    k->show();
}

void MainWindow::csvExport()
{
    ofstream output ("nav.csv");
    if(!output) {
        ui->labelStatusValue->setText( QString::fromStdString("Fehler beim Oeffnen der Datei!"));
        return;
    }
    for(auto o: orte) {
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
    ui->labelStatusValue->setText(QString::fromStdString("In nav.csv exportiert"));
}

void MainWindow::csvImport()
{
    ifstream input("nav.csv");
    if(!input){
        ui->labelStatusValue->setText( QString::fromStdString("Fehler beim Oeffnen der Datei!"));
        return;
    }
    orte.clear();
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

            orte.push_back(new Adresse(Längengrad, Breitengrad, Id, Straße, Hausnummer, Postleitzahl, Stadt));

        } else {
            string Kategorie;
            string Bemerkung;

            pos = line.find(",");
            Kategorie = line.substr(0, pos);
            line.erase(0, pos+1);

            Bemerkung = line;

            orte.push_back(new PoI(Längengrad, Breitengrad, Id, Kategorie, Bemerkung));
        }
    }
    ui->labelStatusValue->setText(QString::fromStdString("Erfolgreich Importiert"));

}

void MainWindow::alleOrte() {
    QDialog *dialog = new QDialog();
    QVBoxLayout *layout = new QVBoxLayout(dialog);
    QStandardItemModel *model = new QStandardItemModel(orte.size(), 4, dialog);
    QTableView *tableView = new QTableView(dialog);

    dialog->setGeometry(0,0,600,900);
    layout->addWidget(tableView);
    dialog->setLayout(layout);

    model->setHorizontalHeaderItem(0, new QStandardItem("Id"));
    model->setHorizontalHeaderItem(1, new QStandardItem("Typ"));
    model->setHorizontalHeaderItem(2, new QStandardItem("Breitengrad"));
    model->setHorizontalHeaderItem(3, new QStandardItem("Laengengrad"));
    model->setHorizontalHeaderItem(4, new QStandardItem("Parameters"));
    tableView->setModel(model);
    tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    for(unsigned int i = 0; i < orte.size(); i++) {
        model->setItem(i,0, new QStandardItem(QString::number(orte[i]->getID())));
        model->setItem(i,2, new QStandardItem(QString::number(orte[i]->getBreiteg())));
        model->setItem(i,3, new QStandardItem(QString::number(orte[i]->getLaengeg())));
        model->setItem(i,4, new QStandardItem(QString::fromStdString(orte[i]->getPara())));

        Adresse *A = dynamic_cast<Adresse*>(orte[i]);
        if(A != nullptr) {
            model->setItem(i,1, new QStandardItem(QString("Adr")));
            continue;
        }

        PoI *P = dynamic_cast<PoI*>(orte[i]);
        if(P != nullptr) {

            model->setItem(i,1, new QStandardItem(QString("PoI")));
            continue;
        }
    }
    tableView->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
    tableView->horizontalHeader()->setSectionResizeMode(1, QHeaderView::ResizeToContents);
    tableView->horizontalHeader()->setSectionResizeMode(2, QHeaderView::ResizeToContents);
    tableView->horizontalHeader()->setSectionResizeMode(3, QHeaderView::ResizeToContents);
    tableView->horizontalHeader()->setSectionResizeMode(4, QHeaderView::ResizeToContents);

    dialog->show();
}

Ort* MainWindow::findID(int id){
    for(Ort* o : orte){
        if(o->istmeineID(id))
            return o;
    }
    return nullptr;
}
