// pointonline.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath>

int main()
{
    double x_a, y_a, x_b, y_b;
    x_a = 5;
    y_a = 10;
    x_b = 4;
    y_b = 7;
    double x_c, y_c;
    std::cout << " Input coordinates C \n";
    std::cout << " Input coordinates x_c = ";
    std::cin >> x_c;
    std::cout << " Input coordinates y_c = ";
    std::cin >> y_c;
    std::cout << "";


    double ac = sqrt((x_c - x_a) * (x_c - x_a)+ (y_c - y_a) * (y_c - y_a));
    double bc = sqrt((x_c - x_b) * (x_c - x_b)+ (y_c - y_b) * (y_c - y_b));
    double eps = 1.0e-10;
    if (abs(ac + bc - 10.0) < eps) {
        std::cout << "c belong";
    }
    else { std::cout << "c not belong"; }
}

 