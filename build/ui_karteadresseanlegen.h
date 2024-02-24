/********************************************************************************
** Form generated from reading UI file 'karteadresseanlegen.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KARTEADRESSEANLEGEN_H
#define UI_KARTEADRESSEANLEGEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_KarteAdresseAnlegen
{
public:
    QLabel *Laengengrad;
    QLabel *Breitengrad;
    QLabel *Strasse;
    QLabel *Hausnummer;
    QLabel *Postleitzahl;
    QPushButton *Bestaetigen;
    QLabel *Stadt;
    QLineEdit *LaengengradLine;
    QLineEdit *BreitengradLine;
    QLineEdit *StrasseLine;
    QLineEdit *HausnummerLine;
    QLineEdit *PostleitzahlLine;
    QLineEdit *StadtLine;

    void setupUi(QDialog *KarteAdresseAnlegen)
    {
        if (KarteAdresseAnlegen->objectName().isEmpty())
            KarteAdresseAnlegen->setObjectName(QString::fromUtf8("KarteAdresseAnlegen"));
        KarteAdresseAnlegen->resize(400, 300);
        Laengengrad = new QLabel(KarteAdresseAnlegen);
        Laengengrad->setObjectName(QString::fromUtf8("Laengengrad"));
        Laengengrad->setGeometry(QRect(40, 90, 81, 16));
        Breitengrad = new QLabel(KarteAdresseAnlegen);
        Breitengrad->setObjectName(QString::fromUtf8("Breitengrad"));
        Breitengrad->setGeometry(QRect(40, 60, 81, 16));
        Strasse = new QLabel(KarteAdresseAnlegen);
        Strasse->setObjectName(QString::fromUtf8("Strasse"));
        Strasse->setGeometry(QRect(40, 120, 57, 15));
        Hausnummer = new QLabel(KarteAdresseAnlegen);
        Hausnummer->setObjectName(QString::fromUtf8("Hausnummer"));
        Hausnummer->setGeometry(QRect(40, 150, 81, 16));
        Postleitzahl = new QLabel(KarteAdresseAnlegen);
        Postleitzahl->setObjectName(QString::fromUtf8("Postleitzahl"));
        Postleitzahl->setGeometry(QRect(40, 180, 81, 16));
        Bestaetigen = new QPushButton(KarteAdresseAnlegen);
        Bestaetigen->setObjectName(QString::fromUtf8("Bestaetigen"));
        Bestaetigen->setGeometry(QRect(260, 250, 80, 23));
        Stadt = new QLabel(KarteAdresseAnlegen);
        Stadt->setObjectName(QString::fromUtf8("Stadt"));
        Stadt->setGeometry(QRect(40, 210, 81, 16));
        LaengengradLine = new QLineEdit(KarteAdresseAnlegen);
        LaengengradLine->setObjectName(QString::fromUtf8("LaengengradLine"));
        LaengengradLine->setGeometry(QRect(230, 80, 113, 23));
        BreitengradLine = new QLineEdit(KarteAdresseAnlegen);
        BreitengradLine->setObjectName(QString::fromUtf8("BreitengradLine"));
        BreitengradLine->setGeometry(QRect(230, 50, 113, 23));
        StrasseLine = new QLineEdit(KarteAdresseAnlegen);
        StrasseLine->setObjectName(QString::fromUtf8("StrasseLine"));
        StrasseLine->setGeometry(QRect(230, 110, 113, 23));
        HausnummerLine = new QLineEdit(KarteAdresseAnlegen);
        HausnummerLine->setObjectName(QString::fromUtf8("HausnummerLine"));
        HausnummerLine->setGeometry(QRect(230, 140, 113, 23));
        PostleitzahlLine = new QLineEdit(KarteAdresseAnlegen);
        PostleitzahlLine->setObjectName(QString::fromUtf8("PostleitzahlLine"));
        PostleitzahlLine->setGeometry(QRect(230, 170, 113, 23));
        StadtLine = new QLineEdit(KarteAdresseAnlegen);
        StadtLine->setObjectName(QString::fromUtf8("StadtLine"));
        StadtLine->setGeometry(QRect(230, 200, 113, 23));

        retranslateUi(KarteAdresseAnlegen);

        QMetaObject::connectSlotsByName(KarteAdresseAnlegen);
    } // setupUi

    void retranslateUi(QDialog *KarteAdresseAnlegen)
    {
        KarteAdresseAnlegen->setWindowTitle(QCoreApplication::translate("KarteAdresseAnlegen", "Dialog", nullptr));
        Laengengrad->setText(QCoreApplication::translate("KarteAdresseAnlegen", "Laengengrad", nullptr));
        Breitengrad->setText(QCoreApplication::translate("KarteAdresseAnlegen", "Breitengrad", nullptr));
        Strasse->setText(QCoreApplication::translate("KarteAdresseAnlegen", "Strasse", nullptr));
        Hausnummer->setText(QCoreApplication::translate("KarteAdresseAnlegen", "Hausnummer", nullptr));
        Postleitzahl->setText(QCoreApplication::translate("KarteAdresseAnlegen", "Postleitzahl", nullptr));
        Bestaetigen->setText(QCoreApplication::translate("KarteAdresseAnlegen", "Bestaetigen", nullptr));
        Stadt->setText(QCoreApplication::translate("KarteAdresseAnlegen", "Stadt", nullptr));
    } // retranslateUi

};

namespace Ui {
    class KarteAdresseAnlegen: public Ui_KarteAdresseAnlegen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KARTEADRESSEANLEGEN_H
