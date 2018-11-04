#include "songmanager.h"

SongManager SongManager::instance = SongManager();

SongManager::SongManager()
{
    currentSong = Song();
    currentFileName = "";
}


void SongManager::ReadSong(QString fileName) {
    QFile file(fileName);
    setCurrentFile(fileName);
    instance.currentSong << file;
    DisplaySong();
}

void SongManager::setCurrentFile(const QString& fileName) {
    instance.currentFileName = fileName;
}

void SongManager::DisplaySong() {
    SongDTO songDTO = SongDTO(instance.currentSong);
    if (instance.songPresenter){
        instance.songPresenter->DisplaySong(songDTO);
    }
}

void SongManager::WriteSong(QString fileName) {
    QFile file(fileName);
    instance.currentSong >> file;
}

QString SongManager::getCurrentFileName() {
    return instance.currentFileName;
}

void SongManager::swapCouplets(int first, int second) {
    swap(instance.currentSong.couplets.at(first).sequenceNumber, instance.currentSong.couplets.at(second).sequenceNumber);
    DisplaySong();
}
