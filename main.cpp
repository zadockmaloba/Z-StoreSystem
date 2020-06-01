#include "homepage.h"
#include "DataBase.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setStyle("Fusion");
    homepage w;
    w.show();
    return app.exec();
}
