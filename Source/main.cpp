//OpenEval v. 1.0

#include "OpenEval.h"

int main(int argc, char *argv[])
{   
    QApplication app(argc, argv);

    OpenEval mainWindow;
    mainWindow.show();

    return app.exec();
}
