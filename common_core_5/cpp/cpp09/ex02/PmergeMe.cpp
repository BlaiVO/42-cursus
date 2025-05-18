#include <iostream>
#include <cstdlib>
#include <climits>
#include <algorithm>
#include <cmath>
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

void PmergeMe::parse(int argc, char **argv, std::vector<int> &vect)
{
    char* p;

    for (int i = 0; i < argc; i++)
    {
        long current = strtol(argv[i], &p, 10);
        if (*p || current < 0 || current > INT_MAX)
        {
            std::cout << "Error: all inputs must be positive integers" << std::endl;
            vect = std::vector<int>();
            return;
        }
        if (std::find(vect.begin(), vect.end(), static_cast<int>(current)) != vect.end())
        {
            std::cout << "Error: all numbers must be unique" << std::endl;
            vect = std::vector<int>();
            return;
        }
        vect.push_back(static_cast<int>(current));
    }
}

void PmergeMe::parse(int argc, char **argv, std::deque<int> &deq)
{
    char* p;

    for (int i = 0; i < argc; i++)
    {
        long current = strtol(argv[i], &p, 10);
        if (*p || current < 0 || current > INT_MAX)
        {
            std::cout << "Error: all inputs must be positive integers" << std::endl;
            return;
        }
        if (std::find(deq.begin(), deq.end(), static_cast<int>(current)) != deq.end())
        {
            std::cout << "Error: all numbers must be unique" << std::endl;
            return;
        }
        deq.push_back(static_cast<int>(current));
    }
}

void PmergeMe::print_container(std::vector <int> vect){
    for (unsigned long i = 0; i < vect.size(); i++)
    {
        std::cout << vect[i];
        if (i != vect.size() - 1)
            std::cout << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::print_container(std::deque <int> deq){
    for (unsigned long i = 0; i < deq.size(); i++)
    {
        std::cout << deq[i];
        if (i != deq.size() - 1)
            std::cout << " ";
    }
    std::cout << std::endl;
}


int Jacobsthal(int k)
{
    return round((pow(2, k + 1) + pow(-1, k)) / 3);
}

void PmergeMe::insert(std::vector<int> &main, std::vector<int> &pend, int odd, std::vector<int> &left, std::vector<int> &vect, bool is_odd, int order)
{
    std::vector<int>::iterator end;

    if (pend.size() == 1) {
        end = std::upper_bound(main.begin(), main.end(), *pend.begin());
        main.insert(end, *pend.begin());
    } else if (pend.size() > 1) {
        size_t jc = 3;
        size_t count = 0;
        size_t idx;
        size_t decrease;

        while (!pend.empty()) {
            idx = Jacobsthal(jc) - Jacobsthal(jc-1);
            if (idx > pend.size())
                idx = pend.size();

            decrease = 0;
            while (idx) {
                end = main.begin();
                if (Jacobsthal(jc + count) - decrease <= main.size())
                    end = main.begin() + Jacobsthal(jc + count) - decrease;
                else
                    end = main.end();
                end = std::upper_bound(main.begin(), end, *(pend.begin() + idx - 1));
                main.insert(end, *(pend.begin() + idx - 1));
                pend.erase(pend.begin() + idx -1);

                idx--;
                decrease++;
                count++;
            }
            jc++;
        }
    }

    std::vector<int> yaslam;

    if (is_odd) {
        end = std::upper_bound(main.begin(), main.end(), odd);
        main.insert(end, odd);
    }
    for (std::vector<int>::iterator i = main.begin(); i != main.end(); i++) {
        std::vector<int>::iterator it = std::find(vect.begin(), vect.end(), *i);
        yaslam.insert(yaslam.end(), it - (order - 1), it + 1);
    }
    yaslam.insert(yaslam.end(), left.begin(), left.end());
    vect = yaslam;
}

void PmergeMe::insert(std::deque<int> &main, std::deque<int> &pend, int odd, std::deque<int> &left, std::deque<int> &deq, bool is_odd, int order)
{
    std::deque<int>::iterator end;

    if (pend.size() == 1) {
        end = std::upper_bound(main.begin(), main.end(), *pend.begin());
        main.insert(end, *pend.begin());
    } else if (pend.size() > 1) {
        size_t jc = 3;
        size_t count = 0;
        size_t idx;
        size_t decrease;

        while (!pend.empty()) {
            idx = Jacobsthal(jc) - Jacobsthal(jc-1);
            if (idx > pend.size())
                idx = pend.size();

            decrease = 0;
            while (idx) {
                end = main.begin();
                if (Jacobsthal(jc + count) - decrease <= main.size())
                    end = main.begin() + Jacobsthal(jc + count) - decrease;
                else
                    end = main.end();
                end = std::upper_bound(main.begin(), end, *(pend.begin() + idx - 1));
                main.insert(end, *(pend.begin() + idx - 1));
                pend.erase(pend.begin() + idx -1);

                idx--;
                decrease++;
                count++;
            }
            jc++;
        }
    }

    std::deque<int> yaslam;

    if (is_odd) {
        end = std::upper_bound(main.begin(), main.end(), odd);
        main.insert(end, odd);
    }
    for (std::deque<int>::iterator i = main.begin(); i != main.end(); i++) {
        std::deque<int>::iterator it = std::find(deq.begin(), deq.end(), *i);
        yaslam.insert(yaslam.end(), it - (order - 1), it + 1);
    }
    yaslam.insert(yaslam.end(), left.begin(), left.end());
    deq = yaslam;
}

void PmergeMe::sort(std::vector<int> &vect)
{
    static int order = 1;
    int unit_size = vect.size() / order;

    if (unit_size < 2)
        return;

    bool is_odd = unit_size % 2 == 1;
    std::vector<int>::iterator start = vect.begin();
    std::vector<int>::iterator end = vect.begin() + ((order * unit_size) - (is_odd * order));

    for (std::vector<int>::iterator it = start; it < end; it += (order * 2)) {
        if (*(it + (order - 1)) > *(it + ((order * 2) - 1))) {
            for (int i = 0; i < order; i++) {
                std::swap(*(it + i), *(it + i + order));
            }
        }
    }
    order *= 2;
    sort(vect);
    order /= 2;

    std::vector<int> main;
    std::vector<int> pend;
    int odd = 0;
    std::vector<int> left;

    main.push_back(*(start + order -1));
    main.push_back(*(start + order * 2 - 1));

    for (std::vector<int>::iterator it = start + order * 2; it < end; it += order)
    {
        pend.push_back(*(it + order - 1));
        it += order;
        main.push_back(*(it + order -1));
    }

    if (is_odd)
        odd = *(end + order - 1);

    left.insert(left.end(), end + (order * is_odd), vect.end());

    if (is_odd || !pend.empty())
        insert(main, pend, odd, left, vect, is_odd, order);
}

void PmergeMe::sort(std::deque<int> &deq)
{
    static int order = 1;
    int unit_size = deq.size() / order;

    if (unit_size < 2)
        return;

    bool is_odd = unit_size % 2 == 1;
    std::deque<int>::iterator start = deq.begin();
    std::deque<int>::iterator end = deq.begin() + ((order * unit_size) - (is_odd * order));

    for (std::deque<int>::iterator it = start; it < end; it += (order * 2)) {
        if (*(it + (order - 1)) > *(it + ((order * 2) - 1))) {
            for (int i = 0; i < order; i++) {
                std::swap(*(it + i), *(it + i + order));
            }
        }
    }
    order *= 2;
    sort(deq);
    order /= 2;

    std::deque<int> main;
    std::deque<int> pend;
    int odd = 0;
    std::deque<int> left;

    main.push_back(*(start + order -1));
    main.push_back(*(start + order * 2 - 1));

    for (std::deque<int>::iterator it = start + order * 2; it < end; it += order)
    {
        pend.push_back(*(it + order - 1));
        it += order;
        main.push_back(*(it + order -1));
    }

    if (is_odd)
        odd = *(end + order - 1);

    left.insert(left.end(), end + (order * is_odd), deq.end());

    if (is_odd || !pend.empty())
        insert(main, pend, odd, left, deq, is_odd, order);
}