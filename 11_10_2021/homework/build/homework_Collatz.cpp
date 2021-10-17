// homework_Collatz.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

int main()
{
    
        int n, k=0;
        std::cout << "Input n= ";
        std::cin >> n;
        std::cout << n ;
        while (n != 1) {
            if (n % 2 == 0) {
                n /= 2;
                ++k;
                std::cout << ",   " << n;
            }
            else {
                n = 3 * n + 1;
                ++k;
                std::cout << ",   " << n;
            }
        }
        std::cout << " ...\n";
        std::cout << "total " << k << " steps";
}

