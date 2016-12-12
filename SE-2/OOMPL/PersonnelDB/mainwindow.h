#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include "person.h"
#include <QTableWidgetItem>
#include <fstream>
#include "record.h"
#include <iostream>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QVector<Person> *v;
    void updateTable(int index);
    std::fstream dataFile;
    Record* readFile(std::fstream&);
    void writeFile(std::fstream&, Record&);
    void updateFile();
private slots:
    void on_btnAccept_clicked();

    void on_btnSearch_clicked();

    void on_tableWidget_itemDoubleClicked(QTableWidgetItem *item);

    void on_btnModify_clicked();

    void on_btnDelete_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
