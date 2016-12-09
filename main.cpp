#include "startup.hpp"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Startup startup;
    startup.show();

    return a.exec();
}
