// file.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>

//поиск элемента в бинарном массиве
void findElement() {
    std::fstream fsa;
    fsa.open("C:\\Users\\Dell\\source\\repos\\file\\binArray.txt", std::ios_base::in | std::ios_base::binary);
    if (!fsa.is_open()) {
        std::cout << "file can't be opened " << std::endl;
    }
    if (fsa.is_open()) {
        std::cout << "file opened " << std::endl;
        int c = fsa.get();
        const int row = c;
        c = fsa.get();
        c = fsa.get();
        const int column = c;
        c = fsa.get();

        int total = row * column;
        int ind_row, ind_column;
        std::cout << "input element's index : \n";
        std::cin >> ind_row >> ind_column;

        int ind = ind_row * column + ind_column;

        fsa.seekg(ind, std::ios::cur);
        
        char el;
        fsa.read(&el, sizeof(char));

        std::cout << el << std::endl;
    }
        fsa.close();
        std::cout << "search finished! check your file!\n";
    
}

//копирование файла через .get() 
void copyFile() {
    std::fstream fs;
    fs.open("C:\\Users\\Dell\\Desktop\\file.txt", std::ios_base::in);
    if (!fs.is_open()) {
        std::cout << "file can't be opened " << std::endl;
    }
    if (fs.is_open()) {
        std::cout << "file opened " << std::endl;

        std::fstream outFile;
        outFile.open("C:\\Users\\Dell\\Desktop\\outFile.txt", std::ios_base::out | std::ios_base::trunc);
        if (outFile.is_open()) {
            std::cout << "file opened " << std::endl;

            while (true) {
                char c = fs.get();
                if (fs.eof()) break;
                //std::cout << c << std::endl;
                outFile.put(c);
            }
            outFile.close();
        }
    }
    fs.close();
    std::cout << "copy finished! check your file!\n";
}

//вывод каждого 4го байта в консоль /get() & seekg()
void output4bytes() {
    std::fstream fs;
    fs.open("C:\\Users\\Dell\\Desktop\\file.txt", std::ios_base::in | std::ios_base::binary);
    if (!fs.is_open()) {
        std::cout << "file can't be opened " << std::endl;
    }
    if (fs.is_open()) {
        std::cout << "file opened " << std::endl;

        char c;

        while (!fs.eof()) {
            fs.seekg(3, std::ios_base::cur);
            c = fs.get();
            std::cout << c;
            if (fs.tellg() == EOF) {
                break;
            }
        }

        fs.close();
    }
    std::cout << "\nfinished!\n";
}


//вывод каждого 4го байта в консоль read()
void outever4bytes() {
    std::fstream fs;
    fs.open("C:\\Users\\Dell\\Desktop\\file.txt", std::ios_base::in | std::ios_base::binary);
    if (!fs.is_open()) {
        std::cout << "file can't be opened " << std::endl;
    }
    if (fs.is_open()) {
        std::cout << "file opened " << std::endl;
        //находим кол-во символов в файле
        fs.seekg(0, std::ios_base::end);
        unsigned int sizeoffile = fs.tellg();
        
        for (size_t i = 3; i < sizeoffile; i += 4)
        {
            int buffer=0;
            fs.seekg(i);
            fs.read((char*)&buffer, sizeof(char));
            //без приведения типа (char) выводит коды символов
            std::cout<< (char)buffer;
        }

        fs.close();
    }
    std::cout << "\nfinished!\n";
}


int main(int argc, char* argv[]) {
    

    std::cout << " argc= " << argc << std::endl;
    std::cout << argv[0] << std::endl;
    for (size_t k = 1; k < argc; ++k) {
        std::cout << argv[k] << std::endl;
    }
    //копирование файла с аргументами в main
    std::fstream fs;
    fs.open(argv[1], std::ios_base::in | std::ios_base::binary);
    for (size_t k = 1; k < argc; ++k) {
        std::cout << argv[k] << std::endl;
    }
    if (!fs.is_open()) {
        std::cout << "file can't be opened " << std::endl;
    }
    if (fs.is_open()) {
        std::cout << "file opened " << std::endl;

        std::fstream outFile;
        outFile.open(argv[2], std::ios_base::out | std::ios_base::trunc);
        if (!outFile.is_open()) {
            std::cout << "file can't be opened " << std::endl;
        }
        if (outFile.is_open()) {
            fs.seekg(18);
            int width = 0, height = 0;
            fs.read((char*)&width, sizeof(int));
            fs.read((char*)&height, sizeof(int));
            std::cout << "wight  " << width << std::endl;

            std::cout << "height " << height << std::endl;
            outFile << height << std::endl;
            outFile << width << std::endl;

            

    }
        outFile.close();
    }
    fs.close();


    copyFile();
    output4bytes();

    outever4bytes();
    findElement();
    

    }


