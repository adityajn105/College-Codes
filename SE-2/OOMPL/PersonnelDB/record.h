#ifndef RECORD_H
#define RECORD_H

class Record
{
    char name[50];
    char dob[15];
    char bloodGrp[10];
    int height;
    float weight;
    int insPNumber;
    char address[100];
    long int phoneNo;
    int drivingLNumber;
public:
    Record();
    friend class MainWindow;
    friend class Person;
};

#endif // RECORD_H
