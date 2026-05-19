#include "mainwindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QTextEdit>
#include <QLabel>
#include <QGroupBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), treeWidget(new TreeWidget(this)) {

    QWidget* central = new QWidget;
    setCentralWidget(central);
    QVBoxLayout* mainLayout = new QVBoxLayout(central);

    // Панель управления
    QHBoxLayout* controlLayout = new QHBoxLayout;
    keyEdit = new QLineEdit;
    keyEdit->setPlaceholderText("Ключ (int)");
    controlLayout->addWidget(keyEdit);

    QPushButton* insertBtn = new QPushButton("Вставить");
    QPushButton* removeBtn = new QPushButton("Удалить");
    QPushButton* searchBtn = new QPushButton("Поиск");
    QPushButton* balanceBtn = new QPushButton("Балансировка");

    controlLayout->addWidget(insertBtn);
    controlLayout->addWidget(removeBtn);
    controlLayout->addWidget(searchBtn);
    controlLayout->addWidget(balanceBtn);
    mainLayout->addLayout(controlLayout);

    // Кнопки обходов
    QHBoxLayout* traverseLayout = new QHBoxLayout;
    QPushButton* preBtn = new QPushButton("Прямой");
    QPushButton* inBtn  = new QPushButton("Симметричный");
    QPushButton* postBtn = new QPushButton("Обратный");
    traverseLayout->addWidget(preBtn);
    traverseLayout->addWidget(inBtn);
    traverseLayout->addWidget(postBtn);
    mainLayout->addLayout(traverseLayout);

    // Кнопки печати
    QHBoxLayout* printLayout = new QHBoxLayout;
    QPushButton* vertBtn = new QPushButton("Вертикальная печать");
    QPushButton* horBtn  = new QPushButton("Горизонтальная печать");
    printLayout->addWidget(vertBtn);
    printLayout->addWidget(horBtn);
    mainLayout->addLayout(printLayout);

    // Область вывода текста
    outputEdit = new QTextEdit;
    outputEdit->setReadOnly(true);
    outputEdit->setMaximumHeight(150);
    mainLayout->addWidget(outputEdit);

    // Виджет для рисования дерева
    treeWidget->setMinimumHeight(400);
    mainLayout->addWidget(treeWidget);

    // Подключение сигналов
    connect(insertBtn, &QPushButton::clicked, this, &MainWindow::onInsertClicked);
    connect(removeBtn, &QPushButton::clicked, this, &MainWindow::onRemoveClicked);
    connect(searchBtn, &QPushButton::clicked, this, &MainWindow::onSearchClicked);
    connect(balanceBtn, &QPushButton::clicked, this, &MainWindow::onBalanceClicked);
    connect(preBtn, &QPushButton::clicked, this, &MainWindow::onPreorderClicked);
    connect(inBtn, &QPushButton::clicked, this, &MainWindow::onInorderClicked);
    connect(postBtn, &QPushButton::clicked, this, &MainWindow::onPostorderClicked);
    connect(vertBtn, &QPushButton::clicked, this, &MainWindow::onVerticalPrintClicked);
    connect(horBtn, &QPushButton::clicked, this, &MainWindow::onHorizontalPrintClicked);

    treeWidget->setTree(&tree);
}

MainWindow::~MainWindow() {}

void MainWindow::onInsertClicked() {
    bool ok;
    int key = keyEdit->text().toInt(&ok);
    if (ok) {
        tree.insert(key);
        treeWidget->update();
        outputEdit->append(QString("Вставлен %1").arg(key));
    } else {
        outputEdit->append("Ошибка: введите целое число");
    }
}

void MainWindow::onRemoveClicked() {
    bool ok;
    int key = keyEdit->text().toInt(&ok);
    if (ok) {
        if (tree.search(key)) {
            tree.remove(key);
            treeWidget->update();
            outputEdit->append(QString("Удалён %1").arg(key));
        } else {
            outputEdit->append(QString("Ключ %1 не найден").arg(key));
        }
    } else {
        outputEdit->append("Ошибка: введите целое число");
    }
}

void MainWindow::onSearchClicked() {
    bool ok;
    int key = keyEdit->text().toInt(&ok);
    if (ok) {
        bool found = tree.search(key);
        outputEdit->append(QString("Поиск %1: %2").arg(key).arg(found ? "найден" : "не найден"));
    } else {
        outputEdit->append("Ошибка: введите целое число");
    }
}

void MainWindow::onBalanceClicked() {
    tree.balance();
    treeWidget->update();
    outputEdit->append("Дерево сбалансировано");
}

void MainWindow::onPreorderClicked() {
    auto vec = tree.preorder();
    QStringList list;
    for (int v : vec) list << QString::number(v);
    outputEdit->append("Прямой обход: " + list.join(" "));
}

void MainWindow::onInorderClicked() {
    auto vec = tree.inorder();
    QStringList list;
    for (int v : vec) list << QString::number(v);
    outputEdit->append("Симметричный обход: " + list.join(" "));
}

void MainWindow::onPostorderClicked() {
    auto vec = tree.postorder();
    QStringList list;
    for (int v : vec) list << QString::number(v);
    outputEdit->append("Обратный обход: " + list.join(" "));
}

void MainWindow::onVerticalPrintClicked() {
    outputEdit->append("Вертикальная печать (в консоли)");
    tree.printVertical();
}

void MainWindow::onHorizontalPrintClicked() {
    outputEdit->append("Горизонтальная печать (в консоли)");
    tree.printHorizontal();
}
