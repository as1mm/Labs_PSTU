#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "tree.h"
#include "treewidget.h"

QT_BEGIN_NAMESPACE
class QLineEdit;
class QPushButton;
class QTextEdit;
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onInsertClicked();
    void onRemoveClicked();
    void onSearchClicked();
    void onBalanceClicked();
    void onPreorderClicked();
    void onInorderClicked();
    void onPostorderClicked();
    void onVerticalPrintClicked();
    void onHorizontalPrintClicked();

private:
    BinarySearchTree tree;
    TreeWidget* treeWidget;
    QLineEdit* keyEdit;
    QTextEdit* outputEdit;
};

#endif // MAINWINDOW_H
