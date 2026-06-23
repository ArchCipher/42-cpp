#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

/*
    Implement a function template iter that takes 3 parameters and returns
   nothing.
   • The first parameter is the address of an array.
   • The second one is the length of the array, passed as a const value.
   • The third one is a function that will be called on every element of the
   array.

    Your iter function template must work with any type of array.
   The third parameter can be an instantiated function template. The function
   passed as the third parameter may take its argument by const reference or
   non-const reference, depending on the context.
*/

template <typename T, typename T2>
void iter(T *arr, const T2 &len, void (*f)(T &))
{
    if (!arr || !f)
    {
        std::cerr << "iter: arr or f is NULL\n";
        return;
    }
    for (T2 i = 0; i < len; i++)
        f(arr[i]); // NOLINT(cppcoreguidelines-pro-bounds-pointer-arithmetic)
}

template <typename T, typename T2>
void iter(const T *arr, const T2 &len, void (*f)(const T &))
{
    if (!arr || !f)
    {
        std::cerr << "iter: arr or f is NULL\n";
        return;
    }
    for (T2 i = 0; i < len; i++)
        f(arr[i]); // NOLINT(cppcoreguidelines-pro-bounds-pointer-arithmetic)
}

#endif
