/*
Постановка задачи
1. Определить пользовательский класс.
2. Определить в классе следующие конструкторы: без параметров, с параметрами,
копирования.
3. Определить в классе деструктор.
4. Определить в классе компоненты-функции для просмотра и установки полей
данных (селекторы и модификаторы).
5. Перегрузить операцию присваивания.
6. Перегрузить операции ввода и вывода объектов с помощью потоков.
7. Перегрузить операции указанные в варианте.
8. Написать программу, в которой продемонстрировать создание объектов и работу
всех перегруженных операций.
*/

#include <iostream>

class Time
{
    private:
    int minutes;
    int seconds;

    public:
    Time() {}
    Time(int a, int b) : minutes(a), seconds(b)
    {
        if (b < 0) { seconds = 0; }
        if (b == 60) { minutes++; seconds = 0; b -= 60; }
        else
        {
            while (b > 60)
            {
                b -= 60;
                minutes++;
                seconds -= 60;
            }
        }
    }
    Time(const Time& t) : minutes(t.minutes), seconds(t.seconds) {}
    ~Time() {}

    void getTime()
    {
        std::cout << minutes << " : " << seconds << "\n";
    }

    void setTime(int &minutes, int &seconds)
    {
        this->minutes = minutes;
        this->seconds = seconds;
    }

    Time& operator++()
    {
        seconds++;
        if (seconds > 60) { minutes++; seconds -= 60; }
        return *this;
    }

    Time& operator--()
    {
        seconds--;
        if (seconds < 0) { seconds = 59; minutes--; }
        return *this;
    }

    Time& operator=(const Time& t)
    {
        if (this != &t)
        {
            minutes = t.minutes;
            seconds = t.seconds;
        }
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const Time& t);
    friend std::istream& operator>>(std::istream& is, Time& t);

};

std::ostream& operator<<(std::ostream& os, const Time& t)
{
    os << t.minutes << " : " << t.seconds << "\n";
    return os;
}

std::istream& operator>>(std::istream& is, Time& t)
{
    is >> t.minutes >> t.seconds;
    return is;
}

int main()
{
    Time t(1, 121);
    Time t1(67, 22);
    t.getTime();
    ++t;
    std::cout << t;
    --t;
    std::cout << t;
    t = t1;
    std::cout << t;
}