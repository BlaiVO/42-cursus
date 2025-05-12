#include <iostream>
#include "RPN.hpp"

int main(int argc, char **argv)
{
    RPN rpn;
    if (argc != 2)
    {
        std::cout << "Error: Invalid argument number" << std::endl;
        return 1;
    }
    rpn.calculate(std::string(argv[1]));
    return 0;
}