// стэк
#include <iostream>

struct Node
{
    Node* next;
    int data;

    Node(int value) : next(nullptr), data(value) {}
};

struct Stack
{
    Node* head;
    Node* tail;
    int size;

    Stack() : head(nullptr), tail(nullptr), size(0) {}
};

void push(Stack& stack, int value)
{
    Node* newNode = new Node(value);

    if (stack.size == 0)
    {
        stack.head = stack.tail = newNode;
    }
    else
    {
        stack.tail->next = newNode;
        stack.tail = newNode;
    }

    stack.size++;
}

void print(const Stack& stack)
{
    if (stack.size == 0) { std::cout << "Stack is empty\n"; return; }

    Node* current = stack.head;
    while (current != nullptr)
    {
        std::cout << current->data << " ";
        current = current->next;
    }

    std::cout << "\n";
}

void deleteK(Stack& stack, int k, int num)
{
    if (num < 1 || k < 0 || num > stack.size || num + k - 1 > stack.size)
    {
        std::cout << "ERROR, cant deleteK\n";
        return;
    }
    if (k == 0) return;

    Node* prev = nullptr;
    Node* current = stack.head;

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
        stack.size--;
    }

    // если num = 0 (удаляем с начала), то prev = nullptr, соответственно головой списка будет наш current
    if (prev == nullptr)
    {
        stack.head = current;
    }
    else
    {
        prev->next = current;
    }

    // если удалили последние узлы, обновляем tail
    if (current == nullptr)
    {
        stack.tail = prev;
    }
}

// добавление элемента перед k
// в addk мы ищем элемент, который стоит перед k и перед ним добавляем новый узел
void addK(Stack& stack, int k, int value) // k - перед каким элементом добавляем
{
    if (k > stack.size)
    {
        std::cout << "ERROR, k > size\n";
        return;
    }

    int count = 1;
    Node* newNode = new Node(value);
    Node* current = stack.head;

    if (k == 1)
    {
        newNode->next = stack.head;
        stack.head = newNode;
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

    stack.size++;
}

int main()
{
    setlocale(LC_ALL, "ru_RU.UTF-8");
    Stack arr;
    int size, k, num, key, kk;
    std::cout << "Введите размер стека: ";
    std::cin >> size;

    std::cout << "Введите значения для заполнения стека размером " << size << "\n";
    for (int i = 0; i < size; i++)
    {
        int value;
        std::cin >> value;
        push(arr, value);
    }
    std::cout << "\n";
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
