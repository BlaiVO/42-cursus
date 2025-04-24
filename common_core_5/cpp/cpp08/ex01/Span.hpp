#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>

class Span
{
    private:
        unsigned int _size;
        std::vector<int> _nums;
        Span();
    public:
        Span(unsigned int N);
        Span(const Span &copy);
        Span &operator=(const Span &a);
        ~Span();
        void addNumber(int num);
        int shortestSpan();
        int longestSpan();
};

#endif