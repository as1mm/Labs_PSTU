#include <iostream>
#include <windows.h>

struct Person
{
    std::string fio;    // фио - это наш ключ (по варианту)
    int numAcc;         // номер счета
    int sum;            // сумма (деньги на счету)
    bool deleted;       // tombstone

    Person() : fio(""), numAcc(0), sum(0), deleted(false) {} // конструктор без параметров
    Person(std::string FIO, int NUMACC, int SUM) : fio(FIO), numAcc(NUMACC), sum(SUM) , deleted(false) {} // конструктор с параметрами
    bool isEmpty() { return fio == "" && !deleted; } // функция, которая проверяет удален ли Person
};

class HashTable
{
    private:

    Person* arr;    // наш массив хеш-таблица
    int m;          // рамзер нашей таблицы
    int colissions; // кол-во коллизий
    int count;      // сколько ячеек в нашей таблице заполнено

    // хеш-функция из варианта
    int hashFunc(const std::string& fio)
    {
        int sum = 0;
        for (char ch : fio) sum += ch;
        return sum % m;
    }

    public:

    // конструктор хеш-таблицы
    HashTable(int size) : m(size), colissions(0), count(0)
    {
        arr = new Person[m];
    }

    // деструктор
    ~HashTable() { delete[] arr; }

    // метод вставки нового элемента в хеш-таблицу
    void insert(Person p)
    {
        if (count == m)     // если кол-во элементов массива == размеру массива, то таблица заполнена -> выходим т.к не можем вставить
        {
            std::cout << "ERROR, table is full\n";
            return;
        }

        int startIdx = hashFunc(p.fio);     // стартовый индекс - это тот индекс, который выдает наша хеш-функция
        int Idx = startIdx;

        // пока ячейка не пуста (в ней что-то есть и стоит tombstone)
        while (!arr[Idx].isEmpty() && !arr[Idx].deleted)
        {
            colissions++; // добавляем коллизию
            // если ключ совпадает с ключом элемента, то мы просто обновляем данные
            if (arr[Idx].fio == p.fio)
            {
                arr[Idx] = p;
                return;
            }

            // двигаемся дальше (ищем пустую ячейку)
            Idx = (Idx + 1) % m;
        }

        // вставляем элемент в пустую ячейку
        arr[Idx] = p;
        // добавляем кол-во использованных ячеек
        count++;
    }

    // метод поиска по фио
    void search(const std::string& fio)
    {
        SetConsoleCP(65001);
        SetConsoleOutputCP(65001);

        int startIdx = hashFunc(fio);
        int Idx = startIdx;

        // пока в ячейке что-то есть
        while (!arr[Idx].isEmpty())
        {
            // если ячейка не удалена и наше фио совпдает с тем, что в ячейке, то мы нашли
            if (!arr[Idx].deleted && arr[Idx].fio == fio)
            {
                std::cout << "Элемент по фио: " << fio << " найден по индексу: " << Idx << "\n";
                return;
            }

            // если не нашли, то двигаемся дальше
            Idx = (Idx + 1) % m;

            // если прошли по всему массиву и ничего не нашли(прошли круг), то выходим из цикла (по кругуу нет смысла ходить)
            if (Idx == startIdx) break;
        }

        // если ничего не нашли
        std::cout << "ERROR, элемент с такой фио не найден\n";
    }

    // метод удаления по фамилии, работает идентично поиску, но просто добавляет tombstone
    void remove(std::string fio)
    {
        SetConsoleCP(65001);
        SetConsoleOutputCP(65001);

        int startIdx = hashFunc(fio);
        int Idx = startIdx;

        // пока в ячейке что-то есть
        while (!arr[Idx].isEmpty())
        {
            // если ячейка не удалена и наше фио совпадает с тем, что в ячейке
            if (!arr[Idx].deleted && arr[Idx].fio == fio)
            {
                arr[Idx].deleted = true; // ставим tombstone
                count--; // уменьшаем кол-во занятых ячеек
                std::cout << "Элемент по фио: " << fio << " удален" << "\n";
                return;
            }

            // если не нашли, то двигаемся дальше
            Idx = (Idx + 1) % m;

            // если прошли круг, то выходим
            if (Idx == startIdx) break;
        }

        // не нашли элемент
        std::cout << "ERROR, элемент с такой фио не найден и не может быть удален\n";
    }

    void print() const
    {
        SetConsoleCP(65001);
        SetConsoleOutputCP(65001);
        std::cout << "\n=== HashTable ===\n";
        std::cout << "Size: " << m << "\n";
        std::cout << "Collisions: " << colissions << "\n";

        for (int i = 0; i < m; i++)
        {
            std::cout << "[ " << i << " ]: ";
            if (arr[i].isEmpty()) std::cout << "Empty\n";
            else if (arr[i].deleted) std::cout << "TOMBSTONE (deleted) [fio = " << arr[i].fio
                                               << ", numAcc = " << arr[i].numAcc
                                               << ", sum = " << arr[i].sum << "]\n";
            else std::cout << "ACTIVE [fio = " << arr[i].fio
                                               << ", numAcc = " << arr[i].numAcc
                                               << ", sum = " << arr[i].sum << "]\n";
        }

        std::cout << "==============================\n";
    }
};

int main()
{
    Person p1("Анисимов Владимир Валерьевич", 22062007, 1000000);
    Person p2("Старцев Виталий Дмитриевич", 258478, 14);
    Person p3("Елькина Юлия Дмитриевна", 17345634, 24821);
    Person p4("Петухов Павел Олегович", 17658, 1337);
    Person p5("Рачков Алексей Алексеевич", 94764, 69);
    Person p6("Анисимов Святослав Алексеевич", 823723, 67);
    Person p7("Салтыков Никита Андреевич", 32745, 23);
    Person p8("Грибков Константин Алексеевич", 234, 1488);
    Person p9("Кудрявцев Максим Леонидови", 1, 10231421);
    Person p10("Пунегов Кирилл Дмитриевич", 228, 2007);

    HashTable table(10);

    table.insert(p1);
    table.insert(p2);
    table.insert(p3);
    table.insert(p4);
    table.insert(p5);
    table.insert(p6);
    table.insert(p7);
    table.insert(p8);
    table.insert(p9);
    table.insert(p10);

    table.search("Анисимов Владимир Валерьевич");

    table.remove("Анисимов Владимир Валерьевич");

    table.print();
}