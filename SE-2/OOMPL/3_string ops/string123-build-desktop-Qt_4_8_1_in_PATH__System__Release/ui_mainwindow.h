/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Thu Feb 4 14:35:07 2016
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *string1;
    QLineEdit *string2;
    QLineEdit *string3;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *len;
    QPushButton *rev;
    QPushButton *pali;
    QPushButton *close;
    QPushButton *reset;
    QPushButton *equal;
    QPushButton *substring;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(688, 490);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 10, 66, 17));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 50, 66, 17));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 100, 66, 17));
        string1 = new QLineEdit(centralWidget);
        string1->setObjectName(QString::fromUtf8("string1"));
        string1->setGeometry(QRect(100, 10, 351, 27));
        string2 = new QLineEdit(centralWidget);
        string2->setObjectName(QString::fromUtf8("string2"));
        string2->setGeometry(QRect(100, 50, 351, 27));
        string3 = new QLineEdit(centralWidget);
        string3->setObjectName(QString::fromUtf8("string3"));
        string3->setGeometry(QRect(100, 96, 511, 31));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(60, 200, 98, 27));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(180, 200, 98, 27));
        len = new QPushButton(centralWidget);
        len->setObjectName(QString::fromUtf8("len"));
        len->setGeometry(QRect(290, 200, 98, 27));
        rev = new QPushButton(centralWidget);
        rev->setObjectName(QString::fromUtf8("rev"));
        rev->setGeometry(QRect(410, 200, 98, 27));
        pali = new QPushButton(centralWidget);
        pali->setObjectName(QString::fromUtf8("pali"));
        pali->setGeometry(QRect(520, 200, 131, 27));
        close = new QPushButton(centralWidget);
        close->setObjectName(QString::fromUtf8("close"));
        close->setGeometry(QRect(60, 250, 98, 27));
        reset = new QPushButton(centralWidget);
        reset->setObjectName(QString::fromUtf8("reset"));
        reset->setGeometry(QRect(200, 250, 98, 27));
        reset->setMinimumSize(QSize(98, 27));
        equal = new QPushButton(centralWidget);
        equal->setObjectName(QString::fromUtf8("equal"));
        equal->setGeometry(QRect(320, 250, 111, 27));
        substring = new QPushButton(centralWidget);
        substring->setObjectName(QString::fromUtf8("substring"));
        substring->setGeometry(QRect(460, 250, 131, 27));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 688, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "string1", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "string2", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Result", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWindow", "copy", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("MainWindow", "concate", 0, QApplication::UnicodeUTF8));
        len->setText(QApplication::translate("MainWindow", "length", 0, QApplication::UnicodeUTF8));
        rev->setText(QApplication::translate("MainWindow", "Reverse", 0, QApplication::UnicodeUTF8));
        pali->setText(QApplication::translate("MainWindow", "Check palindrome", 0, QApplication::UnicodeUTF8));
        close->setText(QApplication::translate("MainWindow", "Close", 0, QApplication::UnicodeUTF8));
        reset->setText(QApplication::translate("MainWindow", "Reset", 0, QApplication::UnicodeUTF8));
        equal->setText(QApplication::translate("MainWindow", "Check equality", 0, QApplication::UnicodeUTF8));
        substring->setText(QApplication::translate("MainWindow", "Search Substring", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
