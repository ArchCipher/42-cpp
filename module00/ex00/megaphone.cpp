#include <iostream>

using std::cout;

int main(int ac, char **av)
{
    if (ac == 1)
    {
        cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
        return (0);
    }
    std::string s;
    size_t      len = 0;
    for (int i = 1; i < ac; i++)
    {
        s = av[i];
        len = s.length();
        for (size_t j = 0; j < len; j++)
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
