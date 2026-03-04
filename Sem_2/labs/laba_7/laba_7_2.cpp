#include <cstdarg>
#include <iostream>

int sum(int count, ...)
{
    va_list arg;
    va_start(arg, count);

    int prev = va_arg(arg, int); //берем первый аргумент
    int s = 0;

    for (int i = 1; i < count; i++) //начинаем с единицы, так как уже взяли первый аргумент(для формулы по сумме)
    {
        int current = va_arg(arg, int); //берем второй аргумент
        s += prev * current; //наша формула суммы: s = a1 * a2 + a2 * a3....
        prev = current;
    }

    va_end(arg);
    return s;
}

int main()
{
    std::cout << "5 ARGS: SUM = " << sum(5, 1, 2, 3, 4, 5) << "\n";
    std::cout << "10 ARGS: SUM = " << sum(10, 1, 2, 3, 4, 5, 3, 3, 5, 10, 11) << "\n";
    std::cout << "12 ARGS: SUM = " << sum(12, 22, 33, 3, 4, 5, 12, 5, 2, 4, 10, 44, 2) << "\n";
    return 0;
}