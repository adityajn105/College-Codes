#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"student.h"
#include "qmessagebox.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->roll->setValidator(new QIntValidator);
    ui->coi->setValidator(new QIntValidator);
    ui->miti->setValidator(new QIntValidator);
    ui->oompi->setValidator(new QIntValidator);
    ui->cggi->setValidator(new QIntValidator);
    ui->cox->setValidator(new QIntValidator);
    ui->mitx->setValidator(new QIntValidator);
    ui->cggx->setValidator(new QIntValidator);
    ui->oompx->setValidator(new QIntValidator);
}

MainWindow::~MainWindow()
{
    delete ui;

}

int student::cnt;
int i;
void student::getinfo(QString name,int roll){
        this->name=name;
        this->rollno=roll;
}

void internal::getint(int co,int oomp,int mit,int cgg){
        this->CGGi=cgg;
        this->COi=co;
        this->OOMPi=oomp;
        this->MITi=mit;
}

void external::getext(int co,int oomp,int mit,int cgg){
        this->CGGx=cgg;
        this->COx=co;
        this->OOMPx=oomp;
        this->MITx=mit;
}

void result::getresult(){
        this->COt=COi+COx;
        this->MITt=MITi+MITx;
        this->CGGt=CGGi+CGGx;
        this->OOMPt=OOMPi+OOMPx;
        this->total=COt+MITt+CGGt+OOMPt;
        this->perc=(total/4);
}



void MainWindow::on_accept_clicked()
{   if(ui->name->text().isEmpty()||ui->roll->text().isEmpty())
    {
        QMessageBox::information(this,"Invalid","Enter Data Properly");
    }
    else{
        i=student::cnt;
        s[i]=new result();
        s[i]->getinfo(ui->name->text(),ui->roll->text().toInt());
        s[i]->getint(ui->coi->text().toInt(),ui->oompi->text().toInt(),ui->miti->text().toInt(),ui->cggi->text().toInt());
        s[i]->getext(ui->cox->text().toInt(),ui->oompx->text().toInt(),ui->mitx->text().toInt(),ui->cggx->text().toInt());
        s[i]->getresult();
        student::cnt++;
        on_clear_clicked();
    }
}



void MainWindow::on_display_clicked()
{
    ui->tableWidget->setRowCount(student::cnt);
    for(i=0;i<student::cnt;i++)
    {
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(s[i]->name));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(QString::number(s[i]->rollno)));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(QString::number(s[i]->COi)));
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(QString::number(s[i]->OOMPi)));
        ui->tableWidget->setItem(i,4,new QTableWidgetItem(QString::number(s[i]->MITi)));
        ui->tableWidget->setItem(i,5,new QTableWidgetItem(QString::number(s[i]->CGGi)));
        ui->tableWidget->setItem(i,6,new QTableWidgetItem(QString::number(s[i]->COx)));
        ui->tableWidget->setItem(i,7,new QTableWidgetItem(QString::number(s[i]->OOMPx)));
        ui->tableWidget->setItem(i,8,new QTableWidgetItem(QString::number(s[i]->MITx)));
        ui->tableWidget->setItem(i,9,new QTableWidgetItem(QString::number(s[i]->CGGx)));
        ui->tableWidget->setItem(i,10,new QTableWidgetItem(QString::number(s[i]->COt)));
        ui->tableWidget->setItem(i,11,new QTableWidgetItem(QString::number(s[i]->OOMPt)));
        ui->tableWidget->setItem(i,12,new QTableWidgetItem(QString::number(s[i]->MITt)));
        ui->tableWidget->setItem(i,13,new QTableWidgetItem(QString::number(s[i]->CGGt)));
        ui->tableWidget->setItem(i,14,new QTableWidgetItem(QString::number(s[i]->total)));
        ui->tableWidget->setItem(i,15,new QTableWidgetItem(QString::number(s[i]->perc,10.2)));
    }
}

void MainWindow::on_search_clicked()
{
    if(ui->rollsearch->text().isEmpty())
    {
        QMessageBox::information(this,"INvalid","Enter ROll number");
    }
    else
    {
        int roll=ui->rollsearch->text().toInt();
        bool b=false;
        for(i=0;i<student::cnt;i++)
        {
            if(s[i]->rollno==roll)
            {
                b=true;
                break;
            }
        }

        if(b)
        {
            QMessageBox::information(this,"Found","Name: "+s[i]->name);
        }
        else
        {
            QMessageBox::information(this,"Not Found","Roll number not found");
        }
    }
}



void MainWindow::on_edit_clicked()
{
    if(ui->rollsearch->text().isEmpty())
    {
        QMessageBox::information(this,"INvalid","Enter ROll number");
    }
    else
    {
        int roll=ui->rollsearch->text().toInt();
        bool b=false;
        for(i=0;i<student::cnt;i++)
        {
            if(s[i]->rollno==roll)
            {
                b=true;
                break;
            }
        }

        if(b)
        {
            QMessageBox::information(this,"Edit","Edit and Click on Save");
            ui->roll->setText(QString::number(s[i]->rollno));
            ui->coi->setText(QString::number(s[i]->COi));
            ui->miti->setText(QString::number(s[i]->MITi));
            ui->oompi->setText(QString::number(s[i]->OOMPi));
            ui->cggi->setText(QString::number(s[i]->CGGi));
            ui->cox->setText(QString::number(s[i]->COx));
            ui->mitx->setText(QString::number(s[i]->MITx));
            ui->cggx->setText(QString::number(s[i]->CGGx));
            ui->oompx->setText(QString::number(s[i]->OOMPx));
            ui->name->setText(s[i]->name);
        }
        else
        {
            QMessageBox::information(this,"Not Found","Roll number not found");
        }
    }
}

void MainWindow::on_save_clicked()
{
    s[i]->getinfo(ui->name->text(),ui->roll->text().toInt());
    s[i]->getint(ui->coi->text().toInt(),ui->oompi->text().toInt(),ui->miti->text().toInt(),ui->cggi->text().toInt());
    s[i]->getext(ui->cox->text().toInt(),ui->oompx->text().toInt(),ui->mitx->text().toInt(),ui->cggx->text().toInt());
    s[i]->getresult();
    on_clear_clicked();
    on_display_clicked();
}

void MainWindow::on_clear_clicked()
{
    ui->name->clear();
    ui->roll->clear();
    ui->coi->clear();
    ui->miti->clear();
    ui->oompi->clear();
    ui->cggi->clear();
    ui->cox->clear();
    ui->mitx->clear();
    ui->cggx->clear();
    ui->oompx->clear();
}

void MainWindow::on_del_clicked()
{
    if(ui->rollsearch->text().isEmpty())
    {
        QMessageBox::information(this,"INvalid","Enter ROll number");
    }
    else
    {
        int roll=ui->rollsearch->text().toInt();
        bool b=false;
        for(i=0;i<student::cnt;i++)
        {
            if(s[i]->rollno==roll)
            {
                b=true;
                break;
            }
        }

        if(b)
        {
            for(int j=i;j<(student::cnt)-1;j++)
            {
                s[j]=s[j+1];
            }
            QMessageBox::information(this,"Found & Deleted","Roll number Found and Deleted");
            student::cnt--;
            on_display_clicked();
        }
        else
        {
            QMessageBox::information(this,"Not Found","Roll number not found");
        }
    }
}

void MainWindow::on_pushButton_clicked()
{
    this->close();
}
