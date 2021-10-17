// sin.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

#include <cmath>
#define PI 3.14159265
//sum of sin(x)+...+sin(...sin(sin(x)))
int main()
{
	double x;
	std::cout << " Input parametr x (deg)= ";
	std::cin >> x;
	int accuracy;
	std::cout << " Input accuracy = ";
	std::cin >> accuracy;
	double  S=0.0;
	

	for (int i = 1; i <= accuracy; ++i) {
	x = sin(x*PI /180);
	S += x;
	}
	std::cout << " S=" <<S;
}


