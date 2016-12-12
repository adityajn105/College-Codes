#ifndef PERSONAL_H
#define PERSONAL_H
#include"qstring.h"
class personal
{
    QString name,city,blood,dob,address,gender;
    int rollno,mob,policy,lc;
    float ht,wt;
    static int count;
public:

    personal();
    void accept(QString,QString,QString,QString,QString,QString,int,int,int,float,float);
    friend  class MainWindow;

};

#endif // PERSONAL_H
