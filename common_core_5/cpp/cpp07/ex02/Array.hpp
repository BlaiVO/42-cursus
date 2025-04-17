#ifndef ARRAY_HPP
# define ARRAY_HPP

template<class T>
class Array
{
    private:
    public:
        Array();
        Array(unsigned int);
        Array(const Array &copy);
        Array &operator=(const Array &a);
        ~Array();
};

#endif