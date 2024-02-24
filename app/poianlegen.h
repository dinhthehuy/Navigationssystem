#ifndef POIANLEGEN_H
#define POIANLEGEN_H

#include <QDialog>

namespace Ui {
class PoIAnlegen;
}

class PoIAnlegen : public QDialog
{
    Q_OBJECT

public:
    explicit PoIAnlegen(QWidget *parent = nullptr);
    ~PoIAnlegen();

private:
    Ui::PoIAnlegen *ui;
};

#endif // POIANLEGEN_H
