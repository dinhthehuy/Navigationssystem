#include "kartepoianlegen.h"
#include "ui_kartepoianlegen.h"

KartePoIAnlegen::KartePoIAnlegen(QWidget *parent, vector<Ort*> *v, QGraphicsScene *scene, QButtonGroup *group, QList<QAbstractButton*> *radioButtonsList, vector<vector<double>> *verbindenGraph) :
    QDialog(parent),
    ui(new Ui::KartePoIAnlegen), list(v), scene(scene), group(group), radioButtonsList(radioButtonsList), verbindenGraph(verbindenGraph)
{
    ui->setupUi(this);
    connect(ui->Bestaetigen, SIGNAL(clicked()), this, SLOT(SubmitButton_Clicked()));
}

KartePoIAnlegen::~KartePoIAnlegen()
{
    delete ui;
}

void KartePoIAnlegen::SubmitButton_Clicked() {
    double Laengengrad = ui->LaengengradLine->text().toDouble();
    double Breitengrad = ui->BreitengradLine->text().toDouble();
    string Kategorie = ui->KategorieLine->text().toStdString();
    string Bemerkung = ui->BemerkungLine->text().toStdString();

    if(Laengengrad != 0 && Breitengrad != 0) {
        list->push_back(new PoI(Laengengrad, Breitengrad, list->size()+1, Kategorie, Bemerkung));

        QRadioButton *button = new QRadioButton(QString::fromStdString(Bemerkung));
        int y = (1246 / (47.270111 - 55.099167)) * (Breitengrad - 55.099167);
        int x = (923 / (15.041932 - 5.866306)) * (Laengengrad - 5.866306);

        button->setGeometry(x, y, 99, 21);
        button->setStyleSheet(
                    "QRadioButton { color: black; background-color: transparent;  }"
                    "QRadioButton::indicator { width: 16px; height: 16px; border-radius: 8px; background-color: gray;}"
                    "QRadioButton::indicator:checked { background-color: red; }"
                    );
        group->addButton(button, list->size()-1);
        scene->addWidget(button);
        radioButtonsList->push_back(button);

        // aktualisiere adjacent Matrix
        for(unsigned int i = 0; i < list->size(); i++) {
            verbindenGraph->at(i).push_back(0);
            verbindenGraph->at(list->size()-1).push_back(0);
        }

        // Verbinde mit zwei am naechsten Orten
        double first, second;
        unsigned int id0, id1, id2;
        first = second = INT_MAX;
        id0 = list->size()-1;
        id1 = id2 = 0;
        for(unsigned int j = 0; j < list->size(); j++) {

            if(id0==j || !radioButtonsList->at(j)->isCheckable()) continue;

            if(list->at(id0)->distanz(*list->at(j)) < first) {
                second = first;
                first = list->at(id0)->distanz(*list->at(j));
                id2 = id1;
                id1 = j;
            } else if(list->at(id0)->distanz(*list->at(j)) < second && list->at(id0)->distanz(*list->at(j)) != first) {
                second = list->at(id0)->distanz(*list->at(j));
                id2 = j;
            }
        }

        verbindenGraph->at(id0)[id1] = list->at(id0)->distanz(*list->at(id1));
        verbindenGraph->at(id1)[id0] = list->at(id0)->distanz(*list->at(id1));

        verbindenGraph->at(id0)[id2] = list->at(id0)->distanz(*list->at(id2));
        verbindenGraph->at(id2)[id0] = list->at(id0)->distanz(*list->at(id2));

        QPen pen(Qt::gray);
        pen.setWidth(5);
        scene->addLine(radioButtonsList->at(id0)->x()+10, radioButtonsList->at(id0)->y()+10, radioButtonsList->at(id1)->x()+10, radioButtonsList->at(id1)->y()+10, pen);
        scene->addLine(radioButtonsList->at(id0)->x()+10, radioButtonsList->at(id0)->y()+10, radioButtonsList->at(id2)->x()+10, radioButtonsList->at(id2)->y()+10, pen);

        close();
    }
}
