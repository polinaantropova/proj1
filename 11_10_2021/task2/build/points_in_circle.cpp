// points_in_circle.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

int main()
{
    //int c_x = 0, c_y = 0;
    double R;
    std::cout << " Input radius R = ";
    std::cin >> R;
    std::cout << "\n";
    int k = 0;
    for (int x = -R; x <= R; ++x) {
        for (int y = -R; y <= R; ++y) {
            if (x * x + y * y <= R * R) { ++k; };
        }
    }
    
    std::cout << "Points =" << k;

}

