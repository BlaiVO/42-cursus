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
        throw std::range_error("addNumber: Span elements limit reached");
    else
        this->_nums.push_back(num);
}

int Span::shortestSpan()
{
    if (this->_nums.size() < 2)
    {
        throw std::logic_error("shortestSpan: Span must have at least 2 elements");
    }
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
    if (this->_nums.size() < 2)
        throw std::logic_error("longestSpan: Span must have at least 2 elements");
    std::vector<int>::iterator max = std::max_element(this->_nums.begin(), this->_nums.end());
    std::vector<int>::iterator min = std::min_element(this->_nums.begin(), this->_nums.end());
    return *max - *min;
}

void	Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (begin >= end)
		throw std::out_of_range("addRange: Inputs are out of range");

	for (; begin != end; begin++)
	{
		this->addNumber(*begin);
	}
}
