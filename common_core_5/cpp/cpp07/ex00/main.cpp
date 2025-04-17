#include <iostream>
#include "whatever.hpp"

int main()
{
    {
        int a = 8;
        int b = 6;

        std::cout << "----Int tests----" << std::endl;

        std::cout << "a, b: " << a << ", " << b << std::endl;
        std::cout << "(swap)" << std::endl;
        swap(a, b);
        std::cout << "a, b: " << a << ", " << b << std::endl;
        
        std::cout << "Min: " << min(a, b) << std::endl;
        std::cout << "Max: " << max(a, b) << std::endl;
    }
    {
        float a = 4.2;
        float b = 6.9;

        std::cout << "----Float tests----" << std::endl;

        std::cout << "a, b: " << a << ", " << b << std::endl;
        std::cout << "(swap)" << std::endl;
        swap(a, b);
        std::cout << "a, b: " << a << ", " << b << std::endl;
        
        std::cout << "Min: " << min(a, b) << std::endl;
        std::cout << "Max: " << max(a, b) << std::endl;
    }
    {
        char a = 'r';
        char b = 'h';

        std::cout << "----String tests----" << std::endl;

        std::cout << "a, b: " << a << ", " << b << std::endl;
        std::cout << "(swap)" << std::endl;
        swap(a, b);
        std::cout << "a, b: " << a << ", " << b << std::endl;
        
        std::cout << "Min: " << min(a, b) << std::endl;
        std::cout << "Max: " << max(a, b) << std::endl;
    }
}