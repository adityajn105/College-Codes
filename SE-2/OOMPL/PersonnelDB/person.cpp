#include "person.h"
#include "record.h"

Person::Person()
{
    name = "";
    dob = "";
    bloodGrp = "";
    height = 0;
    weight = 0;
    height = 0;
    insPNumber = 0;
    address = "";
    phoneNo = 0;
    drivingLNumber = 0;
}

void Person::setData(QString name, QString dob, QString bloodGrp, int height, float weight, int insPNumber, QString address, long int phoneNo, int drivingLNumber) {
    this->name = name;
    this->dob = dob;
    this->bloodGrp = bloodGrp;
    this->height = height;
    this->weight = weight;
    this->insPNumber = insPNumber;
    this->address = address;
    this->phoneNo = phoneNo;
    this->drivingLNumber = drivingLNumber;
}

Person::~Person() {

}

Record *Person::toRecord() {
    Record *r = new Record();
    strcpy(r->name, name.toUtf8().data());
    strcpy(r->dob, dob.toUtf8().data());
    strcpy(r->bloodGrp, bloodGrp.toUtf8().data());
    r->height = height;
    r->weight = weight;
    r->insPNumber = insPNumber;
    strcpy(r->address, address.toUtf8().data());
    r->phoneNo = phoneNo;
    r->drivingLNumber = drivingLNumber;

    return r;
}

void Person::setData(Record r) {
    name = QString(r.name);
    dob = QString(r.dob);
    bloodGrp = QString(r.bloodGrp);
    height = r.height;
    weight = r.weight;
    insPNumber = r.insPNumber;
    address = QString(r.address);
    phoneNo = r.phoneNo;
    drivingLNumber = r.drivingLNumber;
}
