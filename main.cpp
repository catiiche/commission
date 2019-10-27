#include "raschet.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Raschet w;
    w.show();
    return a.exec();
}
