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
    void setFirstName(QString name);
    void setLastName(QString name);
    QString GetLastName() const;
};

#endif // AUTHOR_H
