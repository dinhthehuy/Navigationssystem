#ifndef KARTE_H
#define KARTE_H

#include <QDialog>
#include "poi.h"
#include "adresse.h"
#include "karteadresseanlegen.h"
#include "kartepoianlegen.h"
#include <QWidget>
#include <QPixmap>
#include <QApplication>
#include <QLabel>
#include <QGraphicsScene>
#include <QRadioButton>
#include <QButtonGroup>
#include <QStandardItemModel>
#include <QTableView>
#include <QHeaderView>
#include <QVBoxLayout>
#include <QComboBox>

namespace Ui { class Karte; }

class Karte : public QDialog
{
    Q_OBJECT

public:
    explicit Karte(QWidget *parent = nullptr, vector<Ort*> *v = nullptr);
    ~Karte();
    void update();
    void verbinden(Ort* o1, Ort* o2);

private:
    Ui::Karte *ui;
    vector<Ort*> *orte;
    QGraphicsScene *scene = new QGraphicsScene(this);
    QButtonGroup *group = new QButtonGroup(this);
    QList<QAbstractButton*> radioButtonsList = {};
    QLabel *label;
    QTableView *tableView;
    QComboBox *ortArten = new QComboBox();
    int count = 0;

    vector<vector<double>> verbindenGraph;

    KarteAdresseAnlegen *kA = new KarteAdresseAnlegen(this, orte, scene, group, &radioButtonsList, &verbindenGraph);
    KartePoIAnlegen *kP = new KartePoIAnlegen(this, orte, scene, group, &radioButtonsList, &verbindenGraph);

    void verbindenMitZweiNachbar(unsigned int i);
    int miniDist(int distance[], bool visited[]);
    void DijkstraAlgo(int startNode, unsigned   int endNode, vector<int>& path);
    void getPath(vector<int>& parent, int v, vector<int>& path);

private slots:
    void QRadioButton_Clicked(int id);
    void Entfernung();
    void Information();
    void AlleOrte_Clicked();
    void Laden_Clicked();
    void Routing();
    void Speichern_Clicked();
    void Verbinden_Clicked();
    void OrtAnlegen();
    void OrtLoeschen();
};

#endif // KARTE_H
