// files.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>


void createSnake(int** A, int row, int column, int start1) {

    for (int i = 0; i < row; ++i) {
        if (i % 2 == 0) {
            for (int j = 0; j < column; ++j) {
                A[i][j] = start1++;
            }
        }
        if (i % 2 != 0) {
            for (int j = column - 1; j >= 0; --j) {

                A[i][j] = start1++;
            }
        }
    }
}

int** create(int row, int column) {
    int** A;
    A = new int* [row];
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
int main()
{
    int row = 4;
    int column = 4;
    int start1 = 1;
    int** A;
    A = create(row, column);
    createSnake(A, row, column, start1);
   
    
    std::fstream fs;
    fs.open("C:\\Users\\Dell\\Desktop\\file.txt",std::ios_base::in);
    if (fs.is_open()) {
        std::cout << "file opend " << std::endl;
        

        /*while (true) {
            char c = fs.get();
            if (fs.eof()) break;
            std::cout << c << std::endl;
        }*/

    
        std::fstream outFile;
        outFile.open("C:\\Users\\Dell\\Desktop\\copy.txt", std::ios_base::out| std::ios_base::trunc);
        /*if (outFile.is_open()) {
            std::cout << "file opened " << std::endl;

            int ch;
            unsigned int count = 0;
            while ((ch = fs.get()) != EOF) {
                outFile.put(ch);
                ++count;
            }
            std::cout << "Copied " << count << " bytes" << std::endl;

            outFile.close();
            fs.close();
        }*/
        if (outFile.is_open() && fs.is_open()) {
            std::cout << "files opened " << std::endl;

            while (true) {
                char c = fs.get();
                if (fs.eof()) break;
                std::cout << c << std::endl;
                outFile.put(c);
            }

            outFile << row << "\t" << column << std::endl;

            for (int i = 0; i < row; ++i) {
                for (int j = 0; j < column; ++j) {

                    outFile << A[i][j] << "\t";
                }
                outFile << std::endl;
            }
            //outFile << 4 << " good luck!" << std::endl;

            outFile.close();
            fs.close();
        }

    }
    //std::ifstream fs;
    fs.open("C:\\Users\\Dell\\Desktop\\copy.txt");
  
    int  rows=1, columns=1;
        if ( fs.is_open()) {
            std::cout << "file opened " << std::endl;
            int c = fs.get();
                char rows = c;
                c = fs.get();
                c = fs.get();
                char columns = c;
                std::cout << rows << " " << columns;
           
                int** B;
                B = create(rows, columns);

                for (int i = 0; i < rows; ++i) {
                    for (int j = 0; j < columns; ++j) {

                        c = fs.get();
                        B[i][j] = c;
                        c = fs.get();
                    }
                    
                }
                std::cout << "\n";
                for (int i = 0; i < row; ++i) {
                    for (int j = 0; j < column; ++j) {

                        std::cout << A[i][j] << "\t";
                    }
                    std::cout << std::endl;
                }
            fs.close();
        }
        
}

