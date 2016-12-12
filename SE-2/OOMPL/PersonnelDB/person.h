#ifndef PERSON_H
#define PERSON_H

#include <QString>
#include "record.h"

class Person
{
    QString name;
    QString dob;
    QString bloodGrp;
    int height;
    float weight;
    int insPNumber;
    QString address;
    long int phoneNo;
    int drivingLNumber;
public:
    Person();
    void setData(QString name, QString dob, QString bloodGrp, int height, float weight, int insPNumber,
            QString address, long int phoneNo, int drivingLNumber);
    ~Person();
    friend class MainWindow;
    Record *toRecord();
    void setData(Record);
};

#endif // PERSON_H
