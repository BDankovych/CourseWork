#include "addsongform.h"
#include "ui_addsongform.h"

bool shouldUpdate = false;


AddSongForm::AddSongForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddSongForm)
{
    ui->setupUi(this);
    songDTO.couplets.push_back(CoupletDTO());
    ui->coupletsCountSpinBox->setValue(2);
}



AddSongForm::~AddSongForm()
{

    delete ui;
}

void AddSongForm::on_cancelPushButton_clicked()
{
    delegate->FormCanceled();
    close();
}

bool AddSongForm::validateInputs() {
    if (songDTO.name == "" || songDTO.author.firstName == "" || songDTO.author.lastName == "") {
        return false;
    }
    for (auto couplet: songDTO.couplets) {
        for (auto row: couplet.rows) {
            if (row == "") {
                return false;
            }
        }
    }
    return true;
}

void AddSongForm::on_okPushButton_clicked()
{
    if (validateInputs()) {
        delegate->FormClosedWithSong(songDTO);
        close();
    } else {
        QMessageBox::critical(this, tr("Error"),tr("Please fill all fields.") );
    }

}

void AddSongForm::presentSong() {
    ui->authorNameLineEdit->setText(songDTO.author.firstName);
    ui->authorSurnameLineEdit->setText(songDTO.author.lastName);
    ui->nameLineEdit->setText(songDTO.name);
    ui->coupletsCountSpinBox->setValue(songDTO.coupletsCount);
    updateCouplet();
}

void AddSongForm::on_nameLineEdit_editingFinished()
{
    songDTO.name = ui->nameLineEdit->text();
}

void AddSongForm::on_authorNameLineEdit_editingFinished()
{
    songDTO.author.firstName = ui->authorNameLineEdit->text();
}


void AddSongForm::on_authorSurnameLineEdit_editingFinished()
{
    songDTO.author.lastName = ui->authorSurnameLineEdit->text();
}

void AddSongForm::on_coupletsCountSpinBox_valueChanged(int arg1)
{
    songDTO.coupletsCount = arg1;
    songDTO.couplets.resize(arg1);

    for (int i = 0 ; i < songDTO.couplets.size(); i++) {
        if (songDTO.couplets.at(i).rows.size() == 0 ) {
            songDTO.couplets.at(i).rows.push_back("");
        }
    }
    shouldUpdate = false;
    ui->selectedCoupletComboBox->clear();

    for (int i = 0; i < arg1; i++) {
        shouldUpdate = true;
        ui->selectedCoupletComboBox->addItem(QString::number(i));
    }

}

void AddSongForm::updateCouplet() {
    int rowsCount = songDTO.couplets[ui->selectedCoupletComboBox->currentIndex()].rows.size();
    ui->rowsCountSpinBox->setValue(rowsCount);
    ui->tableWidget->setColumnCount(1);
    ui->tableWidget->setShowGrid(false);
    ui->tableWidget->setRowCount(rowsCount);
    ui->tableWidget->horizontalHeader()->hide();

    ui->tableWidget->setColumnWidth(0,ui->tableWidget->width());
    for (int i = 0; i < rowsCount; i++ ) {
        int currentCoupletIndex = ui->selectedCoupletComboBox->currentIndex();
        QString text = songDTO.couplets[currentCoupletIndex].rows[i];
        QTableWidgetItem *item = new QTableWidgetItem();
        item->setText(text);
        ui->tableWidget->setItem(i,0,item);
    }
}

void resizeList(QList<QString> & list, int newSize) {
    int diff = newSize - list.size();

    if (diff > 0) {
        list.reserve(diff);
        while (diff>0){
            QString t = "";
            list.append(t);
            diff--;
        }
    }else if (diff < 0) list.erase(list.end() + diff, list.end());
}

void AddSongForm::on_rowsCountSpinBox_valueChanged(int arg1)
{
    int coupletIndex = ui->selectedCoupletComboBox->currentIndex();
    resizeList(songDTO.couplets[coupletIndex].rows, arg1);
    updateCouplet();
}

void AddSongForm::on_selectedCoupletComboBox_currentIndexChanged(int index)
{
    if (shouldUpdate) {
        updateCouplet();
    }

}

void AddSongForm::on_pushButton_clicked()
{
    int currentCoupletIndex = ui->selectedCoupletComboBox->currentIndex();
    for (int i = 0; i < ui->tableWidget->rowCount(); i++) {
        songDTO.couplets[currentCoupletIndex].rows[i] = ui->tableWidget->item(i,0)->text();
    }
}
