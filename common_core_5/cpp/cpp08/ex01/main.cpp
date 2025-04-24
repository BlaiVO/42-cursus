#include <iostream>
#include <cstdlib>
#include "Span.hpp"

int main()
{
    {
        std::cout << "----Subject test----" << std::endl;
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    {
        std::cout << "----Huge Span test----" << std::endl;
        int size = 10000;
        Span sp(size);

        std::srand(std::time(0));
        for (int i = 0; i < size; i++)
        {
            sp.addNumber(std::rand());
        }
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }

}