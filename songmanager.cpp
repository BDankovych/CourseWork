#include "songmanager.h"

SongManager::SongManager()
{
    currentSong = Song();
}


void SongManager::readSong(QString fileName) {
    QFile file(fileName);
    SongManager::instance.currentSong << file;
    displaySong();
}


void SongManager::displaySong() {
    SongDTO songDTO = SongDTO(SongManager::instance.currentSong);
    songPresenter->displaySong(songDTO);
}

void SongManager::writeSong(QString fileName) {
    QFile file(fileName);
    SongManager::instance.currentSong >> file;
}
