#ifndef SONGMANAGER_H
#define SONGMANAGER_H


#include "song.h"
#include "songdto.h"
#include "assembly.h"



class SongManager
{
private:
    QString currentFileName;
public:
    SongManager();
    static SongManager instance;
    static void ReadSong(QString fileName);
    static void WriteSong(QString fileName);
    static void DisplaySong();

    SongPresenterProtocol *songPresenter;
    Song currentSong;

    bool isSongLoaded();

    static void setCurrentFile(const QString& fileName);
    static QString getCurrentFileName();
    static void swapCouplets(int first, int second);
};



#endif // SONGMANAGER_H
