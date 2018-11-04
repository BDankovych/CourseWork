#ifndef SONGMANAGER_H
#define SONGMANAGER_H


#include "song.h"
#include "songdto.h"
#include "assembly.h"



class SongManager
{

public:
    SongManager();
    static SongManager instance;
    static void ReadSong(QString fileName);
    static void WriteSong(QString fileName);
    static void DisplaySong();

    SongPresenterProtocol *songPresenter;
    Song currentSong;

};



#endif // SONGMANAGER_H
