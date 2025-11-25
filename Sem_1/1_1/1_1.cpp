#include <iostream>

int main()
{
	int a, b, c;
	std::cin >> a >> b >> c;
	if (a >= b & a >= c)
	{
		std::cout << a;
	}
	else if (b >= c & b >= a)
	{
		std::cout << b;
	}
	else
	{
		std::cout << c;
	}
	return 0;
}
