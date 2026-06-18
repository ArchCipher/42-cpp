#include "Span.hpp"
#include <iostream>

/*
    reserving space in constructor as n is known -> avoids reallocation.
*/
Span::Span(unsigned int n) : maxSize(n)
{
    nums.reserve(n);
}

Span::Span(const Span &copy) : nums(copy.nums), maxSize(copy.maxSize) {}

/*
    copy assignment operator is allowed only when maxSize is the same.
*/
Span &Span::operator=(const Span &copy)
{
    if (this != &copy)
    {
        if (maxSize != copy.maxSize)
            throw std::logic_error(
                "cannot assign Spans with different max sizes");
        nums = copy.nums;
    }
    return (*this);
}

const std::vector<int> &Span::getVector() const
{
    return (nums);
}

/*
    std::adjacent_difference could be used instead, but this would mean creating
        a new vector to store the differences, and scanning it to find the
   shortest difference which is not efficient. Also, if numbers can repeat,
   stopping at the first difference of 0 makes it more efficient.
*/
unsigned int Span::shortestSpan()
{
    if (nums.size() < 2)
        throw std::logic_error("less than 2 elements\n");
    std::sort(nums.begin(), nums.end());
    unsigned int shortest = UINT_MAX;
    for (std::vector<int>::const_iterator it = nums.begin();
         it != nums.end() - 1; it++)
    {
        unsigned int diff = *(it + 1) - *it;
        if (diff == 0)
            return (diff);
        shortest = std::min(diff, shortest);
    }
    return shortest;
}

unsigned int Span::longestSpan()
{
    if (nums.empty() || nums.size() == 1)
        throw std::logic_error("less than 2 elements\n");
    return (*std::max_element(nums.begin(), nums.end()) -
            *std::min_element(nums.begin(), nums.end()));
}

/*
    NOTE:
        Could use nums.capacity() instead of bookkeeping maxSize.
        But safer to store and use maxSize as a constant value.
*/
void Span::addNumber(int num)
{
    if (nums.size() >= maxSize)
        throw std::out_of_range("addNumber: reached max capacity");
    nums.push_back(num);
}

std::ostream &operator<<(std::ostream &out, const Span &s)
{
    const std::vector<int> &nums = s.getVector();
    for (std::vector<int>::const_iterator it = nums.begin(); it != nums.end();
         ++it)
    {
        out << *it;
        if (it != nums.end() - 1)
            out << ", ";
    }
    return (out);
}
