#include "songpresenter.h"
#include "ui_songpresenter.h"

SongPresenter::SongPresenter(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SongPresenter)
{
    ui->setupUi(this);
    SongManager::instance.songPresenter = this;
    ui->spinBox->setMinimum(0);
    ui->spinBox_2->setMinimum(0);
}

SongPresenter::~SongPresenter()
{
    delete ui;
}

void SongPresenter::DisplaySong(const SongDTO& songDTO) {
    ui->authorLabel->setText(songDTO.author.FullName());
    ui->coupletsCountLabel->setText(QString::number(songDTO.coupletsCount));
    ui->isSonnetLabel->setText(songDTO.isSonnet ? "YES" : "NO");

    ui->songTableWidget->clear();
    ui->songTableWidget->setShowGrid(false);
    ui->songTableWidget->setColumnCount(1);
    ui->songTableWidget->setColumnWidth(0,ui->songTableWidget->width());
    QList<QString> rows;
    for (auto couplet : songDTO.couplets) {
        for(auto row: couplet.rows) {
            rows.append(row);
        }
        rows.append("");
    }
    ui->songTableWidget->setRowCount(rows.count());

    for (int i = 0; i < rows.count(); ++i) {
        QTableWidgetItem *item = new QTableWidgetItem();
        item->setText(rows[i]);
        ui->songTableWidget->setItem(i,0,item);
    }

    ui->spinBox->setMaximum(songDTO.coupletsCount - 1);
    ui->spinBox_2->setMaximum(songDTO.coupletsCount - 1);
}

void SongPresenter::CatchError(const QString& error) {

}

void SongPresenter::on_openFIleButton_pressed()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open song","", tr("All files (*.dat)"));
    if (fileName != "") {
        SongManager::ReadSong(fileName);
    }
}


void SongPresenter::on_saveButton_pressed()
{
    if (SongManager::getCurrentFileName().isEmpty()) {
        on_saveAsButton_pressed();
    } else {
        SongManager::WriteSong(SongManager::getCurrentFileName());
    }
}

void SongPresenter::on_saveAsButton_pressed()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save file as", "", tr("All files (*.dat)"));
    SongManager::WriteSong(fileName);
    SongManager::setCurrentFile(fileName);
}

void SongPresenter::on_pushButton_pressed()
{
    int firstCouplet = ui->spinBox->value();
    int secondCouplet = ui->spinBox_2->value();
    SongManager::swapCouplets(firstCouplet, secondCouplet);
}
