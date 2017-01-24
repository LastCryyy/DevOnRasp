/********************************************************************************
** Form generated from reading UI file 'mainwindow_copy.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_COPY_H
#define UI_MAINWINDOW_COPY_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>
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
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1093, 702);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(0, 10, 191, 111));
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 40, 61, 16));
        txt_port = new QLineEdit(groupBox_2);
        txt_port->setObjectName(QString::fromUtf8("txt_port"));
        txt_port->setGeometry(QRect(60, 40, 113, 21));
        txt_port->setMaxLength(5);
        txt_port->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        bt_start_server = new QPushButton(groupBox_2);
        bt_start_server->setObjectName(QString::fromUtf8("bt_start_server"));
        bt_start_server->setGeometry(QRect(60, 70, 113, 41));
        txt_output = new QTextEdit(centralWidget);
        txt_output->setObjectName(QString::fromUtf8("txt_output"));
        txt_output->setGeometry(QRect(10, 170, 181, 461));
        graph = new QCustomPlot(centralWidget);
        graph->setObjectName(QString::fromUtf8("graph"));
        graph->setGeometry(QRect(200, 10, 881, 631));
        graph->setAutoFillBackground(false);
        bt_save = new QPushButton(centralWidget);
        bt_save->setObjectName(QString::fromUtf8("bt_save"));
        bt_save->setGeometry(QRect(60, 130, 113, 32));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1093, 20));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Setting", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Port : ", 0, QApplication::UnicodeUTF8));
        txt_port->setText(QApplication::translate("MainWindow", "65000", 0, QApplication::UnicodeUTF8));
        bt_start_server->setText(QApplication::translate("MainWindow", "Start Server", 0, QApplication::UnicodeUTF8));
        bt_save->setText(QApplication::translate("MainWindow", "Save", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_COPY_H
