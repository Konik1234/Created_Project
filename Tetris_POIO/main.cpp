#include "okno.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    okno window;
    window.show();
    return app.exec();
}
