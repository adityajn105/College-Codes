#ifndef STUDENT_H
#define STUDENT_H
#include"qstring.h"
class student{
    protected:
        QString name;
        int rollno;
        static int cnt;
    public:
        student(){
            name="";
            rollno=0;
        }
        friend class MainWindow;
        void getinfo(QString,int);
};

class internal:public virtual student{
    protected:
        int COi,OOMPi,MITi,CGGi;
    public:
        internal(){
            COi=OOMPi=CGGi=MITi=0;
        }
        friend class MainWindow;
        void getint(int,int,int,int);
};

class external:public virtual student{
    protected:
        int COx,OOMPx,MITx,CGGx;
    public:
        external(){
            COx=CGGx=OOMPx=MITx=0;
        }
        friend class MainWindow;
        void getext(int,int,int,int);
};

class result:public virtual internal,public virtual external{
        int COt,OOMPt,MITt,CGGt,total;
        float perc;
    public:
        result(){
            COt=OOMPt=MITt=CGGt=total=perc=0;
        }
        friend class MainWindow;
        void getresult();
};

#endif // STUDENT_H
