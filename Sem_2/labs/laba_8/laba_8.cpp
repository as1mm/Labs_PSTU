#include <iostream>
#include <string>
#include <fstream>
#include <clocale>
#include <limits>

// создаем структуру государство
struct Gosud
{
    std::string name;
    std::string capital;
    int population;
    int area;

    void print() // метод вывода структуры
    {
        std::cout << "название: " << name << "\n";
        std::cout << "столица: " << capital << "\n";
        std::cout << "население: " << population << "\n";
        std::cout << "площадь: " << area << "\n";
    }

};

// создаем функцию, которая возвращает указатель на новый массив
// функция удаляет элемент, который не соответствует численности населения
Gosud* deleteElement(Gosud* arr, int& size, int popul)
{
    int cnt = 0;

    // считаем сколько элементов(структур) не подходит под условие
    for (int i = 0; i < size; i++)
    {
        if (arr[i].population <= popul) { cnt++; }
    }

    if (cnt == 0) return arr; // если все элементы массива подходят, то иы не изменяем массив, а просто возвращаем тот же

    Gosud* new_arr = new Gosud[size - cnt]; // создаем новый массив динамически

    // перебираем все элементы нашего массива структур
    // и заполняем новый массив уже без ненужного нам элемента
    for (int i = 0, k = 0; i < size; i++)
    {
        if (arr[i].population >= popul)
        {
            new_arr[k] = arr[i];
            k++;
        }
    }

    // очищаем память и изменяем размер
    delete[] arr;
    size -= cnt;
    return new_arr;
}

// создаем функцию добавления элемента(структуры) после k-того элемента
// так же создаем новый массив динамически и добавляем элемент
// элемент мы добавляем самостоятельно(получаем от пользователя)
Gosud* addElement(Gosud* arr, int& size, int k) // k - это после какого элемента добавляем
{
    std::string name, capital, population, area;

    // получаем от пользователя данные о гос-ве
    std::cout << "введите название государства: "; std::getline(std::cin, name);
    std::cout << "введите название столицы: "; std::getline(std::cin, capital);
    std::cout << "введите численность населения: "; std::getline(std::cin, population);
    std::cout << "введите занимаемую площадь: "; std::getline(std::cin, area);
    std::cout << "\n";
    Gosud gos = {name, capital, stoi(population), stoi(area)}; // создаем новое государство
    gos.print(); // выведем новое гос-во

    Gosud* new_arr = new Gosud[size + 1]; // создаем новый массив структур, чтобы добавить новую структуру

    for (int i = 0, j = 0; i < size + 1; i++)
    {
        if (i == k + 1) { new_arr[i] = gos; }
        else { new_arr[i] = arr[j]; j++; }
    }

    size += 1;
    delete[] arr;
    return new_arr;
}

int main()
{
    setlocale(LC_ALL, "ru_RU.UTF-8");

    // открываем файл
    std::ifstream filee("laba_8.txt");
    std::string tmp; // переменная для "\n" в файле
    int size = 5; // столько структур в файле

    Gosud* arr = new Gosud[size];
    std::string name, capital, population, area;

    // проверяем что файл успешно открылся, если открылся, то заполняем массив структур
    if (filee.is_open())
    {
        for (int i = 0; i < size; i++)
        {
            std::getline(filee, name);
            std::getline(filee, capital);
            std::getline(filee, population);
            std::getline(filee, area);

            arr[i] = {name, capital, stoi(population), stoi(area)};

            std::getline(filee, tmp);
        }
        filee.close(); // закрываем файл чтобы не было проблем
    }

    int chisl;
    std::cout << "Введите численность населения: ";
    std::cin >> chisl;

    int k;
    std::cout << "Введите число, после какого элемента добавить новое гос-во: ";
    std::cin >> k;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // это для того, чтобы getline(cin, ...) нормально работал(а то там ошибка какая-то)

    // присваиваем нашему массиву функции, так как наши функции возвращают указатель на массив
    arr = deleteElement(arr, size, chisl); // удаляем структуры, где меньше заданного населения
    arr = addElement(arr, size, k); // добавляем элемент

    std::cout << "\n";

    // выведем наш массив структур
    for (int i = 0; i < size; i++)
    {
        std::cout << i + 1 << "\n";
        arr[i].print();
        std::cout << "\n";
    }

    // очищаем память
    delete[] arr;

    return 0;
}