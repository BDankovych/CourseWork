#ifndef SONGPRESENTER_H
#define SONGPRESENTER_H

#include <QMainWindow>
#include <QFileDialog>
#include <QList>
#include "assembly.h"
#include "songmanager.h"

namespace Ui {
class SongPresenter;
}

class SongPresenter : public QMainWindow, public SongPresenterProtocol
{
    Q_OBJECT

public:
    explicit SongPresenter(QWidget *parent = nullptr);
    ~SongPresenter();
    void DisplaySong(const SongDTO& songDTO) override;
    void CatchError(const QString& error) override;

private slots:
    void on_openFIleButton_pressed();

    void on_saveButton_pressed();

    void on_saveAsButton_pressed();

    void on_pushButton_pressed();

private:
    Ui::SongPresenter *ui;
};

#endif // SONGPRESENTER_H
