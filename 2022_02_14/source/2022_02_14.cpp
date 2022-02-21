// 2022_02_14.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
//T* storage;
//size_t size;

struct Arr{
    T* storage;
    size_t size;
};

/*для того чтобы реализовать для нескольких разных типов "складов", будем указывать это при вызове функции */
T* getElement(Arr a, size_t index) {
    if (index < a.size)
        return *(a.storage + index);
    else {
        return nullptr;
    }
}
/*когда обращаемся к элеентам массива мы потенциально можем изменить отдельеый жлемент
в других функциях мы можем менять весь массив*/
void removeElement(Arr a,size_t nindex) {
    if (nindex < a.size) {
        //после выкинутого элемента всех сместить влево на 1
        for (int i = nindex; i < a.size - 1; ++i) {
            a.storage[i] = a.storage[i + 1];
            
        }
        //delete T[]
        a.size -= 1;
    }
     
    else {
        //return nullptr;
    }
};
// можем функцию вернуть Arr
// 3й параметр 
// модифицируем целиком состояние массива &a
void addElement(Arr a,T) {
    a.size += 1;
    a.storage[a.size] = a.storage;

};
void resize(Arr a,size_t new_size) {
    a.size = new_size;
};

bool testArrAddElem{
};

bool testArrRemElem{
};

bool testArrResize{
};

bool testArrGetElem{
};


int main()
{
    std::cout << "Hello World!\n";
    //shelf
    Arr shelf;
    getElement(shelf, 4);
    //store
    Arr store;
    getElement(store, 4);

}

