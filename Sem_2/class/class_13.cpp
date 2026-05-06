/*
Задача 1.
1. Создать последовательный контейнер.
2. Заполнить его элементами пользовательского типа (тип указан в варианте). Для пользовательского типа перегрузить необходимые операции.
3. Заменить элементы в соответствии с заданием (использовать алгоритмы replace_if(), replace_copy(), replace_copy_if(), fill()).
4. Удалить элементы в соответствии с заданием (использовать алгоритмы remove(),remove_if(), remove_copy_if(),remove_copy())
5. Отсортировать контейнер по убыванию и по возрастанию ключевого поля (использовать алгоритм sort()).
6. Найти в контейнере заданный элемент (использовать алгоритмы  find(), find_if(), count(), count_if()).
7. Выполнить задание варианта для полученного контейнера (использовать алгоритм for_each()) .
8.  Для выполнения всех заданий использовать стандартные алгоритмы библиотеки STL.

Задача 2.
1. Создать адаптер  контейнера.
2. Заполнить его элементами пользовательского типа (тип указан в варианте). Для пользовательского типа перегрузить необходимые операции.
3. Заменить элементы в соответствии с заданием (использовать алгоритмы replace_if(), replace_copy(), replace_copy_if(), fill()).
4. Удалить элементы в соответствии с заданием (использовать алгоритмы remove(),remove_if(), remove_copy_if(),remove_copy())
5. Отсортировать контейнер по убыванию и по возрастанию ключевого поля (использовать алгоритм sort()).
6. Найти в контейнере элемент с заданным ключевым полем (использовать алгоритмы  find(), find_if(), count(), count_if()).
7. Выполнить задание варианта для полученного контейнера (использовать алгоритм for_each()) .
8.  Для выполнения всех заданий использовать стандартные алгоритмы библиотеки STL.

Задача 3
1. Создать ассоциативный контейнер.
2. Заполнить его элементами пользовательского типа (тип указан в варианте). Для пользовательского типа перегрузить необходимые операции.
3. Заменить элементы в соответствии с заданием (использовать алгоритмы replace_if(), replace_copy(), replace_copy_if(), fill()).
4. Удалить элементы в соответствии с заданием (использовать алгоритмы remove(),remove_if(), remove_copy_if(),remove_copy())
5. Отсортировать контейнер по убыванию и по возрастанию ключевого поля (использовать алгоритм sort()).
6. Найти в контейнере элемент с заданным ключевым полем (использовать алгоритмы  find(), find_if(), count(), count_if()).
7. Выполнить задание варианта для полученного контейнера (использовать алгоритм for_each()) .
8.  Для выполнения всех заданий использовать стандартные алгоритмы библиотеки STL.
*/


// я случайно задания из 2 варианта сделал, но с контейнерами 3 варианта!!!!!
#include <iostream>
#include <deque>
#include <queue>
#include <set>
#include <algorithm>
#include <windows.h>

// с прошлой лабы взял, не стал снова писать
// класс тайм
class Time {
private:
    int total_seconds;
public:
    Time(int min = 0, int sec = 0) {
        total_seconds = min * 60 + sec;
        if (total_seconds < 0) total_seconds = 0;
    }

    int getMinutes() const { return total_seconds / 60; }
    int getSeconds() const { return total_seconds % 60; }
    int getTotalSeconds() const { return total_seconds; }

    // Операторы сравнения (необходимы для multiset)
    bool operator<(const Time& other) const {
        return total_seconds < other.total_seconds;
    }

    bool operator==(const Time& other) const {
        return total_seconds == other.total_seconds;
    }

    bool operator>(const Time& other) const {
        return total_seconds > other.total_seconds;
    }

    // Разность двух Time (в секундах)
    int operator-(const Time& other) const {
        return total_seconds - other.total_seconds;
    }

    Time operator+(const Time& other) const {
        Time tmp;
        tmp.total_seconds = total_seconds + other.total_seconds;
        return tmp;
    }

    // Вычитание целого числа секунд из Time – возвращает новый объект
    Time operator-(int sec) const {
        return Time(0, total_seconds - sec);
    }

    // Присваивание с вычитанием секунд
    Time& operator-=(int sec) {
        total_seconds -= sec;
        if (total_seconds < 0) total_seconds = 0;
        return *this;
    }

    // Ввод/вывод
    friend std::istream& operator>>(std::istream& is, Time& t) {
        int m, s;
        char colon;
        is >> m >> colon >> s;
        t = Time(m, s);
        return is;
    }
    friend std::ostream& operator<<(std::ostream& os, const Time& t) {
        os << t.getMinutes() << ":" << (t.getSeconds() < 10 ? "0" : "") << t.getSeconds();
        return os;
    }
};

void print_dq(const std::deque<Time>& dq) {
    for (const auto& item : dq) {
        std::cout << item << " ";
    }
    std::cout << "\n";
}

void zadacha1() {
    std::cout << "--------------------\n";
    std::cout << "Задача 1:\n";
    std::cout << "Исходная очередь: ";
    std::deque<Time> dq = { Time(1, 20), Time(2, 22), Time(3, 0), Time(0, 45), Time(10, 11) };
    print_dq(dq);

    // 3 zadanie
    std::cout << "Копируем самый маленьикй элемент в конец: ";
    Time min = *std::min_element(dq.begin(), dq.end());
    dq.push_back(min);
    print_dq(dq);

    // 4 zadanie
    std::cout << "Удаляем Time(2, 22): ";
    for (auto iter = dq.begin(); iter != dq.end();) {
        if (*iter == Time(2, 22)) iter = dq.erase(iter);
        else ++iter;
    }
    print_dq(dq);

    // 5 zadanie
    std::cout << "Сортируем: ";
    std::sort(dq.begin(), dq.end());
    print_dq(dq);

    // 6 zadanie
    auto it = std::find(dq.begin(), dq.end(), Time(1, 20));
    std::cout << *it << " Найдено!" << "\n";

    // 7 zadanie
    std::cout << "Добавляем сумму: ";
    Time max = *std::max_element(dq.begin(), dq.end());
    Time sum = min + max;
    std::for_each(dq.begin(), dq.end(), [sum](Time& n) {
        n = n + sum;
    });
    print_dq(dq);
    std::cout << "--------------------\n";
}

void print_pq(std::priority_queue<Time> pq) {
    while (!pq.empty()) {
        Time t = pq.top();
        std::cout << t << " ";
        pq.pop();
    }
    std::cout << "\n";
}

Time min_pq(std::priority_queue<Time> pq) {
    Time t;
    while (!pq.empty()) {
        t = pq.top();
        pq.pop();
    }
    return t;
}

std::priority_queue<Time> delElemPq(std::priority_queue<Time> pq, const Time& t) {
    std::priority_queue<Time> tmp;
    while (!pq.empty()) {
        Time t1 = pq.top();
        if (t1 == t) pq.pop();
        else { tmp.push(t1); pq.pop(); }
    }
    return tmp;
}

Time find_pq(std::priority_queue<Time> pq, const Time& t) {
    while (!pq.empty()) {
        Time t1 = pq.top();
        if (t1 == t) return t1;
        pq.pop();
    }
    return Time(0, 0);
}

std::priority_queue<Time> plusRazn(std::priority_queue<Time> pq, const Time& t) {
    std::priority_queue<Time> tmp;
    while (!pq.empty()) {
        Time t1 = pq.top() + t;
        tmp.push(t1);
        pq.pop();
    }
    return tmp;
}

void zadacha2() {
    std::cout << "--------------------\n";
    std::cout << "Задача 2:\n";
    std::priority_queue<Time> pq;
    pq.push(Time(1, 20));
    pq.push(Time(2, 22));
    pq.push(Time(3, 0));
    pq.push(Time(0, 45));
    pq.push(Time(11, 10));
    std::cout << "Исходная очередь: ";
    print_pq(pq);

    // 3 zadanie
    std::cout << "Копируем самый маленьикй элемент в конец: "; // в конец он не добавится
    Time min = min_pq(pq);
    pq.push(min);
    print_pq(pq);

    // 4 zadanie
    std::cout << "Удаляем Time(2, 22): ";
    pq = delElemPq(pq, Time(2, 22));
    print_pq(pq);

    // 5 zadanie
    std::cout << "Сортируем: ";
    // он итак отсортирован
    print_pq(pq);

    // 6 zadanie
    Time it = find_pq(pq, Time(1, 20));
    if (it == Time(0, 0)) std::cout << "Элемент не найден.\n";
    else std::cout << it << " Найдено!" << "\n";

    // 7 zadanie
    std::cout << "Добавляем сумму: ";
    Time max = pq.top(); // самый верхний элемент самый большой по значнию
    Time sum = min + max;
    pq = plusRazn(pq, sum);
    print_pq(pq);
    std::cout << "--------------------\n";
}

void print_mt(const std::multiset<Time>& mt) {
    for (const auto& item : mt) {
        std::cout << item << " ";
    }
    std::cout << "\n";
}

void zadacha3() {
    std::cout << "--------------------\n";
    std::cout << "Задача 3:\n";
    std::multiset<Time> mt = { Time(1, 20), Time(2, 22), Time(3, 0), Time(0, 45), Time(10, 11) };
    std::cout << "Исходная очередь: ";
    print_mt(mt);

    // 3 zadanie
    std::cout << "Копируем самый маленьикй элемент в конец: "; // в конец он не добавится
    Time min = *std::min_element(mt.begin(), mt.end());
    mt.insert(min);
    print_mt(mt);

    // 4 zadanie
    std::cout << "Удаляем Time(2, 22): ";
    for (auto iter = mt.begin(); iter != mt.end();) {
        if (*iter == Time(2, 22)) iter = mt.erase(iter);
        else ++iter;
    }
    print_mt(mt);

    // 5 zadanie
    std::cout << "Сортируем: ";
    // отсортирован в своем порядке
    print_mt(mt);

    // 6 zadanie
    auto it = std::find(mt.begin(), mt.end(), Time(1, 20));
    if (*it == Time(1, 20)) std::cout << *it << " Найдено!" << "\n";
    else std::cout << "Элемент не найден.\n";;

    // 7 zadanie
    std::cout << "Добавляем сумму: ";
    Time max = *std::max_element(mt.begin(), mt.end());
    Time sum = min + max;
    std::multiset<Time> new_mt;
    for (const Time& t : mt) {
        new_mt.insert(t + sum);
    }
    mt.swap(new_mt);
    print_mt(mt);
    std::cout << "--------------------\n";
}

int main() {
    SetConsoleOutputCP(65001);
    zadacha1();
    zadacha2();
    zadacha3();
}