#pragma once
#include <iostream>

template<typename T> 
class Arr {
public:
    Arr();
    Arr(size_t size);
    ~Arr();
    const T& getElement(size_t index) const;
    T& operator[](size_t index);
    size_t getSize() const;
    T removeElement(size_t nindex);
    void printArray() const;
    void addElement(T newelement);
    void resize(size_t new_size);
private:
    T* m_storage;
    size_t m_size;
};

template<typename T> Arr<T>::Arr() {
    m_size = 0;
    m_storage = nullptr;
}

template<typename T> Arr<T>::Arr(size_t size) {
    if (size < 1) { 
        /*throw BadSize();*/ 
    } else {
        m_size = size;
        m_storage = new T[size];
    }
}

template<typename T> Arr<T>::~Arr() {
    if (m_storage != nullptr)
        delete[] m_storage;
}

template<typename T> const T& Arr<T>::getElement(size_t index) const {
    if (index <= m_size)
        return &(*(m_storage + index));
    else {
        std::cout<<"Your element choice is invalid. Now return first element.\n"
        return m_storage[0];
    }
}

template<typename T> T& Arr<T>::operator[] (size_t index) {
    if (index <= m_size)
        return *(m_storage + index);
    else {
        std::cout << "Your element choice is invalid. Now return first element.\n"
        return m_storage[0];
    }
}

template<typename T> size_t Arr<T>::getSize() const {
    return m_size;
};

template<typename T> T Arr<T>::removeElement(size_t nindex) {
    T delElement;
    if (nindex <= m_size) {
        delElement = m_storage[nindex];
        for (int i = nindex; i < getSize() - 1; ++i) {
            m_storage[i] = m_storage[i + 1];
        }
        m_size -= 1;
        return delElement;
    }
    else {
        std::cout << "Your index for delete element is invalid. Now return first element.\n"
        return m_storage[0];
    }
};

template<typename T> void Arr<T>::printArray() const {

    for (int i = 0; i < getSize(); ++i) {
        std::cout << getElement(i) << ' ';
    }
    std::cout<< std::endl;
};

template<typename T> void Arr<T>::addElement(T newelement) {
    T* newstorage = new T[m_size + 1];
    for (size_t i = 0; i < m_size; ++i) {
        newstorage[i] = m_storage[i];
    }
    newstorage[m_size] = newelement;
    delete[] m_storage;
    m_storage = new T[m_size + 1];
    for (size_t i = 0; i < m_size + 1; ++i) {
       m_storage[i] = newstorage[i];
    }
    ++m_size;
    delete[] newstorage;
};

template<typename T> void Arr<T>::resize(size_t new_size) {
    if (new_size < m_size) {
        T* newstorage = new T[new_size];
        for (int i = 0; i < new_size; ++i) {
            newstorage[i] = m_storage[i];
        }
        delete[] m_storage;
        
        T* m_storage = new T[new_size];
        for (int i = 0; i < new_size; ++i) {
            m_storage[i] = newstorage[i];
        }
        delete[] newstorage;
        m_size = new_size;
    }
    else if (new_size > m_size) {
        T* newstorage = new T[new_size];
        for (int i = m_size; i < new_size; ++i) {
            newstorage[i] = 0;
        }
        delete[] m_storage;
        T* m_storage = new T[new_size];
        for (int i = 0; i < new_size; ++i) {
            m_storage[i] = newstorage[i];
        }
        delete[] newstorage;
        m_size = new_size;
    }
};
