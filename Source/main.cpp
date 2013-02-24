//OpenEval v. 2.0 alpha

//Call the function to draw the main window.

#include "OpenEval.h"

int main(int argc, char *argv[])
{   
    QApplication app(argc, argv);

    OpenEval mainWindow;
    mainWindow.show();

    return app.exec();
}
