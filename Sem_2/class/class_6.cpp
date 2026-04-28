/*
1. Определить класс-контейнер.
2. Реализовать конструкторы, деструктор, операции ввода-вывода, операцию
присваивания.
3. Перегрузить операции, указанные в варианте.
4. Реализовать класс-итератор. Реализовать с его помощью операции
последовательного доступа.
5. Написать тестирующую программу, иллюстрирующую выполнение операций.
*/

#include <iostream>

class Vector
{
    private:
    int* data;
    int size;

    public:
    Vector(int val, int s) : size(s)
    {
        data = new int[size];
        for (int i = 0; i < size; i++) data[i] = val;
    }

    Vector(const Vector& v) : size(v.size)
    {
        data = new int[size];
        for (int i = 0; i < size; i++) data[i] = v.data[i];
    }

    ~Vector()
    {
        delete[] data;
        data = 0;
    }

    // присваивание
    Vector& operator=(const Vector& v)
    {
        if (this == &v) return *this;
        size = v.size;
        if (data != 0) delete[] data;
        data = new int[size];
        for(int i = 0; i < size; i++) data[i] = v.data[i];
        return *this;
    }

    // индехы
    int operator[](int idx) const
    {
        if (idx < size) return data[idx];
        else { std::cout << "ERROR, index > size\n"; return data[0]; }
    }

    // прибавляем конст
    Vector operator+(const int K) const
    {
        Vector tmp(K, size);
        for(int i = 0; i < size; i++) tmp.data[i] = data[i] + K;
        return tmp;
    }

    // складываем контейнеры
    Vector operator+(const Vector& v) const
    {
        Vector tmp(0, size);
        for(int i = 0; i < size; i++) tmp.data[i] = data[i] + v.data[i];
        return tmp;
    }

    // вывод контейнера
    void print() const
    {
        for(int i = 0; i < size; i++)
        {
            std::cout << data[i] << " ";
        }
        std::cout << "\n";
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


int main()
{
    Vector ans(0, 3);
    ans.print();
    ans = ans + 3;
    ans.print();
    ans = ans + ans;
    ans.print();
    *ans.back() = 8;
    ans.print();
    std::cout << "first elem = " << *ans.begin() << ", last elem = " << *ans.back();
}