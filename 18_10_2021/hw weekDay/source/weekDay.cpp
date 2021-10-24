// weekDay.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

int main()
{
    int d = 0, m = 0, y = 0, weekday, codeyear, codemonth1, codemonth2;
    // ввод даты
        std::cout << "Input date:\n";
        std::cout << "DAY:";
        std::cin >> d;
        std::cout << "MONTH:";
        std::cin >> m; 
        std::cout << "YEAR:";
        std::cin >> y;

    //формула
       
        codemonth1 = (14 - m) / 12;
        codemonth2 = m + 12 * codemonth1 - 2;
        codeyear = y - codemonth1;
        weekday = d + codeyear + codeyear / 4 - codeyear / 100 + codeyear / 400 + (31 * codemonth2) / 12;
    //отображение дня недели
         
            switch (weekday%7) {
            case 1: std::cout << "monday"; break;
            case 2: std::cout << "tuesday"; break;
            case 3: std::cout << "wednesday"; break;
            case 4: std::cout << "thursday"; break;
            case 5: std::cout << "friday"; break;
            case 6: std::cout << "saturday"; break;
            case 0: std::cout << "sunday";
            }
 
}


