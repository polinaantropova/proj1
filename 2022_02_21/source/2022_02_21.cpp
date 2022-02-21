// 2022_02_21.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#define T int


class Arr {
public:

    Arr() {
        m_size = 0;
        m_storage = nullptr;
    }

    Arr(size_t size) {
        m_size = size;
        m_storage = new T[size];
    }

    ~Arr() {
        if (m_storage != nullptr)
            delete[] m_storage;

    }


    T& getElement(size_t index) {
        if (index < m_size)
            return *(m_storage + index);
        else {
            //return nullptr;
        }
    }

    size_t getSize() const {
        return m_size;
    };

    void removeElement(size_t nindex) {
        if (nindex < m_size) {
            for (int i = nindex; i < getSize() - 1; ++i) {
                m_storage[i] = m_storage[i + 1];
            }
            m_size -= 1;
        }
        else {
            //return nullptr;
        }
    };

    void printArray() {

        for (int i = 0; i < getSize(); ++i) {
            std::cout << getElement(i) << std::endl;
        }
    };
   
    void addElement(T newelement) {
        T* newstorage = new T[m_size + 1];
        ++m_size;
        newstorage[m_size] = newelement;
        delete[] m_storage;
        m_storage = newstorage;

    };
    void resize(size_t new_size) {
        //size = new_size;
        if (new_size < m_size) {
            T* newstorage = new T[new_size];
            for (int i = 0; i < new_size; ++i) {
                newstorage[i] = m_storage[i];
            }
            m_size = new_size;
            delete[] m_storage;
            m_storage = newstorage;

        }
        else if (new_size > m_size) {
            T* newstorage = new T[new_size];
            //
            for (int i = m_size; i < new_size; ++i) {
                newstorage[i] = 0;
            }
            m_size = new_size;
            delete[] m_storage;
            m_storage = newstorage;
        }
    };
private:
    T* m_storage;
    size_t m_size;
};

/*bool testArrAddElem{
return true;
}

bool testArrRemElem{
return true;
}

bool testArrResize{
return true;
}

bool testArrGetElem{
return true;
}*/

int main()
{
    while (1) {
        Arr shelf;
        shelf.addElement(42);
        int exl = 42;
        shelf.getElement(exl);
        shelf.getElement(0);
        shelf.removeElement(0);
    }
    Arr store;
    std::cout << "Hello World!\n";
}
