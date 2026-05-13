#include "tree.h"
#include <iostream>
#include <iomanip>

// ---------- Конструктор и Деструктор ----------
BinarySearchTree::BinarySearchTree() : root(nullptr) {}

BinarySearchTree::~BinarySearchTree() {
    deleteTree(root);
}

// ---------- Удаление вссего дерева ----------
void BinarySearchTree::deleteTree(TreeNode* node) {
    if (!node) return;
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

// ---------- Вставка новой записи ----------
TreeNode* BinarySearchTree::insertRec(TreeNode* node, int key) {
    if (!node) return new TreeNode(key);
    if (key < node->data)
        node->left = insertRec(node->left, key);
    else if (key > node->data)
        node->right = insertRec(node->right, key);
    // если равны – ничего не делаем (можно добавить подсчёт повторов)
    return node;
}

void BinarySearchTree::insert(int key) {
    root = insertRec(root, key);
}

// ---------- Поиск ----------
bool BinarySearchTree::searchRec(TreeNode* node, int key) const {
    if (!node) return false;
    if (key == node->data) return true;
    if (key < node->data) return searchRec(node->left, key);
    return searchRec(node->right, key);
}

bool BinarySearchTree::search(int key) const {
    return searchRec(root, key);
}

// ---------- Нахождение мин записи ----------
TreeNode* BinarySearchTree::findMin(TreeNode* node) {
    while (node && node->left) node = node->left;
    return node;
}


// ---------- Удаление записи ----------
TreeNode* BinarySearchTree::removeRec(TreeNode* node, int key) {
    if (!node) return nullptr;
    if (key < node->data)
        node->left = removeRec(node->left, key);
    else if (key > node->data)
        node->right = removeRec(node->right, key);
    else {
        // узел найден
        if (!node->left) {
            TreeNode* rightChild = node->right;
            delete node;
            return rightChild;
        } else if (!node->right) {
            TreeNode* leftChild = node->left;
            delete node;
            return leftChild;
        } else {
            // два потомка: находим минимальный в правом поддереве
            TreeNode* minNode = findMin(node->right);
            node->data = minNode->data;
            node->right = removeRec(node->right, minNode->data);
        }
    }
    return node;
}

void BinarySearchTree::remove(int key) {
    root = removeRec(root, key);
}

// ---------- Обходы по дереву ----------
void BinarySearchTree::preorderRec(TreeNode* node, QVector<int>& result) const {
    if (!node) return;
    result.push_back(node->data);
    preorderRec(node->left, result);
    preorderRec(node->right, result);
}

QVector<int> BinarySearchTree::preorder() const {
    QVector<int> res;
    preorderRec(root, res);
    return res;
}

void BinarySearchTree::inorderRec(TreeNode* node, QVector<int>& result) const {
    if (!node) return;
    inorderRec(node->left, result);
    result.push_back(node->data);
    inorderRec(node->right, result);
}

QVector<int> BinarySearchTree::inorder() const {
    QVector<int> res;
    inorderRec(root, res);
    return res;
}

void BinarySearchTree::postorderRec(TreeNode* node, QVector<int>& result) const {
    if (!node) return;
    postorderRec(node->left, result);
    postorderRec(node->right, result);
    result.push_back(node->data);
}

QVector<int> BinarySearchTree::postorder() const {
    QVector<int> res;
    postorderRec(root, res);
    return res;
}

// ---------- Балансировка ----------
void BinarySearchTree::collectNodes(TreeNode* node, QVector<TreeNode*>& nodes) {
    if (!node) return;
    collectNodes(node->left, nodes);
    nodes.push_back(node);
    collectNodes(node->right, nodes);
}

TreeNode* BinarySearchTree::buildBalanced(QVector<TreeNode*>& nodes, int start, int end) {
    if (start > end) return nullptr;
    int mid = (start + end) / 2;
    TreeNode* node = nodes[mid];
    node->left = buildBalanced(nodes, start, mid - 1);
    node->right = buildBalanced(nodes, mid + 1, end);
    return node;
}

void BinarySearchTree::balance() {
    if (!root) return;
    QVector<TreeNode*> nodes;
    collectNodes(root, nodes);
    // Очищаем старые связи, т.к. узлы переиспользуются
    root = buildBalanced(nodes, 0, nodes.size() - 1);
}

// ---------- Печать (вертикальная и горизонтальная) ----------
// ---------- Вертикальная печать (обход в глубину с отступами) ----------
static void printVerticalRec(TreeNode* node, int depth) {
    if (!node) return;
    printVerticalRec(node->right, depth + 1);
    std::cout << std::setw(depth * 4) << "" << node->data << std::endl;
    printVerticalRec(node->left, depth + 1);
}

void BinarySearchTree::printVertical() {
    std::cout << "\n=== Vertical print (right-aligned) ===\n";
    printVerticalRec(root, 0);
}

// ---------- Горизонтальная печать (корень слева, ветви вправо) ----------
static void printHorizontalRec(TreeNode* node, int space, int indent) {
    if (!node) return;
    space += indent;
    printHorizontalRec(node->right, space, indent);
    std::cout << std::endl;
    for (int i = indent; i < space; ++i) std::cout << " ";
    std::cout << node->data << std::endl;
    printHorizontalRec(node->left, space, indent);
}

void BinarySearchTree::printHorizontal() {
    std::cout << "\n=== Horizontal print (root on left) ===\n";
    printHorizontalRec(root, 0, 5);
}
