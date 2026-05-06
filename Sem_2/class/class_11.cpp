/*
Задача 1.
1. Создать последовательный контейнер.
2. Заполнить его элементами стандартного типа (тип указан в варианте).
3. Добавить элементы в соответствии с заданием
4. Удалить элементы в соответствии с заданием.
5. Выполнить задание варианта для полученного контейнера.
6.  Выполнение всех заданий оформить в виде глобальных функций.

Задача 2.
1. Создать последовательный контейнер.
2. Заполнить его элементами пользовательского типа (тип указан в варианте). Для
пользовательского типа перегрузить необходимые операции.
3. Добавить элементы в соответствии с заданием
4. Удалить элементы в соответствии с заданием.
5. Выполнить задание варианта для полученного контейнера.
6.  Выполнение всех заданий оформить в виде глобальных функций.

Задача 3
1. Создать параметризированный класс, используя в качестве контейнера
последовательный контейнер.
2. Заполнить его элементами.
3. Добавить элементы в соответствии с заданием
4. Удалить элементы в соответствии с заданием.
5. Выполнить задание варианта для полученного контейнера.
6.  Выполнение всех заданий оформить в виде методов параметризированного
класса.

Задача 4
1. Создать адаптер контейнера.
2. Заполнить его элементами пользовательского типа (тип указан в варианте). Для
пользовательского типа перегрузить необходимые операции.
3. Добавить элементы в соответствии с заданием
4. Удалить элементы в соответствии с заданием.
5. Выполнить задание варианта для полученного контейнера.
6.  Выполнение всех заданий оформить в виде глобальных функций.

Задача  5
1. Создать параметризированный класс, используя в качестве контейнера адаптер
контейнера.
2. Заполнить его элементами.
3. Добавить элементы в соответствии с заданием
4. Удалить элементы в соответствии с заданием.
5. Выполнить задание варианта для полученного контейнера.
6.  Выполнение всех заданий оформить в виде методов параметризированного
класса.
*/

#include <iostream>
#include <deque>
#include <vector>
#include <queue>
#include <algorithm>
#include <windows.h>


// 3. найти элемент с заданным ключом и добавить его на заданную позицию
template<class Container, class T>
bool insertKey(Container& cont, const T& key, size_t pos)
{
    auto it = std::find(cont.begin(), cont.end(), key);
    if (it == cont.end()) return false;
    if (pos > cont.size()) return false;
    cont.insert(cont.begin() + pos, *it);
    return true;
}

// 4. найти элемент с заданным ключом и удалить его из контейнера
template<class Container, class T>
bool eraseKey(Container& cont, const T& key)
{
    auto it = std::find(cont.begin(), cont.end(), key);
    if (it == cont.end()) return false;
    cont.erase(it);
    return true;
}

// 5. найти разницу между макс и мин элементами контейнера и вычесть ее из каждого элемента контейнера
template<class Container>
bool minusRazn(Container& cont)
{
    if (cont.empty()) return false;
    auto [minIt, maxIt] = std::minmax_element(cont.begin(), cont.end());
    int razn = *maxIt - *minIt;
    for (auto& elem : cont)
    {
        elem = elem - razn;
    }
    return true;
}

// для даблов
template<class Container>
bool minusRaznDouble(Container& cont)
{
    if (cont.empty()) return false;
    auto [minIt, maxIt] = std::minmax_element(cont.begin(), cont.end());
    double razn = *maxIt - *minIt;
    for (auto& elem : cont)
    {
        elem = elem - razn;
    }
    return true;
}

// 1 zadanie

void zadanie1()
{
    std::cout << "---------------------------\n";
    std::deque<double> d1;
    d1 = { 2.2, 3.3, 1.7, 6.7 };
    std::cout << "Задача 1 (deque<double>):\nИсходная очередь: ";
    for (auto i : d1) std::cout << i << " ";
    std::cout << "\n";

    // добавим 3.3 на 3 позицию
    if (insertKey(d1, 3.3, 3)) std::cout << "Вставили 3.3 на 3 позицию: ";
    else std::cout << "Элемент не найден.\n";
    for (auto i : d1) std::cout << i << " ";
    std::cout << "\n";

    // удалим элемент 2.2
    if (eraseKey(d1, 2.2)) std::cout << "Удалили 2.2: ";
    else std::cout << "Элемент 2.2 не найден.\n";
    for (auto i : d1) std::cout << i << " ";
    std::cout << "\n";

    // вычислить разницу между макс и мин и вычесть ее
    if (minusRaznDouble(d1)) std::cout << "Вычли разницу: ";
    else std::cout << "Неизвестная ошибка!\n";
    for (auto i : d1) std::cout << i << " ";
    std::cout << "\n";
    std::cout << "---------------------------\n";
}

// 2 zadanie

class Time
{
    private:
    int total_seconds;  // всё в секундах
    public:
    Time(int min = 0, int sec = 0)
    {
        total_seconds = min * 60 + sec;
        if (total_seconds < 0) total_seconds = 0;
    }
    int getMinutes() const { return total_seconds / 60; }
    int getSeconds() const { return total_seconds % 60; }
    int getTotalSeconds() const { return total_seconds; }

    // Операторы сравнения
    bool operator==(const Time& other) const
    {
        return total_seconds == other.total_seconds;
    }

    bool operator<(const Time& other) const
    {
        return total_seconds < other.total_seconds;
    }

    bool operator>(const Time& other) const
    {
        return total_seconds > other.total_seconds;
    }

    // Вычитание двух Time -> разница в секундах
    int operator-(const Time& other) const
    {
        return total_seconds - other.total_seconds;
    }

    // Вычитание целого числа секунд из Time
    Time operator-(int sec) const
    {
        return Time(0, total_seconds - sec);
    }

    // Присваивание с вычитанием секунд
    Time& operator-=(int sec)
    {
        total_seconds -= sec;
        if (total_seconds < 0) total_seconds = 0;
        return *this;
    }

    // Ввод / вывод
    friend std::istream& operator>>(std::istream& is, Time& t)
    {
        int m, s;
        char colon;
        is >> m >> colon >> s;
        t = Time(m, s);
        return is;
    }

    friend std::ostream& operator<<(std::ostream& os, const Time& t)
    {
        os << t.getMinutes() << ":" << (t.getSeconds() < 10 ? "0" : "") << t.getSeconds();
        return os;
    }
};

void zadanie2()
{
    std::cout << "---------------------------\n";
    std::deque<Time> d1;
    d1 = { Time(1, 30), Time(2, 28), Time(0, 44), Time(3, 0), Time(2, 15) };
    std::cout << "Задача 2 (deque<Time>):\nИсходная очередь: ";
    for (auto i : d1) std::cout << i << " ";
    std::cout << "\n";

    // добавим время 02:28 на позицию 1
    if (insertKey(d1, Time(2, 28), 1)) std::cout << "Вставили 02:28 на 1 позицию: ";
    else std::cout << "Элемент не найден.\n";
    for (auto i : d1) std::cout << i << " ";
    std::cout << "\n";

    // удалим элемент 03:00
    if (eraseKey(d1, Time(3, 0))) std::cout << "Удалили 03:00: ";
    else std::cout << "Элемент 03:00 не найден.\n";
    for (auto i : d1) std::cout << i << " ";
    std::cout << "\n";

    // вычислить разницу между макс и мин и вычесть ее
    if (minusRazn(d1)) std::cout << "Вычли разницу: ";
    else std::cout << "Неизвестная ошибка!\n";
    for (auto i : d1) std::cout << i << " ";
    std::cout << "\n";
    std::cout << "---------------------------\n";
}

// 3 zadanie

template <typename T>
class Vector
{
    private:
    std::vector<T> data;

    public:
    void add(const T& value) { data.push_back(value); }
    void print() const
    {
        for (const auto& v : data) std::cout << v << " ";
        std::cout << "\n";
    }

    // 3. найти элемент с заданным ключом и добавить его на заданную позицию
    bool insertKey(const T& key, size_t pos)
    {
        auto it = std::find(data.begin(), data.end(), key);
        if (it == data.end()) return false;
        if (pos > data.size()) return false;
        data.insert(data.begin() + pos, *it);
        return true;
    }

    // 4. найти элемент с заданным ключом и удалить его из контейнера
    bool eraseKey(const T& key)
    {
        auto it = std::find(data.begin(), data.end(), key);
        if (it == data.end()) return false;
        data.erase(it);
        return true;
    }

    // 5. найти разницу между макс и мин элементами контейнера и вычесть ее из каждого элемента контейнера
    bool minusRazn()
    {
        if (data.empty()) return false;
        auto [minIt, maxIt] = std::minmax_element(data.begin(), data.end());
        int diff = *maxIt - *minIt;
        for (auto& elem : data)
        {
            elem = elem - diff;
        }
        return true;
    }

    // для даблов
    bool minusRaznDoubleVec()
    {
        if (data.empty()) return false;
        auto [minIt, maxIt] = std::minmax_element(data.begin(), data.end());
        double razn = *maxIt - *minIt;
        for (auto& elem : data)
        {
            elem = elem - razn;
        }
        return true;
    }
};

void zadanie3()
{

    std::cout << "---------------------------\n";
    Vector<double> v1;
    v1.add(10.5);
    v1.add(6.7);
    v1.add(20.3);
    v1.add(5.1);
    v1.add(11.11);
    std::cout << "Задача 3 (Vector<double):\nИсходный вектор: ";
    v1.print();

    // добавим 11.11 на позицию 0
    if (v1.insertKey(11.11, 0)) std::cout << "Вставили 11.11 на 0 позицию: ";
    else std::cout << "Элемент не найден.\n";
    v1.print();

    // удалим элемент 03:00
    if (v1.eraseKey(6.7)) std::cout << "Удалили 6.7: ";
    else std::cout << "Элемент 6.7 не найден.\n";
    v1.print();

    // вычислить разницу между макс и мин и вычесть ее
    if (v1.minusRaznDoubleVec()) std::cout << "Вычли разницу: ";
    else std::cout << "Неизвестная ошибка!\n";
    v1.print();
    std::cout << "---------------------------\n";
}

// 4 zadanie

template <typename T>
void priorityQueueInsertKey(std::priority_queue<T>& pq, const T& key, int /*pos - игнорируем*/) {
    // Найдём, есть ли key в очереди (нужно переложить все во временный вектор)
    std::vector<T> temp;
    while (!pq.empty())
    {
        temp.push_back(pq.top());
        pq.pop();
    }
    auto it = std::find(temp.begin(), temp.end(), key);
    if (it != temp.end())
    {
        // добавляем копию найденного элемента
        temp.push_back(*it);
    }
    // Перестраиваем priority_queue
    for (const auto& e : temp) pq.push(e);
}

template <typename T>
bool priorityQueueEraseKey(std::priority_queue<T>& pq, const T& key) {
    std::vector<T> temp;
    while (!pq.empty())
    {
        temp.push_back(pq.top());
        pq.pop();
    }
    auto it = std::find(temp.begin(), temp.end(), key);
    if (it == temp.end()) return false;
    temp.erase(it);
    for (const auto& e : temp) pq.push(e);
    return true;
}

template <typename T>
void priorityQueueMinusRazn(std::priority_queue<T>& pq)
 {
    if (pq.empty()) return;
    std::vector<T> temp;
    while (!pq.empty())
    {
        temp.push_back(pq.top());
        pq.pop();
    }
    auto [minIt, maxIt] = std::minmax_element(temp.begin(), temp.end());
    int diff = *maxIt - *minIt;   // для Time разница в секундах
    for (auto& e : temp)
    {
        e = e - diff;  // вычитаем секунды
    }
    for (const auto& e : temp) pq.push(e);
}

void zadanie4()
{
    std::cout << "---------------------------\n";
    std::priority_queue<Time> pq;
    pq.push(Time(1,10));
    pq.push(Time(3,20));
    pq.push(Time(0,50));
    pq.push(Time(2,30));
    pq.push(Time(3,20));
    std::cout << "Задача 4 (priority_queue<Time>):\nИсходная очередь: ";
    // Выведем, скопировав в вектор (priority_queue не имеет итераторов)
    std::vector<Time> forPrint;
    auto pqCopy = pq;
    while (!pqCopy.empty()) { forPrint.push_back(pqCopy.top()); pqCopy.pop(); }
    std::reverse(forPrint.begin(), forPrint.end()); // чтобы вывести от меньшего к большему
    for (auto t : forPrint) std::cout << t << " "; std::cout << "\n";

    // добавим 03:20 (позиция не важна)
    priorityQueueInsertKey(pq, Time(3,20), 0);
    std::cout << "Вставили 03:20: ";
    forPrint.clear(); pqCopy = pq;
    while (!pqCopy.empty()) { forPrint.push_back(pqCopy.top()); pqCopy.pop(); }
    std::reverse(forPrint.begin(), forPrint.end());
    for (auto t : forPrint) std::cout << t << " "; std::cout << "\n";

    // удалим элемент 00:50
    if (priorityQueueEraseKey(pq, Time(0,50)))
        std::cout << "Удалили 00:50: ";
    else
        std::cout << "Элемент 00:50 не найден.\n";
    forPrint.clear(); pqCopy = pq;
    while (!pqCopy.empty()) { forPrint.push_back(pqCopy.top()); pqCopy.pop(); }
    std::reverse(forPrint.begin(), forPrint.end());
    for (auto t : forPrint) std::cout << t << " "; std::cout << "\n";

    // вычислить разницу между макс и мин и вычесть ее
    priorityQueueMinusRazn(pq);
    std::cout << "Вычли разницу: ";
    forPrint.clear(); pqCopy = pq;
    while (!pqCopy.empty()) { forPrint.push_back(pqCopy.top()); pqCopy.pop(); }
    std::reverse(forPrint.begin(), forPrint.end());
    for (auto t : forPrint) std::cout << t << " "; std::cout << "\n";
    std::cout << "------------------------\n";
}

// zadanie 5

template <typename T>
class PriorityQueueWrapper
{
    private:
    std::priority_queue<T> pq;
    public:
    void push(const T& value) { pq.push(value); }
    void print() const
    {
        std::vector<T> temp;
        auto copy = pq;
        while (!copy.empty())
        {
            temp.push_back(copy.top());
            copy.pop();
        }
        std::reverse(temp.begin(), temp.end());
        for (const auto& e : temp) std::cout << e << " ";
        std::cout << "\n";
    }

    // Задание 3: найти элемент и добавить его копию (позиция игнорируется)
    bool insertKey(const T& key, int /*pos*/)
    {
        std::vector<T> temp;
        while (!pq.empty())
        {
            temp.push_back(pq.top());
            pq.pop();
        }
        auto it = std::find(temp.begin(), temp.end(), key);
        if (it == temp.end()) return false;
        temp.push_back(*it);
        for (const auto& e : temp) pq.push(e);
        return true;
    }

    // Задание 4: удалить первый элемент с ключом
    bool eraseKey(const T& key)
    {
        std::vector<T> temp;
        while (!pq.empty())
        {
            temp.push_back(pq.top());
            pq.pop();
        }
        auto it = std::find(temp.begin(), temp.end(), key);
        if (it == temp.end()) return false;
        temp.erase(it);
        for (const auto& e : temp) pq.push(e);
        return true;
    }

    // Задание 5: вычесть разницу max-min из каждого элемента
    void minusRazn()
    {
        if (pq.empty()) return;
        std::vector<T> temp;
        while (!pq.empty())
        {
            temp.push_back(pq.top());
            pq.pop();
        }
        auto [minIt, maxIt] = std::minmax_element(temp.begin(), temp.end());
        int diff = *maxIt - *minIt;
        for (auto& e : temp)
        {
            e = e - diff;
        }
        for (const auto& e : temp) pq.push(e);
    }
};

void zadanie5()
{
    std::cout << "---------------------------\n";
    PriorityQueueWrapper<Time> wrapper;
    wrapper.push(Time(0,30));
    wrapper.push(Time(2,10));
    wrapper.push(Time(1,45));
    wrapper.push(Time(2,10));
    wrapper.push(Time(0,15));
    std::cout << "Задача 5 (PriorityQueueWrapper<Time>):\nИсходная очередь: ";
    wrapper.print();

    // добавим 02:10 (позиция не важна)
    if (wrapper.insertKey(Time(2, 10), 0)) std::cout << "Вставили 02:10: ";
    else std::cout << "Элемент не найден.\n";
    wrapper.print();

    // удалим элемент 00:15
    if (wrapper.eraseKey(Time(0, 15))) std::cout << "Удалили 00:15: ";
    else std::cout << "Элемент не найден.\n";
    wrapper.print();

    // вычесть разницу
    wrapper.minusRazn();
    std::cout << "Вычли разницу: ";
    wrapper.print();
    std::cout << "------------------------\n";
}

int main()
{

    SetConsoleOutputCP(65001);

    zadanie1();
    zadanie2();
    zadanie3();
    zadanie4();
    zadanie5();
}