#ifndef ADDSONGFORM_H
#define ADDSONGFORM_H

#include <QWidget>
#include "songdto.h"
#include "songmanager.h"
#include <qmessagebox.h>

class AddSongFormProtocol {
public:
    virtual void FormClosedWithSong(const SongDTO& songDTO) = 0;
    virtual void FormCanceled() = 0;
};

namespace Ui {
class AddSongForm;
}

class AddSongForm : public QWidget
{
    Q_OBJECT

public:
    explicit AddSongForm(QWidget *parent = nullptr);
    ~AddSongForm();

    AddSongFormProtocol *delegate;
    SongDTO songDTO;

    void presentSong();

private slots:
    void on_cancelPushButton_clicked();

    void on_okPushButton_clicked();

    void on_nameLineEdit_editingFinished();

    void on_authorNameLineEdit_editingFinished();

    void on_authorSurnameLineEdit_editingFinished();

    void on_coupletsCountSpinBox_valueChanged(int arg1);

    void on_rowsCountSpinBox_valueChanged(int arg1);

    void on_selectedCoupletComboBox_currentIndexChanged(int index);

    void on_pushButton_clicked();

private:
    bool validateInputs();
    void updateCouplet();

    Ui::AddSongForm *ui;
};

#endif // ADDSONGFORM_H
