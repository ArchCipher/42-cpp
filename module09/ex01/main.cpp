#include "RPN.hpp"
#include <iostream>

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Usage: ./RPN \"7 7 * 7 -\"\n";
        return 1;
    }
    try
    {
		RPN rpn;
        int res = rpn.evaluate(av[1]);
        std::cout << res << '\n';
    }
    catch (const std::exception &)
    {
        std::cerr << "Error\n";
		return 1;
    }
}
