#ifndef AUTHOR_H
#define AUTHOR_H


#include <QJsonObject>

class Author{
private:
    QString firstName;
    QString lastName;
public:
    Author();
    Author(const QJsonObject &json);
    QJsonObject toJson() const;
    QString GetFirstName() const;
    QString GetLastName() const;
};

#endif // AUTHOR_H
