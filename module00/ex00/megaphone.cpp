#include <iostream>

using std::cout;

static void print_arg(std::string s);

int         main(int ac, char **av)
{
    size_t i;

    if (ac == 1)
    {
        cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
        return (0);
    }
    i = 1;
    while (av[i])
    {
        print_arg(av[i]);
        i++;
        if (av[i])
            cout << " ";
    }
    cout << "\n";
}

static void print_arg(std::string s)
{
    size_t i;
    size_t len;

    i = 0;
    len = s.length();
    while (i < len)
    {
        if (std::islower(static_cast<unsigned char>(s[i])))
            s[i] = std::toupper(static_cast<unsigned char>(s[i]));
        i++;
    }
    cout << s;
}

/*

// using for loop instead of while

int main(int ac, char **av)
{
    std::string s;
    int         i;
    size_t      j;
    size_t      len;

    if (ac == 1)
    {
        cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
        return (0);
    }
    i = 1;
    for (i = 1; i < ac; i++)
    {
        s = av[i];
        len = s.length();
        for (j = 0; j < len; j++)
        {
            if (std::islower(static_cast<unsigned char>(s[j])))
                s[j] = std::toupper(static_cast<unsigned char>(s[j]));
        }
        cout << s;
        if (i + 1 < ac)
            cout << " ";
    }
    cout << "\n";
}
*/