#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <string>
class RPN {
    private:
        std::stack<float> stack;
        std::stack<char> input;
        bool parse_input(std::string input_string);
    public:
        RPN();
        RPN(const RPN &copy);
        RPN &operator=(const RPN &a);
        ~RPN();
        void calculate(std::string input_string);
};

#endif