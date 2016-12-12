/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Mon Dec 28 15:03:02 2015
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
#include <QtGui/QComboBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTableWidget>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *rain_2;
    QTableWidget *tableWidget;
    QLineEdit *snow;
    QPushButton *pushButton_2;
    QTableWidget *tableWidget_2;
    QLineEdit *rain;
    QLabel *Year_2;
    QLabel *snow_2;
    QLabel *htemp_2;
    QLineEdit *year;
    QLineEdit *ltemp;
    QLabel *ltemp_2;
    QPushButton *pushButton;
    QLineEdit *htemp;
    QPushButton *Accept;
    QComboBox *Day;
    QComboBox *month;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(797, 440);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        rain_2 = new QLabel(centralWidget);
        rain_2->setObjectName(QString::fromUtf8("rain_2"));
        rain_2->setGeometry(QRect(430, 50, 67, 17));
        tableWidget = new QTableWidget(centralWidget);
        if (tableWidget->columnCount() < 5)
            tableWidget->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(170, 100, 481, 141));
        snow = new QLineEdit(centralWidget);
        snow->setObjectName(QString::fromUtf8("snow"));
        snow->setGeometry(QRect(280, 50, 113, 27));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(40, 140, 99, 27));
        tableWidget_2 = new QTableWidget(centralWidget);
        if (tableWidget_2->columnCount() < 4)
            tableWidget_2->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(1, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(2, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(3, __qtablewidgetitem8);
        if (tableWidget_2->rowCount() < 2)
            tableWidget_2->setRowCount(2);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget_2->setVerticalHeaderItem(0, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget_2->setVerticalHeaderItem(1, __qtablewidgetitem10);
        tableWidget_2->setObjectName(QString::fromUtf8("tableWidget_2"));
        tableWidget_2->setGeometry(QRect(170, 250, 481, 91));
        rain = new QLineEdit(centralWidget);
        rain->setObjectName(QString::fromUtf8("rain"));
        rain->setGeometry(QRect(480, 50, 113, 27));
        Year_2 = new QLabel(centralWidget);
        Year_2->setObjectName(QString::fromUtf8("Year_2"));
        Year_2->setGeometry(QRect(30, 10, 67, 17));
        snow_2 = new QLabel(centralWidget);
        snow_2->setObjectName(QString::fromUtf8("snow_2"));
        snow_2->setGeometry(QRect(230, 50, 67, 17));
        htemp_2 = new QLabel(centralWidget);
        htemp_2->setObjectName(QString::fromUtf8("htemp_2"));
        htemp_2->setGeometry(QRect(510, 10, 71, 17));
        year = new QLineEdit(centralWidget);
        year->setObjectName(QString::fromUtf8("year"));
        year->setGeometry(QRect(60, 10, 113, 27));
        ltemp = new QLineEdit(centralWidget);
        ltemp->setObjectName(QString::fromUtf8("ltemp"));
        ltemp->setGeometry(QRect(100, 50, 113, 27));
        ltemp_2 = new QLabel(centralWidget);
        ltemp_2->setObjectName(QString::fromUtf8("ltemp_2"));
        ltemp_2->setGeometry(QRect(20, 50, 81, 17));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(40, 280, 99, 27));
        htemp = new QLineEdit(centralWidget);
        htemp->setObjectName(QString::fromUtf8("htemp"));
        htemp->setGeometry(QRect(590, 10, 113, 27));
        Accept = new QPushButton(centralWidget);
        Accept->setObjectName(QString::fromUtf8("Accept"));
        Accept->setGeometry(QRect(610, 50, 99, 27));
        Day = new QComboBox(centralWidget);
        Day->setObjectName(QString::fromUtf8("Day"));
        Day->setGeometry(QRect(300, 10, 78, 27));
        month = new QComboBox(centralWidget);
        month->setObjectName(QString::fromUtf8("month"));
        month->setGeometry(QRect(190, 10, 78, 27));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 797, 25));
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
        rain_2->setText(QApplication::translate("MainWindow", "rain", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Day", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "High Temp", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "low temp", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "Rain", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "snow", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("MainWindow", "Display", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_2->horizontalHeaderItem(0);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "High temp", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget_2->horizontalHeaderItem(1);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "Low Temp", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget_2->horizontalHeaderItem(2);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWindow", "Rain", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget_2->horizontalHeaderItem(3);
        ___qtablewidgetitem8->setText(QApplication::translate("MainWindow", "snow", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget_2->verticalHeaderItem(0);
        ___qtablewidgetitem9->setText(QApplication::translate("MainWindow", "Total", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget_2->verticalHeaderItem(1);
        ___qtablewidgetitem10->setText(QApplication::translate("MainWindow", "Average", 0, QApplication::UnicodeUTF8));
        Year_2->setText(QApplication::translate("MainWindow", "Year", 0, QApplication::UnicodeUTF8));
        snow_2->setText(QApplication::translate("MainWindow", "snow", 0, QApplication::UnicodeUTF8));
        htemp_2->setText(QApplication::translate("MainWindow", "High Temp", 0, QApplication::UnicodeUTF8));
        ltemp_2->setText(QApplication::translate("MainWindow", "Low Temp", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWindow", "Average", 0, QApplication::UnicodeUTF8));
        Accept->setText(QApplication::translate("MainWindow", "Accept", 0, QApplication::UnicodeUTF8));
        month->clear();
        month->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Jan", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Feb", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Mar", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Apr", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "May", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Jun", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Jul", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Aug", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Sep", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Oct", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Nov", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Dec", 0, QApplication::UnicodeUTF8)
        );
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
