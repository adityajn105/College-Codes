#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "weath.h"
#include "qcombobox.h"
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
int weath::cnt=0;
int weath::ht=0;
int weath::lt=0;
int weath::st=0;
int weath::rt=0;
weath::weath()
{
    day=99;htemp=999;ltemp=-999;snow=0;rain=0;
}
void weath::setdata(int day,int htemp,int ltemp,int snow,int rain)
{
       this->day=day;
        this->htemp=htemp;
        this->ltemp=ltemp;
        this->snow=snow;
    this->rain=rain;
    weath::cnt+=1;
    weath::ht+=htemp;
    weath::lt+=ltemp;
    weath::st+=snow;
    weath::rt+=rain;
}


void MainWindow::on_Accept_clicked()
{

    if(ui->year->text().isEmpty())
    {
        QMessageBox::information(this,"Validation","Enter data properly");
    }
    int d,ht,lt,s,r;
    d=ui->Day->currentText().toInt();
    ht=ui->htemp->text().toInt();
    lt=ui->ltemp->text().toInt();
    s=ui->snow->text().toInt();
    r=ui->rain->text().toInt();
    w[d].setdata(d,ht,lt,s,r);
   // ui->Day->clear();
    ui->htemp->clear();
    ui->ltemp->clear();
    ui->snow->clear();
    ui->rain->clear();
    //ui->month->setEnabled();

}

void MainWindow::on_pushButton_2_clicked()
{
    ui->tableWidget->setRowCount(no);
    QString d,ht,lt,r,s;
    for (int i=0;i<no;i++)
    {
    d=QString::number(w[i+1].day,10);
    ht=QString::number(w[i+1].htemp,10);
    lt=QString::number(w[i+1].ltemp,10);
    s=QString::number(w[i+1].snow,10);
    r=QString::number(w[i+1].rain,10);
    ui->tableWidget->setItem(i,0,new QTableWidgetItem(d));
    ui->tableWidget->setItem(i,1,new QTableWidgetItem(ht));
    ui->tableWidget->setItem(i,2,new QTableWidgetItem(lt));
    ui->tableWidget->setItem(i,3,new QTableWidgetItem(r));
    ui->tableWidget->setItem(i,4,new QTableWidgetItem(s));
    }
}

void MainWindow::on_pushButton_clicked()
{
    int cnt=weath::cnt;
    QString ht,lt,r,s;
    int ah,al,as,ar;
    ah=(weath::ht)/cnt;
    al=(weath::lt)/cnt;
    as=(weath::st)/cnt;
    ar=(weath::rt)/cnt;
    ht=QString::number(weath::ht,10);
    lt=QString::number(weath::lt,10);
    r=QString::number(weath::rt,10);
    s=QString::number(weath::st,10);
    ui->tableWidget_2->setItem(0,0,new QTableWidgetItem(ht));
    ui->tableWidget_2->setItem(0,1,new QTableWidgetItem(lt));
    ui->tableWidget_2->setItem(0,2,new QTableWidgetItem(r));
    ui->tableWidget_2->setItem(0,3,new QTableWidgetItem(s));
    ht=QString::number(ah,10);
    lt=QString::number(al,10);
    r=QString::number(ar,10);
    s=QString::number(as,10);
    ui->tableWidget_2->setItem(1,0,new QTableWidgetItem(ht));
    ui->tableWidget_2->setItem(1,1,new QTableWidgetItem(lt));
    ui->tableWidget_2->setItem(1,2,new QTableWidgetItem(r));
    ui->tableWidget_2->setItem(1,3,new QTableWidgetItem(s));
}

void MainWindow::on_month_activated(const QString &arg1)
{
    QString mnt;int yr;
    //ui->Day->clear();
    ui->month->setDisabled(1);
    mnt=arg1;
    if(mnt=="Jan"||mnt=="Mar"||mnt=="May"||mnt=="Jul"||mnt=="Aug"||mnt=="Oct"||mnt=="Dec")
    {no=31;}
    else if(mnt=="Feb"){
        yr=ui->year->text().toInt();
        if(yr%4==0){no=29;}else{no=28;}
    }
    else{no=30;}
    for(int i=1;i<=no;i++)
    {ui->Day->addItem(QString::number(i,10));
    }
}
void MainWindow::on_exit_clicked()
{
    this->close();
}
