#pragma once

template<typename T> 
class Arr {
public:
    Arr();
    Arr(long long size);
    ~Arr();
    Arr(const Arr&);
    Arr(Arr&&);
    T& operator[](size_t index);
    const T& operator[](size_t index)const;
    long long getSize() const;
    void removeElement(size_t nindex);
    void replaceElement(size_t nindex, T newelement);
    void addElement(T newelement);
    Arr& operator=(const Arr&);
    Arr& operator=(Arr&&);
    //bool operator==(const Arr<T>& X)const;  
private:
    T* m_storage;
    long long m_size;
};

template<typename T> Arr<T>::Arr() {
    m_size = 0;
    m_storage = nullptr;
}

template<typename T> Arr<T>::Arr(long long size) {
    if (size < 0) { 
        throw "BadSize!";
    } else {
        m_size = size;
        m_storage = new T[size];
    }
}

template <typename T> Arr<T>::Arr(const Arr<T>& X) {
    m_size = X.size_;
    m_storage = new T[m_size];
    for (size_t i = 0; i < m_size; ++i) {
        m_storage[i] = X.m_storage[i];
    }
}

template <typename T> Arr<T>::Arr(Arr<T>&& X) {
    m_size = X.size;
    m_storage = X.storage;
    X.m_storage = nullptr;
    X.m_size = 0;
}

template<typename T> Arr<T>::~Arr() {
    if (m_storage != nullptr) {
        delete[] m_storage;
        m_size = 0;
        m_storage = nullptr;
    }
}

template<typename T> const T& Arr<T>::operator[](size_t index) const {
    if (index < m_size)
        return m_storage[index];
    else throw "Your element choice is invalid.";
}
template<typename T> T& Arr<T>::operator[] (size_t index) {
    if (index < m_size)
        return m_storage[index];
    else throw "Your element choice is invalid.";
}



template<typename T> long long Arr<T>::getSize() const {
    return m_size;
};

template<typename T> void Arr<T>::removeElement(size_t nindex) {
    if (nindex < m_size){
    if (m_size == 1) {
        m_storage = nullptr;
        m_size = 0;
        return;
    }
    T* newstorage = new T[m_size - 1];
    for (int i = 0; i < nindex; ++i) {
        newstorage[i] = m_storage[i];
    }
    for (int i = nindex + 1; i < m_size; ++i) {
        newstorage[i - 1] = m_storage[i];
    }
    delete[] m_storage;
    m_storage = new T[m_size - 1];
    for (size_t i = 0; i < m_size - 1; ++i) {
        m_storage[i] = newstorage[i];
    }
        --m_size;
        delete[] newstorage;
    }
    else {
        throw "Your index for delete element is invalid."; 
    }
};

template<typename T> void Arr<T>::replaceElement(size_t nindex, T newelement) {
    if (nindex < m_size) {
        
        T* newstorage = new T[m_size];
        for (int i = 0; i < nindex; ++i) {
            newstorage[i] = m_storage[i];
        }
        newstorage[nindex] = newelement;
        for (int i = nindex + 1; i < m_size; ++i) {
            newstorage[i] = m_storage[i];
        }
        delete[] m_storage;
        m_storage = new T[m_size];
        for (size_t i = 0; i < m_size; ++i) {
            m_storage[i] = newstorage[i];
        }
        delete[] newstorage;
    }
    else {
        throw "Your index for delete element is invalid.";
    }
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

template <typename T> Arr<T>& Arr<T>::operator=(const Arr<T>& X) {
    if (this != &X) {
        if (m_storage) 
            delete[] m_storage;
        m_size = X.m_size;
        m_storage = new T[m_size];
        for (unsigned int i = 0; i < m_size; ++i)
            m_storage[i] = X.m_storage[i];
    }
    return *this;
}

template <typename T> Arr<T>& Arr<T>::operator=(Arr<T>&& X) {
    if (this != &X) {
        if (m_storage) 
            delete[] m_storage;
        m_size = X.m_size;
        m_storage = X.m_storage;
        X.m_storage = nullptr;
        X.m_size = 0;
    }
    return *this;
}
