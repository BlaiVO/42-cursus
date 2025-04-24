#include <iostream>
#include "Span.hpp"

int main()
{
    Span s = Span(10);
    s.addNumber(0);
    s.addNumber(6);
    s.addNumber(9);
    s.addNumber(10);
    std::cout << s.longestSpan() << std::endl;
}