#include "mainwindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QTableWidget>
#include <QLineEdit>
#include <QLabel>
#include <QComboBox>
#include <QTextEdit>
#include <QGroupBox>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    QWidget* central = new QWidget;
    setCentralWidget(central);
    QHBoxLayout* mainLayout = new QHBoxLayout(central);

    // Левая панель: управление + вывод
    QVBoxLayout* leftPanel = new QVBoxLayout;

    // --- Редактирование вершин ---
    QGroupBox* vertexBox = new QGroupBox("Вершины");
    QHBoxLayout* vLayout = new QHBoxLayout;
    QPushButton* addVertexBtn = new QPushButton("Добавить вершину");
    QPushButton* removeVertexBtn = new QPushButton("Удалить вершину");
    vLayout->addWidget(addVertexBtn);
    vLayout->addWidget(removeVertexBtn);
    vertexBox->setLayout(vLayout);
    leftPanel->addWidget(vertexBox);

    // --- Редактирование рёбер ---
    QGroupBox* edgeBox = new QGroupBox("Рёбра");
    QGridLayout* eLayout = new QGridLayout;
    eLayout->addWidget(new QLabel("From:"), 0, 0);
    fromEdit = new QLineEdit;
    eLayout->addWidget(fromEdit, 0, 1);
    eLayout->addWidget(new QLabel("To:"), 1, 0);
    toEdit = new QLineEdit;
    eLayout->addWidget(toEdit, 1, 1);
    eLayout->addWidget(new QLabel("Weight:"), 2, 0);
    weightEdit = new QLineEdit("1");
    eLayout->addWidget(weightEdit, 2, 1);
    QPushButton* addEdgeBtn = new QPushButton("Добавить ребро");
    QPushButton* removeEdgeBtn = new QPushButton("Удалить ребро");
    eLayout->addWidget(addEdgeBtn, 3, 0);
    eLayout->addWidget(removeEdgeBtn, 3, 1);
    edgeBox->setLayout(eLayout);
    leftPanel->addWidget(edgeBox);

    // --- Матрица смежности (краткий просмотр) ---
    QPushButton* editMatrixBtn = new QPushButton("Редактировать матрицу смежности");
    leftPanel->addWidget(editMatrixBtn);

    // --- Запуск алгоритмов ---
    QGroupBox* algoBox = new QGroupBox("Алгоритмы");
    QVBoxLayout* aLayout = new QVBoxLayout;
    startVertexCombo = new QComboBox;
    aLayout->addWidget(new QLabel("Стартовая вершина:"));
    aLayout->addWidget(startVertexCombo);
    QPushButton* bfsBtn = new QPushButton("BFS (обход в ширину)");
    QPushButton* dfsBtn = new QPushButton("DFS (обход в глубину)");
    QPushButton* dijkstraBtn = new QPushButton("Алгоритм Дейкстры");
    QPushButton* floydBtn = new QPushButton("Алгоритм Флойда-Уоршелла");
    aLayout->addWidget(bfsBtn);
    aLayout->addWidget(dfsBtn);
    aLayout->addWidget(dijkstraBtn);
    aLayout->addWidget(floydBtn);
    algoBox->setLayout(aLayout);
    leftPanel->addWidget(algoBox);

    // --- Вывод результатов ---
    outputEdit = new QTextEdit;
    outputEdit->setReadOnly(true);
    leftPanel->addWidget(outputEdit);

    // --- Графический виджет ---
    graphWidget = new GraphWidget;
    graphWidget->setGraph(&graph);
    mainLayout->addLayout(leftPanel, 1);
    mainLayout->addWidget(graphWidget, 2);

    // Подключение сигналов
    connect(addVertexBtn, &QPushButton::clicked, this, &MainWindow::onAddVertex);
    connect(removeVertexBtn, &QPushButton::clicked, this, &MainWindow::onRemoveVertex);
    connect(addEdgeBtn, &QPushButton::clicked, this, &MainWindow::onAddEdge);
    connect(removeEdgeBtn, &QPushButton::clicked, this, &MainWindow::onRemoveEdge);
    connect(editMatrixBtn, &QPushButton::clicked, this, &MainWindow::onShowMatrix);
    connect(bfsBtn, &QPushButton::clicked, this, &MainWindow::onRunBFS);
    connect(dfsBtn, &QPushButton::clicked, this, &MainWindow::onRunDFS);
    connect(dijkstraBtn, &QPushButton::clicked, this, &MainWindow::onRunDijkstra);
    connect(floydBtn, &QPushButton::clicked, this, &MainWindow::onRunFloyd);
    connect(graphWidget, &GraphWidget::vertexClicked, this, &MainWindow::onVertexSelected);

    refreshAll();
    updateStartVertexCombo();
}

MainWindow::~MainWindow() {}

void MainWindow::refreshAll() {
    graphWidget->update();
    updateStartVertexCombo();
}

void MainWindow::updateStartVertexCombo() {
    startVertexCombo->clear();
    for (int i = 0; i < graph.vertexCount(); ++i)
        startVertexCombo->addItem(QString::number(i));
}

void MainWindow::onAddVertex() {
    graph.addVertex();
    refreshAll();
    outputEdit->append("Добавлена вершина");
}

void MainWindow::onRemoveVertex() {
    int v = graphWidget->getSelectedVertex(); // нужно добавить метод получения выбранной вершины
    if (v >= 0 && v < graph.vertexCount()) {
        graph.removeVertex(v);
        refreshAll();
        outputEdit->append(QString("Удалена вершина %1").arg(v));
    } else {
        QMessageBox::information(this, "Удаление", "Сначала выберите вершину на графике");
    }
}

void MainWindow::onAddEdge() {
    bool ok1, ok2, ok3;
    int from = fromEdit->text().toInt(&ok1);
    int to   = toEdit->text().toInt(&ok2);
    int w    = weightEdit->text().toInt(&ok3);
    if (ok1 && ok2 && ok3 && from >=0 && from < graph.vertexCount() && to >=0 && to < graph.vertexCount()) {
        graph.addEdge(from, to, w);
        refreshAll();
        outputEdit->append(QString("Добавлено ребро %1-%2 вес %3").arg(from).arg(to).arg(w));
    } else {
        QMessageBox::warning(this, "Ошибка", "Некорректные индексы вершин или вес");
    }
}

void MainWindow::onRemoveEdge() {
    bool ok1, ok2;
    int from = fromEdit->text().toInt(&ok1);
    int to   = toEdit->text().toInt(&ok2);
    if (ok1 && ok2 && from >=0 && from < graph.vertexCount() && to >=0 && to < graph.vertexCount()) {
        graph.removeEdge(from, to);
        refreshAll();
        outputEdit->append(QString("Удалено ребро %1-%2").arg(from).arg(to));
    } else {
        QMessageBox::warning(this, "Ошибка", "Некорректные индексы вершин");
    }
}

void MainWindow::onShowMatrix() {
    // Создаём диалоговое окно с таблицей для редактирования матрицы смежности
    QDialog* dlg = new QDialog(this);
    dlg->setWindowTitle("Матрица смежности");
    QVBoxLayout* layout = new QVBoxLayout(dlg);
    QTableWidget* table = new QTableWidget(graph.vertexCount(), graph.vertexCount());
    for (int i = 0; i < graph.vertexCount(); ++i)
        for (int j = 0; j < graph.vertexCount(); ++j)
            table->setItem(i, j, new QTableWidgetItem(QString::number(graph.getEdgeWeight(i,j))));
    layout->addWidget(table);
    QPushButton* okBtn = new QPushButton("Применить");
    layout->addWidget(okBtn);
    connect(okBtn, &QPushButton::clicked, [=](){
        QVector<QVector<int>> newMat(graph.vertexCount(), QVector<int>(graph.vertexCount(), 0));
        for (int i = 0; i < graph.vertexCount(); ++i)
            for (int j = 0; j < graph.vertexCount(); ++j)
                newMat[i][j] = table->item(i,j)->text().toInt();
        graph.setAdjMatrix(newMat);
        refreshAll();
        dlg->accept();
    });
    dlg->exec();
}

void MainWindow::onRunBFS() {
    int start = startVertexCombo->currentIndex();
    if (start < 0) return;
    QList<int> path = graph.bfs(start);
    QStringList str;
    for (int v : path) str << QString::number(v);
    outputEdit->append("BFS: " + str.join(" -> "));
}

void MainWindow::onRunDFS() {
    int start = startVertexCombo->currentIndex();
    if (start < 0) return;
    QList<int> path = graph.dfs(start);
    QStringList str;
    for (int v : path) str << QString::number(v);
    outputEdit->append("DFS: " + str.join(" -> "));
}

void MainWindow::onRunDijkstra() {
    int start = startVertexCombo->currentIndex();
    if (start < 0) return;
    QVector<int> dist = graph.dijkstra(start);
    QStringList str;
    for (int i = 0; i < dist.size(); ++i) {
        if (dist[i] >= Graph::INF/2) str << "∞";
        else str << QString::number(dist[i]);
    }
    outputEdit->append("Дейкстра от " + QString::number(start) + ": " + str.join(" "));
}

void MainWindow::onRunFloyd() {
    QVector<QVector<int>> dist = graph.floydWarshall();
    outputEdit->append("Матрица кратчайших расстояний (Флойд):");
    QString result;
    for (int i = 0; i < dist.size(); ++i) {
        QStringList row;
        for (int j = 0; j < dist[i].size(); ++j) {
            if (dist[i][j] >= Graph::INF/2) row << "∞";
            else row << QString::number(dist[i][j]);
        }
        result += row.join(" ") + "\n";
    }
    outputEdit->append(result);
}

void MainWindow::onVertexSelected(int v) {
    outputEdit->append(QString("Выбрана вершина %1").arg(v));
}
