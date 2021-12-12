#include <iostream>
#include <fstream>


int main(int argc, char* argv[]) {
    std::cout << " argc="<< argc << std::endl;
    std::cout << argv[0] << std::endl;
    for (size_t k = 1; k < argc; ++k) {
        std::cout << argv[k] << std::endl;
    }
    int ch;
    int count = 0;
    std::fstream fs;
    //открываем первый файл
    fs.open(argv[1], std::ios_base::in | std::ios_base::binary);
    
    if (!fs.is_open()) {
        std::cout << "file can't be opened " << std::endl;
    }
    //меню выбора
    std::cout << "\nchoose the task:\n";
   
    std::cout << "1. change width and height \n" << "2.image 32*32 to console\n";
    std::cout << "3.image 32*33 to console\n" << "4.colour image\n" << "5.changed colour image\n" << "6.width and height of image #1\n" << "7.width and height of image #2\n";
    int choice;
    std::cout << "\nyour choice :" << std::endl;
    std::cin >> choice;
    std::cout << std::endl;
    switch (choice) {
    case 1:
        std::cout << "change width and height \n" << std::endl;
        if (fs.is_open()) {
            std::cout << "file opened " << std::endl;

            //считываем информацию о ширине и высоте изображения
            fs.seekg(18);
            
            char* width = new char[4];
            char* height = new char[4];
            
            fs.read(width, sizeof(int));
            fs.read(height, sizeof(int));
            
            std::cout << "width  " << (int) width << std::endl;
            std::cout << "height " << (int) height << std::endl;
            fs.close();

            std::ofstream ofs;
            ofs.open(argv[2], std::ios_base::binary | std::ios_base::in | std::ios_base::out);
            if (!ofs.is_open()) {
                std::cout << "can't open file";
            }
            else {
                ofs.seekp(18, std::ios::beg);
                ofs.write(height, sizeof(int));
                ofs.seekp(22, std::ios::beg);
                ofs.write(width, sizeof(int));
                ofs.close();
            }
            
            delete[] height;
            delete[] width;
        }
        
        break;

    case 2:
        std::cout << "image 32*32 to console\n" << std::endl;
        if (fs.is_open()) {
            std::cout << "file opened " << std::endl;

            unsigned int bpp = 0;
            fs.seekg(28);
            fs.read((char*)&bpp, sizeof(int));
            std::cout << "BPP " << bpp << std::endl;

            //считываем информацию о ширине и высоте изображения
            fs.seekg(18);
            unsigned int width = 0, height = 0;
            fs.read((char*)&width, sizeof(int));
            fs.read((char*)&height, sizeof(int));
            std::cout << "width  " << width << std::endl;
            std::cout << "height " << height << std::endl;

            int bitoffBits = 0;//bitoffBits
            fs.seekg(10);
            fs.read((char*)&bitoffBits, sizeof(int));
            std::cout << "Read bitoffBits\t" << bitoffBits << std::endl;
            fs.seekg(bitoffBits);

            //выводим bmp-изображение в консоль (32*32)
            for (size_t rows = 0; rows < height; ++rows) {
                for (size_t cols = 0; cols < width; cols += 8) {
                    unsigned char bTmp = 0;
                    fs.read((char*)&bTmp, 1);
                    if (fs.eof()) { break; }

                    for (unsigned char mask = 0x80; mask != 0; mask >>= 1) {
                        std::cout << (((bTmp & mask) == 0) ? '1' : '0');
                    }
                }
                std::cout << std::endl;
            }


            //выводим bmp-изображение в консоль (32*33)

        }
        break;
    case 6:
    {if (fs.is_open()) {
            std::cout << "file opened " << std::endl;

            unsigned int bpp = 0;
            fs.seekg(28);
            fs.read((char*)&bpp, sizeof(int));
            std::cout << "BPP " << bpp << std::endl;

            //считываем информацию о ширине и высоте изображения
            fs.seekg(18);
            unsigned int width = 0, height = 0;
            fs.read((char*)&width, sizeof(int));
            fs.read((char*)&height, sizeof(int));
            std::cout << "width  " << width << std::endl;
            std::cout << "height " << height << std::endl;
        }break;
    case 7:
    std::fstream ofs;
    ofs.open(argv[2], std::ios_base::binary | std::ios_base::in | std::ios_base::out);
    if (!ofs.is_open()) {
        std::cout << "file can't be opened " << std::endl;
    }
    else {
        std::cout << "file opened " << std::endl;

        unsigned int bpp = 0;
        ofs.seekg(28);
        ofs.read((char*)&bpp, sizeof(int));
        std::cout << "BPP " << bpp << std::endl;

        //считываем информацию о ширине и высоте изображения
        ofs.seekg(18);
        unsigned int width = 0, height = 0;
        ofs.read((char*)&width, sizeof(int));
        ofs.read((char*)&height, sizeof(int));
        std::cout << "width  " << width << std::endl;
        std::cout << "height " << height << std::endl;
    }
    
            break;
        }
    }
   


   
   


}

