#include <QApplication>
#include "pages/loginpage.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // Set application name and style
    app.setApplicationName("Stock Market Simulator");
    app.setApplicationDisplayName("Stock Market Simulator");
    app.setStyle("Fusion"); // Modern Qt style

    // Create and show main window
    loginPage mainWindow;
    mainWindow.setWindowTitle("Stock Market Simulator");
    mainWindow.resize(1024, 768); // Set initial window size
    mainWindow.show();

    return app.exec();
}
