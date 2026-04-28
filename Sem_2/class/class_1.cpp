#include <iostream>

class Product
{
    int price;
    int count;

    public:
    Product(int a, int b) : price(a), count(b) {}

    ~Product() {};

    void cost()
    {
        std::cout << "Стоимость = " << price * count << "\n";
    }
};

int main()
{
    Product game(99, 100);

    game.cost();
}