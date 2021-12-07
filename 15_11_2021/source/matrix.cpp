// matrix.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
//#include <matrix1.h>
//print array
void printArray(int** A, int row, int column) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {

            std::cout << A[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

void fillarrRandom(int** A, int row, int column) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            A[i][j] = rand() % 10;
        }
    }
}

//1.Создание 2-массива с заданными размерами.
int** createArray(int row, int column) {

    int** A;

    A = new int* [row];
    for (int i = 0; i < row; ++i) {
        A[i] = new int[column];
    }
    return A;
}

//2.Для независимого 2 - массива реализовать освобождение ресурсов, занимаемых данным массивом
void deleteArray(int** A, int row, int column) {
    for (int i = 0; i < row; i++)
    {
        delete[] A[i];
    }
    delete[] A;
}
//3.Инициализация 2 - массива - все элементы одинаковы и равны заданному значению.
void initArrayOnlyConst(int** A, int row, int column, int yr_const) {
    std::cout << "input your const :\n";
    std::cin >> yr_const;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            A[i][j] = yr_const;
        }
    }
}

/*bool test_const() {

}*/
//4.Инициализация 2 - массива с 1 на главной диагонали и 0 в остальных элементах.
int** eMatrix(int** A, int row, int column) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            if (i == j) { A[i][i] = 1; }
            else
                A[i][j] = 0;
        }
    }
    return A;
}
//5.Создание 2 - массива, являющегося транспонированным исходным.
int** transMatrix(int** A, int row, int column) {
    int **B = createArray(row, column);
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            B[i][j] = A[j][i];
        }
    }
    return B;

}

//6.Модификация исходного 2 - массива в виде поворота на 180 градусов.

int** return180Array(int** A, int row, int column) {
    int** B;
    B = new int* [row];
    for (int i = 0; i < row; ++i) {
        B[i] = new int[column];
    }
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            B[i][j] = A[row - i - 1][column - j - 1];
        }
    }
    return B;

}

//7.Умножение матрицы на число.
int** productMatrix(int** A, int row, int column, int number) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            A[i][j] *= number;
        }
    }
    return A;
}
//8.Создание матрицы, как результата умножения матрицы на число.

int** CreateProductMatrix(int** A, int row, int column, int number) {
    int** B;
    B = createArray(row, column);

    
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            B[i][j] = A[i][j] * number;
        }
    }
    return B;
}

//9.Создание матрицы как результата сложения двух числовых матриц.
void sumMatrix(int** A, int** B, int row, int column) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            A[i][j] += B[i][j];
        }
    }
}
//10.Создание матрицы как результата умножения двух числовых матриц.
//11.Обмен местами двух строк / столбцов 2 - массива.
//12.Получение доступа по ссылке к элементу 2 - массива с заданными значениями строки и столбца.



int main()
{
    int** A;
    int** B;
    int** D;
    int row, column, yr_const=0, number=1;
    std::cout << "razmer row and column:\n";
    std::cin >> row >> column;

    A = createArray(row, column);   
    D=eMatrix(A, row, column);
    printArray(D, row, column);
    std::cout << std::endl;
    
    initArrayOnlyConst(A, row, column, yr_const);
    printArray(A, row, column);
    std::cout << "---------------------------------------------------" << std::endl;
    B=CreateProductMatrix( A,row, column, 4);
    
    printArray(B, row, column);
    std::cout << "---------------------------------------------------" << std::endl;

    A = createArray(row, column);

    fillarrRandom(A, row, column);
    printArray(A, row, column);
    std::cout <<"---------------------------------------------------" << std::endl;

    D= return180Array(A, row, column);
    printArray(D, row, column);
    std::cout << "---------------------------------------------------" << std::endl;
  
    deleteArray(B, row, column);
    deleteArray(A, row, column);

}