#ifndef ASSEMBLY_H
#define ASSEMBLY_H

#include "songdto.h"

class SongPresenterProtocol {
public:
    virtual void displaySong(const SongDTO& songDTO) = 0;
};

#endif // ASSEMBLY_H
