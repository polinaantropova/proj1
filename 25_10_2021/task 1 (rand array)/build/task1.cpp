// task1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>


int main()
{
    int a[10];
    int i, min, sum=0, k=-1;
    double average;
    min = 1000;

    srand(time(0)); 
    

   //случайный массив из 10 элементов от 1 до 900
    for (i = 0; i < 10; ++i) {
        a[i] = 1 + rand() % 900;
        if (a[i] < min)
        {
            min = a[i];
            k = i+1; // запоминаем номер минимального элемента
        }
        sum += a[i];
    }
    average = (double)sum / 10;
    for (i = 0; i < 10; ++i)
        std::cout << a[i] << " ";


    // расположение элементов массива в обратном порядке
    int n = 10, h = 0;
    for (i = 0; i < n / 2; ++i)

    {
        h = a[i];
        a[i] = a[n - 1 - i];
        a[n - 1 - i] = h;


    }

    std::cout << "\n" << "min = " << min << " and his number = " << k << "\n";
    std::cout <<  "average = " << average << " and sum = " << sum;
    std::cout <<"\n" << "return array : " << "\n";

    for (i = 0; i < 10; ++i)
        std::cout << a[i] << " ";

}


