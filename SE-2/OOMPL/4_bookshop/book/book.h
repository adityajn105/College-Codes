#ifndef BOOK_H
#define BOOK_H
#include "qstring.h"
class book
{
    QString author;
    QString title;
    QString publisher;
    int price;
    int stock;
    static int count;
public:
    book();
    void search();
    void accept(QString,QString,QString,int,int);

    friend class MainWindow;

};
#endif // BOOK_H
