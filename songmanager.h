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
    static void ReadSong(QString fileName) {
        QFile file(fileName);
        SongManager::instance.currentSong << file;
        DisplaySong();
    }
    static void WriteSong(QString fileName) {
        QFile file(fileName);
        SongManager::instance.currentSong >> file;
    }
    static void DisplaySong() {
        SongDTO songDTO = SongDTO(SongManager::instance.currentSong);
        SongManager::instance.songPresenter->DisplaySong(songDTO);
    }

    SongPresenterProtocol *songPresenter;
    Song currentSong;

};



#endif // SONGMANAGER_H
