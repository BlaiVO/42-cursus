#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <stdexcept>

template<class T>
class Array
{
    private:
        T *_array;
        unsigned int _size;
    public:
        Array();
        Array(unsigned int n);
        Array(const Array &copy);
        Array &operator=(const Array &a);
        T &operator[](int i);
        ~Array();
        unsigned int size() const;
};

#endif