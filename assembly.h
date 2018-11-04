#ifndef ASSEMBLY_H
#define ASSEMBLY_H

#include "songdto.h"

class SongPresenterProtocol {
public:
    virtual void DisplaySong(const SongDTO& songDTO) = 0;
    virtual void CatchError(const QString& error) = 0;
};

#endif // ASSEMBLY_H
