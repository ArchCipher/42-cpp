#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <deque>
#include <iostream>
#include <string>
#include <vector>

typedef struct s_dq_parts
{
    std::deque<std::pair<int, int> > pairs;
    bool                             has_odd;
    int                              odd;
} t_dq_parts;

typedef struct s_vec_parts
{
    std::vector<std::pair<int, int> > pairs;
    bool                              has_odd;
    int                               odd;
} t_vec_parts;

class PmergeMe
{
    int                        n;
    std::vector<int>           initialLst; // first 5 nums for printing Before
    t_vec_parts                vec;
    t_dq_parts                 dq;

    void                       fillContainers(char **av);
    static std::deque<int>     sortDequeBigs(t_dq_parts &dq);
    static std::vector<int>    sortVecBigs(t_vec_parts &vec);
    static std::vector<size_t> jacobsthalOrder(size_t n);

    template <typename T>
    static void print(const std::string &s, const T &chain, size_t total)
    {
        std::cout << s;
        size_t size = total;
        if (total > 5)
            size = 4;
        for (size_t i = 0; i < size; i++)
        {
            std::cout << chain[i];
            if (i != size - 1)
                std::cout << ' ';
        }
        if (total > 5)
            std::cout << " [...]";
        std::cout << '\n';
    }

  public:
    ~PmergeMe(){};
    PmergeMe(int i);
    void sortContainers(char **av);
};

#endif
