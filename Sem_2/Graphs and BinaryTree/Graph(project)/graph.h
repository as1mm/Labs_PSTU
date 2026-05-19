#ifndef GRAPH_H
#define GRAPH_H

#include <QVector>
#include <QList>
#include <QPair>
#include <QDebug>
#include <limits>

class Graph {
public:
    // бесконечность
    static const int INF;
    Graph(int initialSize = 0);
    ~Graph() = default;

    // Редактирование структуры
    void addVertex();                     // добавить вершину
    void removeVertex(int v);             // удалить вершину (и все инцидентные рёбра)
    void addEdge(int from, int to, int weight = 1);
    void removeEdge(int from, int to);
    void setEdgeWeight(int from, int to, int weight);
    int getEdgeWeight(int from, int to) const;

    // Матрица смежности
    QVector<QVector<int>> getAdjMatrix() const;
    void setAdjMatrix(const QVector<QVector<int>>& matrix);

    // Алгоритмы
    QList<int> bfs(int start) const;                    // обход в ширину
    QList<int> dfs(int start) const;                    // обход в глубину
    QVector<int> dijkstra(int start) const;             // расстояния от start
    QVector<QVector<int>> floydWarshall() const;        // матрица кратчайших расстояний

    // Вспомогательные методы
    int vertexCount() const { return adjMatrix.size(); }
    bool isEmpty() const { return vertexCount() == 0; }
    QList<QPair<QPair<int,int>,int>> getAllEdges() const; // список рёбер (from,to,weight)

private:
    QVector<QVector<int>> adjMatrix; // матрица смежности, adjMatrix[u][v] = вес (0 если нет ребра)

    void dfsRecursive(int v, QVector<bool>& visited, QList<int>& result) const;
};

#endif // GRAPH_H
