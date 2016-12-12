#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "weath.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    weath w[32];
    int no;
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_Accept_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_month_activated(const QString &arg1);

    void on_pushButton_3_clicked();

    void on_exit_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
