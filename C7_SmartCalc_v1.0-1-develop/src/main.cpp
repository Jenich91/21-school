#include "mainqt.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainQT w;

    w.show();
    return a.exec();
}
