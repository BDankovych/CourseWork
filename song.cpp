#include "song.h"

Song::Song()
{
    name = "";
    author = Author();
    couplets.clear();
    coupletsCount = 0;
}

void Song::readFromJson(const QJsonObject &json) {
    name = json["name"].toString();
    coupletsCount = json["coupletsCount"].toInt();
    author = Author(json["author"].toObject());
    couplets.clear();
    for (auto item: json["couplets"].toArray()) {
        couplets.push_back(item.toObject());
    }
}

QJsonObject Song::toJson() const{
    QJsonObject jsonObj;
    jsonObj.insert("name", name);
    jsonObj.insert("couplesCount", coupletsCount);
    jsonObj.insert("author", author.toJson());
    QJsonArray arr;
    for(auto item: couplets) {
        arr.append(item.toJson());
    }
    jsonObj.insert("couplets", arr);
    return jsonObj;
}

void Song::operator>>(QFile &file) const{
    file.open(QFile::WriteOnly);
    QJsonDocument doc;
    doc.setObject(toJson());
    file.write(doc.toJson());
    file.close();
}

void Song::operator<<(QFile &file) {
    file.open(QFile::ReadOnly | QFile::Text);
    QString value = file.readAll();
    file.close();
    QJsonDocument doc = QJsonDocument::fromJson(value.toUtf8());
    QJsonObject songJson = doc.object();
    readFromJson(songJson);
}

bool Song::isSonnet() const {
    return true;
}

QString Song::GetName() const {
    return  name;
}
Author Song::GetAuthor() const {
    return author;
}
int Song::GetCoupletsCount() const {
    return coupletsCount;
}
vector<Couplet> Song::GetCouplets() const {
    return couplets;
}
