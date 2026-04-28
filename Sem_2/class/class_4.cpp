/*
1. Определить пользовательский класс.
2. Определить в классе следующие конструкторы: без параметров, с параметрами,
копирования.
3. Определить в классе деструктор.
4. Определить в классе компоненты-функции для просмотра и установки полей
данных (селекторы и модификаторы).
5. Перегрузить операцию присваивания.
6. Перегрузить операции ввода и вывода объектов с помощью потоков.
7. Определить производный класс.
8. Написать программу, в которой продемонстрировать создание объектов и работу
всех перегруженных операций.
9.  Реализовать функции, получающие и возвращающие объект базового класса.
Продемонстрировать принцип подстановки.
*/

#include <iostream>
#include <cmath>

class Pair
{
    protected:
    int first;
    int second;

    public:
    Pair() : first(0), second(0) {}
    Pair(int a, int b) : first(a), second(b) {}
    Pair(const Pair &other)
    {
        first = other.first;
        second = other.first;
    }
    virtual ~Pair() {}

    void setFirst(int a)
    {
        first = a;
    }

    void setSecond(int a)
    {
        second = a;
    }

    int getFirst() { return first; }

    int getSecond() { return second; }

    void getPair()
    {
        std::cout << "First = " << first << ", Second = " << second << "\n";
    }

    int multiplyPair()
    {
        return first * second;
    }
};

class RightAngled : public Pair
{
    public:
    RightAngled() : Pair() {}
    RightAngled(int a, int b) : Pair(a, b) {}

    double gipotenuza() const
    {
        return sqrt(static_cast<double>(first * first + second * second));
    }
};

int main()
{
    RightAngled r(4, 3);
    std::cout << r.gipotenuza();
}