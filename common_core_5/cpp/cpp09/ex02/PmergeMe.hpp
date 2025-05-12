#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <deque>

class PmergeMe {
    private:
        std::vector<int> vect;
        std::deque<int> deq;
    public:
        PmergeMe();
        PmergeMe(const PmergeMe &copy);
        PmergeMe &operator=(const PmergeMe &copy);
        ~PmergeMe();
        bool parse_vector(int argc, char **argv);
        void sort_vector();
        void print_vector();
};

#endif