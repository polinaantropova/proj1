// matrix.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "matrix1.h"
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

int** sumMatrix(int** A, int** B, int row, int column) {
    int** C;
    C = createArray(row, column);
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            C[i][j]=A[i][j] + B[i][j];
        }
    }
    return C;
}

//10.Создание матрицы как результата умножения двух числовых матриц.

int** multMatrix(int** A,  int row1, int column1, int** B, int row2, int column2) {

    if (column1 != row2)
    {
        std::cout << "Can't multiplication!!!";
        
        //return 0;
    }
    else {
        int** C;
        
        C = new int* [row1];
        for (int i = 0; i < row1; i++)
        {
            C[i] = new int[column2];
            for (int j = 0; j < column2; j++)
            {
                C[i][j] = 0;
                for (int k = 0; k < column1; k++)
                    C[i][j] += A[i][k] * B[k][j];
            }
        }
        return C;
    }
}

//11. Обмен местами двух строк / столбцов 2 - массива.

int** swapRows(int** A, int row, int column, int rowFirst , int rowSec) { 
    int tmp = 0;
    for (int i = 0; i < column; ++i) {
        tmp = A[rowSec - 1][i];
        A[rowSec - 1][i] = A[rowFirst - 1][i];
        A[rowFirst - 1][i] = tmp;
    }
    return A;
}
void swapColumns(int** A, int row, int column, int colFirst, int colSec) { 
    int tmp = 0;
    for (int i = 0; i < row; ++i) {
        tmp = A[i][colFirst - 1];
        A[i][colFirst - 1] = A[i][colSec - 1];
        A[i][colSec - 1] = tmp;
    }
}


//12. Получение доступа по ссылке к элементу 2 - массива с заданными значениями строки и столбца.
 int& getElement(int** A, int yourRow, int yourColumn) {
return A[yourRow - 1][yourColumn - 1];
}
//13. Реализовать алгоритм Гаусса приведения матрицы к диагональному виду
//14. Реализовать вычисление определителя квадратной матрицы


int main()
{
    int** A;
    int** B;
    int** D;
    int** C;
    int** V;
    int row, column, yr_const=0, number=1;
    int row1, column1, row2, column2;
    int rowFirst, colFirst, rowSec, colSec;
    int yourRow, yourColumn;
    std::cout << "razmer row and column:\n";
    std::cin >> row >> column;


    V = createArray(row, column); 
    std::cout << "----------------------4.E matrix -------------------------------" << std::endl;
    D=eMatrix(V, row, column);
    printArray(D, row, column);
    std::cout << std::endl;

    std::cout << "----------------------3.const array---------------------------------" << std::endl;
    std::cout << "input your const :\n";
    std::cin >> yr_const;
    initArrayOnlyConst(V, row, column, yr_const);
    printArray(V, row, column);


    std::cout << "----------------------5.transpon array------------------------------" << std::endl;
    fillarrRandom(V, row, column);
    std::cout << "BEFORE:" << std::endl;
    printArray(V, row, column);
    std::cout << std::endl;
    V=transMatrix(V, row, column);
    std::cout << "AFTER:" << std::endl;
    printArray(V, row, column);
    std::cout << std::endl;

    std::cout << "---------------------6. return 180* array---------------------------" << std::endl;
    D = return180Array(V, row, column);
    printArray(D, row, column);

    std::cout << "-----------------------7.product matrix and number-----------------------------" << std::endl;
    V = productMatrix(V, row, column, number=2);
    printArray(V, row, column);

    std::cout << "-----------------------8.create product matrix and number =4----------------------" << std::endl;
    B = CreateProductMatrix(V, row, column, 4);
    printArray(B, row, column);

    std::cout << "---------------------------------------------------" << std::endl;
    A = createArray(row, column);
    fillarrRandom(A, row, column);
    printArray(A, row, column);
    

    std::cout << "--------------------9.sum Matrix-------------------------------" << std::endl;
    fillarrRandom(A, row, column);
    printArray(A, row, column);
    std::cout << std::endl;
    fillarrRandom(B, row, column);
    printArray(B, row, column);
    std::cout << std::endl;
    std::cout << "Matrix A + B" << std::endl;
    C=sumMatrix(A, B, row, column);
    printArray(C, row, column);
    std::cout << std::endl;

    std::cout << "---------------------10.product matrix------------------------------" << std::endl;
    std::cout << "razmer row1 and column1:\n";
    std::cin >> row1 >> column1; 
    D = createArray(row1, column1);
    fillarrRandom(D, row1, column1);
    printArray(D, row1, column1);

    std::cout << "razmer row2 and column2:\n";
    std::cin >> row2 >> column2;
    fillarrRandom(B, row2, column2);
    printArray(B, row2, column2);
    std::cout << std::endl;
    std::cout << "Matrix A * B" << std::endl;
    C = multMatrix(D, row1, column1, B, row2, column2);
    printArray(C, row1, column2);
    std::cout << "---------------------11.swap rows or columns------------------------------" << std::endl;
    std::cout <<  std::endl; 
    fillarrRandom(A, row, column);
    printArray(A, row, column);
    std::cout << std::endl;

    std::cout << "swap rowFirst and rowSec:\n";
    std::cin >> rowFirst >> rowSec;

    swapRows(A, row, column, rowFirst, rowSec);
    printArray(A, row, column);
    std::cout << std::endl;

    std::cout << "swap colFirst and colSec:\n";
    std::cin >> colFirst >> colSec;

    swapColumns(A, row, column, colFirst, colSec);
    printArray(A, row, column);
    std::cout << std::endl;

    std::cout << "---------------------12. get element-----------------------------" << std::endl;
    std::cout << "input index of element:\n";
    std::cin >> yourRow >> yourColumn;
    std::cout << getElement(A, yourRow, yourColumn);
    std::cout << std::endl;

    deleteArray(C, row1, column2);
    deleteArray(V, row, column);
    deleteArray(B, row, column);
    deleteArray(A, row, column);

    
}