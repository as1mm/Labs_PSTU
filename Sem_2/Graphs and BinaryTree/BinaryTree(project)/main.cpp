#include <QApplication>
#include "mainwindow.h"

// Тут я взял 2 вариант, не 3!!!!
int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MainWindow w;
    w.setWindowTitle("Бинарное дерево поиска");
    w.resize(900, 600);
    w.show();
    return app.exec();
}
