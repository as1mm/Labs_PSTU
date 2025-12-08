#include <iostream>
#include <cmath>
int main()
{
    int n;
    float sum, x, fact = 1;
    std::cin >> n >> x;
    sum = 1 + x;
    for (int i = 2; i <= n; i++)
	{
		fact *= i;
		sum += pow(x, i) / fact;
	}
    std::cout << "sum = " << sum;
    return 0;
}