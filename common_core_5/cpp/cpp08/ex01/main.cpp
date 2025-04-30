#include <iostream>
#include <cstdlib>
#include "Span.hpp"

#include <random>

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
        std::cout << "----Small Span test----" << std::endl;
        int size = 10;
        Span sp(size);

        std::srand(std::time(0));
        for (int i = 0; i < size; i++)
        {
            int num = std::rand() % (size * 10);
            std::cout << num << std::endl;
            sp.addNumber(num);
        }
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;

    }
    {
        std::cout << "----Huge Span test----" << std::endl;
        int size = 10000;
        Span sp(size);

        std::vector<int> values(size * 100);
        for (int i = 0; i < size * 100; ++i) {
            values[i] = i + 1;
        }

        std::random_device rd;
        std::mt19937 gen(rd());

        std::srand(std::time(0));
        std::shuffle(values.begin(), values.end(), gen);
        for (int i = 0; i < size; i++)
        {
            sp.addNumber(values[i]);
        }
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }
}
