#ifndef SONG_H
#define SONG_H


#include "author.h"
#include "couplet.h"
#include <QFile>
#include <QJsonDocument>
#include <vector>

using namespace std;

class Song: QJsonObject
{
private:
    QString name;
    Author author;
    int coupletsCount;
    vector<Couplet> couplets;
public:
    Song();
    void readFromJson(const QJsonObject &json);
    QJsonObject toJson() const;
    void operator << (QFile &file);
    void operator >> (QFile &file) const;
    bool isSonnet() const;

    QString GetName() const;
    Author GetAuthor() const;
    int GetCoupletsCount() const;
    vector<Couplet> GetCouplets() const;
};

#endif // SONG_H
