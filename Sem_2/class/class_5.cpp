/*
1. Определить абстрактный класс.
2. Определить иерархию классов, в основе которой будет находиться абстрактный
класс (см. лабораторную работу №4).
3. Определить класс Вектор, элементами которого будут указатели на объекты
иерархии классов.
4. Перегрузить для класса Вектор операцию вывода объектов с помощью потоков.
5. В основной функции продемонстрировать перегруженные операции и
полиморфизм Вектора.
*/

#include <iostream>
#include <cmath>


// наш абстрактный класс (код взят полностью из 4 лаб, просто добавим чисто виртуальную функцию)
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

    virtual void print() const = 0;
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

    virtual void print() const override
    {
        std::cout << "Katet1 = " << first << " Katet2 = " << second << "\n";
    }
};

int main()
{
    RightAngled r(4, 3);
    r.print();
    std::cout << r.gipotenuza();
}
