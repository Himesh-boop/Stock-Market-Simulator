#include <QApplication>
#include "loginPage.h"

using namespace std;

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    loginPage w;
    w.show();

    return a.exec();
}
