// gusi_kroliki.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

int main()
{
    int i;
    std::cout << " Input half count paws = ";
    std::cin >> i;
    i = i * 2;
    std::cout << "total paws = " << i << "\n";
    int g = 0;
    g = (i % 4) / 2; // остаток лап, при макс. кол-ве кроликов
    
    for (int j = i / 4; j >= 0; --j) {
        std::cout << j << " rabbits, " << g << " gusi" << "\n";
        g += 2; // -1 кролик, +2 гуся
    }
}



