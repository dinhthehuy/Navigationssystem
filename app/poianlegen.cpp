#include "poianlegen.h"
#include "ui_poianlegen.h"

PoIAnlegen::PoIAnlegen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PoIAnlegen)
{
    ui->setupUi(this);
}

PoIAnlegen::~PoIAnlegen()
{
    delete ui;
}
