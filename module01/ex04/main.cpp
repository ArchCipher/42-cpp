#include <fstream>
#include <iostream>

using std::cout;
using std::string;

void   replace_all(std::ifstream &infile, std::ofstream &outfile,
                   const string &searchStr, const string &replaceStr);
string replace_line(const string &line, const string &searchStr,
                    const string &replaceStr);

// https://cplusplus.com/doc/tutorial/files/
int    main(int ac, char **av)
{
    if (ac != 4)
        return (cout << "Usage: ./replace <input_file> <search_string> "
                        "<replacement_string>\n",
                0);
    string searchStr = av[2];
    if (searchStr.empty())
        return (cout << "first RE may not be empty\n", 0);
    string        infileName = av[1];
    std::ifstream infile(infileName);
    if (!infile.is_open())
    {
        cout << "Unable to open input file: " << infileName << "\n";
        return (1);
    }
    string        outfileName = infileName + ".replace";
    std::ofstream outfile(outfileName);
    if (!outfile.is_open())
    {
        cout << "Unable to open outfile file: " << outfileName << "\n";
        infile.close();
        return (1);
    }
    string replaceStr = av[3];
    replace_all(infile, outfile, searchStr, replaceStr);
    infile.close();
    outfile.close();
}

void replace_all(std::ifstream &infile, std::ofstream &outfile,
                 const string &searchStr, const string &replaceStr)
{
    string line;

    while (std::getline(infile, line))
    {
        outfile << replace_line(line, searchStr, replaceStr);
        if (!infile.eof())
            outfile << "\n";
    }
}

string replace_line(const string &line, const string &searchStr,
                    const string &replaceStr)
{
    size_t found = line.find(searchStr);
    if (found == string::npos)
        return line;

    size_t start = 0;
    string replaced_line;
    size_t searchStrLen = searchStr.length();
    while (found != string::npos)
    {
        replaced_line.append(line, start, found - start);
        replaced_line.append(replaceStr);
        start = found + searchStrLen;
        found = line.find(searchStr, start);
    }
    replaced_line.append(line, start, line.length() - start);
    return (replaced_line);
}
