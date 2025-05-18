#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <deque>

class PmergeMe {
    private:
    public:
        PmergeMe();
        PmergeMe(const PmergeMe &copy);
        PmergeMe &operator=(const PmergeMe &copy);
        ~PmergeMe();
        void parse(int argc, char **argv, std::vector<int> &vect);
        void parse(int argc, char **argv, std::deque<int> &deq);
        void print_container(std::vector <int> vect);
        void print_container(std::deque <int> deq);
        void insert(std::vector<int> &main, std::vector<int> &pend, int odd, std::vector<int> &left, std::vector<int> &vect, bool is_odd, int order);
        void insert(std::deque<int> &main, std::deque<int> &pend, int odd, std::deque<int> &left, std::deque<int> &deq, bool is_odd, int order);
        void sort(std::vector<int> &vect);
        void sort(std::deque<int> &deq);

};

#endif