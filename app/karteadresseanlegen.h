#ifndef KARTEADRESSEANLEGEN_H
#define KARTEADRESSEANLEGEN_H

#include <QDialog>
#include <QGraphicsScene>
#include <QButtonGroup>
#include <QRadioButton>
#include "ort.h"
#include "adresse.h"
#include <iostream>

using namespace std;

namespace Ui {
class KarteAdresseAnlegen;
}

class KarteAdresseAnlegen : public QDialog
{
    Q_OBJECT

public:
    explicit KarteAdresseAnlegen(QWidget *parent = nullptr, vector<Ort*> *v = {}, QGraphicsScene *scene = nullptr,
                                 QButtonGroup *group = nullptr, QList<QAbstractButton*> *radioButtonsList = nullptr,
                                 vector<vector<double>> *verbindenGraph = nullptr);
    ~KarteAdresseAnlegen();

private:
    Ui::KarteAdresseAnlegen *ui;
    vector<Ort*> *list;
    QGraphicsScene *scene;
    QButtonGroup *group;
    QList<QAbstractButton*> *radioButtonsList;
    vector<vector<double>> *verbindenGraph;

private slots:
    void SubmitButton_Clicked();
};

#endif // KARTEADRESSEANLEGEN_H
