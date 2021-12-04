// file.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>



//копирование файла
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
//копирование файла с аргументами в main
int main(int argc, char* argv[]) {
    //copyFile();

    std::cout << " argc= " << argc << std::endl;
    std::cout << argv[0] << std::endl;
    for (size_t k = 1; k < argc; ++k) {
        std::cout << argv[k] << std::endl;
    }


    std::fstream fs;
    //fs.open("C:\\Users\\Dell\\Desktop\\file.txt", std::ios_base::in);
    fs.open(argv[1], std::ios_base::in);
    if (!fs.is_open()) {
        std::cout << "file can't be opened " << std::endl;
    }
    if (fs.is_open()) {
        std::cout << "file opened " << std::endl;

        std::fstream outFile;
        //outFile.open("C:\\Users\\Dell\\Desktop\\outFile.txt", std::ios_base::out | std::ios_base::trunc);
        outFile.open(argv[2], std::ios_base::out | std::ios_base::trunc);
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


