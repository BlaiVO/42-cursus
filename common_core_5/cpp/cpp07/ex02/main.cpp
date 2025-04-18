#include <iostream>
#include <string>
#include "Array.hpp"

int main()
{
    {
        std::cout << "-----Int check-----" << std::endl;
        Array <int> a(5);
        for (unsigned int i = 0; i < a.size(); i++)
            a[i] = i + 1;
        std::cout << a[3] << std::endl;
        Array <int> b = a;
        std::cout << "B size: " << b.size() << std::endl;
        for (unsigned int i = 0; i < b.size(); i++)
        std::cout << b[i] << std::endl;
        try
        {
            std::cout << b[28] << std::endl;
        }
        catch (std::exception &e)
        {
            std::cout << "nope: " << e.what() << std::endl;
        }
    }
    {
        std::cout << "-----String check-----" << std::endl;
        Array <std::string> s(3);
        s[0] = "I ";
        s[1] = "like ";
        s[2] = "Rocks";
        std::cout << s[0] << s[1] << s[2] << std::endl;
    }
    return 0;
}