#include <iostream>
#include <fstream>

/*bool getPixel(unsigned char* buffer, size_t weigth, size_t height, size_t row, size_t col) {

}*/

/*void setPicture(unsigned char* buffer, size_t weigth, size_t height, size_t row, size_t col, bool pix_var) {

}*/

int main(int argc, char* argv[]) {
    std::cout << " argc=" << argc << std::endl;
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

    std::cout << "1. change width and height \n" << "2. image 32*32 to console\n";
    std::cout << "3. image 32*33 to console\n" << "4. colour image info\n" << "5. change colour image - swap red and blue\n" << "6. width and height of image #1\n" << "7. width and height of image #2\n";
    std::cout << "8. input small bmp to big bmp\n" << "0. exit \n";
    int choice = -1;
    while (choice != 0) {
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

                std::cout << "width  " << (int)width << std::endl;
                std::cout << "height " << (int)height << std::endl;
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

        case 3:
            std::cout << "image 32*33 to console\n" << std::endl;
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

                //выводим bmp-изображение в консоль (32*33)
                for (size_t rows = 0; rows < height; ++rows) {
                    unsigned char ost = 0;
                    unsigned char toout = 0;
                    //выводим 32 бита
                    for (size_t cols = 0; cols < width - width % 32; cols += 8) {
                        unsigned char bTmp = 0;
                        fs.read((char*)&bTmp, 1);
                        if (fs.eof()) { break; }

                        for (unsigned char mask = 0x80; mask != 0; mask >>= 1) {
                            std::cout << (((bTmp & mask) == 0) ? '1' : '0');
                        }
                    }
                    //выводим остаток от деления на 32(содержат значимую информацию)
                    fs.read((char*)&ost, width % 32);
                    for (unsigned char mask = 0x80; mask != 0; mask >>= 1) {
                        std::cout << (((ost & mask) == 0) ? '1' : '0');
                        break;
                    }
                    //пропускаем незначимые данные   
                    for (int i = 0; i < 3; ++i) {
                        fs.read((char*)&toout, 1);
                    }
                    std::cout << std::endl;
                }
            }
            break;

        case 4:
        {std::cout << "color of file\n" << std::endl;
        if (fs.is_open()) {
            std::cout << "file opened " << std::endl;


            int px=0;
            int buffer=0;

            fs.seekg(10);
            fs.read((char*)&px, sizeof(int));
            px += 3;
            fs.seekg(px);
            std::cout << "Colour: ";
            for (int i = 0; i < 3; ++i) {
                fs.read((char*)&buffer, sizeof(char));
                std::cout <<  buffer  << " ";
                
            }
            
        }
        std::cout << std::endl;
        }
        // red 0 0 255
        // blue 204 72 63
        // green 0 255 0
        // BGR
        break;

        case 5:
            std::cout << "change colour image - swap red and blue \n" << std::endl;
            if (fs.is_open()) {
                std::cout << "file opened " << std::endl;

                std::ofstream ofs;
                
                ofs.open(argv[2], std::ios::binary | std::ios::in | std::ios::out | std::ios::trunc);
                if (ofs.is_open()) {
                    std::cout << "file opened " << std::endl;
                    int bitoffBits = 0;//bitoffBits
                    fs.seekg(10);
                    fs.read((char*)&bitoffBits, sizeof(int));
                    std::cout << "Read bitoffBits\t" << bitoffBits << std::endl;
                    fs.seekg(bitoffBits);

                    unsigned char* buffer = new unsigned char[bitoffBits];
                    fs.read((char*)buffer, bitoffBits * sizeof(char));
                    ofs.write((char*)buffer, bitoffBits * sizeof(char));
                    buffer = new unsigned char[3];
                    while (fs.tellg() != -1) {
                        fs.read((char*)buffer, 3 * sizeof(char));
                        ofs.write((char*)&buffer[2], sizeof(char));
                        ofs.write((char*)&buffer[1], sizeof(char));
                        ofs.write((char*)&buffer[0], sizeof(char));
                        ofs.flush();
                    }

                    delete[] buffer;
                    //fs.close();
                    ofs.close();
                }
               
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
        }
        }
        break;
        case 7: {
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
        }
            break;

        case 8:
            //коллаж
        {std::ifstream image1;
        std::ifstream image2;
        image1.open(argv[1], std::ios::binary | std::ios::in);
        image2.open(argv[2], std::ios::binary | std::ios::in);
        if (!image1.is_open() || !image2.is_open()) {
            std::cout << "failed to open";
        }
        else {
            unsigned int width1 = 0;
            unsigned int height1 = 0;
            image1.seekg(18, std::ios::beg);
            image1.read((char*)&width1, sizeof(int));
            image1.read((char*)&height1, sizeof(int));
            if (width1 % 32 != 0) {
                width1 = width1 + 32 - (width1 % 32);
            }
            unsigned int width2 = 0;
            unsigned int height2 = 0;
            image2.seekg(18, std::ios::beg);
            image2.read((char*)&width2, sizeof(int));
            image2.read((char*)&height2, sizeof(int));
            if (width2 % 32 != 0) {
                width2 = width2 + 32 - (width2 % 32);
            }
            std::cout << "width1   " << width1 << "    " << "height1  " << height1 << std::endl;
            std::cout << "width2   " << width2 << "    " << "height2  " << height2 << std::endl;
            image2.close();


            std::ofstream image2;
            image2.open(argv[2], std::ios::binary | std::ios::in | std::ios::out);
            if (!image2.is_open()) {
                std::cout << "can't open file";
                
            }
            else {
                int sizeInBytes1 = width1 / 8;
                int sizeInBytes2 = width2 / 8;
                char* buffer = new char[sizeInBytes1];
                for (int i = 1; i < height1; i++) {
                    image1.seekg((-1) * sizeInBytes1 * i, std::ios::end);
                    image1.read(buffer, sizeInBytes1 * sizeof(char));
                    image2.seekp((-1) * sizeInBytes2 * i, std::ios::end);
                    image2.write(buffer, sizeInBytes1 * sizeof(char));
                }

                delete[] buffer;
            }
            image1.close();
            image2.close();
        }
        }
        break;
        
        
        }



    }


    fs.close();
}

