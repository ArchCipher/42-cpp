#include "PmergeMe.hpp"
#include <iostream>

/*
	Merge-insert sort algorithm to sort positive integers using 
	Ford-Johnson's algorithm.

	command to test with 3000 random numbers between 1 and 100000:
	./PmergeMe $(jot -r 3000 1 100000 | tr '\n' ' ')

	NOTE:
	Container   | lower_bound | insert | push_front | push_back |
	------------|-------------|--------|------------|------------|
	std::vector | O(log n) | O(n) | O(n) | amortised O(1) |
	std::deque  | O(log n) | O(n) | O(1) | O(1) |

	std::vector is better for random access (better cache locality).
	std::deque is better for insertion at the beginning.
	Ford-Johnson's algorithm uses many middle insertions,
	so push_front advantage is insignificant.
*/

int main(int ac, char **av)
{
    if (ac == 1)
    {
        std::cout << "Usage: ./PmergeMe 3 5 9 7 42\n";
        return 1;
    }
    PmergeMe c(ac - 1);
    try
    {
        c.sortContainers(av + 1);
    }
    catch (const std::exception &)
    {
        std::cerr << "Error\n";
        return 1;
    }
}
