#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    PmergeMe pme;
    if (argc == 1)
    {
        std::cout << "Error: must input at least 1(one) number" << std::endl;
        return 1;
    }
    --argc; ++argv;

    std::clock_t vector_start = std::clock();
    std::vector <int> vect;
    pme.parse(argc, argv, vect);
    if (vect.empty())
        return 1;
    pme.sort(vect);
    std::clock_t vector_end = std::clock();
    double vector_time = static_cast<double>(vector_end - vector_start) / CLOCKS_PER_SEC * 1000000;

    std::clock_t deque_start = std::clock();
    std::deque <int> deq;
    pme.parse(argc, argv, deq);
    if (deq.empty())
        return 1;
    pme.sort(deq);
    std::clock_t deque_end = std::clock();
    double deque_time = static_cast<double>(deque_end - deque_start) / CLOCKS_PER_SEC * 1000000;

    std::deque<int> unsorted;
    pme.parse(argc, argv, unsorted);
    std::cout << "Before: ";
    pme.print_container(unsorted);
    std::cout << "After: ";
    pme.print_container(vect);
	std::cout << "Time to process a range of " << vect.size() << " elements with std::vector<int>: " << vector_time << " microseconds" << std::endl;
	std::cout << "Time to process a range of " << deq.size() << " elements with std::deque<int>: " << deque_time << " microseconds" << std::endl;
}