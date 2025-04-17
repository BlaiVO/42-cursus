#include <iostream>
#include "iter.hpp"

template<class T>
void printT(T t)
{
    std::cout << t << std::endl;
}

template<class T>
void addOne(T &t)
{
    ++t;
}

int main()
{
    int int_arr[] = {8, 6, 12, -90, 42};
    char char_arr[] = {'p', 'a', 't', 'a', 't', 'a'};

    std::cout << "Iter with int and printT()" << std::endl;
    ::iter(int_arr, 5, printT);
    std::cout << "Iter with char and printT()" << std::endl;
    ::iter(char_arr, 6, printT);
    std::cout << "addOne() with both arrays" << std::endl;
    ::iter(int_arr, 5, ::addOne);
    ::iter(char_arr, 6, ::addOne);
    std::cout << "Iter with int and printT()" << std::endl;
    ::iter(int_arr, 5, printT);
    std::cout << "Iter with char and printT()" << std::endl;
    ::iter(char_arr, 6, printT);
    return 0;
}
