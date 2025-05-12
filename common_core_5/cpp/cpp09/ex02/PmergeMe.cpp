#include <iostream>
#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{}

PmergeMe::PmergeMe(const PmergeMe &copy)
{
    *this = copy;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &a)
{
    if (this != &a)
    {
        *this = a;
    }
    return *this;
}

PmergeMe::~PmergeMe()
{
}

bool PmergeMe::parse_vector(int argc, char **argv)
{
    char* p;

    for (int i = 0; i < argc; i++)
    {
        long current = strtol(argv[i], &p, 10);
        if (*p || current < 0 || current > INT_MAX)
        {
            std::cout << "Error: all inputs must be positive integers" << std::endl;
            return false;
        }
        if (std::find(vect.begin(), vect.end(), static_cast<int>(current)) != vect.end())
        {
            std::cout << "Error: all numbers must be unique" << std::endl;
            return false;
        }
        vect.push_back(static_cast<int>(current));
    }
    return true;
}

bool is_sorted_vector(std::vector<int> vect)
{
    int last = 0;
    for (unsigned long i = 0; i < vect.size(); i++)
    {
        if (vect[i] < last)
            return false;
        last = vect[i];
    }
    return true;
}

void PmergeMe::sort_vector()
{
    int group_size = 2;

    std::cout << "level 0" << std::endl;
    while (!is_sorted_vector(vect))
    {
        std::cout << "level 1" << std::endl;
        for (int i = 0; i < (int)vect.size(); i++)
        {
          std::cout << "level 2" << std::endl;
            if (vect[i] > vect[i + (group_size/2)])
            {
            std::cout << "level 3" << std::endl;
                for (int y = 0; y < group_size/2; y++)
                {
                    std::cout << "level 4" << std::endl;
                    int aux = vect[i + y];
                    vect[i + y] = vect[i + (group_size/2) + y];
                    vect[i + (group_size/2) + y] =  aux;
                }
            }
        }
    }
}

void PmergeMe::print_vector(){
    for (unsigned long i = 0; i < vect.size(); i++)
    {
        std::cout << vect[i];
        if (i != vect.size() - 1)
            std::cout << " ";
    }
    std::cout << std::endl;
}