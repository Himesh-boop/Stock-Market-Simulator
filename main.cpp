#include <QApplication>
#include "pages/loginpage.h"
#include "db/logindb.h"
#include <qmessagebox.h>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    app.setApplicationName("Stock Market Simulator");
    app.setApplicationDisplayName("Stock Market Simulator");
    app.setStyle("Fusion");

    qDebug() << "Available drivers:" << QSqlDatabase::drivers();

    QString pluginPath = QCoreApplication::applicationDirPath() + "/sqldrivers";
    QCoreApplication::addLibraryPath(pluginPath);
    qDebug() << "Plugin path added:" << pluginPath;

    loginDB dbInitializer;

    loginPage mainWindow;
    mainWindow.setWindowTitle("Stock Market Simulator");
    mainWindow.resize(1024, 768); // Set initial window size
    mainWindow.show();

    return app.exec();
}
