// #include <Array.hpp>
#include "iter.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

#define MAX_VAL 5

void add_one(int &c)
{
    c += 1;
}

void print(const int &x)
{
    std::cout << x << '\n';
}

void test_invalid_params()
{
    // array is NULL
    int *num = NULL;
    ::iter(num, 0, &print);

    // f is NULL
    int numbers[MAX_VAL];
    void (*f)(const int &) = 0;
    ::iter(numbers, MAX_VAL, f);
}

int main(void)
{
    int numbers[MAX_VAL];
    srand(time(NULL));
    // size_t len = MAX_VAL;
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int val = static_cast<int>(arc4random());
        numbers[i] = val;
        // numbers[i] = abs(val) % 26;
    }
    ::iter(numbers, MAX_VAL, &print);
    std::cout << "----------------------\n";
    ::iter(numbers, MAX_VAL, &add_one);
    ::iter(numbers, MAX_VAL, &print);
    std::cout << "----------------------\n";
    test_invalid_params();
    return 0;
}
