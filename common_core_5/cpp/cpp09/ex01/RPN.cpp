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

void error(std::string msg = "")
{
    std::cout << "Error";
    if (msg != "")
        std::cout << ": " << msg;
    std::cout << std::endl;
}

bool RPN::parse_input(std::string input_string)
{
    if (input_string.find_first_not_of(" +-/*0123456789") != std::string::npos)
        return false;
    for (int i = (int)input_string.length() - 1; i >= 0; i--)
    {
        if (input_string[i] == ' ')
            return false;
        this->input.push(input_string[i]);
        if (i != 0 and input_string[--i] != ' ')
            return false;
    }
    return input_string[0] != ' ';
}

float operate(char op, float n1, float n2)
{
    switch (op)
    {
    case '+':
        return n1 + n2;
        break;
    case '-':
        return n1 - n2;
        break;
    case '*':
        return n1 * n2;
        break;
    case '/':
        return n1 / n2;
        break;
    default:
        return (0);
        break;
    }
}

void RPN::calculate(std::string input_string) {
    std::string operators = "+-/*";
    if (!parse_input(input_string))
        return error("malformed input");
    while (!input.empty())
    {
        if (operators.find(input.top()) != std::string::npos) {
            if (stack.size() < 2)
                return error("not enough numbers to operate");
            float n2 = stack.top();
            stack.pop();
            float n1 = stack.top();
            stack.pop();
            if (input.top() == '/' && n2 == 0)
                return error("division by zero");
            stack.push(operate(input.top(), n1, n2));
        }
        else
            stack.push((float)(input.top() - '0'));
        input.pop();
    }
    if (stack.size() != 1)
        return error("missing operators");
    std::cout << stack.top() << std::endl;
}
