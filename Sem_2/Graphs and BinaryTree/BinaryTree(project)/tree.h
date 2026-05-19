#ifndef TREE_H
#define TREE_H
#include <QVector>
#include <QDebug>

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    TreeNode* root;

    // Вспомогательные рекурсивные методы
    TreeNode* insertRec(TreeNode* node, int key);
    TreeNode* removeRec(TreeNode* node, int key);
    TreeNode* findMin(TreeNode* node);
    bool searchRec(TreeNode* node, int key) const;

    void preorderRec(TreeNode* node, QVector<int>& result) const;
    void inorderRec(TreeNode* node, QVector<int>& result) const;
    void postorderRec(TreeNode* node, QVector<int>& result) const;

    void collectNodes(TreeNode* node, QVector<TreeNode*>& nodes);
    TreeNode* buildBalanced(QVector<TreeNode*>& nodes, int start, int end);

    void deleteTree(TreeNode* node);

public:
    BinarySearchTree();
    ~BinarySearchTree();

    void insert(int key);
    void remove(int key);
    bool search(int key) const;

    QVector<int> preorder() const;
    QVector<int> inorder() const;
    QVector<int> postorder() const;

    void balance();

    // Для отрисовки и печати
    TreeNode* getRoot() const { return root; }
    void printVertical();       // в консоль вертикально (с отступами)
    void printHorizontal();     // в консоль горизонтально (повёрнутое дерево)
};

#endif // TREE_H
