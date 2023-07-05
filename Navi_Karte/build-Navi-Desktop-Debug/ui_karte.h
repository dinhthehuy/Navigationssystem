/********************************************************************************
** Form generated from reading UI file 'karte.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KARTE_H
#define UI_KARTE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Karte
{
public:
    QHBoxLayout *horizontalLayout;
    QGraphicsView *graphicsView;

    void setupUi(QDialog *Karte)
    {
        if (Karte->objectName().isEmpty())
            Karte->setObjectName(QString::fromUtf8("Karte"));
        Karte->resize(941, 1264);
        Karte->setLayoutDirection(Qt::LeftToRight);
        horizontalLayout = new QHBoxLayout(Karte);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        graphicsView = new QGraphicsView(Karte);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        horizontalLayout->addWidget(graphicsView);


        retranslateUi(Karte);

        QMetaObject::connectSlotsByName(Karte);
    } // setupUi

    void retranslateUi(QDialog *Karte)
    {
        Karte->setWindowTitle(QCoreApplication::translate("Karte", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Karte: public Ui_Karte {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KARTE_H
