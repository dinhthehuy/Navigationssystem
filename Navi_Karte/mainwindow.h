#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include "poi.h"
#include "adresse.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "karte.h"

using namespace std;
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Ort* findID(int id);

private slots:
    void addPoI();
    void addAdr();
    void berechnen();
    void csvExport();
    void csvImport();
    void karte();
    void alleOrte();

private:
    Ui::MainWindow *ui;
    vector<Ort*> orte = {};
    Karte *k;

    void updateTable();
};
#endif // MAINWINDOW_H
