#include <iostream>

int main()
{
	float n;
	std::cin >> n;
	if (n < 5)
	{
		std:: cout << n * 3;
	}
	else if (n > 7)
	{
		std:: cout << n + 3;
	}
	else
	{
		std:: cout << n / 10;
	}
}