//повторы в последовательности из английских строчных и заглавных букв, знаков препинания
//цифры для обозначения повтора элементов
//на входе файл
//на выходе закодированный файл

/*вариант 1 : создать переменную в хоторой храним символ
вариант 2: обойтись без переменной с запоминанием символа*/

#include <iostream>
#include <fstream>


int main()
{
    size_t repeatcounter=0;
    size_t nonrepeatcounter = 0;
    char curSymb = '0';
    
    std::fstream file;
    file.open("C:\\Users\\Dell\\source\\repos\\2022_04_04\\in.txt");
    if (!file.is_open()) {
        std::cout << "file 1 can't be opened " << std::endl;
    }
    if (file.is_open()) {
        std::ofstream outfile;
        outfile.open("C:\\Users\\Dell\\source\\repos\\2022_04_04\\out.txt");
        if (!outfile.is_open()) {
            std::cout << "file 2 can't be opened " << std::endl;
        }
        if (outfile.is_open()) {
            char buffer[128];
            char x;
            file >> x;
            curSymb = x;
            while (!file.eof()) {
                if (curSymb == x) {
                    ++repeatcounter;
                    x=file.get();
                }
                else /*{
                    //записать в выходной файл counter curSymb;
                    if (repeatcounter != 1) {
                        outfile << repeatcounter;
                    }
                    outfile<<curSymb;
                    repeatcounter = 1;
                    curSymb = x;
                    x = file.get();
                }*/ {
                //записать в выходной файл counter curSymb;
                    if (repeatcounter != 1) {
                        outfile << repeatcounter;
                    }
                    outfile << curSymb;
                    repeatcounter = 1;
                    curSymb = x;
                    x = file.get();
                }
            }
            outfile << repeatcounter;
            outfile << curSymb;
            outfile << '\0';
        }
        outfile.close();
    }
    file.close();
}

