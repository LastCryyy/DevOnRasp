/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QGroupBox>
#include <QHeaderView>
#include <QLabel>
#include <QLineEdit>
#include <QMainWindow>
#include <QMenuBar>
#include <QPushButton>
#include <QStatusBar>
#include <QTextEdit>
#include <QToolBar>
#include <QWidget>
#include "qcustomplot.h"


QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGroupBox *groupBox_2;
    QLabel *label;
    QLineEdit *txt_port;
    QPushButton *bt_start_server;
    QTextEdit *txt_output;
    QCustomPlot *graph;
    QPushButton *bt_save;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1093, 702);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(0, 10, 191, 111));
        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 40, 61, 16));
        txt_port = new QLineEdit(groupBox_2);
        txt_port->setObjectName(QStringLiteral("txt_port"));
        txt_port->setGeometry(QRect(60, 40, 113, 21));
        txt_port->setMaxLength(5);
        txt_port->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        bt_start_server = new QPushButton(groupBox_2);
        bt_start_server->setObjectName(QStringLiteral("bt_start_server"));
        bt_start_server->setGeometry(QRect(60, 70, 113, 41));
        txt_output = new QTextEdit(centralWidget);
        txt_output->setObjectName(QStringLiteral("txt_output"));
        txt_output->setGeometry(QRect(10, 170, 181, 461));
        graph = new QCustomPlot(centralWidget);
        graph->setObjectName(QStringLiteral("graph"));
        graph->setGeometry(QRect(200, 10, 881, 631));
        graph->setAutoFillBackground(false);
        bt_save = new QPushButton(centralWidget);
        bt_save->setObjectName(QStringLiteral("bt_save"));
        bt_save->setGeometry(QRect(60, 130, 113, 32));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1093, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Setting", 0));
        label->setText(QApplication::translate("MainWindow", "Port : ", 0));
        txt_port->setText(QApplication::translate("MainWindow", "65000", 0));
        bt_start_server->setText(QApplication::translate("MainWindow", "Start Server", 0));
        bt_save->setText(QApplication::translate("MainWindow", "Save", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
