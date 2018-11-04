#ifndef SONGDTO_H
#define SONGDTO_H

#include "song.h"
#include <algorithm>

struct AuthorDTO {

    QString firstName;
    QString lastName;

    AuthorDTO() {
        firstName = lastName = "";
    }

    AuthorDTO(const Author& author) {
        firstName = author.GetFirstName();
        lastName = author.GetLastName();
    }

    QString FullName() const {
        return firstName + " " + lastName;
    }
};


struct CoupletDTO {

    int sequenceNumber;
    QStringList rows;

    CoupletDTO() {
        sequenceNumber = 0;
    }

    CoupletDTO(const Couplet& couplet) {

        sequenceNumber = couplet.GetSequenceNumber();
        rows = couplet.GetRows();
    }
};


struct SongDTO
{

    QString name;
    AuthorDTO author;
    int coupletsCount;
    vector<CoupletDTO> couplets;
    bool isSonnet;

    SongDTO() {

        name = "";
        author = AuthorDTO();
        coupletsCount = 0;

    }

    SongDTO(const Song& song) {

        name = song.GetName();
        author = AuthorDTO(song.GetAuthor());
        coupletsCount = song.GetCoupletsCount();
        isSonnet = song.isSonnet();

        auto songCouplets = song.GetCouplets();

        for (auto couplet: songCouplets) {
            couplets.push_back(CoupletDTO(couplet));
        }

        std::sort(couplets.begin(), couplets.end(), [](CoupletDTO a, CoupletDTO b) {return a.sequenceNumber < b.sequenceNumber; });
    }

};

#endif // SONGDTO_H
