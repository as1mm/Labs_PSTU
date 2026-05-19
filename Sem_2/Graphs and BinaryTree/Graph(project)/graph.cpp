#include "graph.h"
#include <queue>
#include <stack>
#include <algorithm>

Graph::Graph(int initialSize) {
    if (initialSize > 0) {
        adjMatrix.resize(initialSize);
        for (int i = 0; i < initialSize; ++i)
            adjMatrix[i] = QVector<int>(initialSize, 0);
    }
}

void Graph::addVertex() {
    int newSize = adjMatrix.size() + 1;
    adjMatrix.resize(newSize);
    for (int i = 0; i < newSize; ++i) {
        if (i == newSize - 1) {
            adjMatrix[i] = QVector<int>(newSize, 0);
        } else {
            adjMatrix[i].resize(newSize);
            adjMatrix[i][newSize - 1] = 0;
        }
    }
}

void Graph::removeVertex(int v) {
    if (v < 0 || v >= adjMatrix.size()) return;
    adjMatrix.erase(adjMatrix.begin() + v);
    for (int i = 0; i < adjMatrix.size(); ++i) {
        adjMatrix[i].erase(adjMatrix[i].begin() + v);
    }
}

void Graph::addEdge(int from, int to, int weight) {
    if (from < 0 || from >= vertexCount() || to < 0 || to >= vertexCount()) return;
    if (weight <= 0) weight = 1; // вес должен быть положительным
    adjMatrix[from][to] = weight;
    adjMatrix[to][from] = weight; // для неориентированного графа
}

void Graph::removeEdge(int from, int to) {
    if (from < 0 || from >= vertexCount() || to < 0 || to >= vertexCount()) return;
    adjMatrix[from][to] = 0;
    adjMatrix[to][from] = 0;
}

void Graph::setEdgeWeight(int from, int to, int weight) {
    if (from < 0 || from >= vertexCount() || to < 0 || to >= vertexCount()) return;
    if (weight > 0) {
        adjMatrix[from][to] = weight;
        adjMatrix[to][from] = weight;
    }
}

int Graph::getEdgeWeight(int from, int to) const {
    if (from < 0 || from >= vertexCount() || to < 0 || to >= vertexCount()) return 0;
    return adjMatrix[from][to];
}

QVector<QVector<int>> Graph::getAdjMatrix() const {
    return adjMatrix;
}

void Graph::setAdjMatrix(const QVector<QVector<int>>& matrix) {
    if (matrix.isEmpty()) return;
    int n = matrix.size();
    adjMatrix = matrix;
    for (int i = 0; i < n; ++i)
        for (int j = i+1; j < n; ++j)
            if (adjMatrix[i][j] != adjMatrix[j][i])
                adjMatrix[j][i] = adjMatrix[i][j];
}

// BFS
QList<int> Graph::bfs(int start) const {
    QList<int> result;
    int n = vertexCount();
    if (n == 0 || start < 0 || start >= n) return result;
    QVector<bool> visited(n, false);
    std::queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty()) {
        int v = q.front(); q.pop();
        result.push_back(v);
        for (int to = 0; to < n; ++to) {
            if (adjMatrix[v][to] != 0 && !visited[to]) {
                visited[to] = true;
                q.push(to);
            }
        }
    }
    return result;
}

// DFS (рекурсивный)
void Graph::dfsRecursive(int v, QVector<bool>& visited, QList<int>& result) const {
    visited[v] = true;
    result.push_back(v);
    for (int to = 0; to < vertexCount(); ++to) {
        if (adjMatrix[v][to] != 0 && !visited[to]) {
            dfsRecursive(to, visited, result);
        }
    }
}

QList<int> Graph::dfs(int start) const {
    QList<int> result;
    int n = vertexCount();
    if (n == 0 || start < 0 || start >= n) return result;
    QVector<bool> visited(n, false);
    dfsRecursive(start, visited, result);
    return result;
}

// Дейкстра
QVector<int> Graph::dijkstra(int start) const {
    int n = vertexCount();
    QVector<int> dist(n, INF);
    if (n == 0 || start < 0 || start >= n) return dist;
    dist[start] = 0;
    QVector<bool> used(n, false);
    for (int i = 0; i < n; ++i) {
        int v = -1;
        for (int j = 0; j < n; ++j)
            if (!used[j] && (v == -1 || dist[j] < dist[v]))
                v = j;
        if (dist[v] == INF) break;
        used[v] = true;
        for (int to = 0; to < n; ++to) {
            int w = adjMatrix[v][to];
            if (w > 0 && dist[v] + w < dist[to])
                dist[to] = dist[v] + w;
        }
    }
    return dist;
}

// Флойд–Уоршелл
QVector<QVector<int>> Graph::floydWarshall() const {
    int n = vertexCount();
    QVector<QVector<int>> dist = adjMatrix;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (i != j && dist[i][j] == 0)
                dist[i][j] = INF;
    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (dist[i][k] < INF && dist[k][j] < INF && dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
    return dist;
}

QList<QPair<QPair<int,int>,int>> Graph::getAllEdges() const {
    QList<QPair<QPair<int,int>,int>> edges;
    int n = vertexCount();
    for (int i = 0; i < n; ++i)
        for (int j = i+1; j < n; ++j)
            if (adjMatrix[i][j] != 0)
                edges.append({{i, j}, adjMatrix[i][j]});
    return edges;
}

const int Graph::INF = std::numeric_limits<int>::max() / 2;
