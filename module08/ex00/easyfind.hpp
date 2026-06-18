#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <stdexcept>

/*
    function template easyfind that accepts a type T. It takes two parameters:
    the first one is of type T, and the second one is an integer.
    Assuming T is a container of integers, this function finds the first
        occurrence of the second parameter in the first parameter.
    If no occurrence is found, you can either throw an exception or return an
        error value of your choice. If you need some inspiration, analyze how
        standard containers behave. You don’t have to handle associative
   containers.

        NOTE:
        - Sequence containers: array, vector, deque, forward_list, list
        - Associative containers: set, map, multiset, multimap
        - Container adaptors: stack, queue, priority_queue, flag_set,
            flag_map, flag_multiset, flag_multimap
        - Unordered associative containers: unordered_set, unordered_map,
            unordered_multiset, unordered_multimap
*/

template <typename T>
typename T::const_iterator easyfind(const T &numbers, const int &num)
{
    typename T::const_iterator it =
        std::find(numbers.begin(), numbers.end(), num);
    if (it == numbers.end())
        throw std::runtime_error("element not found");
    return it;
}

#endif
