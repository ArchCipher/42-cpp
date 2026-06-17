#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>

/*
    class template Array that contains elements of type T and that implements
    the following behavior and functions:
    • Construction with no parameter: Creates an empty array.
    • Construction with an unsigned int n as a parameter: Creates an array of n
    elements initialized by default. Tip: Try to compile int * a = new int();
    then display *a. Value initialised to 0: Array(unsigned int n) : arr(new
    T[n]()), n(n) {} By default, the array is garbage value(??) or 0?. Without
    this valgrind will show errors, but subject requires initialised to default.
    • You MUST use the operator new[] to allocate memory.
        Preventive allocation (allocating memory in advance) is forbidden.
        Your program must never access non-allocated memory.
    • Elements can be accessed through the subscript operator: [ ].
    • When accessing an element with the [ ] operator, if its index is out of
        bounds, an std::out_of_range exception is thrown.
    • A member function size() that returns the number of elements in the array.
    This member function takes no parameters and must not modify the current
    instance.

    NOTE:
    copy assignment creates a new array with copy constructor, then swaps with
    the current array. The swapped tmp array is deleted by the destructor when
    the scope ends.
    This is the same behavior as creating a new allocated array, copying values
    and deleting the current array. But this is safer than the first approach
    because it doesn't require to manually delete the current array.
*/

template <typename T> class Array
{
    T           *arr;
    unsigned int n;

    void         swap(Array &other)
    {
        T *tmp = arr;
        arr = other.arr;
        other.arr = tmp;
        unsigned int tmp_n = n;
        n = other.n;
        other.n = tmp_n;
    }

  public:
    ~Array()
    {
        delete[] arr;
    }

    Array() : arr(0), n(0) {}

    Array(unsigned int n) : arr(new T[n]), n(n) {}

    Array(const Array &copy) : arr(new T[copy.n]), n(copy.n)
    {
        for (unsigned int i = 0; i < n; i++)
            arr[i] = copy.arr[i];
    }

    Array &operator=(const Array &copy)
    {
        if (this != &copy)
        {
            Array other(copy);
            swap(other);
        }
        return (*this);
    }

    T &operator[](unsigned int idx)
    {
        if (idx >= n)
            throw std::out_of_range("out of bounds access in Array<T>");
        return arr[idx];
    }

    const T &operator[](unsigned int idx) const
    {
        if (idx >= n)
            throw std::out_of_range("out of bounds access in Array<T>");
        return arr[idx];
    }

    unsigned int size() const
    {
        return n;
    }
};

#endif
