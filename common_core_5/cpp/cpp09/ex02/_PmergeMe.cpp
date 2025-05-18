#include <iostream>
#include <cstdlib>
#include <climits>
#include <algorithm>
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

void vector_swap_pair(std::vector<int> &vect, int p_size ,int p1, int p2)
{
    //* v = {4, 3, 2, 1}
    for (int i = 0; i < p_size; i++)
    {
        int aux = vect[p2 + i];
        vect[p2 + i] = vect[p1 + i];
        vect[p1 + i] = aux;
        std::cout << "SWAPPING RESULT: vect[" << p1 + 1 <<"] = " << vect[p1 + i] << ", vect[" << p2 + i << "] = " << vect[p2 + i] << std::endl;
    }
}

void PmergeMe::sort_vector()
{
    int p_size = 2;
    int size = (int)vect.size();
    while (!is_sorted_vector(vect))
    {
        std::cout << "\nwhile: p_size = " << p_size << std::endl;
        std::cout << "While: vect = ";
        this->print_vector();
        if (size % 2 != 0 && p_size == size - 1)
        {
            if (vect[size] - 1)
            {
                vect.insert(vect.begin(), vect[size - 1]);
                vect.pop_back();
            }
        }
        int i = 0;
        while(i < size)
        {
            std::cout << "\nfor: i = " << i << std::endl;
            std::cout << "for: i + (p_size / 2) = " << i + (p_size / 2) << std::endl;
            //std::cout << "for: vect[i], vect[i] = " << i + (p_size / 2) << std::endl;
            if (vect[i] > vect[i  + (p_size / 2)])
            {
                std::cout << "calling vector_swap_pair" << std::endl;
                vector_swap_pair(vect, p_size / 2, i, i + (p_size / 2));
            }
            i += p_size;
        }
        if (p_size > size)
        {
            std::cout << "ERROR: OOB" << std::endl;
            return;
        }
        p_size *= 2;
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