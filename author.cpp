#include "author.h"

Author::Author() {
    firstName = "";
    lastName = "";
}

Author::Author(const QJsonObject &json) {
    firstName = json["firstName"].toString();
    lastName = json["lastName"].toString();
}

QJsonObject Author::toJson() const {
    QJsonObject jsonObj;
    jsonObj.insert("firstName", firstName);
    jsonObj.insert("lastName", lastName);
    return jsonObj;
}

QString Author::GetFirstName() const {
    return firstName;
}
QString Author::GetLastName() const {
    return lastName;
}
