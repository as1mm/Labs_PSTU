#include "graphwidget.h"
#include <QPainter>
#include <QMouseEvent>
#include <QtMath>

GraphWidget::GraphWidget(QWidget *parent)
    : QWidget(parent), m_graph(nullptr), m_selectedVertex(-1), m_dragging(false)
{
    setMinimumSize(500, 400);
}

void GraphWidget::setGraph(Graph* graph) {
    m_graph = graph;
    computeInitialPositions();
    update();
}

void GraphWidget::setSelectedVertex(int v) {
    m_selectedVertex = v;
    update();
}

void GraphWidget::clearSelection() {
    m_selectedVertex = -1;
    update();
}

void GraphWidget::computeInitialPositions() {
    if (!m_graph || m_graph->vertexCount() == 0) return;
    int n = m_graph->vertexCount();
    double angleStep = 2 * M_PI / n;
    QRect rect = this->rect().adjusted(50, 50, -50, -50);
    QPoint center = rect.center();
    int radius = qMin(rect.width(), rect.height()) / 2;
    for (int i = 0; i < n; ++i) {
        double angle = i * angleStep;
        int x = center.x() + radius * qCos(angle);
        int y = center.y() + radius * qSin(angle);
        m_vertexPositions[i] = QPoint(x, y);
    }
}

void GraphWidget::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);
    if (!m_graph) return;
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(Qt::black);

    // Рисуем рёбра
    auto edges = m_graph->getAllEdges();
    for (const auto& edge : edges) {
        int from = edge.first.first;
        int to = edge.first.second;
        int weight = edge.second;
        drawEdge(painter, from, to, weight);
    }

    // Рисуем вершины
    for (int i = 0; i < m_graph->vertexCount(); ++i) {
        QPoint p = m_vertexPositions[i];
        if (i == m_selectedVertex)
            painter.setBrush(Qt::green);
        else
            painter.setBrush(Qt::lightGray);
        painter.drawEllipse(p, 20, 20);
        painter.drawText(QRect(p.x()-15, p.y()-15, 30, 30), Qt::AlignCenter, QString::number(i));
    }
}

void GraphWidget::drawEdge(QPainter& painter, int from, int to, int weight) {
    QPoint p1 = m_vertexPositions[from];
    QPoint p2 = m_vertexPositions[to];
    painter.drawLine(p1, p2);
    // Рисуем вес на середине ребра
    QPoint mid = (p1 + p2) / 2;
    painter.drawText(mid + QPoint(5, -5), QString::number(weight));
}

int GraphWidget::findVertexAtPoint(const QPoint& p) const {
    for (auto it = m_vertexPositions.constBegin(); it != m_vertexPositions.constEnd(); ++it) {
        QPoint vp = it.value();
        if ((p - vp).manhattanLength() < 20) // приблизительно внутри круга
            return it.key();
    }
    return -1;
}

void GraphWidget::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        int v = findVertexAtPoint(event->pos());
        if (v != -1) {
            m_selectedVertex = v;
            m_dragging = true;
            m_dragStartPos = event->pos();
            emit vertexClicked(v);
            update();
        }
    }
}

void GraphWidget::mouseMoveEvent(QMouseEvent *event) {
    if (m_dragging && m_selectedVertex != -1) {
        m_vertexPositions[m_selectedVertex] = event->pos();
        update();
        emit vertexMoved(m_selectedVertex, event->pos());
    }
}

void GraphWidget::mouseReleaseEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton && m_dragging) {
        m_dragging = false;
        // не снимаем выделение, чтобы можно было редактировать
    }
}
