#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MainWindow w;
    w.setWindowTitle("Графы: BFS, DFS, Дейкстра, Флойд");
    w.resize(1000, 600);
    w.show();
    return app.exec();
}
