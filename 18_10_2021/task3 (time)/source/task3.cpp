// task3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

int main()
{
  
        int a, b, c, d, e, f, hours = 0, min = 0, sec = 0, time1, time2, time3 = 0;

        std::cout << "input start time (h:m:s)\n";
        std::cin >> a >> b >> c;


        std::cout << "input finish time(h:m:s)\n";
        std::cin >> d >> e >> f;

        time1 = (a * 60 + b) * 60 + c;
        time2 = (d * 60 + e) * 60 + f;

        time3 = time2 - time1;

        sec = time3 % 60;
        min = (time3 / 60) % 60;
        hours = time3 / 3600;





        std::cout << "delta time : " << hours << " : " << min << " : " << sec << " \n";




    
}

