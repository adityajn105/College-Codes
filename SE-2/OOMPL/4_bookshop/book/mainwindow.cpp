#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "book.h"
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
book::book()
{
    author=title=publisher='\0';
    price=0;stock=0;
}
int book::count;
void book::accept(QString author,QString title,QString publisher,int price,int stock)
{
    this->author=author;
    this->publisher=publisher;
    this->title=title;
    this->price=price;
    this->stock=stock;

}

void MainWindow::on_add_clicked()
{
    if(ui->title->text().isEmpty()||ui->author->text().isEmpty()||ui->pub->text().isEmpty()||ui->price->text().isEmpty()||ui->stock->text().isEmpty())
    {
        QMessageBox::information(this,"DATABASE ERROR","Enter data proberly");
    }
    QString a,t,p;
    int pr,st;
    a=ui->author->text();
    t=ui->title->text();
    p=ui->pub->text();
    pr=ui->price->text().toInt();
    st=ui->stock->text().toInt();
    b[book::count] =new book;
    b[book::count]->accept(a,t,p,pr,st);
   ui->tableWidget->setRowCount(30);
   ui->tableWidget->setItem(book::count,0,new QTableWidgetItem(a));
   ui->tableWidget->setItem(book::count,1,new QTableWidgetItem(t));
   ui->tableWidget->setItem(book::count,2,new QTableWidgetItem(p));
   ui->tableWidget->setItem(book::count,3,new QTableWidgetItem(ui->price->text()));
   ui->tableWidget->setItem(book::count,4,new QTableWidgetItem(ui->stock->text()));
   book::count+=1;
            ui->author->clear();
            ui->title->clear();
            ui->pub->clear();
            ui->price->clear();
            ui->stock->clear();
}

void MainWindow::on_pushButton_clicked()
{
    if(ui->titles->text().isEmpty()||ui->auths->text().isEmpty())
    {
        QMessageBox::information(this,"SEARCH ERROR","Enter data proberly");
    }
    QString t=ui->titles->text();
    QString a=ui->auths->text();
    int no=0;int i;
    for(i=0;i<book::count;i++)
    {
        if(t==b[i]->title&&a==b[i]->author){no=1;break;}
    }

    QString pr=QString::number(b[i]->price,10);
    QString st=QString::number(b[i]->stock,10);

    if(no==1)
    {QMessageBox::information(this,"BOOK FOUND!",b[i]->title+" by "+b[i]->author+" Found \nPublisher:"
                             +b[i]->publisher+"\nPrice:"+pr+"\nStock:"+st);}
    else
    {QMessageBox::information(this,"BOOK NOT FOUND!","...BOOK NOT IN DATABASE...");
    ui->auths->clear();
    ui->titles->clear();}

}


void MainWindow::on_issue_clicked()
{
    if(ui->titles->text().isEmpty()||ui->auths->text().isEmpty()||ui->quantity->text().isEmpty())
    {
        QMessageBox::information(this,"ISSUE ERROR","Enter data properly");
    }
    QString t=ui->titles->text();
    QString a=ui->auths->text();
    int no=0;int i;
    int q=ui->quantity->text().toInt();
    for(i=0;i<book::count;i++)
    {
        if(t==b[i]->title&&a==b[i]->author){no=1;break;}
    }

    if(no==0)
    {
        QMessageBox::information(this,"Book NOT FOUND!","..BOOK NOT IN DATABASE...");
        ui->auths->clear();
        ui->titles->clear();
    }
    else if(no==1 && q>b[i]->stock)
    {
        QMessageBox::information(this,"ISSUE ERROR","Book available\nbut\nnot sufficient");
        ui->quantity->clear();
    }
    else
    {
        b[i]->stock-=q;
        QString pr=QString::number((b[i]->price)*q,10);
        QString st=QString::number(b[i]->stock,10);
        QMessageBox::information(this,"ISSUED",b[i]->title+" by "+b[i]->author+" has been issued\n"
                                 +st+" book remaining\nTotal Cost:"+pr+"\nTHANK YOU...VISIT AGAIN");
        ui->tableWidget->setItem(i,4,new QTableWidgetItem(st));
        ui->auths->clear();
        ui->titles->clear();
        ui->quantity->clear();
    }

}


void MainWindow::on_exit_clicked()
{
    this->close();
}
