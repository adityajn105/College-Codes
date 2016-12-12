#ifndef QLONGVALIDATOR_H
#define QLONGVALIDATOR_H

#include <QValidator>

class QLongValidator : public QValidator
{
    Q_OBJECT
public:
    explicit QLongValidator(QObject *parent = 0);
    virtual State	validate ( QString & input, int & pos ) const;
signals:

public slots:
    
};

#endif // QLONGVALIDATOR_H
