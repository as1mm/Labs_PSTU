/*
1. Реализовать класс, перегрузить для него операции, указанные в варианте.
2. Определить исключительные ситуации.
3. Предусмотреть генерацию исключительных ситуаций.
*/

const int MAX_SIZE = 30;

enum ErrorCode
{
    ERROR1 = 1,
    ERROR2 = 2
};

#include <iostream>

class Vector
{
    private:
    int* data;
    int size;

    public:
    Vector(int val, int s)
    {
        if (s > MAX_SIZE) throw ERROR1;
        size = s;
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
        if (0 <= idx < size) throw ERROR2;
        return data[idx];
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

    void operator++()
    {
        int val;
        int new_size = size + 1;
        int* new_data = new int[new_size];
        std::cout << "Enter value: ";
        std::cin >> val;
        new_data[0] = val;
        for (int i = 1; i < new_size; i++)
            new_data[i] = data[i - 1];
        delete[] data;
        data = new_data;
        size = new_size;
    }

    void operator++(int)
    {
        int val;
        int new_size = size + 1;
        int* new_data = new int[new_size];
        std::cout << "Enter value: ";
        std::cin >> val;
        for (int i = 0; i < new_size - 1; i++)
            new_data[i] = data[i];
        new_data[new_size] = val;
        delete[] data;
        data = new_data;
        size = new_size;
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
};

int main()
{
    try
    {
        Vector v1(6, 3);
        v1.print();
        Vector v2(0, 31);
        v2.print();
        std::cout << v1[-1];
        int ans = v1[-1];
        std::cout << ans;
    }

    catch(ErrorCode error)
    {
        if (error == ERROR1) std::cout << "ERROR1!!!! Max_size = 30\n";
        if(error == ERROR2) std::cout << "ERROR2!!!! Index out of range\n";
    }
}