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
		Span sp = Span(50000);

		std::vector<int>vec(50000);
		for (int i = 0; i <= 50000; ++i)
		{
			vec[i] = rand() % 100000;
		}
		sp.addRange(vec.begin(), vec.end());
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }
    {
        std::cout << "----Errors test----" << std::endl;
        std::cout << "Trying addNumber, longestSpan and shortestSpan on a Span(0)" << std::endl;
        Span sp(0);
        try {
            sp.addNumber(4);
        } catch (std::range_error e) {
            std::cout << e.what() << std::endl;
        }
        try {
            sp.longestSpan();
        } catch (std::logic_error e) {
            std::cout << e.what() << std::endl;
        }
        try {
            sp.shortestSpan();
        } catch (std::logic_error e) {
            std::cout << e.what() << std::endl;
        }
        std::cout << std::endl << "Trying to add too many numbers with addRange" << std::endl;
        sp = Span(5);
        std::vector<int> v;
        for (int i = 0; i < 6; i++)
        {
            v.push_back(i);
        }
        try {
            sp.addRange(v.begin(), v.end());
        } catch (std::range_error e) {
            std::cout << e.what() << std::endl;
        }
        std::cout << std::endl << "Trying to pass v.end() as begin and v.begin() as end to addRange" << std::endl;
        v.resize(5);
        try {
            sp.addRange(v.end(), v.begin());
        } catch (std::out_of_range e) {
            std::cout << e.what() << std::endl;
        }
    }
}
