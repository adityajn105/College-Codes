#ifndef WEATH_H
#define WEATH_H
class weath
{
    int day,htemp,ltemp,rain,snow;
    static int cnt,ht,lt,rt,st;
public:
    weath();
    void setdata(int,int,int,int,int);
    friend class MainWindow;
};
#endif // WEATH_H
