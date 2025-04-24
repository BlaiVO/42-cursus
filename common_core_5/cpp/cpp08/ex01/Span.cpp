#include "Span.hpp"
#include <stdexcept>
#include <algorithm>

Span::Span(){};

Span::Span(unsigned int N)
{
    this->_size = N;
}

Span::Span (const Span &copy)
{
    this->_size = copy._size;
    this->_nums = copy._nums;
}

Span &Span::operator=(const Span &a)
{
    if (this != &a)
    {
        this->_size = a._size;
        this->_nums = a._nums;
    }
    return *this;
}

Span::~Span(){};

void Span::addNumber(int num)
{
    if (this->_nums.size() >= this->_size)
        throw std::range_error("Span elements limit reached");
    else
        this->_nums.push_back(num);
}

int Span::shortestSpan() const
{
}

int Span::longestSpan()
{
    std::pair<std::vector<int>::iterator, std::vector<int>::iterator> p;
    p = std::minmax_element(this->_nums.begin(), this->_nums.end());
    return *p.second - *p.first;
}