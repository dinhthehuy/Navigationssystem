#ifndef KARTEPOIANLEGEN_H
#define KARTEPOIANLEGEN_H

#include <QDialog>
#include <QGraphicsScene>
#include <QButtonGroup>
#include <QRadioButton>
#include <iostream>
#include "poi.h"

using namespace std;

namespace Ui {
class KartePoIAnlegen;
}

class KartePoIAnlegen : public QDialog
{
    Q_OBJECT

public:
    explicit KartePoIAnlegen(QWidget *parent = nullptr, vector<Ort*> *v = {}, QGraphicsScene *scene = nullptr,
                             QButtonGroup *group = nullptr, QList<QAbstractButton*> *radioButtonsList = nullptr,
                             vector<vector<double>> *verbindenGraph = nullptr);
    ~KartePoIAnlegen();

private:
    Ui::KartePoIAnlegen *ui;
    vector<Ort*> *list;
    QGraphicsScene *scene;
    QButtonGroup *group;
    QList<QAbstractButton*> *radioButtonsList;
    vector<vector<double>> *verbindenGraph;

private slots:
    void SubmitButton_Clicked();
};

#endif // KARTEPOIANLEGEN_H
