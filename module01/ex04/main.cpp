#include <iostream>
#include <fstream>

using std::cout;
using std::string;

void copy_replace(std::ifstream &infile, std::ofstream &outfile, char *s1, char *s2)
{
    string s;
    size_t found;
    size_t len;
    size_t start;

    len = strlen(s1);
    std::getline(infile, s);
    while (!s.empty())
    {
        start = 0;
        found = s.find(s1);
        if (found != string::npos)
        {
            while (found != string::npos)
            {
                outfile << s.substr(start, found - start);
                outfile << s2;
                start = found + len;
                found = s.find(s1, found + len);
            }
            outfile << s.substr(start);
        }
        else
            outfile << s;
        if (!(std::getline(infile, s)))
            break ;
        outfile << std::endl;
    }
}

// https://cplusplus.com/doc/tutorial/files/
int main(int ac, char **av)
{
    string outfileName;

    if (ac != 4)
        return (0);
    if (!av[2][0])
        return (cout << "first RE may not be empty\n", 0);
    std::ifstream infile(av[1]);
    if (!infile.is_open())
    {
        cout << "Unable to open file\n";
        return (1);
    }
    outfileName = av[1];
    outfileName.append(".replace");
    std::ofstream outfile(outfileName);
    if (!outfile.is_open())
    {
        cout << "Unable to create a new file\n";
        infile.close();
        return (1);
    }
    copy_replace(infile, outfile, av[2], av[3]);
    infile.close();
    outfile.close();
}
