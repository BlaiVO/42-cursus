#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

template <class T>
class MutantStack : public std::stack<T>
{
    public:
        typedef std::stack<T> stack;
        typedef typename stack::container_type container;
        typedef typename container::iterator iterator;

        MutantStack() : stack() {}
        MutantStack(const stack &src) : stack(src) {}
        ~MutantStack(){}
        stack &operator=(const stack &src)
        {
            if (*this != src)
                *this = src;
            return (*this);
        }
        iterator begin()
        {
            return (stack::c.begin());
        }

        iterator end()
        {
            return (stack::c.end());
        }
};

#endif