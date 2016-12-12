#include "qlongvalidator.h"
#include <QValidator>

QLongValidator::QLongValidator(QObject *parent) :
    QValidator(parent)
{
}

QValidator::State QLongValidator::validate ( QString & input, int & pos ) const {

    long num = input.toLong();

    if(input.toLong() == 0 && input.length() != 0) {

        return QValidator::Invalid;
    }

    if(num > 0 && num <= 9999999999) {

        return QValidator::Acceptable;
    }

    if(input.length() < 10) {
        return QValidator::Intermediate;
    }

    if(input.length() > 10 || num > 9999999999) {

        return QValidator::Invalid;
    }

    if(num < 0) {
        return QValidator::Invalid;
    }

    return QValidator::Intermediate;
}
