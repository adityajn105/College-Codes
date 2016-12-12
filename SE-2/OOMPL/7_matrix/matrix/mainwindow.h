#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"matrix.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    matrix <int> a,b,res1;
    matrix <float>p,q,res2;
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_add_clicked();

    void on_accept_clicked();

    void on_disp_clicked();

    void on_integer_clicked();

    void on_floating_clicked();

    void on_sub_clicked();

    void on_mul_clicked();

    void on_transA_clicked();

    void on_transB_clicked();

    void on_exit_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
