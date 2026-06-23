// #include <Array.hpp>
#include "Span.hpp"
#include <cstdlib>
#include <ctime>
#include <deque>
#include <iostream>

#define MAX_VAL 100000
#define MIN_VAL 20
#define FT 42

void test_assignment()
{
    Span a(3);
    Span b(3);
    Span c(4);
    int  arr1[] = {1, 2, 3, 4};
    int  arr2[] = {3, 2, 1};
    try
    {
        a.addRange(arr1, arr1 + 3);
        b.addRange(arr2, arr2 + 3);
        c.addRange(arr1, arr1 + 4);
    }
    catch (const std::exception &e)
    {
        std::cout << "test_assignment ERROR" << e.what() << '\n';
    }
    std::cout << "-----test copy assignment-----\n"
              << "a: " << a << '\n'
              << "b: " << b << '\n'
              << "c: " << c << "\n\n";
    a = b;
    std::cout << "a = b\n"
              << "a: " << a << '\n'
              << "b: " << b << "\n\n";
    try
    {
        std::cout << "a = c\n";
        a = c;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << '\n';
    }
    Span d(a);
    std::cout << "-----test copy constructor-----\n"
              << "a: " << a << '\n'
              << "d: " << d << '\n';
}

void test_max_size(Span &nums)
{
    int arr[] = {1, 2, 3, 4};
    std::cout << "-----test max size-----\n";
    std::cout << "nums size: " << nums.getVector().size() << '\n';
    try
    {
        nums.addNumber(FT);
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << '\n';
    }
    try
    {
        nums.addRange(arr, arr + 4);
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << '\n';
    }
}

void test_add_range()
{
    std::cout << "-----test add range-----\n";
    Span a(MIN_VAL);
    std::cout << "a: " << a << '\n';
    int             arr[] = {1, 2, 3, 4};
    std::deque<int> b(3, 3);
    try
    {
        a.addRange(arr, arr + 4);
        std::cout << "add range from array\n"
                  << "a: " << a << '\n';
        a.addRange(b.begin(), b.end());
        std::cout << "add range from deque\n"
                  << "a: " << a << '\n';
    }
    catch (const std::exception &e)
    {
        std::cout << "test_aadd_range ERROR" << e.what() << '\n';
    }
    std::cout << "----test invalid range----\n";
    try
    {
        a.addRange(arr + 4, arr);
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << '\n';
    }
    std::cout << "-----test add number-----\n";
    a.addNumber(FT);
    std::cout << "a: " << a << '\n';
}

void test_spans(Span &nums)
{
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
        nums.addNumber(static_cast<int>(std::rand()) % MAX_VAL);
    std::cout << "-----test spans-----\n"
              << "nums size: " << nums.getVector().size() << '\n'
              << "shortest span: " << nums.shortestSpan() << '\n'
              << "longest span: " << nums.longestSpan() << '\n';
}

int main(void)
{
    Span nums(MAX_VAL);
    std::cout << "nums size: " << nums.getVector().size() << '\n';
    test_spans(nums);
    test_max_size(nums);
    test_add_range();
    test_assignment();
    return 0;
}
