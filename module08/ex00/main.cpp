#include "easyfind.hpp"
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <iostream>
#include <iterator>
#include <vector>

#define MAX_VAL 5
#define FT 42

/*
    REFERENCE:
        [C++ containers]
    (https://www.youtube.com/watch?v=LWpYKFzkc8U)
    [C++ iterators]
        (https://www.youtube.com/watch?v=SgcHcbQ0RCQ)
*/

int generator()
{
    const uint32_t val = arc4random() % 100;
    return (static_cast<int>(val));
}

template <typename T> void print(const T &nums)
{
    for (typename T::const_iterator it = nums.begin(); it != nums.end(); ++it)
        std::cout << *it << '\n';
}

template <typename T> void test_easyfind(const T &nums, int a)
{
    print(nums);
    try
    {
        typename T::const_iterator it = ::easyfind(nums, a);
        std::cout << "element found: " << *it << '\n';
        for (; it != nums.end(); ++it)
            std::cout << *it << '\n';
    }
    catch (const std::runtime_error &e)
    {
        std::cout << e.what() << '\n';
    }
}

int main(void)
{
    srand(time(NULL));
    std::cout << "-----test with vector-----\n";
    std::vector<int> nums;
    std::generate_n(std::back_insert_iterator<std::vector<int> >(nums), MAX_VAL,
                    generator);
    test_easyfind(nums, FT);
    std::cout << "-----test with deque-----\n";
    std::deque<int> d;
    std::generate_n(std::back_insert_iterator<std::deque<int> >(d), MAX_VAL,
                    generator);
    test_easyfind(d, FT);
    return 0;
}
