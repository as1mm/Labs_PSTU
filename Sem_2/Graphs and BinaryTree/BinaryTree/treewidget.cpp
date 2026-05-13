#include "treewidget.h"
#include <QPainter>
#include <QPen>
#include <QFont>

TreeWidget::TreeWidget(QWidget *parent) : QWidget(parent), m_tree(nullptr) {}

void TreeWidget::setTree(BinarySearchTree* tree) {
    m_tree = tree;
    update(); // перерисовать
}

void TreeWidget::drawNode(QPainter& painter, TreeNode* node, int x, int y, int xOffset) {
    if (!node) return;
    const int radius = 20;
    const int yOffset = 60;

    // Рисуем линии к детям
    if (node->left) {
        painter.drawLine(x, y, x - xOffset, y + yOffset);
        drawNode(painter, node->left, x - xOffset, y + yOffset, xOffset / 2);
    }
    if (node->right) {
        painter.drawLine(x, y, x + xOffset, y + yOffset);
        drawNode(painter, node->right, x + xOffset, y + yOffset, xOffset / 2);
    }

    // Рисуем узел
    painter.setBrush(Qt::lightGray);
    painter.drawEllipse(QPoint(x, y), radius, radius);
    painter.drawText(QRect(x - radius, y - radius, 2*radius, 2*radius),
                     Qt::AlignCenter, QString::number(node->data));
}

void TreeWidget::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(QPen(Qt::black, 2));
    painter.setFont(QFont("Arial", 10));

    if (m_tree && m_tree->getRoot()) {
        int startX = width() / 2;
        int startY = 50;
        int initialOffset = width() / 4;
        drawNode(painter, m_tree->getRoot(), startX, startY, initialOffset);
    } else {
        painter.drawText(rect(), Qt::AlignCenter, "Дерево пусто");
    }
}
