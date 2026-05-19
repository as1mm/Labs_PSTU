#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include "graph.h"
#include "graphwidget.h"

class QTableWidget;
class QLineEdit;
class QComboBox;

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onAddVertex();
    void onRemoveVertex();
    void onAddEdge();
    void onRemoveEdge();
    void onRunBFS();
    void onRunDFS();
    void onRunDijkstra();
    void onRunFloyd();
    void onVertexSelected(int v);
    void onShowMatrix();

private:
    Graph graph;
    GraphWidget* graphWidget;
    QTableWidget* matrixTable;
    QLineEdit* fromEdit;
    QLineEdit* toEdit;
    QLineEdit* weightEdit;
    QComboBox* startVertexCombo;
    QTextEdit* outputEdit;

    void updateMatrixTable();
    void updateStartVertexCombo();
    void refreshAll();
};

#endif // MAINWINDOW_H
