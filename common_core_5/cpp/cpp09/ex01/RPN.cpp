#include <iostream>
#include "RPN.hpp"

RPN::RPN()
{}

RPN::RPN(const RPN &copy) {
    this->stack = copy.stack;
    this-> input = copy.input;
}

RPN &RPN::operator=(const RPN &a)
{
    if (this != &a)
    {
        this->stack = a.stack;
    }
    return *this;
}

RPN::~RPN()
{}

void error()
{
    std::cout << "Error" << std::endl;
    //return 1;
}

bool validate_input(std::string input_string, std::stack<char> &input) {
    std::string valid_tokens = "+-/*0123456789";
    for (long unsigned int i = 0; i < input_string.length(); i++)
    {
        std::cout << "LAP" << std::endl;
        if (valid_tokens.find(input_string[i]) == std::string::npos)
        {
            std::cout << "Error 1:" << std::endl;
            return false;
        }
        input.push(input_string[i]);
        if (i + 1 < input_string.length())
        {
            if (input_string[++i] != ' ')
            {
                std::cout << "Error 2" << std::endl;
                return false;
            }
        }
    }
    return input_string[input_string.length() - 1] != ' ';
}

void RPN::calculate(std::string input_string) {

    if (!validate_input(input_string, this->stack))
        return error();
}





