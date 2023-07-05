/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *lineHaus;
    QPushButton *addOrtButton;
    QLineEdit *lineKat;
    QLabel *label_5;
    QLineEdit *lineLon;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label;
    QLabel *label_9;
    QLineEdit *lineLat;
    QLabel *label_13;
    QLineEdit *lineID1;
    QPushButton *addPoIButton;
    QLineEdit *linePLZ;
    QPushButton *csvExportButton;
    QLabel *label_6;
    QLineEdit *lineID2;
    QLabel *label_4;
    QLabel *label_8;
    QLabel *label_7;
    QPushButton *entfernungButton;
    QLineEdit *lineStadt;
    QLineEdit *lineStr;
    QLabel *labelStatusValue;
    QLineEdit *lineBem;
    QPushButton *csvImportButton;
    QLabel *Entfernung;
    QLabel *label_10;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_15;
    QLabel *label_14;
    QPushButton *karteButton;
    QPushButton *alleOrtePushButton;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(784, 363);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        lineHaus = new QLineEdit(centralwidget);
        lineHaus->setObjectName(QString::fromUtf8("lineHaus"));
        lineHaus->setGeometry(QRect(550, 60, 113, 24));
        addOrtButton = new QPushButton(centralwidget);
        addOrtButton->setObjectName(QString::fromUtf8("addOrtButton"));
        addOrtButton->setGeometry(QRect(550, 150, 131, 24));
        lineKat = new QLineEdit(centralwidget);
        lineKat->setObjectName(QString::fromUtf8("lineKat"));
        lineKat->setGeometry(QRect(300, 30, 113, 24));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(480, 30, 51, 20));
        lineLon = new QLineEdit(centralwidget);
        lineLon->setObjectName(QString::fromUtf8("lineLon"));
        lineLon->setGeometry(QRect(70, 30, 113, 24));
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(490, 200, 131, 20));
        label_12 = new QLabel(centralwidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(490, 260, 21, 20));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 30, 21, 16));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(340, 0, 21, 20));
        lineLat = new QLineEdit(centralwidget);
        lineLat->setObjectName(QString::fromUtf8("lineLat"));
        lineLat->setGeometry(QRect(70, 70, 113, 24));
        label_13 = new QLabel(centralwidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(490, 230, 21, 20));
        lineID1 = new QLineEdit(centralwidget);
        lineID1->setObjectName(QString::fromUtf8("lineID1"));
        lineID1->setGeometry(QRect(550, 230, 113, 24));
        addPoIButton = new QPushButton(centralwidget);
        addPoIButton->setObjectName(QString::fromUtf8("addPoIButton"));
        addPoIButton->setGeometry(QRect(300, 90, 101, 24));
        linePLZ = new QLineEdit(centralwidget);
        linePLZ->setObjectName(QString::fromUtf8("linePLZ"));
        linePLZ->setGeometry(QRect(550, 90, 113, 24));
        csvExportButton = new QPushButton(centralwidget);
        csvExportButton->setObjectName(QString::fromUtf8("csvExportButton"));
        csvExportButton->setGeometry(QRect(30, 300, 121, 24));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(450, 60, 81, 20));
        lineID2 = new QLineEdit(centralwidget);
        lineID2->setObjectName(QString::fromUtf8("lineID2"));
        lineID2->setGeometry(QRect(550, 260, 113, 24));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(220, 60, 71, 20));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(490, 120, 41, 20));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(500, 90, 31, 20));
        entfernungButton = new QPushButton(centralwidget);
        entfernungButton->setObjectName(QString::fromUtf8("entfernungButton"));
        entfernungButton->setGeometry(QRect(680, 250, 81, 24));
        lineStadt = new QLineEdit(centralwidget);
        lineStadt->setObjectName(QString::fromUtf8("lineStadt"));
        lineStadt->setGeometry(QRect(550, 120, 113, 24));
        lineStr = new QLineEdit(centralwidget);
        lineStr->setObjectName(QString::fromUtf8("lineStr"));
        lineStr->setGeometry(QRect(550, 30, 113, 24));
        labelStatusValue = new QLabel(centralwidget);
        labelStatusValue->setObjectName(QString::fromUtf8("labelStatusValue"));
        labelStatusValue->setGeometry(QRect(220, 260, 151, 21));
        labelStatusValue->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lineBem = new QLineEdit(centralwidget);
        lineBem->setObjectName(QString::fromUtf8("lineBem"));
        lineBem->setGeometry(QRect(300, 60, 113, 24));
        csvImportButton = new QPushButton(centralwidget);
        csvImportButton->setObjectName(QString::fromUtf8("csvImportButton"));
        csvImportButton->setGeometry(QRect(30, 260, 121, 24));
        Entfernung = new QLabel(centralwidget);
        Entfernung->setObjectName(QString::fromUtf8("Entfernung"));
        Entfernung->setGeometry(QRect(490, 300, 151, 20));
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(570, 0, 51, 20));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 70, 21, 16));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(220, 30, 61, 20));
        label_15 = new QLabel(centralwidget);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(170, 260, 41, 20));
        label_14 = new QLabel(centralwidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(30, 230, 121, 20));
        karteButton = new QPushButton(centralwidget);
        karteButton->setObjectName(QString::fromUtf8("karteButton"));
        karteButton->setGeometry(QRect(320, 180, 80, 51));
        alleOrtePushButton = new QPushButton(centralwidget);
        alleOrtePushButton->setObjectName(QString::fromUtf8("alleOrtePushButton"));
        alleOrtePushButton->setGeometry(QRect(30, 140, 80, 51));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        lineHaus->setText(QCoreApplication::translate("MainWindow", "Hausnummer", nullptr));
        addOrtButton->setText(QCoreApplication::translate("MainWindow", "Addresse hinzuf\303\274gen", nullptr));
        lineKat->setText(QCoreApplication::translate("MainWindow", "Kategorie", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Strasse", nullptr));
        lineLon->setText(QCoreApplication::translate("MainWindow", "Longitude", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Entfernung berechnen", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "ID2", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Lon", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "PoI", nullptr));
        lineLat->setText(QCoreApplication::translate("MainWindow", "Latitude", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "ID1", nullptr));
        lineID1->setText(QCoreApplication::translate("MainWindow", "ID1", nullptr));
        addPoIButton->setText(QCoreApplication::translate("MainWindow", "PoI hinzuf\303\274gen", nullptr));
        linePLZ->setText(QCoreApplication::translate("MainWindow", "plz", nullptr));
        csvExportButton->setText(QCoreApplication::translate("MainWindow", "Export", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Hausnummer", nullptr));
        lineID2->setText(QCoreApplication::translate("MainWindow", "ID2", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Bemerkung", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Stadt", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "PLZ", nullptr));
        entfernungButton->setText(QCoreApplication::translate("MainWindow", "Berechnen", nullptr));
        lineStadt->setText(QCoreApplication::translate("MainWindow", "Stadt", nullptr));
        lineStr->setText(QCoreApplication::translate("MainWindow", "Strasse", nullptr));
        labelStatusValue->setText(QCoreApplication::translate("MainWindow", "OK", nullptr));
        lineBem->setText(QCoreApplication::translate("MainWindow", "Bemerkung", nullptr));
        csvImportButton->setText(QCoreApplication::translate("MainWindow", "Import", nullptr));
        Entfernung->setText(QCoreApplication::translate("MainWindow", "Entfernung:", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Adresse", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Lat", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Kategorie", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "Status:", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Import/Export", nullptr));
        karteButton->setText(QCoreApplication::translate("MainWindow", "Karte", nullptr));
        alleOrtePushButton->setText(QCoreApplication::translate("MainWindow", "Alle Orte", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
