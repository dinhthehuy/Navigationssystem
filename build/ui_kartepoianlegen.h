/********************************************************************************
** Form generated from reading UI file 'kartepoianlegen.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KARTEPOIANLEGEN_H
#define UI_KARTEPOIANLEGEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_KartePoIAnlegen
{
public:
    QPushButton *Bestaetigen;
    QLabel *Laengengrad;
    QLabel *Breitengrad;
    QLabel *Kategorie;
    QLabel *Bemerkung;
    QLineEdit *LaengengradLine;
    QLineEdit *BreitengradLine;
    QLineEdit *KategorieLine;
    QLineEdit *BemerkungLine;

    void setupUi(QDialog *KartePoIAnlegen)
    {
        if (KartePoIAnlegen->objectName().isEmpty())
            KartePoIAnlegen->setObjectName(QString::fromUtf8("KartePoIAnlegen"));
        KartePoIAnlegen->resize(400, 252);
        Bestaetigen = new QPushButton(KartePoIAnlegen);
        Bestaetigen->setObjectName(QString::fromUtf8("Bestaetigen"));
        Bestaetigen->setGeometry(QRect(270, 200, 80, 23));
        Laengengrad = new QLabel(KartePoIAnlegen);
        Laengengrad->setObjectName(QString::fromUtf8("Laengengrad"));
        Laengengrad->setGeometry(QRect(30, 100, 81, 16));
        Breitengrad = new QLabel(KartePoIAnlegen);
        Breitengrad->setObjectName(QString::fromUtf8("Breitengrad"));
        Breitengrad->setGeometry(QRect(30, 70, 81, 16));
        Kategorie = new QLabel(KartePoIAnlegen);
        Kategorie->setObjectName(QString::fromUtf8("Kategorie"));
        Kategorie->setGeometry(QRect(30, 130, 71, 16));
        Bemerkung = new QLabel(KartePoIAnlegen);
        Bemerkung->setObjectName(QString::fromUtf8("Bemerkung"));
        Bemerkung->setGeometry(QRect(30, 160, 81, 16));
        LaengengradLine = new QLineEdit(KartePoIAnlegen);
        LaengengradLine->setObjectName(QString::fromUtf8("LaengengradLine"));
        LaengengradLine->setGeometry(QRect(240, 100, 113, 23));
        BreitengradLine = new QLineEdit(KartePoIAnlegen);
        BreitengradLine->setObjectName(QString::fromUtf8("BreitengradLine"));
        BreitengradLine->setGeometry(QRect(240, 70, 113, 23));
        KategorieLine = new QLineEdit(KartePoIAnlegen);
        KategorieLine->setObjectName(QString::fromUtf8("KategorieLine"));
        KategorieLine->setGeometry(QRect(240, 130, 113, 23));
        BemerkungLine = new QLineEdit(KartePoIAnlegen);
        BemerkungLine->setObjectName(QString::fromUtf8("BemerkungLine"));
        BemerkungLine->setGeometry(QRect(240, 160, 113, 23));

        retranslateUi(KartePoIAnlegen);

        QMetaObject::connectSlotsByName(KartePoIAnlegen);
    } // setupUi

    void retranslateUi(QDialog *KartePoIAnlegen)
    {
        KartePoIAnlegen->setWindowTitle(QCoreApplication::translate("KartePoIAnlegen", "Dialog", nullptr));
        Bestaetigen->setText(QCoreApplication::translate("KartePoIAnlegen", "Bestaetigen", nullptr));
        Laengengrad->setText(QCoreApplication::translate("KartePoIAnlegen", "Laengengrad", nullptr));
        Breitengrad->setText(QCoreApplication::translate("KartePoIAnlegen", "Breitengrad", nullptr));
        Kategorie->setText(QCoreApplication::translate("KartePoIAnlegen", "Kategorie", nullptr));
        Bemerkung->setText(QCoreApplication::translate("KartePoIAnlegen", "Bemerkung", nullptr));
    } // retranslateUi

};

namespace Ui {
    class KartePoIAnlegen: public Ui_KartePoIAnlegen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KARTEPOIANLEGEN_H
