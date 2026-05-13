#ifndef TREEWIDGET_H
#define TREEWIDGET_H

#include <QWidget>
#include "tree.h"

class TreeWidget : public QWidget {
    Q_OBJECT
public:
    explicit TreeWidget(QWidget *parent = nullptr);
    void setTree(BinarySearchTree* tree);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    BinarySearchTree* m_tree;
    void drawNode(QPainter& painter, TreeNode* node, int x, int y, int xOffset);
};

#endif // TREEWIDGET_H
