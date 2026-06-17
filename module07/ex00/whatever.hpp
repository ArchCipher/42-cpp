#ifndef WHATEVER_HPP
#define WHATEVER_HPP

/*
    • swap: Swaps the values of two given parameters. Does not return anything.
    • min: Compares the two values passed as parameters and returns the smallest
    one. If they are equal, it returns the second one.
    • max: Compares the two values passed as parameters and returns the greatest
    one. If they are equal, it returns the second one.

    REFERENCE:
        [Templates in C++](https://www.youtube.com/watch?v=I-hZkUa9mIs)
*/

// NOLINTNEXTLINE(bugprone-exception-escape)
template <typename T> void swap(T &a, T &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

/*
    T min(T &a, T &b) -> will fail if one arg is const and other isn't
*/
template <typename T> T min(const T &a, const T &b)
{
    if (a < b)
        return a;
    return b;
}

template <typename T> T max(const T &a, const T &b)
{
    if (a > b)
        return a;
    return b;
}

#endif
