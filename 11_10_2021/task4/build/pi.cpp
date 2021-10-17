// pi.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

int main()
{
    
    int n;
    double pi = 0.0;
    double PI = 0.0;
    std::cout << " Input accuracy = ";
    std::cin >> n; 
    for (int i = 0; i < n; ++i) {
        pi = 1.0 / (2 * i + 1) - 1.0 / (2 * i + 3);
        PI += pi;
    }
    std::cout << "pi= "<<4*PI;
  
}

