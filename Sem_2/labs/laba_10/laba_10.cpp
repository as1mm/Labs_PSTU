#include <iostream>
#include <ctime>

int main()
{
    int size;
    std::cout << "VVEDITE RAZMER ARR: ";
    std::cin >> size;
    int* arr = new int[size];
    std::cout << "\n";

    //Заполнили(рандом числами) и вывели массив
    srand(time(0));
    for (int i = 0; i < size; i++)
    {
        arr[i] = 1 + rand() % 100;
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
    //

    //Инициализируем с какого по какой элемент мы удаляем и какой элемент добавляем в конце
    int k, number, chislo;
    std::cout << "S KAKOGO ELEMENTA DELETAEM(INDEX): " << "\n";
    std::cin >> number;
    std::cout << "KOL-VO EL: " << "\n";
    std::cin >> k;
    std::cout << "CHISLO KOTOROE MI DOBAVIM: " << "\n";
    std::cin >> chislo;

    //Создаем новый массив (итоговый)
    int new_size = size - k + 1;
    int* new_arr = new int[new_size];
    //

    //Заполняем новый массив без тех элементов, которые нам надо удалить (по факту удаялем эти элементы)
    int index = 0;
    for (int i = 0; i < size; i++)
    {
        if (i == number)
        {
            i += k - 1;
        }
        else
        {
            new_arr[index] = arr[i];
            index++;
        }
    }
    new_arr[index] = chislo;
    std::cout << "\n";
    //

    //Удаляем ненужнйы массив
    delete[] arr;
    //

    //Выводим наш итоговый массив
    for (int i = 0; i < new_size; i++)
    {
        std::cout << new_arr[i] << " ";
    }
    //

    return 0;
}