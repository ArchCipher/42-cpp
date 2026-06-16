#include <fstream>
#include <iostream>

using std::cout;
using std::string;

void   replace_all(std::ifstream &infile, std::ofstream &outfile,
                   const string &search_str, const string &replace_str);
string replace_line(const string &line, const string &search_str,
                    const string &replace_str);

/*
    NAME
        replace
    USAGE:
        ./replace <input_file> <search_string> <replacement_string>
    DESCRIPTION:
        Replace all occurrences of a search string with a replacement string in
        a file.
    REFERENCES:
        [Input/Output with files](https://cplusplus.com/doc/tutorial/files/)
*/

int    main(int ac, char **av)
{
    if (ac != 4)
    {
        cout << "Usage: ./replace <input_file> <search_string> "
                "<replacement_string>\n";
        return (0);
    }
    string search_str = av[2];
    if (search_str.empty())
        return (cout << "first RE may not be empty\n", 0);
    string        infile_name = av[1];
    std::ifstream infile(infile_name);
    if (!infile.is_open())
    {
        cout << "ERROR: Unable to open input file: " << infile_name << "\n";
        return (1);
    }
    string        outfile_name = infile_name + ".replace";
    std::ofstream outfile(outfile_name);
    if (!outfile.is_open())
    {
        cout << "ERROR: Unable to open outfile file: " << outfile_name << "\n";
        infile.close();
        return (1);
    }
    string replace_str = av[3];
    replace_all(infile, outfile, search_str, replace_str);
    infile.close();
    outfile.close();
}

void replace_all(std::ifstream &infile, std::ofstream &outfile,
                 const string &search_str, const string &replace_str)
{
    string line;

    while (std::getline(infile, line))
    {
        outfile << replace_line(line, search_str, replace_str);
        if (!infile.eof())
            outfile << "\n";
    }
}

string replace_line(const string &line, const string &search_str,
                    const string &replace_str)
{
    size_t found = line.find(search_str);
    if (found == string::npos)
        return line;

    size_t start = 0;
    string replaced_line;
    size_t search_str_len = search_str.length();
    while (found != string::npos)
    {
        replaced_line.append(line, start, found - start);
        replaced_line.append(replace_str);
        start = found + search_str_len;
        found = line.find(search_str, start);
    }
    replaced_line.append(line, start, line.length() - start);
    return (replaced_line);
}
