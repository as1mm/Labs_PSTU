#ifndef GRAPHWIDGET_H
#define GRAPHWIDGET_H

#include <QWidget>
#include <QMap>
#include <QPoint>
#include "graph.h"

class GraphWidget : public QWidget {
    Q_OBJECT
public:
    explicit GraphWidget(QWidget *parent = nullptr);
    void setGraph(Graph* graph);
    void setSelectedVertex(int v); // для подсветки при выборе
    int getSelectedVertex() const { return m_selectedVertex; }
    void clearSelection();

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

signals:
    void vertexClicked(int v);
    void vertexMoved(int v, const QPoint& newPos);

private:
    Graph* m_graph;
    QMap<int, QPoint> m_vertexPositions; // координаты вершин
    int m_selectedVertex;
    QPoint m_dragStartPos;
    bool m_dragging;

    void computeInitialPositions(); // разместить вершины по кругу
    int findVertexAtPoint(const QPoint& p) const;
    void drawEdge(QPainter& painter, int from, int to, int weight);
};

#endif // GRAPHWIDGET_H
