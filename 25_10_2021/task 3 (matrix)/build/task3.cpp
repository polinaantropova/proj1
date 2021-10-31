// task3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
void printArray(int a[][4], const int row, const int column) {
    std::cout << "array\n";
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
            std::cout << a[i][j]<<"\t";
        std::cout << std::endl;
    }
}
//массив, в котором поменяли строки
void ArrayswapRow(int a[][4], const int row, const int column) {
    
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < column/2; ++j) {
            int tmp = a[i][j];
            a[i][j] = a[i][column -1 - j];
            a[i][column-1 - j] = tmp;
        }
       
    }
}
void ArrayswapCol(int a[][4], const int row, const int column) {
    int j = 0;
    for (int i = 0; i < row / 2; ++i)
    {
        
        for (int j = 0; j < column; ++j) {
            int tmp = a[i][j];
            a[i][j] = a[row - 1 - i][j];
            a[row - 1 - i][j] = tmp;
        }
    }
    
}
void transponirovanie(int a[][4], const int row, const int column) {
    
    
       
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < i; j++) {
            int tmp = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = tmp;
        }

    }

    }

int main()
{  
    int i;
   const int row = 4, column = 4; //размеры массива
        int a[row][column];       
        srand(time(0));
        for (int i = 0; i < row; i++)   //строки массива
            for (int j = 0; j < column; j++)   //столбцы массива
                a[i][j] = 1 + rand() % 100;  
        printArray(a, row, column);   //печатаем полученный массив
        ArrayswapRow(a, row, column);  //меняем строки
        std::cout<< "\n" << "after swap lines :" << "\n";
        printArray(a, row, column);  //выводим измененный массив
        ArrayswapCol(a, row, column);  //меняем столбцы
        std::cout << "\n" << "after swap columns :" << "\n";
        printArray(a, row, column);  //выводим измененный массив
        transponirovanie(a, row, column);//транспонирование
        std::cout << "\n" << "transponirovanie :" << "\n";
        printArray(a, row, column);  //выводим измененный массив
        
}

