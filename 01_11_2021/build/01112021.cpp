// 01112021.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
void printArray(int a[][4], const int row, const int column) {
    std::cout << "array\n";
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
            std::cout << a[i][j] << "\t";
        std::cout << std::endl;
    }
}

int main()
{
    int r=-1, c=-1;
    const int row = 4, column = 4; //размеры массива
    int a[row][column];
    srand(time(0));
    for (int i = 0; i < row; i++)   //строки массива
        for (int j = 0; j < column; j++)   //столбцы массива
            a[i][j] = 1 + rand() % 100;
    printArray(a, row, column);   //печатаем полученный массив
    

    for (int i = 1; i < row; ++i)
        a[i][0] += a[i - 1][0];

    for (int j = 1; j < column; ++j)
        a[0][j] += a[0][j - 1];

    for (int i = 1; i < row; i++)   //строки массива
        for (int j = 1; j < column; ++j)   //столбцы массива
            a[i][j] += a[i - 1][j] + a[i][j - 1];
    printArray(a, row, column);
    /*
    int d = 0;
    int t = a[3][2];
    std::cout << "find " << t << std::endl;
    
    for (int i = 0; i < row; )   //строки массива
        for (int j = i; j < column; ) { //столбцы массива
            
                if (a[i][j] < t) { ++i;
                
            
                }
                else if (a[i][j] == t) { std::cout << i << " " << j << "  diag"; }
                else if (a[i][j] > t) {
                    int k = row - i;
                    for (int i = k; i < row; i++) //нижний левый блок  
                        for (int j = 0; j < column - i; ++j) {
                            if (a[i][j] == t) {
                                r = i;
                                c = j;
                                std::cout << "  left";
                                d = 1;
                                
                            }
                            //if (d == 1) { break; }
                        }
                    if (d != 1) {
                         //верхний правый блок  
                        for (int i = 0; i < row; ++i) {
                            for (int j = column - 1; j < column; ++j)
                                if (a[i][j] == t) {
                                r = i;
                                c = j;
                                std::cout << "right";
                                    d = 1;
                                    if (d == 1) { break; }
                                }
                           
                        }
                    }
                    
                }
                
            
        }
    std::cout << r << " " << c << "  it is itog";*/
}

