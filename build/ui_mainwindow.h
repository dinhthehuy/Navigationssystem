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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *csvExportButton;
    QLabel *labelStatusValue;
    QPushButton *csvImportButton;
    QLabel *label_15;
    QPushButton *karteButton;
    QPushButton *alleOrtePushButton;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(464, 296);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        csvExportButton = new QPushButton(centralwidget);
        csvExportButton->setObjectName(QString::fromUtf8("csvExportButton"));
        csvExportButton->setGeometry(QRect(180, 200, 81, 31));
        labelStatusValue = new QLabel(centralwidget);
        labelStatusValue->setObjectName(QString::fromUtf8("labelStatusValue"));
        labelStatusValue->setGeometry(QRect(250, 250, 151, 21));
        labelStatusValue->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        csvImportButton = new QPushButton(centralwidget);
        csvImportButton->setObjectName(QString::fromUtf8("csvImportButton"));
        csvImportButton->setGeometry(QRect(180, 150, 81, 31));
        label_15 = new QLabel(centralwidget);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(180, 250, 41, 20));
        karteButton = new QPushButton(centralwidget);
        karteButton->setObjectName(QString::fromUtf8("karteButton"));
        karteButton->setGeometry(QRect(180, 50, 80, 31));
        alleOrtePushButton = new QPushButton(centralwidget);
        alleOrtePushButton->setObjectName(QString::fromUtf8("alleOrtePushButton"));
        alleOrtePushButton->setGeometry(QRect(180, 100, 80, 31));
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
        csvExportButton->setText(QCoreApplication::translate("MainWindow", "Export", nullptr));
        labelStatusValue->setText(QCoreApplication::translate("MainWindow", "OK", nullptr));
        csvImportButton->setText(QCoreApplication::translate("MainWindow", "Import", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "Status:", nullptr));
        karteButton->setText(QCoreApplication::translate("MainWindow", "Karte", nullptr));
        alleOrtePushButton->setText(QCoreApplication::translate("MainWindow", "Alle Orte", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
