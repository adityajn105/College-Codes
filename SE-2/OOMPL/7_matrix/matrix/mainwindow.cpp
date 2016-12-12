#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "matrix.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->add->setDisabled(1);
    ui->sub->setDisabled(1);
    ui->mul->setDisabled(1);
    ui->accept->setDisabled(1);
    ui->disp->setDisabled(1);
    ui->transA->setDisabled(1);
    ui->transB->setDisabled(1);
}
MainWindow::~MainWindow()
{
    delete ui;
}
template<class T> matrix<T> matrix<T>::multiply(matrix<T>z)
{
    matrix temp;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            for(int k=0;k<3;k++)
            {
                temp.mat[i][j]=temp.mat[i][j]+(mat[i][k]*z.mat[k][j]);
            }
    return temp;
}
void MainWindow::on_add_clicked()
{
     ui->disp->setEnabled(1);
    if(ui->integer->isChecked())
    {
        res1=a.add(b);
    }
    else
    {
        res2=p.add(q);
    }
}

void MainWindow::on_accept_clicked()
{
    ui->add->setEnabled(1);
    ui->sub->setEnabled(1);
    ui->mul->setEnabled(1);
    ui->transA->setEnabled(1);
    ui->transB->setEnabled(1);
    if(ui->integer->isChecked())
    {
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
            {
                a.mat[i][j]=ui->mat1->item(i,j)->text().toInt();
                b.mat[i][j]=ui->mat2->item(i,j)->text().toInt();
            }
    }
    else
    {
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
            {
                p.mat[i][j]=ui->mat1->item(i,j)->text().toFloat();
                q.mat[i][j]=ui->mat2->item(i,j)->text().toFloat();
            }
    }
}

void MainWindow::on_disp_clicked()
{
    if(ui->integer->isChecked())
    {
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                ui->res->setItem(i,j,new QTableWidgetItem(QString::number(res1.mat[i][j])));
    }
    else
    {
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                ui->res->setItem(i,j,new QTableWidgetItem(QString::number(res2.mat[i][j],10.4)));
    }
}

void MainWindow::on_integer_clicked()
{

    ui->accept->setEnabled(1);
}

void MainWindow::on_floating_clicked()
{
    ui->accept->setEnabled(1);

}

void MainWindow::on_sub_clicked()
{
     ui->disp->setEnabled(1);
     if(ui->integer->isChecked())
     {
         res1=a.subtract(b);
     }
     else
     {
         res2=p.subtract(q);
     }
}

void MainWindow::on_mul_clicked()
{
     ui->disp->setEnabled(1);
     if(ui->integer->isChecked())
     {
         res1=a.multiply(b);
     }
     else
     {
         res2=p.multiply(q);
     }
}

void MainWindow::on_transA_clicked()
{
    ui->disp->setEnabled(1);
    if(ui->integer->isChecked())
    {
        res1=a.trans();
    }
    else
    {
        res2=p.trans();
    }
}

void MainWindow::on_transB_clicked()
{
    ui->disp->setEnabled(1);
    if(ui->integer->isChecked())
    {
        res1=b.trans();
    }
    else
    {
        res2=q.trans();
    }
}

void MainWindow::on_exit_clicked()
{
    this->close();
}

void MainWindow::on_pushButton_clicked()
{

}
