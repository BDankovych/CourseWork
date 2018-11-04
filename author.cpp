#include "author.h"

Author::Author() {
    firstName = "";
    lastName = "";
}

Author::Author(const QJsonObject &json) {
    firstName = json["firstName"].toString();
    lastName = json["lastName"].toString();
}

QJsonObject Author::toJson() {
    QJsonObject jsonObj;
    jsonObj.insert("firstname", firstName);
    jsonObj.insert("lastName", lastName);
    return jsonObj;
}
