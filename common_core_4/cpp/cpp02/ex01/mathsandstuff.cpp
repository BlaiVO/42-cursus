#include <iostream>
#include <cmath>
#include "Fixed.hpp"

Fixed   intToFixed(const int num)
{
    Fixed   f;
    // int     val = 0;
    int     limit = (sizeof(int) * 8) - 8;
    std::cout << limit << std::endl;
    int mask = std::pow(2, limit) - 1;
    std::cout << mask << std::endl;
    // int     i = 1;
    f.setRawBits(num & mask);
    // while (limit)
    // {
    //     val &= i & num;
    //     i <<= 1;
    //     limit--;
    // }
    return (f);
}

int main(void)
{
    Fixed f = intToFixed(10);
    std::cout << f.getRawBits() << std::endl;
    return (0);
}