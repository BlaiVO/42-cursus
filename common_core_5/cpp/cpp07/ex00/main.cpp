#include <iostream>
#include "whatever.hpp"

int main()
{
    {
        std::cout << "----Subject tests----" << std::endl;
        int a = 2;
        int b = 3;
        ::swap( a, b );
        std::cout << "a = " << a << ", b = " << b << std::endl;
        std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
        std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
        std::string c = "chaine1";
        std::string d = "chaine2";
        ::swap(c, d);
        std::cout << "c = " << c << ", d = " << d << std::endl;
        std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
        std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
    }
    {
        int a = 8;
        int b = 6;

        std::cout << "----Int tests----" << std::endl;

        std::cout << "a, b: " << a << ", " << b << std::endl;
        std::cout << "(swap)" << std::endl;
        ::swap(a, b);
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
        ::swap(a, b);
        std::cout << "a, b: " << a << ", " << b << std::endl;
        
        std::cout << "Min: " << min(a, b) << std::endl;
        std::cout << "Max: " << max(a, b) << std::endl;
    }
    {
        char a = 'r';
        char b = 'h';

        std::cout << "----Char tests----" << std::endl;

        std::cout << "a, b: " << a << ", " << b << std::endl;
        std::cout << "(swap)" << std::endl;
        ::swap(a, b);
        std::cout << "a, b: " << a << ", " << b << std::endl;
        
        std::cout << "Min: " << min(a, b) << std::endl;
        std::cout << "Max: " << max(a, b) << std::endl;
    }
}