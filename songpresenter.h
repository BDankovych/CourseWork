#ifndef SONGPRESENTER_H
#define SONGPRESENTER_H

#include <QMainWindow>
#include "assembly.h"
namespace Ui {
class SongPresenter;
}

class SongPresenter : public QMainWindow, public SongPresenterProtocol
{
    Q_OBJECT

public:
    explicit SongPresenter(QWidget *parent = nullptr);
    ~SongPresenter();
    void displaySong(const SongDTO& songDTO) override;

private:
    Ui::SongPresenter *ui;
};

#endif // SONGPRESENTER_H
