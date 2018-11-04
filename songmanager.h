#ifndef SONGMANAGER_H
#define SONGMANAGER_H


#include "song.h"
#include "songdto.h"
#include "assembly.h"



class SongManager
{
private:
    SongManager();
public:
    static SongManager instance;
    void readSong(QString fileName);
    void writeSong(QString fileName);
    void displaySong();

    SongPresenterProtocol *songPresenter;
    Song currentSong;

};

SongManager SongManager::instance = SongManager();

#endif // SONGMANAGER_H
