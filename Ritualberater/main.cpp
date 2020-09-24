#include "Ritualberater.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Ritualberater w;
    w.show();
    return a.exec();
}
