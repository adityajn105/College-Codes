#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "book.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    book *b[30];
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_search_clicked();

    void on_add_clicked();

    void on_pushButton_clicked();

    void on_issue_clicked();

    void on_exit_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
