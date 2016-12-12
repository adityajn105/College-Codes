#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "personal.h"
#include "qstring.h"
#include "qmessagebox.h"
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
int i;
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
    p[personal::count]=new personal;
    p[personal::count]->accept(name,city,blood,dob,address,gender,mob,lc,policy,ht,wt);
    personal::count+=1;
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
    for(int i=0;i<personal::count;i++)
    {

        QString ht=QString::number(p[i]->ht,10.2);
        QString wt=QString::number(p[i]->wt,10.2);
        QString mob=QString::number(p[i]->mob,10);
        QString policy=QString::number(p[i]->policy,10);
        QString lc=QString::number(p[i]->lc,10);
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(p[i]->name));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(p[i]->city));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(p[i]->gender));
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(mob));
        ui->tableWidget->setItem(i,4,new QTableWidgetItem(p[i]->dob));
        ui->tableWidget->setItem(i,5,new QTableWidgetItem(p[i]->address));
        ui->tableWidget->setItem(i,6,new QTableWidgetItem(policy));
        ui->tableWidget->setItem(i,7,new QTableWidgetItem(p[i]->blood));
        ui->tableWidget->setItem(i,8,new QTableWidgetItem(lc));
        ui->tableWidget->setItem(i,9,new QTableWidgetItem(ht));
        ui->tableWidget->setItem(i,10,new QTableWidgetItem(wt));
    }
}

void MainWindow::on_search_clicked()
{
    if(ui->key->text().isEmpty())
    {
        QMessageBox::information(this,"Error","Enter Licence no properly");
    }
    else
    {
    int no=0;
        for(i=0;i<personal::count;i++)
        {
            QString ln=QString::number(p[i]->lc,10);
            if(ln==ui->key->text())
            {
                no=1;break;
            }
        }
    QString ht=QString::number(p[i]->ht,10.2);
    QString wt=QString::number(p[i]->wt,10.2);
    QString mob=QString::number(p[i]->mob,10);
    QString policy=QString::number(p[i]->policy,10);
    QString lc=QString::number(p[i]->lc,10);

    if(no==1)
    {
        QMessageBox::information(this,"DataBase Found","Details are as follows:\nName: "+p[i]->name+
                                 "\nCity: "+p[i]->city+"\nGender: "+p[i]->gender+"\nMOB:"+mob+"\nDOB:"+p[i]->dob+
                                 "\nAddress: "+p[i]->address+"\nPolicy: "+policy+"\nBlood Group: "+p[i]->blood+
                                 "\nLicence no: "+lc+"\nHeight: "+ht+"\nWeight: "+wt);
    }
    else
    {
        QMessageBox::information(this,"DataBase Not Found","Details are not in DataBase");
    }
    }
}

void MainWindow::on_mod_clicked()
{
    if(ui->key->text().isEmpty())
    {
        QMessageBox::information(this,"Error","Enter Licence no properly");
    }
    else{
    int no=0;
     for(i=0;i<personal::count;i++)
     {
         QString ln=QString::number(p[i]->lc,10);
         if(ln==ui->key->text())
         {
             no=1;break;
         }
     }
     if(no==0)
     {
         QMessageBox::information(this,"Not Found","Enter Licence no not found in Database");
     }
     else
     {
    QString ht=QString::number(p[i]->ht,10.2);
    QString wt=QString::number(p[i]->wt,10.2);
    QString mob=QString::number(p[i]->mob,10);
    QString policy=QString::number(p[i]->policy,10);
    QString lc=QString::number(p[i]->lc,10);

    ui->name->setText(p[i]->name);
    ui->city->setText(p[i]->city);
    ui->address->setPlainText(p[i]->address);
    ui->mob->setText(mob);
    ui->lc->setText(lc);
    ui->policy->setText(policy);
    ui->height->setText(ht);
    ui->weight->setText(wt);
    QMessageBox::information(this,"Modify","Click on Save Changes to modify");
     }
    }
  }


void MainWindow::on_pushButton_clicked()
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
    p[i]->accept(name,city,blood,dob,address,gender,mob,lc,policy,ht,wt);
    ui->city->clear();
    ui->name->clear();
    ui->address->clear();
    ui->mob->clear();
    ui->lc->clear();
    ui->policy->clear();
    ui->height->clear();
    ui->weight->clear();
    on_display_clicked();
    for(int j=0;j<=10;j++)
    {
    ui->tableWidget->item(i,j)->setBackground(QBrush(QColor(225,0,0,150)));
    }
}

void MainWindow::on_del_clicked()
{
    if(ui->key->text().isEmpty())
    {
        QMessageBox::information(this,"Error","Enter Licence no properly");
    }
    else{
    int no=0;
     for(i=0;i<personal::count;i++)
     {
         QString ln=QString::number(p[i]->lc,10);
         if(ln==ui->key->text())
         {
             no=1;break;
         }
     }
     if(no==0)
     {
         QMessageBox::information(this,"Not Found","Enter Licence no not found in Database");
     }
     else
     {
        delete p[i];
        p[i]=new personal();
        personal::count--;
        for(int j=i;j<=personal::count;j++)
        {
        p[j]=p[j+1];
        }
        on_display_clicked();
     }
     ui->key->clear();}
}

void MainWindow::on_clear_clicked()
{
    ui->city->clear();
    ui->name->clear();
    ui->address->clear();
    ui->mob->clear();
    ui->lc->clear();
    ui->policy->clear();
    ui->height->clear();
    ui->weight->clear();
    ui->key->clear();
}


void MainWindow::on_exit_clicked()
{
    this->close();
}
