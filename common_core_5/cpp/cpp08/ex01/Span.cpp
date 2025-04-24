#include "Span.hpp"
#include <stdexcept>
#include <algorithm>
#include <cmath>

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
    //std::sort(this->_nums.begin(), this->_nums.end());
}

int Span::shortestSpan()
{
    if (this->_size < 2)
        throw std::logic_error("Span must have at least 2 elements");
	std::vector<int> tmp = this->_nums;
	std::sort(tmp.begin(), tmp.end());
	int min = tmp[1] - tmp[0];
	for (unsigned int i = 1; i < tmp.size(); i++)
	{
		if (tmp[i] - tmp[i - 1] < min)
			min = tmp[i] - tmp[i - 1];
        if (min == 0)
            return (min);
	}
	return (min);
}

int Span::longestSpan()
{
    if (this->_size < 2)
        throw std::logic_error("Span must have at least 2 elements");
    std::pair<std::vector<int>::iterator, std::vector<int>::iterator> p;
    p = std::minmax_element(this->_nums.begin(), this->_nums.end());
    return *p.second - *p.first;
}