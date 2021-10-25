// task2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include <iostream>



int main()
{
    
    int i;

    srand(time(0));
    int size = 0;
    std::cout << "input number symbols in number : ";
    std::cin >> size;
    


    //массив с элементами-цифрами 16ричной сс
    char c[16] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };
    // for (i = 0; i < 16; ++i)
         //std::cout << c[i] << " ";

    //выводим 16ричное число заданного размера
    char* l = new char[size];
    for (int i = 0; i < size; ++i) {
        l[i] = c[rand() % 16];
        std::cout << l[i];
    }
    std::cout << "\n";
    delete[] l;
}

