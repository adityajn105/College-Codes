#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "stri.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    str *s1,*s2,*s3;

private slots:
    void on_pushButton_clicked();

    void on_len_clicked();

    void on_pushButton_2_clicked();

    void on_rev_clicked();

    void on_pali_clicked();

    void on_close_clicked();

    void on_reset_clicked();

    void on_equal_clicked();

    void on_substring_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
