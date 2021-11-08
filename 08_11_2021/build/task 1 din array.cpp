// task 1 din array.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

int** create(int row, int column) {
    int** A;
    A = new int *[row];
    for (int i = 0; i < row; ++i) {
        A[i] = new int[column];
    }
    return A;
}

void initialize (int **A, int row, int column, int start1) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            A[i][j] = start1 + i + j;
            std::cout << A[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

void initialize2(int** A, int row, int column, int start2) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            int k;
            A[i][j] = start2;
            ++start2;
            std::cout << A[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

int main()
{
    //одномерный динамический массив
    int razmer, start;
    std::cout << "razmer :\n";
    std::cin >> razmer;
    std::cout << "start number : \n";
    std::cin >> start;
    new int;
    int* a = new int[razmer];
    for (int i = 0; i < razmer; i++) {
        a[i] = start + i;
    }

    for (int i = 0; i < razmer; i++)
        std::cout << a[i] << " ";

    delete[] a;
    std::cout << std::endl;

    //двумерный динамический массив
    int row, column, start1;
    std::cout << "razmer row and column:\n";
    std::cin >> row >> column;
    std::cout << "start number : \n";
    std::cin >> start1;
    

    int** A;
    A = create(row, column); 
    initialize(A, row, column, start1); 
    std::cout << std::endl;
    initialize2(A, row, column,start1);

    for (int i = 0; i < row; i++)
    {
        delete[] A[i];
    }
    delete[] A;
}

