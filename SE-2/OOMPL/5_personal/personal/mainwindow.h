#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "personal.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    personal *p[30];
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_accept_clicked();

    void on_display_clicked();

    void on_search_clicked();

    void on_mod_clicked();

    void on_pushButton_clicked();

    void on_del_clicked();

    void on_clear_clicked();

    void on_exit_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
