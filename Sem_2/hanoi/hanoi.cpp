#include <iostream>

void hanoi(int kolca, int start, int point, int temp)
{
    if (kolca <= 0) { return; }

    hanoi(kolca - 1, start, temp, point);
    std::cout << start << "-->" << point << "\n";
    hanoi(kolca - 1, temp, point, start);
}

int main()
{
    hanoi(3, 1, 3, 2);
    return 0;
}