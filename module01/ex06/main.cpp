#include "Harl.hpp"

using std::cout;

int main(int ac, char **av)
{
    if (ac != 2)
    {
        cout << "Usage: ./harFilter level\n";
        return (0);
    }
    Harl harl;
    harl.complain(av[1]);
}
