#include <iostream>
#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Error: Invalid argument number" << std::endl;
        return 1;
    }
    RPN::calculate(std::string(argv[1]));
    return 0;
}