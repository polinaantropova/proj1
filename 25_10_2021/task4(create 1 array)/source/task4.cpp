// из двух массивов сделать один, так чтобы пары были упорядочены по возрастанию
//

#include <iostream>

int main()
{
    int a[5], b[5], c[10];
    //случайный массив из 10 элементов от 1 до 900
    for (int i = 0; i < 5; ++i) {
        a[i] = 1 + rand() % 90;
        std::cout << a[i] << " ";   
    }
    std::cout << std::endl;
    for (int i = 0; i < 5; ++i) {
        b[i] = 1 + rand() % 90;
        std::cout << b[i] << " ";
        }
    std::cout << std::endl;
    for (int i = 0; i < 10; ++i) {
        c[i] = 0;

    }
    for (int i = 0, j=0; i < 5,j < 10; ++i,j += 2) {
        
            if (a[i] < b[i]) {
                c[j] = a[i];
                c[j + 1] = b[i];
            }
            else {
                c[j] = b[i];
                c[j + 1] = a[i];
            }
        }    
    for (int i = 0; i < 10; ++i) {
        std::cout << c[i] << " ";

    }

}

