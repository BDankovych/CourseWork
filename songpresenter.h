#ifndef SONGPRESENTER_H
#define SONGPRESENTER_H

#include <QMainWindow>
#include <QFileDialog>
#include <QList>
#include "assembly.h"
#include "songmanager.h"
#include "addsongform.h"

namespace Ui {
class SongPresenter;
}

class SongPresenter : public QMainWindow, public SongPresenterProtocol, public AddSongFormProtocol
{
    Q_OBJECT

public:
    explicit SongPresenter(QWidget *parent = nullptr);
    ~SongPresenter();
    void DisplaySong(const SongDTO& songDTO) override;
    void CatchError(const QString& error) override;

    void FormClosedWithSong(const SongDTO& songDTO) override;
    void FormCanceled() override;

private slots:
    void on_openFIleButton_pressed();

    void on_saveButton_pressed();

    void on_saveAsButton_pressed();

    void on_pushButton_pressed();

    void on_addNewSongButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    AddSongForm addSongForm;
    Ui::SongPresenter *ui;

    bool isEditing;
};

#endif // SONGPRESENTER_H
