#ifndef STRI_H
#define STRI_H
#include "qstring.h"


class str{
    QString data;
public:
    str();
    str(QString);
    str operator=(str);
    void operator+(str);
    int length();
    int operator==(str);
    str operator<(str);
    int substring(str);
    int pali();

friend class MainWindow;

};
#endif // STRI_H
