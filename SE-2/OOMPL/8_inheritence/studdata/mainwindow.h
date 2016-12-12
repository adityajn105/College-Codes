#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"student.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    result *s[10];
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_accept_clicked();

    void on_display_clicked();

    void on_search_clicked();

    void on_edit_clicked();

    void on_save_clicked();

    void on_clear_clicked();

    void on_del_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
