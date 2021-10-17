// zifryvchisle.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

int main()
{//решение для int
    int a;
    std::cout << " Input a : ";
    std::cin >> a;
    std::cout << "\n";
	
	int sum = 0;
	int product = 1;
	while (a > 0) {
		sumOfDigits += a % 10;
		product *= a % 10;
		a /= 10;
	}
	std::cout << "sum = " << sum << ", product = " << product << "\n";
}
