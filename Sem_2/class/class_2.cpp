#include <iostream>

class Road
{
    std::string point_a;
    std::string point_b;
    float time;

    public:

    Road() : point_a(""), point_b(""), time(0) {}
    Road(std::string a, std::string b, float t) : point_a(a), point_b(b), time(t) {}
    Road(const Road& r)
    {
        point_a = r.point_a;
        point_b = r.point_b;
        time = r.time;
    }

    ~Road() {}

    void print()
    {
        std::cout << "Начало движения: " << point_a
                  << "\nКонец движения: " << point_b
                  << "\nЗанимаемое время: " << time << "\n";
    }
};

int main()
{
    Road m228;
    Road m1337("Москва", "Пермь", 17);
    Road m6767(m1337);

    m228.print();
    m1337.print();
    m6767.print();
}