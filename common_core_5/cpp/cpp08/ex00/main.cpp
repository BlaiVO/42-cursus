#include <iostream>
#include <vector>
#include <deque>
#include "easyfind.hpp"

int main()
{
    std::vector<int> v;
    v.push_back(3);
    v.push_back(42);
    v.push_back(12);
    v.push_back(-66);
    v.push_back(1);

    std::deque<int> deq;
    deq.push_back(3);
    deq.push_back(42);
    deq.push_back(12);
    deq.push_back(-66);
    deq.push_back(1);

    std::cout << "looking for 1 in std::vector: " << *easyfind(v, 1) << std::endl;
    std::cout << "looking for 1 in std::deque: " <<*easyfind(deq, 1) << std::endl;
    try {
        std::cout << "looking for 86 in std::vector: " << *easyfind(v, 86) << std::endl;
    } catch (std::logic_error) {
        std::cout << "86 not found" << std:: endl;
    }
    try {
     std::cout << "looking for 86 in std::deque: " << *easyfind(deq, 86) << std::endl;
    } catch (std::logic_error) {
        std::cout << "86 not found" << std:: endl;
    }

}
