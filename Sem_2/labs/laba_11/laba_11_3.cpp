#include <iostream>

struct Node
{
    Node* next;
    int data;

    Node(int value) : next(nullptr), data(value) {}
};

struct Queue
{
    Node* head;
    Node* tail;
    int size;

    Queue() : head(nullptr), tail(nullptr), size(0) {}
};

// добавляет элемент в конец очереди (tail)
void push(Queue& queue, int value)
{
    Node* newNode = new Node(value);

    if (queue.tail == nullptr) { queue.head = queue.tail = newNode; }
    else
    {
        queue.tail->next = newNode;
        queue.tail = newNode;
    }

    queue.size++;
}

// печатает очередь
void print(Queue& queue)
{
    if (queue.size == 0) { std::cout << "Queue is empty.\n"; return; }
    Node* current = queue.head;

    while (current != nullptr)
    {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << "\n";
}

// удаляет k элементов с num номера
void DeleteK(Queue& queue, int k, int num)
{
    if (num < 1 || k < 0 || num > queue.size || num + k - 1 > queue.size)
    {
        std::cout << "ERROR, cant DeleteK.\n";
        return;
    }

    if (k == 0) return;

    Node* current = queue.head;
    Node* prev = nullptr;

    for (int i = 1; i < num; i++)
    {
        prev = current;
        current = current->next;
    }

    for (int i = 0; i < k; i++)
    {
        Node* tmp = current;
        current = current->next;
        delete tmp;
        queue.size--;
    }

    if (prev == nullptr)
    {
        queue.head = current;
    }
    else
    {
        prev->next = current;
    }

    if (current == nullptr)
    {
        queue.tail = prev;
    }
}

// добавляет элемент перед k-тым элементом
void AddK(Queue& queue, int k, int value)
{
    if (k > queue.size) { std::cout << "ERROR, cant AddK, k > queue.size."; return; }

    Node* newNode = new Node(value);
    Node* current = queue.head;
    int count = 1;

    if (k == 1)
    {
        newNode->next = queue.head;
        queue.head = newNode;
        return;
    }

    while (count != k - 1)
    {
        current = current->next;
        count++;
    }

    newNode->next = current->next;
    current->next = newNode;

    queue.size++;
}

int main()
{
    setlocale(LC_ALL, "ru_RU.UTF-8");
    Queue arr;
    int size, k, num, key, kk;
    std::cout << "Введите размер очереди: ";
    std::cin >> size;

    std::cout << "Введите значения для заполнения очереди размером " << size << ": ";
    for (int i = 0; i < size; i++)
    {
        int value;
        std::cin >> value;
        push(arr, value);
    }
    print(arr);

    std::cout << "Введите сколько элементов удалить: ";
    std::cin >> k;
    std::cout << "Введите с какого номера удалять: ";
    std::cin >> num;
    DeleteK(arr, k, num);
    print(arr);

    std::cout << "Вввдите ключ (значение): ";
    std::cin >> key;
    std::cout << "Введите перед каким элементом добавляем: ";
    std::cin >> kk;
    AddK(arr, kk, key);
    print(arr);

    return 0;
}