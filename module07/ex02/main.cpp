#include "Array.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

#define MAX_VAL 750
#define MAX_SIZE 10
#define FT 42

bool test_copy_assignment()
{
    Array<int> a(MAX_SIZE / 2);
    Array<int> b(MAX_SIZE);

    for (unsigned int i = 0; i < b.size(); i++)
    {
        const int value = static_cast<int>(std::rand());
        if (i < a.size())
            a[i] = value;
        b[i] = value;
    }
    a = b;
    if (a.size() != b.size() || a[0] != b[0])
    {
        std::cerr << "assignment test failed\n";
        return 1;
    }
    b[0] = FT;
    a[0] = 0;
    if (b[0] != FT)
    {
        std::cerr << "deep copy test failed\n";
        return 1;
    }
    // below should not compile as this is const
    // const Array<int> c(10);
    // c[0] = 42;
    return 0;
}

// NOLINTNEXTLINE(bugprone-exception-escape)
int main(void)
{
    if (test_copy_assignment())
        return 1;

    Array<int> numbers(MAX_VAL);
    int       *mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = static_cast<int>(std::rand());
        numbers[i] = value;
        mirror[i] = value;
    }
    // SCOPE
    Array<int> tmp = numbers;
    Array<int> test(tmp); // NOLINT(performance-unnecessary-copy-initialization)

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i] || tmp[i] != numbers[i] ||
            test[i] != tmp[i])
        {
            std::cerr << "didn't save the same value!!\n";
            delete[] mirror;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    delete[] mirror; //
    return 0;
}
