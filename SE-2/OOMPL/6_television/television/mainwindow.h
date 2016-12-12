#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"tele.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    tele t;
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void operator>>(tele&);
    void operator<<(tele&);
    
private slots:
    void on_accept_clicked();

    void on_display_clicked();

    void on_exit_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
