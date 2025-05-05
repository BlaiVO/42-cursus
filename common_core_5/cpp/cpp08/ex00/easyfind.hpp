#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <exception>
# include <algorithm>

template <typename T>
typename T::iterator easyfind(T &cont, int target)
{
    typename T::iterator it;
    it = std::find(cont.begin(), cont.end(), target);
    if (it == cont.end())
        throw std::logic_error("Target number not in container");
    return it;
}

#endif