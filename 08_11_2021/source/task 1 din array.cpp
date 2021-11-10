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

void initialize(int** A, int row, int column, int start1) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            
            A[i][j] = start1;
            ++start1;
            std::cout << A[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}
// квадратная спираль
void createSpiral (int** A, int row, int column, int start1) {
    
        for (int i = 0; i < column/2 +1; ++i) {

        for (int j = i; j < column-i; ++j) {
            
            A[i][j] = start1++;
        }
       
        for (int k = i+1; k < column - i; ++k) {

            A[k][column -1 -i] = start1++;
        }

        for (int j = column -i-2; j >=i; --j) {

            A[column-i-1][j] = start1++;
        }

        for (int k = column -2 -i; k > i; --k) {

            A[k][i] = start1++;
        }    
    }
        
}
// змейка
void createSnake(int** A, int row, int column, int start1) {

    for (int i = 0; i < row; ++i) {
        if (i % 2 == 0) {
            for (int j =0; j < column; ++j) {
                A[i][j] = start1++;
            }
        }
        if (i % 2 != 0) {
            for (int j = column-1; j >= 0; --j) {

                A[i][j] = start1++;
            }
        }
  
    }

}


void printArray(int** A, int row, int column) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            
            std::cout << A[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

int main()
{/*
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
    std::cout << std::endl;*/

    //двумерный динамический массив
    int row, column, start1;
    std::cout << "razmer row and column:\n";
    std::cin >> row >> column;
    std::cout << "start number : \n";
    std::cin >> start1;
    

    int** A;
    A = create(row, column); 
    std::cout << "arrage in order" << std::endl;
    initialize(A, row, column, start1); 
    std::cout << std::endl;
    std::cout << "arrage-spiral" << std::endl;
    createSpiral(A, row, column, start1);
    printArray(A, row, column);
    std::cout << std::endl;
    std::cout << "arrage-snake" << std::endl;
    createSnake(A, row, column, start1);
    printArray(A, row, column);
    std::cout << std::endl;
    for (int i = 0; i < row; i++)
    {
        delete[] A[i];
    }
    delete[] A;
}

