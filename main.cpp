#include "songpresenter.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SongPresenter w;
    w.show();

    return a.exec();
}
