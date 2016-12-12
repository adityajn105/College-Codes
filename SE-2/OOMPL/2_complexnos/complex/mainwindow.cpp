#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qmessagebox.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

comp::comp()
{
    real=0;
    img=0;
}

comp::comp(float r,float i)
{
    real=r;
    img=i;

}

comp comp::operator+(comp c)
{

    return comp(real+c.real,img+c.img);
}




void MainWindow::on_pushButton_clicked()
{
    if(ui->real1->text()==NULL||ui->img1->text()==NULL||ui->real2->text()==NULL||ui->img2->text()==NULL)
    {
        QMessageBox::information(this,"Validation","Please Enter Data");
    }
    comp *c1=new comp(ui->real1->text().toFloat(),ui->img1->text().toFloat());
    comp *c2=new comp(ui->real2->text().toFloat(),ui->img2->text().toFloat());
    comp *c3=new comp;

    *c3=*c1+*c2;
    QString r,i;
    r=QString::number(c3->real,10.1);
    i=QString::number(c3->img,10.1);
    ui->real->setText(r);
    ui->img->setText(i);
}





void MainWindow::on_pushButton_5_clicked()
{
    ui->real->clear();
    ui->img->clear();
    ui->real1->clear();
    ui->img1->clear();
    ui->real2->clear();
    ui->img2->clear();
}

comp comp::operator -(comp c)
{
    comp temp;
    temp.real=real-c.real;
    temp.img=img-c.img;
    return temp;
}


void MainWindow::on_pushButton_2_clicked()
{
    if(ui->real1->text()==NULL||ui->img1->text()==NULL||ui->real2->text()==NULL||ui->img2->text()==NULL)
    {
        QMessageBox::information(this,"Validation","Please Enter Data");
    }
    comp *c1=new comp(ui->real1->text().toFloat(),ui->img1->text().toFloat());
    comp *c2=new comp(ui->real2->text().toFloat(),ui->img2->text().toFloat());
    comp *c3=new comp;

    *c3=*c1-*c2;
    QString r,i;
    r=QString::number(c3->real,10.1);
    i=QString::number(c3->img,10.1);
    ui->real->setText(r);
    ui->img->setText(i);

}
comp comp::operator *(comp c)
{

    return comp((c.real*real)-(c.img*img),(img*c.real)+(c.img*real));

}

void MainWindow::on_pushButton_4_clicked()
{
    if(ui->real1->text()==NULL||ui->img1->text()==NULL||ui->real2->text()==NULL||ui->img2->text()==NULL)
    {
        QMessageBox::information(this,"Validation","Please Enter Data");
    }
    comp *c1=new comp(ui->real1->text().toFloat(),ui->img1->text().toFloat());
    comp *c2=new comp(ui->real2->text().toFloat(),ui->img2->text().toFloat());
    comp *c3=new comp;

    *c3=*c1* *c2;
    QString r,i;
    r=QString::number(c3->real,10.1);
    i=QString::number(c3->img,10.1);
    ui->real->setText(r);
    ui->img->setText(i);
}


comp operator /(comp c1,comp c2)
{
    comp temp;
    temp.real=((c1.real*c2.real)+(c1.img*c2.img))/((c2.real*c2.real)+(c2.img*c2.img));
    temp.img=((c1.img*c2.real)-(c1.real*c2.img))/((c2.real*c2.real)+(c2.img*c2.img));
    return temp;
}

void MainWindow::on_pushButton_3_clicked()
{
    if(ui->real1->text()==NULL||ui->img1->text()==NULL||ui->real2->text()==NULL||ui->img2->text()==NULL)
    {
        QMessageBox::information(this,"Validation","Please Enter Data");
    }
    comp *c1=new comp(ui->real1->text().toFloat(),ui->img1->text().toFloat());
    comp *c2=new comp(ui->real2->text().toFloat(),ui->img2->text().toFloat());
    comp *c3=new comp;

    *c3=*c1/ *c2;
    QString r,i;
    r=QString::number(c3->real,10.1);
    i=QString::number(c3->img,10.1);
    ui->real->setText(r);
    ui->img->setText(i);
}

void MainWindow::on_pushButton_6_clicked()
{
    this->close();
}
