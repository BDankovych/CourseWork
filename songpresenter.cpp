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

void SongPresenter::DisplaySong(const SongDTO& songDTO) {
    ui->authorLabel->setText(songDTO.author.FullName());
    ui->coupletsCountLabel->setText(QString::number(songDTO.coupletsCount));
    ui->isSonnetLabel->setText(songDTO.isSonnet ? "YES" : "NO");
    //configure displaying for table
}

void SongPresenter::CatchError(const QString& error) {

}

void SongPresenter::on_openFIleButton_pressed()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open song","/Desktop", tr("All files (*.dat)"));
    SongManager::ReadSong(fileName);
}
