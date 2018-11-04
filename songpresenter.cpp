#include "songpresenter.h"
#include "ui_songpresenter.h"

SongPresenter::SongPresenter(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SongPresenter)
{
    ui->setupUi(this);
}

SongPresenter::~SongPresenter()
{
    delete ui;
}

void SongPresenter::displaySong(const SongDTO& songDTO) {

}
