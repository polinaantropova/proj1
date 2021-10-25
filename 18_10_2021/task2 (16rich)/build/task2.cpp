// task2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>

//вывести 16-ричное представление целого беззнакового числа
int main()
{
    
   

    /*switch
    switch (a) {
    case 10: return 'A';
    case 11: return << 'B';
    case 12: return << 'C';
    case 13: return << 'D';
    case 14: return << 'E';
    case 15: return << 'F';
    default: std::to_string(a);
    }
    //деление числа
       
    }
    */

    
        std::cout << "10rich to 16rich" << std::endl;
        int ostatok;
        unsigned int n;
        const char* N[] = { "0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F" };
        std::string str = "";
        std::cout << "input unsigned int   n=";
        std::cin >> n;
        while (n != 0) {
            ostatok = n % 16;
            n /= 16;
            str = str.append(N[ostatok]);
        }
        reverse(str.begin(), str.end());
        std::cout << str;
    
}

