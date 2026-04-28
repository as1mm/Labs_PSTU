/*
1. Определить шаблон класса-контейнера (см. лабораторную работу №6).
2. Реализовать конструкторы, деструктор, операции ввода-вывода, операцию
присваивания.
3. Перегрузить операции, указанные в варианте.
4. Инстанцировать шаблон для стандартных типов данных (int, float, double).
5. Написать тестирующую программу, иллюстрирующую выполнение операций для
контейнера, содержащего элементы стандартных типов данных.
6. Реализовать пользовательский класс (см. лабораторную работу №3).
7. Перегрузить для пользовательского класса операции ввода-вывода.
8. Перегрузить операции необходимые для выполнения операций контейнерного
класса.
9. Инстанцировать шаблон для пользовательского класса.
10. Написать тестирующую программу, иллюстрирующую выполнение операций для
контейнера, содержащего элементы пользовательского класса.
*/

#include <iostream>

template<class T>
class Vector
{
    private:
    T* data;
    int size;

    public:
    Vector(T value, int s)
    {
        size = s;
        data = new T[size];
        for(int i = 0; i < size; i++)
            data[i] = value;
    }

    Vector(const Vector& v)
    {
        size = v.size;
        for(int i = 0; i < size; i++)
            data[i] = v.data[i];
    }

    ~Vector()
    {
        delete[] data;
        data = 0;
    }

    Vector operator+(const T& K) const
    {
        Vector tmp(*this);
        for (int i = 0; i < size; i++)
            tmp.data[i] = tmp.data[i] + K;
        return tmp;
    }

    Vector operator+(const Vector& v) const
    {
        if (v.size != size) return 0;

        Vector tmp(T(), size);
        for (int i = 0; i < size; i++)
            tmp.data[i] = data[i] + v.data[i];
        return tmp;
    }

    Vector& operator=(const Vector& v)
    {
        if (this == &v) return *this;
        if (data != 0) delete[] data;
        size = v.size;
        data = new T[size];
        for(int i = 0; i < size; i++)
            data[i] = v.data[i];
        return *this;
    }

    T operator[](int idx)
    {
        if (idx < size) return data[idx];
        else { std::cout << "ERROR, idx > size\n"; return data[0]; }
    }

    friend std::ostream& operator<<(std::ostream& os, const Vector& v)
    {
        for (int i = 0; i < v.size; i++)
            os << v.data[i] << " ";
        std::cout << "\n";
        return os;
    }

    // сначала размер, потом value
    friend std::istream& operator>>(std::istream& is, const Vector& v)
    {
        int new_size;
        is >> new_size;

        T* new_data = new T[new_size];
        for (int i = 0; i < new_size; i++)
            in >> new_data[i];

        delete[] v.data;
        v.data = new_data;
        v.size = new_size;
        return in;
    }

    class Iterator
    {
        private:
        int* ptr;

        public:
        Iterator(int* p) : ptr(p) {}

        Iterator& operator++()
        {
            ++ptr;
            return *this;
        }

        Iterator& operator--()
        {
            --ptr;
            return *this;
        }

        int& operator*() { return *ptr; }
    };

    Iterator begin() { return Iterator(data); } // первый элемент контейнера
    Iterator end() { return Iterator(data + size); } // указатель на пустоту за последним элементом контейнера
    Iterator back() { return Iterator(data + size - 1); } // последний элемент контейнера
};

class Time
{
    private:
    int minutes;
    int seconds;

    // нормализуем секунды
    void normalize()
    {
        if (seconds >= 60)
        {
            minutes += seconds / 60;
            seconds %= 60;
        }
    }

    public:
    Time() : minutes(0), seconds(0) {}
    Time(int m, int s) : minutes(m), seconds(s) { normalize(); }

    Time operator+(const Time& t) const
    {
        Time tmp;
        tmp.minutes = t.minutes + minutes;
        tmp.seconds = t.seconds + seconds;
        tmp.normalize();
        return tmp;
    }

    Time operator+(const int& K) const
    {
        Time tmp;
        tmp.seconds = seconds + K;
        tmp.minutes = minutes;
        tmp.normalize();
        return tmp;
    }

    Time& operator=(const Time& t)
    {
        if (this == &t) return *this;
        minutes = t.minutes;
        seconds = t.seconds;
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const Time& t)
    {
        os << (t.minutes < 10 ? "0" : "") << t.minutes << ":" << (t.seconds < 10 ? "0" : "") << t.seconds;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Time& t)
    {
        int m, s;
        is >> m >> s;
        t = Time(m, s);
        return is;
    }
};

int main()
{
    Vector<int> v1(0, 3);
    std::cout << v1;

    Vector<double> v2(2.2, 3);
    std::cout << v2;

    Vector<std::string> v3("string", 3);
    std::cout << v3;

    Vector<Time> v4(Time(19, 16), 3);
    std::cout << v4;

    Time t(21, 62);
    t = t + 20;
    Vector<Time> v5(t, 3);
    std::cout << v5;
}
