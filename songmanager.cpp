#include "songmanager.h"

SongManager SongManager::instance = SongManager();

SongManager::SongManager()
{
    currentSong = Song();
}


void SongManager::ReadSong(QString fileName) {
    QFile file(fileName);
    instance.currentSong << file;
    DisplaySong();
}


void SongManager::DisplaySong() {
    SongDTO songDTO = SongDTO(instance.currentSong);
    instance.songPresenter->DisplaySong(songDTO);
}

void SongManager::WriteSong(QString fileName) {
    QFile file(fileName);
    instance.currentSong >> file;
}
