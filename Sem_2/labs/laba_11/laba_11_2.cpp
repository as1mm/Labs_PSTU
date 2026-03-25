#include <iostream>

struct Node
{
    int data;
    Node* next;
    Node* prev;

    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};


struct List
{
    int size;
    Node* head;
    Node* tail;

    List() : size(0), head(nullptr), tail(nullptr) {}
};

void push_back(List& list, int value)
{
    Node* newNode = new Node(value);

    if (list.tail == nullptr)
    {
        list.head = list.tail = newNode;
    }

    else
    {
        list.tail->next = newNode;
        newNode->prev = list.tail;
        list.tail = newNode;
    }

    list.size++;
}

void print(const List& list)
{
    if (list.size == 0) { std::cout << "list is empty\n"; return; }

    Node* current = list.head;
    while (current != nullptr)
    {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << "\n";
}


// удадляем k элементов с num номера
void DeleteK(List& list, int k, int num)
{
    if (num < 1 || k < 0 || num > list.size || num + k - 1 > list.size)
    {
        std::cout << "ERROR, cant DeleteK\n";
        return;
    }

    if (k == 0) return;

    Node* current = list.head;
    Node* prev;

    for (int i = 1; i < num; i++)
    {
        current = current->next;
    }

    prev = current->prev;

    for (int i = 0; i < k; i++)
    {
        Node* tmp = current;
        current = current->next;
        delete tmp;
        list.size--;
    }

    if (prev == nullptr)
    {
        list.head = current;
    }
    else
    {
        prev->next = current;
    }

    if (current == nullptr)
    {
        list.tail = prev;
    }
}

// добавляем элемент перед k
void AddK(List& list, int k, int value)
{
    if (k > list.size) { std::cout << "ERROR, k > list.size\n"; return; }

    int count = 1;
    Node* newNode = new Node(value);
    Node* current = list.head;

    if (k == 1)
    {
        newNode->next = list.head;
        list.head = newNode;
        return;
    }

    // ищем элемент перед k, current = указатель на этот элемент
    while (count != k - 1)
    {
        current = current->next;
        count++;
    }

    // работаем с указателями (вставляем новый узел)
    newNode->next = current->next;
    current->next = newNode;

    list.size++;
}

int main()
{
    setlocale(LC_ALL, "ru_RU.UTF-8");
    List arr;
    int size, k, num, key, kk;
    std::cout << "Введите размер списка: ";
    std::cin >> size;

    std::cout << "Введите значения списка для заполнения списка размером " << size << " ";
    for (int i = 0; i < size; i++)
    {
        int value;
        std::cin >> value;
        push_back(arr, value);
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