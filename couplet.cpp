#include "couplet.h"

Couplet::Couplet()
{
    sequenceNumber = 0;
    rows.clear();
}

Couplet::Couplet(const QJsonObject &json) {
    sequenceNumber = json["sequenceNumber"].toInt();
    QJsonArray arr = json["rows"].toArray();
    rows.clear();
    for(auto item: arr) {
        rows.push_back(item.toString());
    }
}

QJsonObject Couplet::toJson() {
    QJsonObject jsonObj;
    jsonObj.insert("sequenceNumber", sequenceNumber);
    jsonObj.insert("rows", QJsonArray::fromStringList(rows));
    return jsonObj;
}

int Couplet::GetSequenceNumber() const {
    return sequenceNumber;
}

QStringList Couplet::GetRows() const {
    return  rows;
}

void Couplet::setSequenceNumber(int newNumber) {
    sequenceNumber = newNumber;
}
