/*
1. Определить иерархию пользовательских классов (см. лабораторную работу №5).
Во главе иерархии должен стоять абстрактный класс с чисто виртуальными
методами для ввода  и вывода информации об атрибутах объектов.
2. Реализовать конструкторы, деструктор, операцию присваивания, селекторы и
модификаторы.
3. Определить класс-группу на основе структуры, указанной в варианте.
4. Для группы реализовать конструкторы, деструктор, методы для добавления и
удаления элементов в группу, метод для просмотра группы, перегрузить операцию
для получения информации о размере группы.
5. Определить класс Диалог – наследника группы, в котором реализовать методы для
обработки событий.
6. Добавить методы для обработки событий  группой и объектами пользовательских
классов.
7. Написать тестирующую программу.
8. Нарисовать диаграмму классов и диаграмму объектов.
*/

#include <iostream>

class Abstr
{
    public:
    virtual void Show() const = 0;
    virtual void Input() = 0;
    virtual ~Abstr() {}
};

// можно было этот класс сделать абстрактным(наверное, в прошлых лабах я так делал)
class Person : public Abstr
{
    private:
    std::string name;
    int age;

    public:
    Person() : name(""), age(0) {}
    Person(const std::string& n, int a) : name(n), age(a) {}

    void Show() const override
    {
        std::cout << "Name: " << name << "\nAge: " << age << "\n";
    }

    void Input() override
    {
        std::string n;
        int a;
        std::cout << "Enter name: "; std::cin >> n;
        std::cout << "Enter age: "; std::cin >> a;
        name = n;
        age = a;
    }

    int getAge() const { return age; }
    std::string getName() const { return name; }

    void setAge(int a) { age = a; }
    void setName(const std::string& n) { name = n; }

    Person& operator=(const Person& p)
    {
        if (this == &p) return *this;
        age = p.age;
        name = p.name;
        return *this;
    }
};

class Abiturient : public Person
{
    private:
    int score;
    std::string spec;

    public:
    Abiturient() : Person(), score(0), spec("") {}
    Abiturient(int sc, const std::string& spc, int a, const std::string& n) : Person(n, a), score(sc), spec(spc) {}

    void Show() const override
    {
        Person::Show();
        std::cout << "Score: " << score << "\nSpecialty: " << spec << "\n";
    }

    void Input() override
    {
        int sc;
        std::string spc;
        Person::Input();
        std::cout << "Enter score: ";
        std::cin >> sc;
        std::cout << "Enter specialty(without spaces): ";
        std::cin >> spc;
        score = sc;
        spec = spc;
    }

    int getScore() const { return score; }
    std::string getSpecialty() const { return spec; }

    void setScore(int sc) { score = sc; }
    void setSpecialty(const std::string& spc) { spec = spc; }

    Abiturient& operator=(const Abiturient& a)
    {
        if (this == &a) return *this;
        Person::operator=(a);
        score = a.score;
        spec = a.spec;
        return *this;
    }
};

class VectorGroup
{
    private:
    Abstr** data;
    int size;
    int elem; // сколько элементов
    void resize(int new_size)
    {
        Abstr** new_data = new Abstr*[new_size];
        for (int i = 0; i < size; i++)
            new_data[i] = data[i];
        delete[] data;
        data = new_data;
        size = new_size;
    }

    public:
    VectorGroup() : data(nullptr), size(0), elem(0) {}
    VectorGroup(int s) : data(nullptr), size(s), elem(0)
    {
        for (int i = 0; i < s; i++)
        {
            Abiturient* a = new Abiturient();
            a->Input();
            push_back(a);
        }
    }
    ~VectorGroup()
    {
        clear();
        delete[] data;
    }

    void clear()
    {
        for (int i = 0; i < size; i++)
            delete data[i];
        elem = 0;
    }

    void push_back(Abstr* a)
    {
        if (elem == size)
        {
            int new_size = size * 2;
            resize(new_size);
        }
        data[elem++] = a;
    }

    bool pop_back()
    {
        if (elem == 0) return false;
        delete data[elem - 1];
        elem--;
        return true;
    }

    void print() const
    {
        if (elem == 0)
        {
            std::cout << "Group is empty" << "\n";
            return;
        }

        for (int i = 0; i < elem; i++)
        {
            data[i]->Show();
            std::cout << "\n";
        }
        std::cout << "\n";
    }

    int operator()() const { return elem; }

    int avgAge() const
    {
        if (elem == 0) return 0;
        int avg = 0;
        for (int i = 0; i < elem; i++)
        {
            Person* p = dynamic_cast<Person*>(data[i]); // короче мы приводим data[i](это указатель abstr*) в указатель Person и берем возраст (получается переуказали указатель, сложно)
            if (p) avg += p->getAge();
        }

        return avg / elem;
    }
};

class Dialog : public VectorGroup
{
    public:
    Dialog() {}

    void run()
    {
        char cmd;
        std::cout << "Commands:\n"
                  << "m(n) - create group of n abiturients\n"
                  << "+ - add one elemet\n"
                  << "- - delete last element\n"
                  << "s - print informations about elements of group (show all)\n"
                  << "z - print informations about avg age\n"
                  << "q - quit\n"
                  << ">> ";
        while(std::cin >> cmd)
        {
            if (cmd == 'q') break;

            switch (cmd)
            {
            case 'm':
            {
                int n;
                std::cin >> n;
                clear();
                for (int i = 0; i < n; i++)
                {
                    std::cout << "Elemet " << i + 1 << "\n";
                    Abstr* elem = new Abiturient();
                    elem->Input();
                    push_back(elem);
                }
                std::cout << "Created!\n";
                break;
            }
            case '+':
            {
                Abstr* elem = new Abiturient();
                elem->Input();
                push_back(elem);
                std::cout << "Added!\n";
                break;
            }
            case '-':
            {
                if (pop_back()) std::cout << "Removed last!\n";
                else std::cout << "Group is empty.\n";
                break;
            }
            case 's':
            {
                print();
                break;
            }
            case 'z':
            {
                std::cout << "Average age: " << avgAge() << "\n";
                break;
            }
            default:
                std::cout << "Uknown command.\n";
            }
            std::cout << ">>";
        }
    }
};

int main()
{
    Dialog dlg;
    dlg.run();

    //Abiturient ab1(228, "govno", 18, "vitalik");
    //ab1.Show();
}