#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "stri.h"
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


str::str(){}

str::str(QString s)
{
this->data=s;
}

int str::length()
{
    int n=0;
    while(data[n]!='\0')
    {
        n++;
    }
    return n;
}

str str::operator=(str s)
{
int i=0;
while(i<s.length())
    {
        data[i]=s.data[i];
        i++;
    }
    data[i]='\0';
    return *this;
}

str str::operator<(str s)
{
    int i=0,j=s.length();
    data[j]='\0';
    j--;
    while(i<s.length())
    {
        data[j]=s.data[i];
        i++;j--;
    }
    return *this;
}

int str::substring(str s)
{
    int i=0, j=length()-1;
    int cnt=0;
    while(i<=j)
    {
        int l=i;
        int yn=0;
        for(int k=0;k<=s.length()-1;k++)
        {
            if(s.data[k]==data[l])
            {
                yn++;
            }
            else
            {
                break;
            }
            l++;
        }
        if(yn==s.length())
        {
            cnt++;
        }
        i++;
    }
    return cnt;
}

void str::operator +(str s)
{
    int i=length(),l=0;
    while(l<s.length())
    {
        data[i]=s.data[l];
        l++;i++;
    }
    data[i]='\0';
}

int str::operator ==(str s)
{
    if(length()!=s.length())
    {return 0;}
    else
        {
        int i=0,k;
        while(i<length())
        {
        if(data[i]==s.data[i])
        {
            i++; k=1;
        }
        else{k=0;break;}
        }
        return k;
    }
}
int str::pali()
{
    int i=0,l=length()-1;int r;
    while(i<=(length()-1)/2)
    {
        if(data[i]==data[l])
        {i++;l--;r=1;}
        else{r=0;break;}
    }
    return r;
}

void MainWindow::on_pushButton_clicked()
{
    if(ui->string1->text().isEmpty())
    {QMessageBox::information(this,"Error","Enter strings propertly");}
    s1=new str(ui->string1->text());
    s2=new str();
    *s2=*s1;
    ui->string3->setText(s2->data);
}

void MainWindow::on_rev_clicked()
{
    if(ui->string1->text().isEmpty())
    {QMessageBox::information(this,"Error","Enter strings propertly");}
    s1=new str(ui->string1->text());
    s2=new str();
    *s2<*s1;
     ui->string3->setText(s2->data);


}
void MainWindow::on_len_clicked()
{
    if(ui->string1->text().isEmpty())
    {QMessageBox::information(this,"Error","Enter strings propertly");}
    s1=new str(ui->string1->text());

    int i=s1->length();
    QString q=QString::number(i,10);
    ui->string3->setText("The length of string is :"+q);
}

void MainWindow::on_pushButton_2_clicked()
{  if(ui->string1->text().isEmpty()||ui->string2->text().isEmpty())
   {QMessageBox::information(this,"Error","Enter strings propertly");}
   s1=new str(ui->string1->text());
   s2=new str(ui->string2->text());

   *s1+*s2;
   ui->string3->setText(s1->data);
}



void MainWindow::on_pali_clicked()
{
    if(ui->string1->text().isEmpty())
    {QMessageBox::information(this,"Error","Enter strings propertly");}
    s1=new str(ui->string1->text());

    int i=s1->pali();
    if(i==0)
    { ui->string3->setText("The string is not palindrome");}
    else{ui->string3->setText("The string is palindrome");}
}

void MainWindow::on_close_clicked()
{
    this->close();
}

void MainWindow::on_reset_clicked()
{
    ui->string1->clear();
    ui->string2->clear();
    ui->string3->clear();
}

void MainWindow::on_equal_clicked()
{
     s1=new str(ui->string1->text());
     s2=new str(ui->string2->text());
     if(ui->string1->text().isEmpty()||ui->string2->text().isEmpty())
     {QMessageBox::information(this,"Error","Enter strings propertly");}
     if(*s1==*s2)
     {ui->string3->setText("Strings are Equal");}
     else{ui->string3->setText("Strings are not Equal");}
}

void MainWindow::on_substring_clicked()
{
    if(ui->string1->text().isEmpty()||ui->string2->text().isEmpty())
    {QMessageBox::information(this,"Error","Enter strings propertly");}
    s1=new str(ui->string1->text());
    s2=new str(ui->string2->text());
    s3=new str();
    int cnt=s1->substring(*s2);
    QString q=QString::number(cnt,10);
    ui->string3->setText("Number of substring found are: "+q);
}
