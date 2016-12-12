#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "personal.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{ 
    Q_OBJECT

public:
    personal dataobj;
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_accept_clicked();

    void on_display_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
