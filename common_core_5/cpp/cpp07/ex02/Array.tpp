#include "Array.hpp"

template<class T>
Array<T>::Array()
{
    this->_array = NULL;
    this->_size = 0;
}

template<class T>
Array<T>::Array(unsigned int n)
{
    this->_array = new[n] T();
    this->_size = n;
}

template<class T>
Array<T>::Array(const Array &copy)
{
}

template<class T>
T &Array<T>::operator[](int i)
{
    if (i < 0 || i >= this->_size)
        throw (std::out_of_range)
    return this->_array[i];
}


template<class T>
Array<T>::~Array()
{
    if (this->_array)
        delete this->_array;
}

template<class T>
unsigned int Array<T>::size() const
{
    return this->_size;
}
