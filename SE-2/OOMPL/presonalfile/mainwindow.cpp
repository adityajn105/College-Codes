#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <fstream>
#include"personal.h"
#include"qmessagebox.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->height->setValidator(new QIntValidator);
    ui->weight->setValidator(new QIntValidator);
    ui->mob->setValidator(new QIntValidator);
    ui->policy->setValidator(new QIntValidator);
    ui->lc->setValidator(new QIntValidator);
}

MainWindow::~MainWindow()
{
    delete ui;
}

int personal::count;
personal::personal()
{
    name=city=blood=dob,address=gender='\0';
    ht=wt=0.0;
    mob=rollno=lc=policy=0;
}

void personal::accept(QString name,QString city,QString blood,QString dob,QString address,
                      QString gender,int mob,int lc,int policy,float ht,float wt)
{
       this->name=name;
       this->city=city;
       this->blood=blood;
       this->dob=dob;
       this->address=address;
       this->gender=gender;
       this->mob=mob;
       this->ht=ht;
       this->wt=wt;
       this->lc=lc;
       this->policy=policy;
}




void MainWindow::on_accept_clicked()
{

    if(ui->name->text().isEmpty()||ui->lc->text().isEmpty())
    {
        QMessageBox::information(this,"Error","Enter Data properly");
    }
    else
    {
    QString name=ui->name->text();
    QString city=ui->city->text();
    QString blood=ui->blood->currentText();
    QString dob=ui->dateEdit->text();
    QString address=ui->address->toPlainText();
    QString gender=ui->gender->currentText();
    int mob=ui->mob->text().toInt();
    int lc=ui->lc->text().toInt();
    int policy=ui->policy->text().toInt();
    float ht=ui->height->text().toFloat();
    float wt=ui->weight->text().toFloat();
    dataobj.accept(name,city,blood,dob,address,gender,mob,lc,policy,ht,wt);
    personal::count+=1;


    std::ofstream datfile;
    datfile.open("dat.txt",std::ios::out|std::ios::app|std::ios::binary);

    dataobj.name=name;
    dataobj.city=city;
    dataobj.blood=blood;
    dataobj.dob=dob;
    dataobj.address=address;
    dataobj.gender=gender;
    dataobj.mob=mob;
    dataobj.lc=lc;
    dataobj.policy=policy;
    dataobj.ht=ht;
    dataobj.wt=wt;
    datfile.write((char*)&dataobj,sizeof(dataobj));

    datfile.close();

    ui->name->clear();
    ui->city->clear();
    ui->address->clear();
    ui->mob->clear();
    ui->lc->clear();
    ui->policy->clear();
    ui->height->clear();
    ui->weight->clear();
    }
}



void MainWindow::on_display_clicked()
{
       ui->tableWidget->setRowCount(personal::count);
       std::ifstream datfile;
       datfile.open("dat.txt",std::ios::out|std::ios::binary);

       datfile.read((char*)&dataobj,sizeof(dataobj));
       int i=0;
       while(!datfile.eof() || i<personal::count)
       {
           QString ht=QString::number(dataobj.ht,10.2);
           QString wt=QString::number(dataobj.wt,10.2);
           QString mob=QString::number(dataobj.mob,10);
           QString policy=QString::number(dataobj.policy,10);
           QString lc=QString::number(dataobj.lc,10);
           ui->tableWidget->setItem(i,0,new QTableWidgetItem(dataobj.name));
           ui->tableWidget->setItem(i,1,new QTableWidgetItem(dataobj.city));
           ui->tableWidget->setItem(i,2,new QTableWidgetItem(dataobj.gender));
           ui->tableWidget->setItem(i,3,new QTableWidgetItem(mob));
           ui->tableWidget->setItem(i,4,new QTableWidgetItem(dataobj.dob));
           ui->tableWidget->setItem(i,5,new QTableWidgetItem(dataobj.address));
           ui->tableWidget->setItem(i,6,new QTableWidgetItem(policy));
           ui->tableWidget->setItem(i,7,new QTableWidgetItem(dataobj.blood));
           ui->tableWidget->setItem(i,8,new QTableWidgetItem(lc));
           ui->tableWidget->setItem(i,9,new QTableWidgetItem(ht));
           ui->tableWidget->setItem(i,10,new QTableWidgetItem(wt));
           datfile.read((char*)&dataobj,sizeof(dataobj));
           i++;
       }
       datfile.close();
}
