#ifndef ITER_HPP
# define ITER_HPP

template<class T>
void iter(T *array, int len, void (*f)(T&))
{
    for (int i = 0; i < len; i++)
    {
        f(array[i]);
    }
}

#endif