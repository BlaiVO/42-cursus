#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <chrono>
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
    if (!pme.parse_vector(argc, argv))
        return 1;
    pme.print_vector();
    pme.sort_vector();
    pme.print_vector();
}