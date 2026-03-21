#include <iostream>
#include <clocale>

// узел
struct Node
{
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

// список
struct List
{
    int size;
    Node* head;
    Node* tail;

    List() : size(0), head(nullptr), tail(nullptr) {}
};


// добавление узла в конец нашего списка (для начального заполнения списка)
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
        list.tail = newNode;
    }

    list.size++;
}

// удаление k элементов с определенного номера num
// ищем узел с которого будем удалять и предыдущий ему узел
// удаляем k узлов, а потом работаем с указателями
void deleteK(List& list, int k, int num)
{
    if (num < 1 || k < 0 || num > list.size || num + k - 1 > list.size)
    {
        std::cout << "ERROR, cant deleteK\n";
        return;
    }
    if (k == 0) return;

    Node* prev = nullptr;
    Node* current = list.head;

    // ищем узел с номером num и запоминаем предыдущий
    for (int i = 1; i < num; i++)
    {
        prev = current;
        current = current->next;
    }

    // удаляем k узлов, начиная с current
    for (int i = 0; i < k; i++)
    {
        Node* tmp = current;
        current = current->next;        // после удаления всех ненужных нам узлов current будет следующим узлом
        delete tmp;
        list.size--;
    }

    // если num = 0 (удаляем с начала), то prev = nullptr, соответственно головой списка будет наш current
    if (prev == nullptr)
    {
        list.head = current;
    }
    else
    {
        prev->next = current;
    }

    // если удалили последние узлы, обновляем tail
    if (current == nullptr)
    {
        list.tail = prev;
    }
}

// добавление элемента перед k
// в addk мы ищем элемент, который стоит перед k и перед ним добавляем новый узел
void addK(List& list, int k, int value) // k - перед каким элементом добавляем
{
    if (k > list.size)
    {
        std::cout << "ERROR, k > size\n";
        return;
    }

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

// вывод списка
void print(const List& list)
{
    if (list.size == 0) { std::cout << "List is empty\n"; return; }
    Node* current = list.head;
    while (current != nullptr)
    {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << "\n";
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
    deleteK(arr, k, num);
    print(arr);

    std::cout << "Вввдите ключ (значение): ";
    std::cin >> key;
    std::cout << "Введите перед каким элементом добавляем: ";
    std::cin >> kk;
    addK(arr, kk, key);
    print(arr);

    return 0;
}