/*
Задача 1.
1. Создать ассоциативный контейнер.
2. Заполнить его элементами стандартного типа (тип указан в варианте).
3. Добавить элементы в соответствии с заданием
4. Удалить элементы в соответствии с заданием.
5. Выполнить задание варианта для полученного контейнера.
6.  Выполнение всех заданий оформить в виде глобальных функций.
Задача 2.
1. Создать ассоциативный контейнер.
2. Заполнить его элементами пользовательского типа (тип указан в варианте). Для
пользовательского типа перегрузить необходимые операции.
3. Добавить элементы в соответствии с заданием
4. Удалить элементы в соответствии с заданием.
5. Выполнить задание варианта для полученного контейнера.
6.  Выполнение всех заданий оформить в виде глобальных функций.
Задача 3
1. Создать параметризированный класс, используя в качестве контейнера
ассоциативный контейнер.
2. Заполнить его элементами.
3. Добавить элементы в соответствии с заданием
4. Удалить элементы в соответствии с заданием.
5. Выполнить задание варианта для полученного контейнера.
6.  Выполнение всех заданий оформить в виде методов параметризированного класса.
*/

/*
с этой лабы перехожу на новые скобочки, типа
int main{
    std::cout << "Новые скобочик";
}
щас как будто все так пишут, на форумах чаще встречается этот тип скобочек, в нейронках тоже (а может это из-за нейронок все так пишут?)
*/

#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <windows.h>

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
        os << t.getMinutes() << ":"
           << (t.getSeconds() < 10 ? "0" : "") << t.getSeconds();
        return os;
    }
};

// функции для первых двух заданий
// Задание 3: найти элемент с ключом и добавить его копию (позиция игнорируется)
template<class Container, class T>
bool insertKeyCopy(Container& cont, const T& key) {
    auto it = cont.find(key);
    if (it == cont.end()) return false;
    cont.insert(*it);
    return true;
}

// Задание 4: найти элемент с ключом и удалить его (один экземпляр)
template <class Container, class T>
bool eraseOneKey(Container& cont, const T& key) {
    auto it = cont.find(key);
    if (it == cont.end()) return false;
    cont.erase(it);
    return true;
}

// Задание 5: найти разницу max-min и вычесть её из каждого элемента
template <class Container>
bool subtractDiffFromAll(Container& cont) {
    if (cont.empty()) return false;
    auto minIt = cont.begin();
    auto maxIt = std::prev(cont.end());
    auto diff = *maxIt - *minIt;   // для double это число, для Time – секунды
    // Создаём временный контейнер с изменёнными значениями
    Container temp;
    for (const auto& elem : cont) {
        temp.insert(elem - diff);
    }
    cont.swap(temp);
    return true;
}

// zadacha 1
void zadanie1() {
    std::cout << "---------------------------\n";
    std::multiset<double> ms = {2.2, 3.3, 1.7, 6.7, 3.3};
    std::cout << "Задача 1 (multiset<double>):\nИсходный multiset: ";
    for (double x : ms) std::cout << x << " ";
    std::cout << "\n";

    // Добавить копию элемента 3.3 (позиция не важна)
    if (insertKeyCopy(ms, 3.3))
        std::cout << "Добавили копию 3.3: ";
    else
        std::cout << "Элемент 3.3 не найден.\n";
    for (double x : ms) std::cout << x << " ";
    std::cout << "\n";

    // Удалить один элемент 2.2
    if (eraseOneKey(ms, 2.2))
        std::cout << "Удалили 2.2: ";
    else
        std::cout << "Элемент 2.2 не найден.\n";
    for (double x : ms) std::cout << x << " ";
    std::cout << "\n";

    // Вычесть разницу между max и min из всех элементов
    if (subtractDiffFromAll(ms))
        std::cout << "Вычли разницу: ";
    else
        std::cout << "Ошибка! Контейнер пуст.\n";
    for (double x : ms) std::cout << x << " ";
    std::cout << "\n";
    std::cout << "---------------------------\n";
}

// zadanie 2
void zadanie2() {
    std::cout << "---------------------------\n";
    std::multiset<Time> ms = {Time(1,30), Time(2,28), Time(0,44), Time(3,0), Time(2,28)};
    std::cout << "Задача 2 (multiset<Time>):\nИсходный multiset: ";
    for (const Time& t : ms) std::cout << t << " ";
    std::cout << "\n";

    // Добавить копию Time(2,28)
    if (insertKeyCopy(ms, Time(2,28)))
        std::cout << "Добавили копию 02:28: ";
    else
        std::cout << "Элемент не найден.\n";
    for (const Time& t : ms) std::cout << t << " ";
    std::cout << "\n";

    // Удалить один элемент Time(3,0)
    if (eraseOneKey(ms, Time(3,0)))
        std::cout << "Удалили 03:00: ";
    else
        std::cout << "Элемент 03:00 не найден.\n";
    for (const Time& t : ms) std::cout << t << " ";
    std::cout << "\n";

    // Вычесть разницу
    if (subtractDiffFromAll(ms))
        std::cout << "Вычли разницу: ";
    else
        std::cout << "Ошибка! Контейнер пуст.\n";
    for (const Time& t : ms) std::cout << t << " ";
    std::cout << "\n";
    std::cout << "---------------------------\n";
}

// zadanie 3
template <class T>
class MyMultiset {
private:
    std::multiset<T> data;
public:
    void add(const T& value) { data.insert(value); }
    void print() const {
        for (const auto& v : data) std::cout << v << " ";
        std::cout << "\n";
    }

    // Задание 3: найти элемент и добавить его копию (позиция игнорируется)
    bool insertCopy(const T& key, size_t /*pos*/) {
        auto it = data.find(key);
        if (it == data.end()) return false;
        data.insert(*it);
        return true;
    }

    // Задание 4: найти и удалить один элемент с ключом
    bool eraseOne(const T& key) {
        auto it = data.find(key);
        if (it == data.end()) return false;
        data.erase(it);
        return true;
    }

    // Задание 5: вычесть разницу max-min из всех элементов
    bool subtractDiff() {
        if (data.empty()) return false;
        auto minIt = data.begin();
        auto maxIt = std::prev(data.end());
        auto diff = *maxIt - *minIt;   // для double это double, для Time – int секунд
        std::multiset<T> temp;
        for (const auto& elem : data) {
            temp.insert(elem - diff);
        }
        data.swap(temp);
        return true;
    }
};

void zadanie3() {
    std::cout << "---------------------------\n";
    MyMultiset<double> ms;
    ms.add(10.5);
    ms.add(6.7);
    ms.add(20.3);
    ms.add(5.1);
    ms.add(11.11);
    std::cout << "Задача 3 (MyMultiset<double>):\nИсходный multiset: ";
    ms.print();

    // Добавить копию 11.11
    if (ms.insertCopy(11.11, 0))
        std::cout << "Добавили копию 11.11: ";
    else
        std::cout << "Элемент не найден.\n";
    ms.print();

    // Удалить 6.7
    if (ms.eraseOne(6.7))
        std::cout << "Удалили 6.7: ";
    else
        std::cout << "Элемент 6.7 не найден.\n";
    ms.print();

    // Вычесть разницу
    if (ms.subtractDiff())
        std::cout << "Вычли разницу: ";
    else
        std::cout << "Ошибка!\n";
    ms.print();
    std::cout << "---------------------------\n";
}


int main() {
    SetConsoleOutputCP(65001);

    zadanie1();
    zadanie2();
    zadanie3();
    return 0;
}
