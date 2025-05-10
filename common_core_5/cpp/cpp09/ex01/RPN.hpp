#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <string>
class RPN {
    private:
        std::stack<int> stack;
        std::stack<char> input;
        RPN();
        RPN(const RPN &copy);
        RPN &operator=(const RPN &a);
    public:
        ~RPN();
        static void calculate(std::string input_string);
};

#endif