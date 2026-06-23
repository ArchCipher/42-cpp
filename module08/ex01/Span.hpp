#ifndef SPAN_HPP
#define SPAN_HPP
#include <algorithm>
#include <climits>
#include <iosfwd> // io stream forward declarations
#include <stdexcept>
#include <vector>

/*
    Develop a Span class that can store a maximum of N integers. N is an
        unsigned int variable and will be the only parameter passed to the
        constructor.
    member functions:
          addNumber() to add a single number to the Span.
          addRange() to add a range of numbers to the Span.
        These member functions will be used in order to fill the Span. Any
   attempt to add a new element if there are already N elements stored should
   throw an exception. shortestSpan() to find the shortest span between all the
   numbers stored. longestSpan() to find the longest span between all the
   numbers stored.

        REFERENCE:
    [C++ iterators: range access](https://www.youtube.com/watch?v=vd_pyrxDtNQ)
*/

class Span
{
    std::vector<int>   nums;
    // NOLINTNEXTLINE(cppcoreguidelines-avoid-const-or-ref-data-members)
    const unsigned int maxSize;

  public:
    ~Span() {};
    Span(unsigned int n);
    Span(const Span &copy);
    Span                             &operator=(const Span &copy);

    const std::vector<int>           &getVector() const;
    unsigned int                      shortestSpan();
    unsigned int                      longestSpan();
    void                              addNumber(int num);

    template <typename Iterator> void addRange(Iterator first, Iterator last)
    {
        std::ptrdiff_t dist = std::distance(first, last);
        if (dist < 0)
            throw std::invalid_argument("addrange: invalid range");
        if (dist > UINT_MAX ||
            maxSize - nums.size() < static_cast<unsigned int>(dist))
            throw std::out_of_range("addRange: reached max capacity");
        nums.insert(nums.end(), first, last);
    }
};

std::ostream &operator<<(std::ostream &out, const Span &s);

#endif
