#include "PmergeMe.hpp"
#include <algorithm>
#include <cerrno>
#include <climits>
#include <cstdlib> // std::strtol
#include <exception>
#include <sys/time.h>

static t_vec_parts split_vec(std::vector<std::pair<int, int> > &pairs);
static t_dq_parts  split_deque(std::deque<std::pair<int, int> > &pairs);
static bool        cmp_by_first(const std::pair<int, int> &a,
                                const std::pair<int, int> &b);
static int         get_num(const char *s);
static long        get_time();

PmergeMe::PmergeMe(int n) : n(n)
{
    vec.pairs.reserve(n / 2);
    vec.has_odd = false;
    dq.has_odd = false;
}

void PmergeMe::sortContainers(char **av)
{
    fillContainers(av);
    long             t0 = get_time();
    std::vector<int> vec_chain = sortVecBigs(vec);
    long             t1 = get_time();
    long             vec_time = t1 - t0;
    t0 = get_time();
    std::deque<int> dq_chain = sortDequeBigs(dq);
    t1 = get_time();
    if (vec_chain.size() != dq_chain.size())
    {
        std::cerr << "Error: sort failed\n";
        return;
    }
    print("Before: ", initialLst, n);
    print("After:  ", vec_chain, n);
    std::cout << "Time to process a range of " << vec_chain.size()
              << " elements with std::vector : " << vec_time << " µs\n"
              << "Time to process a range of " << dq_chain.size()
              << " elements with std::deque  : " << t1 - t0 << " µs\n";
}

void PmergeMe::fillContainers(char **av)
{
    while (*av)
    {
        int big = get_num(*av);
        av++;
        if (initialLst.size() < 5)
            initialLst.push_back(big);
        if (!*av)
        {
            vec.has_odd = true;
            vec.odd = big;
            dq.has_odd = true;
            dq.odd = big;
            break;
        }
        int small = get_num(*av);
        av++;
        if (initialLst.size() < 5)
            initialLst.push_back(small);
        if (big < small)
            std::swap(big, small);
        std::pair<int, int> pair = std::make_pair(big, small);
        dq.pairs.push_back(pair);
        vec.pairs.push_back(pair);
    }
}

/*
	Recursively split into pairs and sort bigs.
	Free insert the smallest small to the beginning.
	Insert the rest of the smalls in Jacobsthal order.

	NOTE:
	Ford-Johnson can bound search up to paired big as code below,
	but use one lower_bound binary search for speed.
	std::vector<int>::iterator bound =
	    std::lower_bound(chain.begin(), chain.end(), vec.pairs[order[i]].first);
	std::vector<int>::iterator pos =
	    std::lower_bound(chain.begin(), bound, vec.pairs[order[i]].second);
	chain.insert(pos, vec.pairs[order[i]].second);
*/
std::vector<int> PmergeMe::sortVecBigs(t_vec_parts &vec)
{
    std::vector<int> chain;
    if (vec.pairs.size() == 1)
    {
        chain.push_back(vec.pairs[0].second);
        chain.push_back(vec.pairs[0].first);
    }
    else if (vec.pairs.size() > 1)
    {
        t_vec_parts parts = split_vec(vec.pairs);
        chain = sortVecBigs(parts);
        std::sort(vec.pairs.begin(), vec.pairs.end(), cmp_by_first);
        chain.insert(chain.begin(), vec.pairs[0].second); // free insert
        std::vector<size_t> order = jacobsthalOrder(vec.pairs.size());
        for (size_t i = 0; i < order.size(); i++)
        {
            std::vector<int>::iterator pos = std::lower_bound(
                chain.begin(), chain.end(), vec.pairs[order[i]].second);
            chain.insert(pos, vec.pairs[order[i]].second);
        }
    }
    if (vec.has_odd)
    {
        std::vector<int>::const_iterator pos =
            std::lower_bound(chain.begin(), chain.end(), vec.odd);
        chain.insert(pos, vec.odd);
    }
    return chain;
}

std::deque<int> PmergeMe::sortDequeBigs(t_dq_parts &dq)
{
    std::deque<int> chain;
    if (dq.pairs.size() == 1)
    {
        chain.push_back(dq.pairs[0].second);
        chain.push_back(dq.pairs[0].first);
    }
    else if (dq.pairs.size() > 1)
    {
        t_dq_parts parts = split_deque(dq.pairs);
        chain = sortDequeBigs(parts);
        std::sort(dq.pairs.begin(), dq.pairs.end(), cmp_by_first);
        chain.push_front(dq.pairs[0].second); // free insert
        std::vector<size_t> order = jacobsthalOrder(dq.pairs.size());
        for (size_t i = 0; i < order.size(); i++)
        {
            std::deque<int>::iterator pos = std::lower_bound(
                chain.begin(), chain.end(), dq.pairs[order[i]].second);
            chain.insert(pos, dq.pairs[order[i]].second);
        }
    }
    if (dq.has_odd)
    {
        std::deque<int>::const_iterator pos =
            std::lower_bound(chain.begin(), chain.end(), dq.odd);
        chain.insert(pos, dq.odd);
    }
    return chain;
}

/*
	Build jacobsthal number and order

	jacobsthal numbers: J(n) = J(n-1) + 2 * J(n-2)
	J(0) = 0 and J(1) = 1 are seeded manually
	jacobsthal numbers: 0 1 1 3 5 11 21 43

	jacobsthal order: (1) () (3 2) (4 5) (11 10 9 8 7 6) (21... 12) (43... 22)
	For each group, the numbers are inserted in reverse order.
	For example, where n is the number of pairs:
	1. n = 4, the order is 1 3 2 4 5
		as 5 is greater than 4, it becomes 1 3 2 4
		for 0 based index, free insert: 0, order: 2, 1, 3
	2. n = 2, the order is 1 3 2
		as 3 is greater than 2, it becomes 1 2
		for 0 based index, free insert: 0, order: 1
*/
std::vector<size_t> PmergeMe::jacobsthalOrder(size_t n)
{
    std::vector<size_t> order;
    if (n <= 1)
        return order;
    size_t              first_two[] = {0, 1};
    std::vector<size_t> jac;
    jac.insert(jac.begin(), first_two, first_two + 2);
    while (jac.back() < n)
        jac.push_back(jac[jac.size() - 1] + 2 * jac[jac.size() - 2]);
    for (size_t i = 2; i < jac.size(); ++i)
    {
        size_t jac_num = std::min(jac[i], n);
        for (size_t j = jac_num; j > jac[i - 1]; --j)
            order.push_back(j - 1);
    }
    return order;
}

t_vec_parts split_vec(std::vector<std::pair<int, int> > &pairs)
{
    t_vec_parts d;
    d.has_odd = false;
    for (size_t i = 0; i < pairs.size(); i += 2)
    {
        if (i + 1 == pairs.size())
        {
            d.has_odd = true;
            d.odd = pairs[i].first;
            return d;
        }
        int big = pairs[i].first;
        int small = pairs[i + 1].first;
        if (big < small)
            std::swap(big, small);
        d.pairs.push_back(std::make_pair(big, small));
    }
    return d;
}

/*
	version using iterator:
	std::deque<std::pair<int, int> >::const_iterator it = pairs.begin();
        it != pairs.end(); it += 2)
    {
        if (std::next(it) == pairs.end())
		...
			d.odd = it->first;
		...
		int big = it->first;
        int small = (it + 1)->first;
	
	Using index makes it simpler. std::list cannot be indexed and would need
	iterators to access elements. it += 2 doesn't work for list as random access
	is not allowed for list.
*/
static t_dq_parts split_deque(std::deque<std::pair<int, int> > &pairs)
{
    t_dq_parts d;
    d.has_odd = false;
    for (size_t i = 0; i < pairs.size(); i += 2)
    {
        if (i + 1 == pairs.size())
        {
            d.has_odd = true;
            d.odd = pairs[i].first;
            return d;
        }
        int big = pairs[i].first;
        int small = pairs[i + 1].first;
        if (big < small)
            std::swap(big, small);
        d.pairs.push_back(std::make_pair(big, small));
    }
    return d;
}

static bool cmp_by_first(const std::pair<int, int> &a,
                         const std::pair<int, int> &b)
{
    return (a.first < b.first);
}

static int get_num(const char *s)
{
    if (*s < '1' || *s > '9')
        throw std::exception();
    char *p = NULL;
    errno = 0;
    long i = std::strtol(s, &p, 10);
    if (errno || *p || i > INT_MAX)
        throw std::exception();
    return static_cast<int>(i);
}

static long get_time()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return ((long)tv.tv_sec * 1e6) + tv.tv_usec;
}
