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
//"перевод" символов в двоичный код
std::string binar(int c) {
    int lin, counter = 0;
    std::string itog;
    char alph[] = { '0', '1' };
    while (c > 0) {
        lin = c % 2;
        for (int i = 0; i <= 1; ++i) {
            if (lin == i) {
                itog += alph[i];
                break;
            }
        }
        counter += 1;
        c /= 2;
    }

    for (int i = 0; i < counter / 2; ++i) {
        std::swap(itog[i], itog[counter - 1 - i]);
    }
    unsigned int len = itog.length();
    if (len < 8) {
        for (int i = 0; i < 8 - len; ++i) {
            itog = '0' + itog;
        }
    }
    return itog;
}

void BinImage(int size) {
    int count = 0;
    std::ifstream inFile("C:\\Users\\Dell\\Desktop\\copy.txt", std::ios_base::binary);
    if (inFile) {
        std::cout << "file 1 opend!!! " << std::endl;

        std::ofstream image("C:\\Users\\Dell\\Desktop\\image.txt" , std::ios_base::out);
        if (image.is_open()) {
            std::cout << "file 2 opend!!! " << std::endl;
        }
        while (true) {
            char c = inFile.get();
            if (inFile.eof()) break;
           
            

            int razmer = (int)c;
            std::string bn = binar(razmer);
            unsigned long long len = bn.length();
            for (int i = 0; i < len; ++i) {
                if (bn[i] == '0') {
                    if (count == size) {
                        std::cout << std::endl;
                        image << std::endl;
                        count = 0;
                    }
                    std::cout << " ";
                    image << ' ';
                }
                if (bn[i] == '1') {
                    if (count == size) {
                        std::cout << std::endl;
                        image << std::endl;
                        count = 0;
                    }
                    std::cout << "*";
                    image << '*';
                }
                ++count;
                
            }
            image.close();
        }

        

    }

    inFile.close();
    
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
        
        

        BinImage(15);
}

