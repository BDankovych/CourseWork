#ifndef COUPLET_H
#define COUPLET_H


#include <QStringList>
#include <QJsonObject>
#include <QJsonArray>


class Couplet: QJsonObject
{
private:

    QStringList rows;
public:
    Couplet();
    Couplet(const QJsonObject &json);
    QJsonObject toJson();

    int GetSequenceNumber() const;
    QStringList GetRows() const;
    void setSequenceNumber(int newNumber);

    int sequenceNumber;
};

#endif // COUPLET_H
