#include <windows.h>
#include <locale.h>
#include <vector>
#include <iostream>
#include <memory>

template <class T>
class MyUnique
{
public:
    MyUnique() {}
    MyUnique(T* a) :ptr(a)
    {
    };
    ~MyUnique()
    {
        std::cout << "Delete MyUnique\n";
        delete ptr;
    };

    T* release() 
    {
        auto p = ptr;
        ptr = NULL;
        return p;
    }

    T operator *() { return *ptr; }

    MyUnique(const MyUnique&) = delete;

private:
    
    void operator = (const MyUnique a) = delete;

    T* ptr=NULL;
};

class MyClass
{
public:
    MyClass(int a): size(a)
    {
        P_arr= new int(size);
        for (int i =0; i < size; ++i)
        {
            P_arr[i] = i;
        }
    }
  
    ~MyClass() 
    { std::cout << "Delete MyClass\n";
    delete P_arr;
    }
private:
    int size = 0;
    int* P_arr = NULL;
};



int main()
{
	setlocale(LC_ALL, "Russian");
	system("chcp 1251");
 

    MyUnique<MyClass> unique_int(new MyClass(5));
  //  std::cout << *unique_int;
    auto p = unique_int.release();
    delete p;
    return 0;
}